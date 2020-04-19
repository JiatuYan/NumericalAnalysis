SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

Plot : Plot.o CubicSpline.o 
	g++ -o $@ $^ -llapacke
	
%.o : %.cpp
	g++ -c $< -llapacke 

clean :
	rm *.o *.exe *.txt html latex -fr Plot
