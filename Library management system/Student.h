#pragma once
#include "School.h"


class Student : public School
{
private:
	vector<string> borrowed;
public:
	bool SaveBorrowed(const string& username);
	Student(const string& username);
	bool Borrow(const int& index, const string& username);
	bool Return(const int& index, const string& username);
};
