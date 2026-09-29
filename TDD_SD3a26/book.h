#include<iostream>
#pragma once
struct Book
{
	std::string title;
	double price;
	Book(std::string s, double p)
	{
		title = s;
		price = p;
	}
	Book()
	{
		price = 0;
		title = "";
	}
};