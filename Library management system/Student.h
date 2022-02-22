#pragma once
#include "School.h"


class Student : public School
{
private:
public:
	void Borrow();
	void Return();
	~Student();
};
