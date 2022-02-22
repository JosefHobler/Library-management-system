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

void School::List() const
{
	cout << "List\n\n";
	for (int i = 0; i < name_of_book.size(); i++)
	{
		cout << CenteredText(to_string(book_id[i]), 3) << "|" << CenteredText(name_of_book[i], 30) << "|" << CenteredText(author_of_book[i], 30) << "|" << "\n";
	}
}

int School::FindByAuthor(const string& author)
{
	found = find(author_of_book.begin(), author_of_book.end(), author) != author_of_book.end() ? true : false;
	return find(author_of_book.begin(), author_of_book.end(), author) - author_of_book.begin();
}

int School::FindByName(const string& name)
{
	found = find(name_of_book.begin(), name_of_book.end(), name) != name_of_book.end() ? true : false;
	return find(name_of_book.begin(), name_of_book.end(), name) - name_of_book.begin();
}

int School::FindByID(const int& id)
{
	found = find(book_id.begin(), book_id.end(), id) != book_id.end() ? true : false;
	return find(book_id.begin(), book_id.end(), id) - book_id.begin();
}

bool School::GetFound() const
{
	return found;
}

bool School::Save() const
{
	ofstream NewBooks("Books.txt");
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

string School::GetNameVector(const int& index) const
{
	return name_of_book[index];
}


void School::ModifyAuthorVector(const string& value)
{
	author_of_book.push_back(value);
}

void School::ModifyAuthorVector(const int& index, const string& value)
{
	author_of_book[index] = value;
}

void School::ModifyNameVector(const string& value)
{
	name_of_book.push_back(value);
}

void School::ModifyNameVector(const int& index,const string& value)
{
	name_of_book[index] = value;
}

void School::ModifyBookIDVector(const int& value)
{
	book_id.push_back(value);
}

int School::GetNumberOfBooks() const
{
	return name_of_book.size();
}

