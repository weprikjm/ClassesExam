#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"
#include "Tree.h"
#include "p2Stack.h"

int main()
{
		Tree<char> arbre('F');

		NodeTree<char>* b = arbre.Add('B');
		NodeTree<char>* g = arbre.Add('G');
		arbre.Add('A',b);
		NodeTree<char>* d = arbre.Add('D', b);
		arbre.Add('C', d);
		arbre.Add('E', d);
		NodeTree<char>* i = arbre.Add('I', g);
		arbre.Add('H', i);

		DList<NodeTree<char>*> list;

		arbre.VisitAllInOrderIterative(&list);

		arbre.PrintTree(&list);

		getchar();

		return 0;
}