#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"

int main()
{
		DList<int> List;
		List.Add(4);
		List.Add(5);

		List.RemoveElement(List.getElementAtPos(0));
		List.PrintNode(List.getElementAtPos(1));
		//printf("%d", List.Count());
		getchar();
		return 0;
}