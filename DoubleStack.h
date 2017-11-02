/*
 *  DoubleStack.h
 *  Complete DoubleStack Class Header and Declaration
 *  	   Written by : Jia Wen Goh
 *                 On : 15-02-2017
 */

#ifndef DOUBLESTACK_H_
#define DOUBLESTACK_H_

class DoubleStack {
	private:
		// Constant static int of the initial stack capacity
		const static int INIT_CAPACITY = 5;
		
		/******************************** 
		 *       Stack Variables        *
		 ********************************/
		// Double pointer that contains the stack array
		double	*stack;
		
		// The current count of the number of elements in the stack
		int	stackCount;
		
		//The capacity of the stack
		int	stackCapacity;
		
		/******************************** 
		 *       Helper Functions       *
		 ********************************/
		// Initialize a stack with the given capacity
		void	init(int);
		
		// Checks if the stack capacity is reached; if so, expand it
		void	expandCheck();
		
		// If the program tries to access an empty stack, throw an 
		// exception
		void	runtimeErrorCheck();
		
		// Prints the element in the stack
		void 	print();
		
		// If the capacity of the stack is reached, expand it
		int	capacityCheck();
		
	public:
		/******************************** 
		 * Constructors and Destructors *
		 ********************************/
		// Initializes an empty stack
		DoubleStack();
		
		// Initializes a stack so that elements of the array are on the 
		// stack with the array element 0 pushed first, and 
		// it's (size-1)st element at the top of the stack
		DoubleStack(double[], int);
		
		// Deletes heap-allocated data of the stack
		~DoubleStack();
		
		/******************************** 
		 *       Other Functions        *
		 ********************************/
		// Checks if the stack is empty; return true if it is, false 
		// if not
		bool 	isEmpty();
		
		// Clears the stack
		void 	clear();
		
		// Returns the size of the stack
		int 	size();
		
		// Returns the element at the top of the stack
		double 	top();

		/******************************** 
		 *         Pop and Push         *
		 ********************************/
		// Pops the top element off the stack
		void 	pop();
		
		// Pushes the given double onto the stack
		void 	push(double);
};

#endif