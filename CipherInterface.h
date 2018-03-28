#ifndef __CIPHER_INTERFACE__
#define __CIPHER_INTERFACE__

#include <string> /* For C++ strings */

using namespace std;

/**
 * This class implements the interface for a cipher.
 * It defines functions usually used in a cipher
 */
class CipherInterface
{
	/** The public members **/
	public:

		/**
		 * The default constructor
		 */
		CipherInterface(){}
		
		
		/**
		 * Sets the key to use
		 * @param key - the key to use
		 * @return - True if the key is valid and False otherwise
		 */
		virtual bool setKey(const unsigned char* key){ return false;  }

		/**	
		 * Encrypts a plaintext string
		 * @param plaintext - the plaintext string
		 * @return - the encrypted ciphertext string
		 */
		virtual unsigned char* encrypt(const unsigned char* plaintext){ return NULL; }

		/**
		 * Decrypts a string of ciphertext
		 * @param ciphertext - the ciphertext
		 * @return - the plaintext
		 */
		virtual unsigned char* decrypt(const unsigned char* ciphertext) { return NULL; }

		/* The protected members */
	protected:
	
};

#endif
