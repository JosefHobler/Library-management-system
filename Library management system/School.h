#pragma once
#include "Custom functions.h"


class School
{
private:
	bool found;
	vector<string> name_of_book;
	vector<string> author_of_book;
	vector<string> available;
	vector<int> book_id;
public:
	School();
	
	int FindByAuthor(const string& author);
	int FindByName(const string& name);
	int FindByID(const int& ID);
	
	void List() const;
	bool Save() const ;
	
	bool ReadText(const string& file_name) const;
	
	void ModifyBookIDVector(const int& value);
	
	void ModifyAuthorVector(const string& value);
	bool ModifyAuthorVector(const int& index, const string& value);
	
	void ModifyNameVector(const string& value);
	void ModifyNameVector(const int& index, const string& value);
	
	void ModifyAvailableVector(const string& value);
	void ModifyAvailableVector(const int& index, const string& value);
	
	void EraseLastElement();
	void GetToLastElement(int index);
	
	string GetNameVector(const int& index) const;
	int GetNumberOfBooks() const;
	bool GetAvailable(const int& index) const;
	bool GetFound() const;
};