CXX = g++
CXXFLAGS = -Wextra -Werror -Wall
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^

clean :
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)

tar : main.cpp math.cpp
	tar -cf exemple.tar main.cpp math.cpp
