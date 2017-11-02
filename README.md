# RPNCalc
  A. Written by : Jia Wen Goh
  
  B. # Program Description
     Implement a Reverse Polish Notation (RPN) calculator similar to the 
     built-in "dc" calculator. The calculator must be able to perform basic
     arithmetic operations (+, -, x, /), clear it's 'memory', print the top-
     most double, and read-in an input from another file.
     The RPNCalc will rely on a stack that will store the doubles. Any 
     arithmetic operations will be done on the top 2 doubles in the stack.
     
  C. # Files
     * DoubleStack *
     DoubleStack.h			Class definitions, defines:
												- the variables that will be used
												- the basic functions required for the stack, 
													(e.g. popping/pushing elements, returning
													the size/top double of the stack, etc.)
     DoubleStack.cpp		Class implementations (w/ public and private 
												vars & funcs)
			      
     * RPNCalc *
     RPNCalc.h 	    		Class definitions
												- declaring a stack object and variables that
													will be used
												- the functions required for the calculator, 
													namely running, reading the user's input and
													processing the necessary functions
     RPNCalc.cpp			Class implementations (w/ public and private 
											vars & funcs)
     
  D. ** How to compile and run **
     As there exists a Makefile:
       compile: make
       run:     ./RPNCalc
