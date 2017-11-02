/*
 *  DoubleStack.cpp
 *  Complete DoubleStack Implementation
 *  	   Written by : Jia Wen Goh
 *                 On : 15-02-2017
 */

#include <iostream>
#include "DoubleStack.h"
using namespace std;

/*******************************
 * CONSTRUCTORS & DESCTRUCTORS *
 *******************************/

/* [Name]:		DoubleStack
 * [Purpose]:		Constructor; Initializes an empty stack
 * [Parameters]:	-
 * [Returns]:		-
 */
DoubleStack::DoubleStack()
{
	init(INIT_CAPACITY);
}

/* [Name]:		DoubleStack
 * [Purpose]:		Constructor; Initializes a stack with the given array
 * [Parameters]:	1 double array (input), 1 int (capacity)
 * [Returns]:		-
 */
DoubleStack::DoubleStack(double input[], int capacity)
{
	init(capacity);
	for (int i = 0; i < capacity; i++)
		push(input[i]);
}

/* [Name]:		~DoubleStack
 * [Purpose]:		Destructor; Deletes the heap-allocated data (of 
			the stack) 
 * [Parameters]:	-
 * [Returns]:		-
 */
DoubleStack::~DoubleStack()
{
	delete []stack;
}

/*******************************
 *	 OTHER FUNCTIONS       *
 *******************************/

/* [Name]:		isEmpty
 * [Purpose]:		Checks if the stack is empty
 * [Parameters]:	-
 * [Returns]:		bool (true if empty, false if not)
 */
bool DoubleStack::isEmpty()
{
	if (stackCount == 0)
		return true;
	else
		return false;
}

/* [Name]:		clear
 * [Purpose]:		Makes stack into an empty one
 * [Parameters]:	-
 * [Returns]:		void
 */
void DoubleStack::clear()
{
	stackCount = 0;
}

/* [Name]:		size
 * [Purpose]:		Returns the number of doubles in the stack
 * [Parameters]:	-
 * [Returns]:		int (size)
 */
int DoubleStack::size()
{
	return stackCount;
}

/* [Name]:		top
 * [Purpose]:		Returns the double at the top of the stack
 * [Parameters]:	-
 * [Returns]:		double (top element)
 */
double DoubleStack::top()
{
	runtimeErrorCheck();
	return stack[stackCount - 1];
}

/*******************************
 *	   POP & PUSH          *
 *******************************/

/* [Name]:		pop
 * [Purpose]:		Pops the double off the top of the stack
 * [Parameters]:	-
 * [Returns]:		void
 */
void DoubleStack::pop()
{
	runtimeErrorCheck();
	stackCount--;
}

/* [Name]:		push
 * [Purpose]:		Pushes the double to the top of the stack
 * [Parameters]:	1 double (input)
 * [Returns]:		void
 */
void DoubleStack::push(double input)
{
	stackCount++;
	expandCheck();
	stack[stackCount - 1] = input;
}

/*******************************
 *      HELPER FUNCTIONS       *
 *******************************/

/* [Name]:		init
 * [Purpose]:		Initializes the stack with the given capacity
 * [Parameters]:	1 int (capacity to be initialized)
 * [Returns]:		void
 */
void DoubleStack::init(int capacity)
{
	stackCapacity	= capacity;
	stack		= new double[stackCapacity];
	stackCount	= 0;
}

/* [Name]:		expandCheck
 * [Purpose]:		Checks if the stackCapacity is reached; if it is,
 * 			multiply the capacity value by 2 and update the stack
 * 			(i.e. double the capacity of that stack).
 * [Parameters]:	-
 * [Returns]:		void
 */
void DoubleStack::expandCheck()
{
	if (stackCount == stackCapacity) {
		stackCapacity *= 2;
		double *temp = new double[stackCapacity];
		for (int i = 0; i < stackCount; i++)
			temp[i] = stack[i];
		delete []stack;
		stack = temp;
	}
}

/* [Name]:		print
 * [Purpose]:		Prints the elements of the stack
 * 			(Used for debugging)
 * [Parameters]:	-
 * [Returns]:		void
 */
void DoubleStack::print()
{
	for (int i = stackCount-1; i >= 0; i--) {
		cout << stack[i] << endl;
	}
}

/* [Name]:		runtimeErrorCheck
 * [Purpose]:		Throws a runtime_error and outputs "empty_stack"
 * 			if the stack is empty.
 * [Parameters]:	-
 * [Returns]:		void
 */
void DoubleStack::runtimeErrorCheck()
{
	if (isEmpty() == true)
		throw std::runtime_error("empty_stack");
}

/* [Name]:		capacityCheck
 * [Purpose]:		Return the current capacity of the stack.
 * 			(Used for debugging purposes)
 * [Parameters]:	-
 * [Returns]:		int
 */
int DoubleStack::capacityCheck()
{
	return stackCapacity;
}
