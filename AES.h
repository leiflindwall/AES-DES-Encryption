#ifndef AES_H
#define AES_H

#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <string.h>
#include <string>
#include "CipherInterface.h"
#include <ctype.h>

using namespace std;

/** 
 * Implements a AES cipher
 */
class AES: public CipherInterface
{
	/* The public members */
	public:
		
		/**
		 * The default constructor
	 	 */
		AES(){}
			
		/**
		 * Sets the key to use
		 * @param key - the key to use
		 * @return - True if the key is valid and False otherwise
		 */
		virtual bool setKey(const unsigned char* key);

		/**	
		 * Encrypts a plaintext string
		 * @param plainText - the plaintext string
		 * @return - the encrypted ciphertext string
		 */
		virtual unsigned char* encrypt(const unsigned char* plainText);

		/**
		 * Decrypts a string of cipherText
		 * @param ciphertext - the cipherText
		 * @return - the plaintext
		 */
		virtual unsigned char* decrypt(const unsigned char* cipherText);
	
			
	/* The protected members */
	protected:

		//TODO: declare the AES key
};


#endif
