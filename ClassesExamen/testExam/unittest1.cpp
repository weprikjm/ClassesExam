#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\ClassesExamen\dynamicArray.h"
#include "..\ClassesExamen\myString.h"
#include "..\ClassesExamen\DList.h"
#include "..\ClassesExamen\Point2D.h"
#include "..\ClassesExamen\Projectile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testExam
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		/*
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
		*/
			// Projectile ----------------------------------------
			TEST_METHOD(Projectile_test)
		{
				Projectile p;

				p.point.x = 10.0f;
				p.point.y = 10.0f;

				p.speed.x = 2.0f;
				p.speed.y = 0.0f;

				Point2D<float> current = p.GetCurrentPosition(3.0f);

				Assert::AreEqual((float)16.0f, current.x, 0.00001f);
				Assert::AreEqual((float)10.0f, current.y, 0.00001f);
			}
			
		// ArrDyn remove wasted memory ----------------------------------------
		TEST_METHOD(ArrDyn_optimizeMem)
		{
			dynamicArray<int> array(10);

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual((unsigned int)10, array.GetCapacity());

			unsigned int wasted = array.removeWastedMemory();

			Assert::AreEqual((unsigned int)3, array.GetCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
	
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_mid)
		{
			DList<int> l;

			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);

			l.delNodes(1, 2);

			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)2, l.Count());
		}
		
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_begin)
		{
			DList<int> l;

			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);

			l.delNodes(0, 3);

			Assert::AreEqual((int)4, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)1, l.Count());
		}
		
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_end)
		{
			DList<int> l;

			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);

			l.delNodes(2, 100);

			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)2, l.end->data);
			Assert::AreEqual((unsigned int)2, l.Count());
		}
		/*
		// String prefix ----------------------------------------
		TEST_METHOD(String_prefix)
		{
			p2SString a("1234567890");
			p2SString b(50);
			b = "hola";

			a.prefix(b);
			b.prefix("1234567890");

			Assert::AreEqual(strcmp(a.GetString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.GetString(), "1234567890hola"), 0);
		}

		*/

	};
}