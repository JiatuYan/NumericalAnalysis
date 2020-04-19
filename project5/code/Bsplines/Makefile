SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

test : test.o QuadraticBsplines.o CubicBsplines.o
	g++ -o $@ $^ -llapacke
	
%.o : %.cpp
	g++ -c $< -llapacke 

clean :
	rm *.o *.exe *.txt html latex -fr test
