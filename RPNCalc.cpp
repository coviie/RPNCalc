/*
 *  RPNCalc.cpp
 *  Complete RPNCalc Implementation
 *  	   Written by : Jia Wen Goh
 *                 On : 15-02-2017
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "RPNCalc.h"
#include "DoubleStack.h"
using namespace std;

/*******************************
 * CONSTRUCTORS & DESCTRUCTORS *
 *******************************/

/* [Name]:		RPNCalc
 * [Purpose]:		Constructor; Initializes the variables
 * [Parameters]:	-
 * [Returns]:		-
 */
RPNCalc::RPNCalc()
{
	input = " ";
	value = 0;
	stackOutput1 = 0;
	stackOutput2 = 0;
}

/* [Name]:		~RPNCalc
 * [Purpose]:		Destructor; Deletes heap-allocated data (none)
 * [Parameters]:	-
 * [Returns]:		-
 */
RPNCalc::~RPNCalc()
{
	
}

/*******************************
 *        RUN FUNCTIONS        *
 *******************************/

/* [Name]:		run
 * [Purpose]:		Launches the calculator process (like dc's cmd loop),
 * 			reading in commands from cin. Each command is then 
 * 			read, and readfile() or checkInput() will then 
 * 			determine what to do.
 * [Parameters]:	-
 * [Returns]:		void
 */
void RPNCalc::run()
{	
	while (true) {
		cin >> input;
		if (input == "f" or input == "F") {
			cin >> input;
			if (readfile() == false)
				break;
		}
		else if (checkInput() == false)
			break;
	}
}

/*******************************
 *    CALCULATION FUNCTIONS    *
 *******************************/

/* [Name]:		operation
 * [Purpose]:		Does the arithmetic operations, depending on the 
 * 			arithmetic symbol input.
 * 			Pops the top 2 elements and does the arithmetic.
 * [Parameters]:	-
 * [Returns]:		void
 */
void RPNCalc::operation()
{
	stackOutput2 = stack.top();
	stack.pop();
	stackOutput1 = stack.top();
	stack.pop();
	
	if (input == "+")
		addition();
	
	if (input == "-")
		subtraction();
	
	if (input == "*")
		multiplication();
	
	if (input == "/")
		division();
}

/* [Name]:		addition
 * [Purpose]:		Adds/Sums the 2 top-most doubles.
 * [Parameters]:	-
 * [Returns]:		void
 */
void RPNCalc::addition()
{
	stackOutput1 += stackOutput2;
	stack.push(stackOutput1);
}

/* [Name]:		subtraction
 * [Purpose]:		Subtracts the 2 top-most doubles 
 * 			(order is important; it is 2nd-top-most - top-most)
 * [Parameters]:	-
 * [Returns]:		void
 */
void RPNCalc::subtraction()
{
	stackOutput1 -= stackOutput2;
	stack.push(stackOutput1);
}

/* [Name]:		multiplication
 * [Purpose]:		Multiplies the 2 top-most doubles
 * [Parameters]:	-
 * [Returns]:		void
 */
void RPNCalc::multiplication()
{
	stackOutput1 *= stackOutput2;
	stack.push(stackOutput1);
}

/* [Name]:		division
 * [Purpose]:		Divides the 2 top-most doubles 
 * 			(order is important; it is 2nd-top-most / top-most)
 * [Parameters]:	-
 * [Returns]:		void
 */
void RPNCalc::division()
{
	stackOutput1 /= stackOutput2;
	stack.push(stackOutput1);
}

/*******************************
 *       HELPER FUNCTIONS      *
 *******************************/

/* [Name]:		checkInput
 * [Purpose]:		'Gateway' after the user's input, i.e. based on the
 * 			user's input, determine what to do.
 * 			- +/-/x// 	Does arithmetic on the top 2 doubles
 * 			- p/P 		Prints the top-most double
 * 			- c/C		Clears the entire stack
 * 			- q/Q		Quits the programme
 * 			- If any other inputs are added, then output 
 * 			  ": unimplemented" on cerr.
 * [Parameters]:	-
 * [Returns]:		Bool; the function returns false if q is keyed in,
 * 			and true if anything else. This bool is read by 
 * 			run(), that determines what to do with it.
 */
bool RPNCalc::checkInput()
{
	if (got_double(&value))
		stack.push(value);
		
	else if (input == "+" or input == "-" or input == "*" 
					 or input == "/")
		operation();
			
	else if (input == "p" or input == "P")
		print();
	
	else if (input == "c" or input == "C")
		stack.clear();

		
	else if (input == "q" or input == "Q")
		return false;
	
	else
		cerr << input << ":  unimplemented\n";
	
	return true;
}

/* [Name]:		print
 * [Purpose]:		Prints the top-most double of the stack
 * [Parameters]:	-
 * [Returns]:		void
 */
void RPNCalc::print()
{
	cout << stack.top() << endl;
}

/* [Name]:		readfile
 * [Purpose]:		Called when the user inputs "f" or "F".
 * 			Reads the following string as the filename.
 * 			If the file doesn't exist, output an error, else read
 * 			into it.
 * 			(Recursively calls itself if the file contains a "f")
 * [Parameters]:	-
 * [Returns]:		Bool; the function returns false if q is in the read
 * 			file, and true if anything else. This bool is read by
 * 			run(), that determines what to do with it.
 */
bool RPNCalc::readfile()
{
	ifstream inf;
	inf.open(input);
	if (inf.fail()) {
		cerr << "Unable to read " << input << endl;
		return true;
	}
	
	while ( inf >> input ) {
		if (input == "f" or input == "F") {
			inf >> input;
			if (readfile() == false) {
				return false;
			}
		}
		else if (checkInput() == false)
			return false;
	}
	
	inf.close();
	
	return true;
}

/* [Name]:		got_double
 * [Purpose]:		If the string contains a double, convert the input
 * 			into a double, and place it in a variable
 * [Parameters]:	1 double (where to store the converted double)
 * [Returns]:		bool
 */
bool RPNCalc::got_double(double *resultp)
{
        return sscanf(input.c_str(), "%lf", resultp) == 1;
}