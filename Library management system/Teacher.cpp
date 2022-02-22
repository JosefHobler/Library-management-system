#include "Teacher.h"


bool Teacher::Add(const string& name, const string& author)
{
	ModifyNameVector(name);
	ModifyAuthorVector(author);
	ModifyBookIDVector(GetNumberOfBooks());
	if (WriteText(name, true))
	{
		return true;
	}
	return false;
}

bool Teacher::ReWriteText(const int& index) const
{
	if (WriteText(GetNameVector(index), true))
	{
		return true;
	}
	return false;
}

bool Teacher::AppendText(const int& index) const
{
	if (WriteText(GetNameVector(index), false))
	{
		return true;
	}
	return false;
}

bool Teacher::WriteText(const string& name, const bool& mode) const
{
	string text;
	getline(cin >> ws, text);
	fstream Adding;
	Adding.open(name + ".txt", mode ? ios::out : ios::app);
	{
		if (Adding.is_open())
		{
			Adding << text;
			Adding.close();
		}
		else
		{
			return false;
		}
	}
	if (Save())
	{
		return true;
	}
	return false;
}

bool Teacher::ModifyName(const int& index, const string& value)
{
	string old_name = (GetNameVector(index)) + ".txt";
	string new_name = value + ".txt";
	rename(&old_name[0], &new_name[0]);
	remove(&old_name[0]);
	ModifyNameVector(index, value);
	if (!Save())
	{
		return false;
	}
	return true;
}

bool Teacher::ModifyAuthor(const int& index, const string& value)
{
	ModifyAuthorVector(index, value);
	if (!Save())
	{
		return false;
	}
	return true;
}

void Teacher::Update()
{

}

void Teacher::Delete()
{

}
