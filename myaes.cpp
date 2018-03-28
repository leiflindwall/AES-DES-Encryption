#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

/* Compilation */
/* g++ myaes.cpp -o myaes -lcrypto */

/* AES key for Encryption and Decryption */
const static unsigned char aes_key[]={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};

int main( )
{
	/* Input data to encrypt (128-bits i.e., 16 bytes) */
	unsigned char aes_input[]="helloworld123456";
	
	/* Buffers for Encryption and Decryption. NOTE: I am making my buffers
	 * 18 here in order to leave one place for the string NULL terminator
	 * because I am encrypting and decrypting strings.  Normally, I would not
	 * be doing this.
	 */
	unsigned char enc_out[17];
	unsigned char dec_out[17];
	
	/* Clear both buffers */
	memset(enc_out, 0, 17);
	memset(dec_out, 0, 17);
		
	/* AES-128 bit ECB Encryption key */
	AES_KEY enc_key, dec_key;
	
	/* Set the encryption key */
	if(AES_set_encrypt_key(aes_key, 128, &enc_key)!=0)
	{
		fprintf(stderr, "AES_set_encrypt_key() failed!\n");
		exit(-1);
	}

	/* Encrypt! */
	AES_ecb_encrypt(aes_input, enc_out, &enc_key, AES_ENCRYPT);

	/** Now, lets decrypt the text we have encrypted **/
	
	
	/* Set the decryption key */
	if(AES_set_decrypt_key(aes_key, 128, &dec_key) != 0)
	{
		fprintf(stderr, "AES_set_decrypt_key() failed!\n");
	}
	
	/* Decrypt! */
	AES_ecb_encrypt(enc_out, dec_out, &dec_key, AES_DECRYPT);
	
	fprintf(stderr, "I have encrypted and decrypted text %s. The end result is %s\n", aes_input, dec_out);
		
	return 0;
}

