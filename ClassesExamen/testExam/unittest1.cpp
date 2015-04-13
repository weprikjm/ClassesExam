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
		
		TEST_METHOD(AssignationOperator)		//----------------------------------------------- myString Class test methods
		{
			myString chain;
			myString chain2;

			chain.setString("hola");
			chain2.setString("adeu");

			chain = chain2;

			Assert::IsTrue(chain == chain2);

		}
		TEST_METHOD(PlusEqualOperator)
		{
			myString chain;
			myString chain2;

			chain.setString("hola");
			chain2.setString("adeu");

			chain += chain2;

			Assert::IsTrue(chain == "holaadeu");
		}
		TEST_METHOD(DifferentThan)
		{
			myString chain;
			myString chain2;

			chain.setString("hola");
			chain2.setString("adeu");

			Assert::IsTrue(chain != chain2);


		}

		TEST_METHOD(DifferentThanChar)
		{
			myString chain;
			myString chain2;

			chain.setString("hola");
			chain2.setString("adeu");

			Assert::IsTrue(chain != "hey");

		}

		TEST_METHOD(EqualThan)
		{
			myString chain;
			myString chain2;

			chain.setString("hola");
			chain2.setString("adeu");

			Assert::IsTrue(chain != chain2);

		}

		TEST_METHOD(EqualThanChar)
		{
			myString chain;
			myString chain2;

			chain.setString("hola");
			chain2.setString("adeu");

			Assert::IsTrue(chain != "hey");

		}







		TEST_METHOD(setTo)//------------------------  Point2D class test methods
		{
			Point2D<int> p1;
			Point2D<int> p2;

			p1.setTo(1,1);
			p2.setTo(1,1);

			Assert::IsTrue(p1==p2);

		}

		TEST_METHOD(Clear)//------------------------  Point2D class test methods
		{
			Point2D<int> p1;
			Point2D<int> p2;

			p1.Clear();
			p2.Clear();

			Assert::IsTrue(p1 == p2);

		}

		TEST_METHOD(lessEqual)//------------------------  Point2D class test methods
		{
			Point2D<int> p1;
			Point2D<int> p2;

			p1.setTo(1,1);
			p2.setTo(1, 1);

			p1 -= p2;

			Assert::AreEqual(p1.x,0);
			Assert::AreEqual(p1.y, 0);

		}
		TEST_METHOD(moreEqual)//------------------------  Point2D class test methods
		{
			Point2D<int> p1;
			Point2D<int> p2;

			p1.setTo(1, 1);
			p2.setTo(1, 1);

			p1 += p2;

			Assert::AreEqual(p1.x, 2);
			Assert::AreEqual(p1.y, 2);

		}

		TEST_METHOD(AreEqual)//------------------------  Point2D class test methods
		{
			Point2D<int> p1;
			Point2D<int> p2;

			p1.setTo(1, 1);
			p2.setTo(1, 1);

			

			Assert::IsTrue(p1.x == p2.x);
			Assert::IsTrue(p1.y == p2.y);

		}
		TEST_METHOD(AreDifferent)//------------------------  Point2D class test methods
		{
			Point2D<int> p1;
			Point2D<int> p2;

			p1.setTo(1, 1);
			p2.setTo(1, 1);

		

			Assert::IsFalse(p1.x != p2.x);
			Assert::IsFalse(p1.y != p2.y);

		}

		TEST_METHOD(distanceTo)//------------------------  Point2D class test methods
		{
			Point2D<int> p1;
			Point2D<int> p2;

			p1.setTo(1, 1);
			p2.setTo(1, 1);

			int distance = p1.DistanceTo(p2);

			Assert::AreEqual(distance, 1);
			
		}



	};
}