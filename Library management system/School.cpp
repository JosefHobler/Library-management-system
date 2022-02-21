#include "School.h"


School::School()
{
	string line;
	ifstream Books("Books.txt");
	if (Books.is_open())
	{
		while (!Books.eof())
		{
			getline(Books, line);
			book_id.push_back(line[0] - '0');
			getline(Books, line);
			name_of_book.push_back(line);
			getline(Books, line);
			author_of_book.push_back(line);
		}
		Books.close();
	}
}

void School::List()
{
	cout << "List\n\n";
	for (int i = 0; i < name_of_book.size(); i++)
	{
		cout << " " << book_id[i] << " | " << name_of_book[i] << " | " << author_of_book[i] << "\n";
	}
}

void School::Save()
{
	fstream NewBooks;
	NewBooks.open("Books.txt", ios::app);
	if (NewBooks.is_open())
	{
		NewBooks << "\n" << book_id[book_id.size() - 1] << "\n" << name_of_book[name_of_book.size() - 1] << "\n" << author_of_book[author_of_book.size() - 1];
		NewBooks.close();
	}
}

void School::ModifyAuthorVector(string value)
{
	author_of_book.push_back(value);
}

void School::ModifyNameVector(string value)
{
	name_of_book.push_back(value);
}

void School::ModifyBookIDVector(int value)
{
	book_id.push_back(value);
}

int School::GetNumberOfBooks() const
{
	return name_of_book.size();
}