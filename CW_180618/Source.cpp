#include"Library.h"
#include<fstream>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
#include"Book.h"
void print(pair<string, Book> e)
{ 
	cout <<e.first<<" "<< e.second;
}

int main()
{
	multimap<string, Book> bs;
	set<string>as;  //ne dopuskaet povtorenii
	ifstream inf("Books.txt");
	string title, author;
	while (!inf.eof())
	{
		inf >> author >> title;
		bs.insert(pair<string, Book>(author, Book(author, title))); //dobavlenie knigi
	}

	//bs.erase("DenBraun"); //delete udalenie
	/*
	multimap<string, Book>::reverse_iterator it;  //raspechatat'
	for (it = bs.rbegin();it != bs.rend();it++)
		cout << it->first << " " << it->second << endl;*/

	//for_each(bs.begin(),bs.end(),print); //raspechatat' 

	for (auto it = bs.begin(); it != bs.end();it++) //sobiraem v set
	{
		as.insert(it->first);
	}
	for (auto it = as.begin(); it != as.end();it++)
	{
		auto itr = bs.equal_range(*it);
		cout << *it << endl;
		for_each(itr.first, itr.second, print);
		cout << endl;cout << endl;
	}

	system("pause");
	return 0;
 }