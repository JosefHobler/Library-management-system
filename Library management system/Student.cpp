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
	borrowed.push_back(GetNameVector(index));
	ModifyAvailableVector(index, "Unavailable");
	if (SaveBorrowed(username))
	{
		return true;
	}
	return false;
}

bool Student::Return(const int& index, string username)
{
	ModifyAvailableVector(FindByName(borrowed[index]), "Available");
	swap(borrowed[index], borrowed[borrowed.size() - 1]);
	borrowed.erase(borrowed.end() - 1);
	cout << borrowed.size();
	Sleep(1000);
	if (borrowed.size() != 0)
	{
		if (SaveBorrowed(username))
		{
			return true;
		}
	}
	else
	{
		username += ".txt";
		remove(&username[0]);
		if (Save())
		{
			return true;
		}
	}
	return false;
}

bool Student::SaveBorrowed(const string& username) const
{
	ofstream borrow(username + ".txt");
	if (borrow.is_open())
	{
		for (int i = 0; i < borrowed.size(); i++)
		{
			borrow << borrowed[i];
			if (i != (borrowed.size() - 1))
			{
				borrow << "\n";
			}
		}
		borrow.close();
		if (Save())
		{
			return true;
		}
	}
	return false;
}

void Student::BorrowList() const
{
	for (int i = 0; i < borrowed.size(); i++)
	{
		cout << i + 1 << ") " << borrowed[i] << "\n";
	}
}

int Student::GetBorrowedSize() const
{
	return borrowed.size();
}