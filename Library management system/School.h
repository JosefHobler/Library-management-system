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
	bool GetFound() const;
	int FindByAuthor(const string& author);
	int FindByName(const string& name);
	int FindByID(const int& ID);
	void List() const;
	bool Save() const ;
	string GetNameVector(const int& index) const;
	void ModifyNameVector(const string& value);
	void ModifyAuthorVector(const string& value);
	void ModifyBookIDVector(const int& value);
	void ModifyNameVector(const int& index, const string& value);
	void ModifyAvailableVector(const string& value);
	void ModifyAvailableVector(const int& index, const string& value);
	void ModifyAuthorVector(const int& index, const string& value);
	int GetNumberOfBooks() const;
	void EraseLastElement();
	void GetToLastElement(int index);
	bool ReadText(const string& file_name) const;
	bool GetAvailable(const int& index) const;
};