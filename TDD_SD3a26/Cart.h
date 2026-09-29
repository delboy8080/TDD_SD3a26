#pragma once
#include "book.h"
#include <list>
class Cart
{
	std::list<Book*> books;
public:
	bool AddBook(Book* b1);
	int AddAllBooks(std::list<Book*>& bks);
	int size();
	bool removeBook(std::string title);
	double getSubTotal();
};

