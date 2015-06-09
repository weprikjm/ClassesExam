#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\ClassesExamen\dynamicArray.h"
#include "..\ClassesExamen\myString.h"
#include "..\ClassesExamen\DList.h"
#include "..\ClassesExamen\Point2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testExam
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		

		TEST_METHOD(DynArray_Operator_concat)
		{
			dynamicArray<int> array;
			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(4);
			array.PushBack(5);
			array.PushBack(8);
			dynamicArray<int> array2;
			array2.PushBack(991);
			array2.PushBack(992);
			array2.PushBack(993);
			array += array2;
			Assert::AreEqual((int)array.GetElements(), 8);
			Assert::AreEqual((int)array[0], 1);
			Assert::AreEqual((int)array[1], 2);
			Assert::AreEqual((int)array[2], 4);
			Assert::AreEqual((int)array[3], 5);
			Assert::AreEqual((int)array[4], 8);
			Assert::AreEqual((int)array[5], 991);
			Assert::AreEqual((int)array[6], 992);
			Assert::AreEqual((int)array[7], 993);
		}





	};
}