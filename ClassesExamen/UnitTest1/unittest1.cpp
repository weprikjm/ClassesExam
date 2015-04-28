#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ClassesExamen/Tree.h"
#include "../ClassesExamen/DList.h"
#include <Assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Tree<char> arbre('F');

			NodeTree<char>* b = arbre.Add('B');
			NodeTree<char>* g = arbre.Add('G');
			arbre.Add('A', b);
			NodeTree<char>* d = arbre.Add('D', b);
			arbre.Add('C', d);
			arbre.Add('E', d);
			NodeTree<char>* i = arbre.Add('I', g);
			arbre.Add('H', i);

			DList<NodeTree<char>*> list;

			arbre.VisitAllInOrderIterative(&list);


			Assert::AreEqual((int)list.Count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');

		}

	};
}