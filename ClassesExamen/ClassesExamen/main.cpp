#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"
#include "Tree.h"

int main()
{
		Tree<int> arbre;
		NodeTree<int>* node1 = new NodeTree<int>(3);
		
		arbre.Add(node1);
		arbre.root->siblings.PrintNode(arbre.root->siblings.getElementAtPos(0));

		getchar();

		return 0;
}