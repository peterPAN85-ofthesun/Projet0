EXEC = prog
CXX = g++
CXXFLAGS = -Werror -Wextra -Wall
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -rf *.o
