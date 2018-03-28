#ifndef DES_H
#define DES_H

#include <stdio.h>
#include <stdlib.h>
#include <openssl/des.h>
#include <string.h>
#include <string>
#include "CipherInterface.h"
#include <ctype.h>

using namespace std;

/** 
 * Implements a DES cipher
 */
class DES: public CipherInterface
{
	/* The public members */
	public:
		
		/**
		 * The default constructor
	 	 */
		DES(){}
			
		/**
		 * Sets the key to use
		 * @param key - the key to use
		 * @return - True if the key is valid and False otherwise
		 */
		virtual bool setKey(const unsigned char* key);

		/**	
		 * Encrypts a plaintext string
		 * @param plaintext - the plaintext string
		 * @return - the encrypted ciphertext string
		 */
		virtual unsigned char* encrypt(const unsigned char* plaintext);

		/**
		 * Decrypts a string of ciphertext
		 * @param ciphertext - the ciphertext
		 * @return - the plaintext
		 */
		virtual unsigned char* decrypt(const unsigned char* ciphertext);
	
			
	/* The protected members */
	protected:


		/**
		 * Converts two characters into a hex integers
		 * and then inserts the integers into the higher
		 * and lower bits of the byte
		 */
		unsigned char twoCharToHexByte(const unsigned char* twoChars);
		
		/**
		 * Converts a character into a hexidecimal integer
		 * @param character - the character to convert
		 * @return - the converted character, or 'z' on error
		 */
		unsigned char charToHex(const char& character);
		
		/** 
		 * Converts a long integer (4 bytes = 32 bits)
		 * into an array of 8 characters.
		 * @param l - the long integer to convert
		 * @param c - the character array to store the result
		 */
		void ltoc(DES_LONG l, unsigned char *c);


		/**
		 * Converts an array of 8 characters
		 * (i.e. 4 bytes/32 bits)
		 * @param c - the array of 4 characters (i.e. 1-byte per/character
		 * @return - the long integer (32 bits) where each byte
		 * is equivalent to one of the bytes in a character array
		 */
		DES_LONG ctol(unsigned char *c);
		
		/* The 64-bit, user-defined encryption key */
		unsigned char des_key[8];
		
		/* The key structure used by the DES library */
		des_key_schedule key;
};


#endif
