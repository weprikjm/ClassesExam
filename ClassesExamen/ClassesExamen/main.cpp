#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"
#include "Tree.h"
#include "p2Stack.h"
#include "Circle.h"
#include "arrayList.h"

int fibonacci_rec(int n)
{


	if (n == 0 || n == 1)
		return 1;




	return fibonacci_rec(n-1) + fibonacci_rec(n-2);

}



int fibonacci_it(int pos)
{
	int nextValue = 1;
	int previousValue = 0;

	if (pos == 0 || pos == 1)
		return 1;

	else
		for (int i = 0; i < pos; i++)
		{
			nextValue += previousValue;
			previousValue
		}
	

		return nextValue;

}




int main(int argc, char** argv)
{
		arrayList<int> queueList;
		Node<int>* node;

		queueList.Push(1);
		queueList.Push(2);

		queueList.Pop(node);



		getchar();

		return 0;
}