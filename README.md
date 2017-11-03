  # RPN Calculator
  **Purpose of program**: A Reverse Polish Notation (RPN) calculator similar to the built-in "dc" calculator. 
     The calculator performs basic arithmetic operations (+, -, x, /), clear it's 
     'memory', print the top-most double, and read-in an input from another file. The 
     RPNCalc relies on a stack that will store the doubles. Any arithmetic operations 
     will be done on the top 2 doubles in the stack.

     
 **Description of uploads:**
  *DoubleStack*
  DoubleStack.h	& .cpp: the basic functions required for the stack, (e.g. popping/pushing elements, returning the size/top double of the stack, etc.)
  
  *RPNCalc*
  RPNCalc.h & .cpp: functions required for the calculator, namely running, reading the user's input and processing the necessary functions
     
  *Test files*
  testRPNCalc.cpp: Tests the RPNCalc
     
  **How to compile and run:**
     As there exists a Makefile:
       compile: make
       run:     ./RPNCalc
