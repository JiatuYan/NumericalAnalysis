SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

test : test.o PLG.o
	g++ -o $@ $^

%.o : %.cpp
	g++ -c $< 

clean :
	rm test *.o
