all:	cipher mydes myaes

cipher:	cipher.o DES.o AES.o
	g++ -std=c++11 cipher.o DES.o AES.o -o cipher -lcrypto


cipher.o:	cipher.cpp
	g++ -std=c++11 -g -c cipher.cpp

mydes:	mydes.cpp
	g++ -std=c++11 mydes.cpp -o mydes -lcrypto

myaes:	myaes.cpp
	g++ -std=c++11 myaes.cpp -o myaes -lcrypto

DES.o:	DES.cpp DES.h
	g++ -std=c++11 -g -c DES.cpp

AES.o:	AES.cpp AES.h
	g++ -std=c++11 -g -c AES.cpp

RSA.o:	RSA.cpp RSA.h
	g++ -std=c++11 -g -c RSA.cpp


clean:
	rm -rf *.o cipher myaes mydes
