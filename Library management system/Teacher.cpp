#include "Teacher.h"


void Teacher::Add()
{
	cout << "Name of the book: "; cin >> Add_name; cout << "\n";
	cout << "Author of the book : "; cin >> Add_author; cout << "\n";
	ModifyNameVector(Add_name);
	ModifyAuthorVector(Add_author);
	ModifyBookIDVector(GetNumberOfBooks());
	cout << "Write text (write ~ to save): ";
	while (true) 
	{
		cin >> Add_text;
		if (Add_text == '~')
		{
			break;
		}
		Add_text_vec.push_back(Add_text);
	}
	ofstream Adding(Add_name + ".txt");
	{
		for (int i = 0; i < Add_text_vec.size(); i++)
		{
			Adding << Add_text_vec[i];
		}
		Adding.close();
		Add_text_vec.clear();
	}
	Save();
	cout << "Book added\n";
}

void Teacher::Update()
{

}

void Teacher::Delete()
{

}
