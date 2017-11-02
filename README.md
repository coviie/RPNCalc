# RPNCalc
*Written by: Jia Wen Goh
  
*About:  A Reverse Polish Notation (RPN) calculator similar to the built-in "dc" calculator. The calculator performs basic arithmetic operations (+, -, x, /), clear it's 'memory', print the top-most double, and read-in an input from another file.
The RPNCalc relies on a stack that will store the doubles. Any arithmetic operations will be done on the top 2 doubles in the stack.
     
*Files:
- DoubleStack.h & .cpp: Foundational stack data structure  
- RPNCalc.h & .cpp:	Calculator functions
- testRPNCalc:		Test file for the RPN Calculator

*Running:
As there exists a Makefile:
	compile: make
	run:     ./RPNCalc
