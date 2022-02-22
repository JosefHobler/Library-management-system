#include "Teacher.h"


bool Teacher::Add(string name, string author)
{
	this->name = name;
	this->author = author;
	while (true) 
	{
		cin >> Add_text;
		if (Add_text == '~')
		{
			break;
		}
		Add_text_vec.push_back(Add_text);
	}
	ModifyNameVector(name);
	ModifyAuthorVector(author);
	ModifyBookIDVector(GetNumberOfBooks());
	ofstream Adding(name + ".txt");
	{
		if (Adding.is_open())
		{
			for (int i = 0; i < Add_text_vec.size(); i++)
			{
				Adding << Add_text_vec[i];
			}
			Adding.close();
			Add_text_vec.clear();
		}
		else
		{
			return false;
		}
	}
	Save();
	return true;
}

bool Teacher::ModifyName(int index, string value)
{
	ModifyNameVector(index, value);
	if (!Save())
	{
		return false;
	}
	return true;
}

bool Teacher::ModifyAuthor(int index, string value)
{
	ModifyAuthorVector(index, value);
	if (!Save())
	{
		return false;
	}
	return true;
}

bool Teacher::ModifyText(int index)
{
	return true;
}

void Teacher::Update()
{

}

void Teacher::Delete()
{

}
