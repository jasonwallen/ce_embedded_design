# This is the default rule, evaluated when typing shell command 'make'
# The body of the rule is executed only if any of its dependencies
# is more recent than executable file 'main'.
main: Shape.o Rectangle.o Circle.o main.o
	g++ Shape.o Rectangle.o Circle.o main.o -o main

Shape.o: Shape.cc Shape.h
	g++ -c Shape.cc

Rectangle.o: Rectangle.cc Rectangle.h Shape.h
	g++ -c Rectangle.cc

Circle.o: Circle.cc Circle.h Shape.h
	g++ -c Circle.cc

main.o: main.cc Circle.h Rectangle.h Shape.h
	g++ -c main.cc

# Any intermediate rule can be executed directly by typing shell command
# 'make' followed by the name of the rule. Here: 'make clean'
clean:
	rm -f *.o main


