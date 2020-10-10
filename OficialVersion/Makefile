#Jason Jellie
#
COMP=g++ -Wall

all: runme

clean:
	rm -f runme*
	rm -f *.o

runme: main.cpp header.h JasonJ.o ScottK.o DavidJ.o
	$(COMP) -o runme main.cpp JasonJ.o ScottK.o DavidJ.o

JasonJ.o: JasonJ.cpp JasonJ.h
	$(COMP) -c JasonJ.cpp

ScottK.o: ScottK.cpp ScottK.h
	$(COMP) -c ScottK.cpp

DavidJ.o: DavidJ.cpp DavidJ.h
	$(COMP) -c DavidJ.cpp
