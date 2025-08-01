prog : main.o math.o
	g++ -o prog main.o math.o

main.o : main.cpp
	g++ -o main.o -c main.cpp -Wextra -Werror -Wall

math.o : math.cpp
	g++ -o math.o -c math.cpp -Wextra -Werror -Wall
