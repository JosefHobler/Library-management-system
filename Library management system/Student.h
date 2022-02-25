#pragma once
#include "School.h"


class Student : public School
{
private:
	vector<string> borrowed;
public:
	Student(const string& username);
	
	bool Borrow(const int& index, const string& username);
	
	bool Return(const int& index, string username);
	
	bool SaveBorrowed(const string& username) const;
	
	void BorrowList() const;
	
	int GetBorrowedSize() const;
};