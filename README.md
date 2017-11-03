  # RPN Calculator
  **Purpose of program**: A Reverse Polish Notation (RPN) calculator similar to the built-in "dc" calculator. 
     The calculator performs basic arithmetic operations (+, -, x, /), clear it's 
     'memory', print the top-most double, and read-in an input from another file. The 
     RPNCalc relies on a stack that will store the doubles. Any arithmetic operations 
     will be done on the top 2 doubles in the stack.

     
 **Description of uploads:**
     *DoubleStack*
     DoubleStack.h		Class definitions, defines:
				- the variables that will be used
				- the basic functions required for the stack, 
				  (e.g. popping/pushing elements, returning
				  the size/top double of the stack, etc.)
     DoubleStack.cpp		Class implementations (w/ public and private 
				vars & funcs)
			      
     *RPNCalc*
     RPNCalc.h 	    		Class definitions
				- declaring a stack object and variables that
				  will be used
				- the functions required for the calculator, 
				  namely running, reading the user's input and
				  processing the necessary functions
     RPNCalc.cpp		Class implementations (w/ public and private 
				vars & funcs)
     
     *Test files*
     testRPNCalc.cpp		Tests the RPNCalc
     
  **How to compile and run**
     As there exists a Makefile:
       compile: make
       run:     ./RPNCalc
