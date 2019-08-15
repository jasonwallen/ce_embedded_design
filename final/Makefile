main: finalProjectMain.o RobotControl.o
	g++ finalProjectMain.o RobotControl.o -o main

finalProjectMain.o: finalProjectMain.cc
	g++ -c finalProjectMain.cc

RobotControl.o: RobotControl.cc RobotControl.h
	g++ -c RobotControl.cc

clean:
	rm -f *.o main
