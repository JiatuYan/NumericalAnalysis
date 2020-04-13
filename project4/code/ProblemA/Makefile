SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

Plot : Plot.o function.o CubicSpline.o 
	g++ -o $@ $^ -llapacke
	
%.o : %.cpp
	g++ -c $< -llapacke 

clean :
	rm *.o *.exe html latex -fr maxnorm.txt Plot Plot_6.txt Plot_11.txt Plot_21.txt Plot_41.txt Plot_81.txt
