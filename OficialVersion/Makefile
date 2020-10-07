#Jason Jellie
#
COMP=g++ -Wall

all: runme char.o save.o ScottK.o

clean:
	rm -f runme
	rm -f *.o

runme: test.cpp header.h char.o JasonJ.o ScottK.o
	$(COMP) -o runme test.cpp char.o JasonJ.o ScottK.o

char.o: char.cpp char.h
	$(COMP) -c char.cpp

JasonJ.o: JasonJ.cpp JasonJ.h
	$(COMP) -c JasonJ.cpp

ScottK.o: ScottK.cpp ScottK.h
	$(COMP) -c ScottK.cpp



