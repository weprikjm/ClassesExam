#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"
#include "Tree.h"
#include "p2Stack.h"
#include "Circle.h"

int main(int argc, char** argv)
{
		DList<int> vector;

		vector.Add(1);
		vector.Add(2);
		vector.Add(3);
		int i = vector[0];
		printf("%d",i);
		

		getchar();

		return 0;
}