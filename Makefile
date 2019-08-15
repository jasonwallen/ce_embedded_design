main: finalProjectMain.o RobotControl.o setup.o
	g++ finalProjectMain.o RobotControl.o setup.o -o main

finalProjectMain.o: finalProjectMain.cc
	g++ -c finalProjectMain.cc

RobotControl.o: RobotControl.cc RobotControl.h
	g++ -c RobotControl.cc

setup.o: setup.cc setup.h
	g++ -c setup.cc

clean:
	rm -f *.o main
