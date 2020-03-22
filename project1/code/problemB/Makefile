SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

test : $(OBJ)
	g++ -o $@ $(OBJ)

%.o : %.cpp
	g++ -c $< 

clean :
	rm *.o *.exe html latex -fr test output.txt
