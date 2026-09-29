#include "Cart.h"

bool Cart::AddBook(Book* b1)
{
	if (b1 != nullptr)
	{
		books.push_back(b1);
		return true;
	}
	return false;
}

int Cart::AddAllBooks(std::list<Book*>& bks)
{
	int count = 0;
	std::list<Book*>::iterator it = bks.begin();
	while (it != bks.end())
	{
		if (AddBook(*it))
		{
			count++;
		}
		it++;
	}
	return count;
}

int Cart::size()
{
	return books.size();
}

bool Cart::removeBook(std::string title)
{
	int count = 0;
	std::list<Book*>::iterator it = books.begin();
	while (it != books.end())
	{
		if ((*it)->title == title)
		{
			it = books.erase(it);
			return true;
		}
		it++;
	}
	return false;
}

double Cart::getSubTotal()
{
	double total = 0.0;
	std::list<Book*>::iterator it = books.begin();
	while (it != books.end())
	{
		total += (*it)->price;
		it++;
	}
	return total;
}