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
	vector<string> name_of_book;
	vector<string> author_of_book;
	vector<int> book_id;
public:
	School();
	void List();
	void Save();
	void ModifyNameVector(string value);
	void ModifyAuthorVector(string value);
	void ModifyBookIDVector(int value);

	int GetNumberOfBooks() const;
};