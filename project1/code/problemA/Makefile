SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

test1 : test1.o function1.o BinaryMethod.o
	g++ -o $@ $^

test2 : test2.o function2.o BinaryMethod.o
	g++ -o $@ $^

test3 : test3.o function3.o BinaryMethod.o
	g++ -o $@ $^

test4 : test4.o function4.o BinaryMethod.o
	g++ -o $@ $^

%.o : %.cpp
	g++ -c $< 

clean :
	rm *.o *.exe html latex -fr test1 test2 test3 test4 output1.txt output2.txt output3.txt output4.txt
