test_clone_and_mutate: s32bit.o addressable_float.o clone_and_mutate.o
	g++ -std=c++17 -o test_clone_and_mutate s32bit.o addressable_float.o clone_and_mutate.o test_clone_and_mutate.cpp 

s32bit.o:
	g++ -g -c -std=c++17 -o s32bit.o s32bit.cpp
	
addressable_float.o:
	g++ -g -c -std=c++17 -o addressable_float.o addressable_float.cpp
	
clone_and_mutate.o: addressable_float.o
	g++ -g -c -std=c++17 -o clone_and_mutate.o clone_and_mutate.cpp
	
	
clean:
	rm addressable_float.o s32bit.o clone_and_mutate.o test_clone_and_mutate
