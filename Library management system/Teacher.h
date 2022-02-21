#pragma once
#include "School.h"


class Teacher : public School
{
private:
	vector<char> Add_text_vec;
	char Add_text;
	string name;
	string Add_author;
	int Add_id;
public:
	void Add();
	void Update();
	void Delete();
};