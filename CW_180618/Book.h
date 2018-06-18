#pragma once

#include"Library.h";
class Book
{
	string author;
	string title;
	public:
		Book()
		{
			author = "";
			title = "";
		}
		Book(string author, string title)
		{
			this->author = author;
			this->title = title;
		}
		friend ostream &operator <<(ostream& os, Book obj);
};
ostream&operator <<(ostream& os, Book obj)
{
	os << /*obj.author << "\t" <<*/ obj.title<<endl;
	return os;
}