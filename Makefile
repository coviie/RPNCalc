###########################################################################
##                         Makefile for (RPNCalc)                        ##
###########################################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3

RPNCalc: DoubleStack.o RPNCalc.o testRPNCalc.o
	${CXX} ${LDFLAGS} -o RPNCalc DoubleStack.o RPNCalc.o testRPNCalc.o

DoubleStack.o:  	DoubleStack.cpp 	DoubleStack.h 
RPNCalc.o:     		RPNCalc.cpp		RPNCalc.h
testRPNCalc.o:		testRPNCalc.cpp		RPNCalc.h	DoubleStack.h

clean:
	rm -rf RPNCalc *.o *.dSYM
