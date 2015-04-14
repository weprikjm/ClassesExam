#include <iostream>
#include "dynamicArray.h"
#include "DList.h"
#include "myString.h"
#include "Point2D.h"
#include "Tree.h"

int main()
{
		Tree<char> arbre('F');

		NodeTree<char>* b = arbre.Add('B');
		NodeTree<char>* g = arbre.Add('G');
		arbre.Add('A',b);
		NodeTree<char>* d = arbre.Add('D', b);
		arbre.Add('C', d);
		arbre.Add('E', d);
	
		DList<char>* list = new DList<char>;
		arbre.VisitAllNodes(list);

		getchar();

		return 0;
}