test_32bit: s32bit.o addressable_float.o germinal_centre.o
	g++ -std=c++17 -o test_32bit s32bit.o addressable_float.o germinal_centre.o test_32bit.cpp 

s32bit.o:
	g++ -g -c -std=c++17 -o s32bit.o s32bit.cpp
	
addressable_float.o:
	g++ -g -c -std=c++17 -o addressable_float.o addressable_float.cpp
	
germinal_centre.o: addressable_float.o
	g++ -g -c -std=c++17 -o germinal_centre.o germinal_centre.cpp
	
clean:
	rm s32bit.o addressable_float.o germinal_centre.o test_32bit
