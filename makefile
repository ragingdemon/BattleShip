Test:	main.o board.o coordinate.o
	g++ main.o board.o coordinate.o -o Test
main.o:	main.cpp
	g++ -c main.cpp
board.o:	board.cpp
	g++ -c board.cpp
coordinate.o:	coordinate.cpp
	g++ -c coordinate.cpp