#pragma once
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;


class School
{
private:
	bool found;
	vector<string> name_of_book;
	vector<string> author_of_book;
	vector<int> book_id;
public:
	School();
	bool GetFound() const;
	int FindByAuthor(string author);
	int FindByName(string name);
	int FindByID(int ID);
	void List();
	bool Save();
	void ModifyNameVector(string value);
	void ModifyAuthorVector(string value);
	void ModifyBookIDVector(int value);
	void ModifyNameVector(int index, string value);
	void ModifyAuthorVector(int index, string value);
	int GetNumberOfBooks() const;
};