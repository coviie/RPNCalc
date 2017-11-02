/*
 *  RPNCalc.h
 *  Complete RPNCalc Class Header and Declaration
 *  	   Written by : Jia Wen Goh
 *                 On : 15-02-2017
 */

#ifndef RPNCALC_H_
#define RPNCALC_H_

#include "DoubleStack.h"

class RPNCalc {
	private:
		/******************************** 
		 *       Calc Variables         *
		 ********************************/
		// The DoubleStack object that holds the doubles
		DoubleStack 	stack;
		
		// Variable that will store the double if the input is a double
		double		value;
		
		// Variables that will be popped for the calculation
		double		stackOutput1;
		double		stackOutput2;
		
		// String that stores the user's input 
		std::string	input;
		
		/******************************** 
		 *     Calculation Functions    *
		 ********************************/
		// In-charge of the operation process
		void	operation();
		
		// Individual operation functions
		void	addition();
		void	subtraction();
		void	multiplication();
		void	division();
		
		/******************************** 
		 *       Helper Functions       *
		 ********************************/
		// Prints the top-most double
		void	print();
		
		// Reads the file given
		bool	readfile();
		
		// Checks the user's input and determines what to do with it
		bool	checkInput();
		
		// If the input string contains a double, convert it into 
		// a double
		bool	got_double(double*);
		
		
	public:
		/******************************** 
		 * Constructors and Destructors *
		 ********************************/
		// Initializes the object
		RPNCalc();
		// Deletes heap-allocated data of the object
		~RPNCalc();
		
		/******************************** 
		 *         Run Function         *
		 ********************************/
		// Launch a process like dc's command loop, 
		// reading in commands from cin
		void	run();
};

#endif