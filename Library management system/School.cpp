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

int School::FindByAuthor(string author)
{
	found = find(author_of_book.begin(), author_of_book.end(), author) != author_of_book.end() ? true : false;
	return author_of_book.begin() - find(author_of_book.begin(), author_of_book.end(), author);
}

int School::FindByName(string name)
{
	found = find(name_of_book.begin(), name_of_book.end(), name) != name_of_book.end() ? true : false;
	return name_of_book.begin() - find(name_of_book.begin(), name_of_book.end(), name);
}

int School::FindByID(int id)
{
	found = find(book_id.begin(), book_id.end(), id) != book_id.end() ? true : false;
	return book_id.begin() - find(book_id.begin(), book_id.end(), id);
}

bool School::GetFound() const
{
	return found;
}

bool School::Save()
{
	ofstream NewBooks("Books.txt");
	cout << name_of_book.size();
	Sleep(500);
	if (NewBooks.is_open())
	{
		for (int i = 0; i < name_of_book.size(); i++)
		{
			NewBooks << book_id[i] << "\n" << name_of_book[i] << "\n" << author_of_book[i];
			if (i != (name_of_book.size() - 1))
			{
				NewBooks << "\n";
			}
		}
		NewBooks.close();
	}
	else
	{
		return false;
	}
	return true;
}

void School::ModifyAuthorVector(string value)
{
	author_of_book.push_back(value);
}

void School::ModifyAuthorVector(int index, string value)
{
	author_of_book[index] = value;
}

void School::ModifyNameVector(string value)
{
	name_of_book.push_back(value);
}

void School::ModifyNameVector(int index, string value)
{
	name_of_book[index] = value;
}

void School::ModifyBookIDVector(int value)
{
	book_id.push_back(value);
}

int School::GetNumberOfBooks() const
{
	return name_of_book.size();
}

