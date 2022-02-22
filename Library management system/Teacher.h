#pragma once
#include "School.h"


class Teacher : public School
{
private:
public:
	bool WriteText(const string& name, const bool& mode) const;
	bool ReWriteText(const int& index) const;
	bool AppendText(const int& index) const;
	bool ModifyName(const int& index, const string& name);
	bool ModifyAuthor(const int& index, const string& author);
	bool Add(const string& name, const string& author);
	void Update();
	void Delete();
};