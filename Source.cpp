
Page
1
of 4
/*
Stefania Ascencio
CHAPTER 17
STACKS
PE 1
COSC 2412
Two stacks of the same type are the same if they have the same number of
elements and their elements at the corresponding positions are the same.
Overload the relational operator == for the class stackType that returns
true if two stacks of the same type are the same;
it returns false otherwise. Also, write the definition of the function
template to overload this operator.
*/
#include <iostream>
#include<cassert>//FOR ASSERT FUNC
using namespace std;
template <class Type>//definition of the template class stackType
class stackType
{
private:
	int maxStackSize;
	int stackTop; // data of the class
	Type* list;
	// data of the class
public:
	void initializeStack();
	bool isFullStack() const;
	bool isEmptyStack() const;
	void push(const Type&);//adds a new element to the top of the 
	stack(books example)
		void pop();//Removes the top element of the stack: NO EMPTY, and 
	must exist
		Type top() const;
	stackType(int = 20);
	~stackType();
	bool operator==(const stackType<Type>&);//bool for true or false, 
	Overload == Operator
}; // end template class stackType
// initialize stack
template <class Type>
void stackType<Type>::initializeStack()
{
	stackTop = 0;//must start to 0
}
// check for stack Full
template <class Type>
bool stackType<Type>::isFullStack() const
{
	return (stackTop == maxStackSize);
}
// check for emptyStack
template <class Type>
bool stackType<Type>::isEmptyStack() const//BOOL TO RETURN TRUE OR FALSE
{
	return (stackTop == 0);
}    //   end function isEmptyStack
 // insert an element into stack
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	if (!isFullStack())
	{
		list[stackTop] = newItem;
		stackTop++;
	} // end if
	else
		cout << "Can't add to a full stack";
}    //   end func. push
 // delete element from the stack
template <class Type>
void stackType<Type>::pop()
{
	if (!isEmptyStack())
		stackTop--;
	else
		cout << "It can't be  remove from an empty stack";
}    //   end function pop
 // return the value of stack-top
template <class Type>
Type stackType<Type>::top() const
{
	assert(stackTop != 0);
	return list[stackTop - 1];
}
// constructor for class stackType
template <class Type>
stackType<Type>::stackType(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "The Size is Invalid ";
		stackSize = 10;
	} // end if
	else
		maxStackSize = stackSize;
	stackTop = 0;
	list = new Type[maxStackSize];
}
// destructor for the class stackType
template <class Type>
stackType<Type>::~stackType()
{
	delete[] list;
}    //  ~ end destructor stackType
 // overload the equality operator
template <class Type>
bool stackType<Type>::operator==
(const stackType<Type>& right)
{
	// check for same number of elements
	if (this->stackTop != right.stackTop)
		return false;
	//check for equality of elements at corresponding positions
	for (int i = 0; i < stackTop; i++)
		if (this->list[i] != right.list[i])
			return false;
	return true;
}
//main function
int main()
{
	cout << "This Program overloads the relational "
		<< "Operator == for the class stackType." << endl;
	// create objects stackType
	stackType<int> s1(13);
	stackType<int> s2(28);
	// insert elements into the stacks
	cout << "\n\Inserting elements "
		<< "to both the stacks 5, 10, 15, 20, 25.." << endl;
	for (int i = 5; i < 50; i += 5)
	{
		s1.push(i);
		s2.push(i);
	} // end for
	  //Conditional to check if stacks are equal or not
	if (s1 == s2)
		cout << "\n\Both stacks are equal" << endl;
	else
		cout << "\n\The stacks are not equal" << endl;
	// insert one more element into the second stack
	cout << "\n\Inserting element 6 to the second stack." << endl;
	s2.push(6);//add
	//check and print whether the stacks are equal or not
	if (s1 == s2)
		cout << "\n\Both stacks are equal" << endl;
	else
		cout << "\n\The stacks are not equal" << endl;
	system("pause");
	return 0;
}
