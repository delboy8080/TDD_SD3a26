#include "pch.h"
#include "CppUnitTest.h"
#include "../TDD_SD3a26/Cart.h"
#include <list>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestShoppingCart
{
	TEST_CLASS(TestShoppingCart)
	{
		Book *b1, *b2, *b3;
	public:
	
		TEST_METHOD_INITIALIZE(setUp)
		{
			b1 = new Book("The Widow", 6.99);
			b2 = new Book("Harry potter and the philosophers stone", 9.99);
			b3 = new Book("Grey Mountain", 16.99);
			Logger::WriteMessage("Setup");
		}
		TEST_METHOD_CLEANUP(TearDown)
		{
			delete b1, b2, b3;
			Logger::WriteMessage("TEar Down");
		}
		TEST_METHOD(TestAddValidBook)
		{

			Logger::WriteMessage("Test1");
			Cart c;
			bool result = c.AddBook(b1);
			Assert::IsTrue(result);
		}
		TEST_METHOD(TestAddNullptr)
		{
			Cart c;
			bool result = c.AddBook(nullptr);
			Assert::IsFalse(result);
			Logger::WriteMessage("Test 2");
		}
		TEST_METHOD(testAddAllWithnullptrInList)
		{
			Cart c;
			list<Book*> books;
			books.push_back(b1);
			books.push_back(b2);
			books.push_back(nullptr);
			Assert::AreEqual(2, c.AddAllBooks(books));
		}

		TEST_METHOD(testAddAllWithAllBooks)
		{
			Cart c;
			list<Book*> books;
			books.push_back(b1);
			books.push_back(b2);
			books.push_back(b3);
			Assert::AreEqual(0, c.size(), L"Wrong initial value");
			Assert::AreEqual(3, c.AddAllBooks(books));
			Assert::AreEqual(3, c.size());
		}

		TEST_METHOD(testAddAllWithEmptyList)
		{
			Cart c;
			list<Book*> books;
			Assert::AreEqual(0, c.size());
			Assert::AreEqual(0, c.AddAllBooks(books));
			Assert::AreEqual(0, c.size());
		}

		TEST_METHOD(testRemoveValidBook)
		{
			Cart c;
			c.AddBook(b1);
			c.AddBook(b3);
			c.AddBook(b2);
			Assert::AreEqual(3, c.size());
			bool result = c.removeBook("Grey Mountain");
			Assert::IsTrue(result);
			Assert::AreEqual(2, c.size());
		}
		TEST_METHOD(removeInValidBook)
		{
			Cart c;
			c.AddBook(b1);
			c.AddBook(b3);
			c.AddBook(b2);
			Assert::AreEqual(3, c.size());
			bool result = c.removeBook("Harry potter and the chamber of secrets");
			Assert::IsFalse(result);
			Assert::AreEqual(3, c.size());
		}

		TEST_METHOD(removeSubTotalEmpty)
		{
			Cart c;
			
			Assert::AreEqual(0, c.size());
			Assert::AreEqual(0.0, c.getSubTotal(),0.01);
		}
		TEST_METHOD(removeSubTotalOneBook)
		{
			Cart c;
			c.AddBook(b1);
			Assert::AreEqual(1, c.size());
			Assert::AreEqual(6.99, c.getSubTotal(), 0.01);
		}
		TEST_METHOD(removeSubTotalThreeBook)
		{
			Cart c;
			c.AddBook(b1);
			c.AddBook(b2);
			c.AddBook(b3);
			Assert::AreEqual(3, c.size());
			Assert::AreEqual(33.97, c.getSubTotal(), 0.01);
		}
	};
}
