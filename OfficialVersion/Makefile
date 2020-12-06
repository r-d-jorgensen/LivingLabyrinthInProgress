#Jason Jellie
#
COMP=g++ -Wall

all: LLL LLLTEST

clean:
	rm -f LLL*
	rm -f *.o

LLL: main.cpp JasonJ.cpp ScottK.cpp DavidJ.cpp
	$(COMP) -o LLL main.cpp

LLLTEST: main.cpp JasonJ.cpp ScottK.cpp DavidJ.cpp
	$(COMP) -o LLLTEST main.cpp -DTEST
