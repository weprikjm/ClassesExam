#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"

int main()
{
		DList<int> l;

		l.add(1);
		l.add(2);
		l.add(3);
		l.add(4);

		l.delNodes(1, 2);

		
		printf("%d", l.start->data);
		printf("%d", l.end->data);

		printf("%d",l.Count());

		getchar();
		return 0;
}