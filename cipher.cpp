#include <string>
#include <iostream>
#include "CipherInterface.h"
#include "DES.h"
#include "AES.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	/**
	 * TODO: Replace the code below	with your code which can SWITCH
	 * between DES and AES and encrypt files. DO NOT FORGET TO PAD
	 * THE LAST BLOCK IF NECESSARY.
	 *
	 * NOTE: due to the incomplete skeleton, the code may crash or
	 * misbehave.
	 */

	 string aes = "AES";
 	 string des = "DES";
	 string current_cipher = argv[1];
	 string current_key = argv[2];
	 string current_op = argv[3];
	 string in = argv[4];
	 string out = argv[5];
	 ofstream outfile;
	 string plaintext, ciphertext;
	 fstream infile(argv[4], fstream::in);

	 // read the plaintext
	 getline(infile, plaintext, '\0');

	 cout << "plaintext: " << plaintext << endl;
	 cout << "**************\n" << endl;

	 // close the input file
	 infile.close();

	 // open output file
	 outfile.open(out);

	 // check arguments
	 cout << "**************\n";
	 cout << "cipher: " << argv[1] << endl;
	 cout << "key: " << argv[2] << endl;
	 cout << "ENC/DEC: " << argv[3] << endl;
	 cout << "input file: " << argv[4] << endl;
	 cout << "output file: " << argv[5] << endl;

	/* Create an instance of the DES cipher */
	CipherInterface* cipher = NULL;

	if(argc < 6)
	{
		cout << "incorrect execution: \n";
		cout << "correct: ./cipher <CIPHER NAME> <KEY> <ENC/DEC> ";
		cout << "<INPUT FILE> <OUTPUT FILE>\n";
		cout << "valid ciphers: DES, AES\n";
	}
	else if(current_cipher.compare(aes) == 0)
	{
		/* Create an instance of the AES cipher */
		cipher = new AES();

	}
	else if(current_cipher.compare(des) == 0)
	{
		/* Create an instance of the DES cipher */
		cipher = new DES();
	}
	else
	{
		// if cipher cannot be found
		cout << "Non-valid choice of cipher\n" << endl;
	}


	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	else
	{
		/* Set the encryption key
		 * A valid key comprises 16 hexidecimal
		 * characters. Below is one example.
		 * Your program should take input from
		 * command line.
		 */
		cipher->setKey((unsigned char*)"0123456789abcdef");

		/* Perform encryption */
		//string cipherText = cipher->encrypt("hello world");

		/* Perform decryption */
		//cipher->decrypt(cipherText);

/*
		if(current_op.compare(enc) == 0)
			{
				/* Perform encryption */
	/*			ciphertext = cipher->encrypt(plaintext);
				cout << "ENCRYPT: " << endl << ciphertext << endl << endl;
				outfile << ciphertext;
				outfile.close();
			}
			else if(current_op.compare(dec) == 0)
			{
				/* Perform decryption */
/*				string originaltext = cipher->decrypt(plaintext);
				cout << "DECRYPT: " << endl << originaltext << endl << endl;
				outfile << originaltext;
				outfile.close();
			}
			else
			{
				cout << "Invalid operation: must be ENC/DEC for encrypt/decrypt\n";
			}

			*/
	}

	//system("pause");
	return 0;
}
