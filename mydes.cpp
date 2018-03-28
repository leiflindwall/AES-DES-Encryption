#include <stdio.h>
#include <stdlib.h>
#include <openssl/des.h>
#include <string.h>

#define ENC 1
#define DEC 0

/* Compilation */
/* g++ mydes.cpp -o mydes -lcrypto */

/**
 * Converts an array of 8 characters
 * (i.e. 4 bytes/32 bits)
 * @param c - the array of 4 characters (i.e. 1-byte per/character
 * @return - the long integer (32 bits) where each byte
 * is equivalent to one of the bytes in a character array
 */
DES_LONG ctol(unsigned char *c) 
{
        DES_LONG l;
        l =((DES_LONG)(*((c)++)));
        l = l | (((DES_LONG)(*((c)++)))<<8L);
        l = l | (((DES_LONG)(*((c)++)))<<16L);
        l = l | (((DES_LONG)(*((c)++)))<<24L);
        return l;
};


/** 
 * Converts a long integer (4 bytes = 32 bits)
 * into an array of 8 characters.
 * @param l - the long integer to convert
 * @param c - the character array to store the result
 */
void ltoc(DES_LONG l, unsigned char *c) 
{
        *((c)++)=(unsigned char)(l&0xff);
        *((c)++)=(unsigned char)(((l)>> 8L)&0xff);
        *((c)++)=(unsigned char)(((l)>>16L)&0xff);
        *((c)++)=(unsigned char)(((l)>>24L)&0xff);
}


int main()
{
	
	int k;
	
	/* An aray of two long integer. Each long integer is (typically) 32-bits */
	DES_LONG in[2];
	
	/* The 64-bit, user-defined encryption key */
	static unsigned char cbc_key[8] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};

	/* The key structure used by the DES library */
	des_key_schedule key;
	
	/* Use the user-defined key to generate the keys for each
	 * stage of the DES
	 */
	if ((k = des_set_key_checked(&cbc_key,key)) != 0)
		printf("\nkey error\n");
	
	/* The plain text - must be 64 bits (i.e. 
	 * In this example, there are 8 ASCI
	 * characters where each character is
	 * 1 byte (8-bits).
	 */
	unsigned char plainText[] = "BillyBob";
	
	/* Print the original text */	
	fprintf(stderr, "Original text: %s\n", plainText);
	
	/* The cipher text */
	unsigned char cipherText[9];
	
	/* The decrypted text */
	unsigned char decryptedText[9];
	
	/* Stuff the first 4 bytes of the plaintext into a long */
	in[0] = ctol(plainText);
	
	/* Stuff the next 4 bytes of the plaintext into a long */
	in[1] = ctol(plainText + 4);
	
		
	/* Encrypt the the array of 2 longs; in[0] and
	 * and in[1] will be replaced with the corresponding
	 * ciphertext
	 */
	des_encrypt1(in, key, ENC);
	
	memset(cipherText, 0, 9);
		
	/* Convert the first 32 bits of ciphertext from a 
	 * long integer (32-bits) into character format 
	 * (4-char array).
	 */
	ltoc(in[0], cipherText);
		
	/* Convert the first 32 bits of ciphertext from a 
	 * long integer (32-bits) into character format 
	 * (4-char array).
	 */
	ltoc(in[1], cipherText + 4);
	
	/* Print the cipher text */
	fprintf(stderr, "Cipher text: %s\n", cipherText);
	
	/**
	 * Lets convert the ciphertext from
	 * the character format into long format
	 */
	in[0] = ctol(cipherText);
	in[1] = ctol(cipherText + 4);
	
		
	/* Decrypt the cipher text */
	des_encrypt1(in,key,DEC);

	memset(decryptedText, 0, 9);
	
	/* Convert the first 4 bytes of plaintext from long to char */
	ltoc(in[0], decryptedText);
	ltoc(in[1], decryptedText + 4);
	
	printf("DES Decryption: %s\n", decryptedText);
}



