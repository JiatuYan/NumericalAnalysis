SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

test1 : test1.o function1.o SecantMethod.o
	g++ -o $@ $^

test2 : test2.o function2.o SecantMethod.o
	g++ -o $@ $^

test3 : test3.o function3.o SecantMethod.o
	g++ -o $@ $^

%.o : %.cpp
	g++ -c $< 

clean :
	rm *.o *.exe html latex -fr test1 test2 test3 output1.txt output2.txt output3.txt
