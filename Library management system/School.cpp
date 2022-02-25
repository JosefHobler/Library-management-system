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
			getline(Books, line);
			available.push_back(line);
			
		}
		Books.close();
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

void School::List() const
{
	cout << "List\n\n";
	for (int i = 0; i < name_of_book.size(); i++)
	{
		cout << CenteredText(to_string(book_id[i]), 3) << "|" << CenteredText(name_of_book[i], 20) <<
			"|" << CenteredText(author_of_book[i], 20) << "|" << CenteredText(available[i], 15) << "|" << "\n";
	}
}

bool School::Save() const
{
	ofstream NewBooks("Books.txt");
	if (NewBooks.is_open())
	{
		for (int i = 0; i < name_of_book.size(); i++)
		{
			NewBooks << book_id[i] << "\n" << name_of_book[i] << "\n" << author_of_book[i] << "\n" << available[i];
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

bool School::ReadText(const string& file_name) const
{
	string line;
	ifstream read(file_name + ".txt");
	if (read.is_open())
	{
		while (!read.eof())
		{
			getline(read, line);
			cout << line << "\n";
		}
		read.close();
		return true;
	}
	return false;
}

void School::ModifyBookIDVector(const int& value)
{
	book_id.push_back(value);
}

void School::ModifyAuthorVector(const string& value)
{
	author_of_book.push_back(value);
}

bool School::ModifyAuthorVector(const int& index, const string& value)
{
	author_of_book[index] = value;
	if (Save())
	{
		return true;
	}
	return false;
}

void School::ModifyNameVector(const string& value)
{
	name_of_book.push_back(value);
}

void School::ModifyNameVector(const int& index, const string& value)
{
	name_of_book[index] = value;
}

void School::ModifyAvailableVector(const string& value)
{
	available.push_back(value);
}

void School::ModifyAvailableVector(const int& index, const string& value)
{
	available[index] = value;
}

void School::EraseLastElement()
{
	name_of_book.erase(name_of_book.end() - 1);
	author_of_book.erase(author_of_book.end() - 1);
	book_id.erase(book_id.end() - 1);
	available.erase(available.end() - 1);
}

void School::GetToLastElement(int index)
{
	swap(name_of_book[index], name_of_book[name_of_book.size() - 1]);
	swap(author_of_book[index], author_of_book[author_of_book.size() - 1]);
	swap(book_id[index], book_id[book_id.size() - 1]);
	swap(available[index], available[available.size() - 1]);
}

string School::GetNameVector(const int& index) const
{
	return name_of_book[index];
}

int School::GetNumberOfBooks() const
{
	return name_of_book.size();
}

bool School::GetAvailable(const int& index) const
{
	return available[index] == "Available";
}

bool School::GetFound() const
{
	return found;
}