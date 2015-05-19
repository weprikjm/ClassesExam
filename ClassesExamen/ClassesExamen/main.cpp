#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"
#include "Tree.h"
#include "p2Stack.h"
#include "Circle.h"

int* fibonacci(int n, int* previous, int* next, int* total)
{


	if (n == 0)
		return total;
	

	*total = *previous + *next;

	return fibonacci(n*-1, next, total, total);

}




int main(int argc, char** argv)
{
		dynamicArray<int> vector;
		int* total;
		fibonacci(4, 1, 1, &total);
		

		getchar();

		return 0;
}