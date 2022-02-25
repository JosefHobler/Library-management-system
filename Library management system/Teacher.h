#pragma once
#include "School.h"


struct Teacher : public School
{
	bool Add(const string& name, const string& author);
	
	bool Delete(const int& index, string file_name);
	
	bool WriteText(const string& index, const bool& mode) const;
	
	bool ModifyName(const int& index, const string& name);
};