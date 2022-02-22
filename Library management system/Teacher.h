#pragma once
#include "School.h"


class Teacher : public School
{
private:
	vector<char> Add_text_vec;
	char Add_text;
	string name;
	string author;
public:
	bool ModifyText(int index);
	bool ModifyName(int index, string name);
	bool ModifyAuthor(int index, string author);
	bool Add(string name, string author);
	void Update();
	void Delete();
};