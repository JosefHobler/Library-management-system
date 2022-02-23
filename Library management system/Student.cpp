#include "Student.h"

Student::Student(const string& username)
{
	string word;
	ifstream borrow(username + ".txt");
	if (borrow.is_open())
	{
		while (!borrow.eof())
		{
			getline(borrow, word);
			borrowed.push_back(word);
		}
		borrow.close();
	}
}


bool Student::Borrow(const int& index, const string& username)
{
	borrowed.push_back(username);
	ModifyAvailableVector(index, "Unavailable");
	if (SaveBorrowed(username))
	{
		return true;
	}
	return false;
}

bool Student::SaveBorrowed(const string& username)
{
	ofstream borrow(username + ".txt");
	if (borrow.is_open())
	{
		for (int i = 0; i < borrowed.size(); i++)
		{
			borrow << borrowed[i];
		}
		borrow.close();
		if (Save())
		{
			return true;
		}
	}
	return false;
}

bool Student::Return(const int& index, const string& username)
{
	swap(borrowed[index], borrowed[borrowed.size() - 1]);
	borrowed.erase(borrowed.end() - 1);
	ModifyAvailableVector(index, "Available");
	if (SaveBorrowed(username))
	{
		return true;
	}
	return false;
}