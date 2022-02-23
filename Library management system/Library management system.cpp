#include "Student.h"
#include "Teacher.h"
#include "Custom functions.h"

bool Login(const string& file, string& username)
{
	string password;
	string right_password = "";
	string right_username = "";
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password; cout << "\n";
	ifstream logging(file + ".txt");
	if (logging.is_open())
	{
		logging.ignore(256, ' ');
		logging >> right_username;
		logging.ignore(256, ' ');
		logging >> right_password;
		logging.close();
	}
	return right_password == password && right_username == username;
}

int Search(int choice, School* teacher)
{
	string name;
	string author;
	int id;
	cout << "Search book by:\n";
	cout << "1) Name\n";
	cout << "2) Author\n";
	cout << "3) ID\n";
	cout << "Your choice: "; cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
		cout << "Name: "; getline(cin >> ws, name);
		cout << name;
		return teacher->FindByName(name);
	case 2:
		cout << "Author: "; getline(cin >> ws, author);
		return teacher->FindByAuthor(author);
	case 3:
		cout << "ID: "; cin >> id;
		return teacher->FindByID(id);
	}
}

int main()
{
	string username;
	bool log;
	string name;
	string author;
	int id;
	unique_ptr<Student> student;
	unique_ptr<Teacher> teacher = make_unique<Teacher>();
	string file;
	int choice;
	int index;
	system("cls");
	cout << "Welcome to Library Management System\n\n";
	cout << "1) Login as Teacher\n";
	cout << "2) Login as Student\n";
	cout << "3) Exit\n";
	cout << "Your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		file = "TeacherLogin";
		if (!Login(file, username))
		{
			cout << "Logging failed\n";
			Sleep(1000);
			return 0;
		}
		cout << "Login successfull\n";
		Sleep(1000);
		while (true)
		{
			system("cls");
			cout << "1) Add new book\n";
			cout << "2) Update any book\n";
			cout << "3) Delete a book\n";
			cout << "4) List of books\n";
			cout << "5) Show book\n";
			cout << "6) Exit\n";
			cout << "Your choice: ";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				cout << "Name of the book: "; getline(cin >> ws, name);
				cout << "Author of the book : "; getline(cin >> ws, author);
				cout << "Write text: ";
				if (teacher->Add(name, author))
				{
					cout << "\nBook added\n";
				}
				else
				{
					cout << "\nError\n";
				}
				Sleep(500);
				break;
			case 2:
				index = Search(choice, teacher.get());
				if (teacher->GetFound())
				{
					system("cls");
					cout << "What do you want to modify:\n";
					cout << "1) Name\n";
					cout << "2) Author\n";
					cout << "3) Text\n";
					cout << "Your choice: "; cin >> choice;
					system("cls");
					switch (choice)
					{
					case 1:
						cout << "Enter new name of the book: "; getline(cin >> ws, name);
						if (teacher->ModifyName(index, name))
						{
							cout << "Name successfully changed\n";
						}
						else
						{
							cout << "Error\n";
						}
						break;
					case 2:
						cout << "Enter new author of the book: "; getline(cin >> ws, author);
						if (teacher->ModifyAuthor(index, author))
						{
							cout << "Author successfully changed\n";
						}
						else
						{
							cout << "Error\n";
						}
						break;
					case 3:
						cout << "How do you want to modify text:\n";
						cout << "1) Completely rewrite\n";
						cout << "2) Append\n";
						cout << "Your choice: "; cin >> choice;
						system("cls");
						switch (choice)
						{
						case 1:
							cout << "Write text: ";
							if (teacher->ReWriteText(index))
							{
								cout << "\nText successfully rewritten\n";
							}
							else
							{
								cout << "\nError\n";
							}
							break;
						case 2:
							cout << "Write appended text: ";
							if (teacher->AppendText(index))
							{
								cout << "\nText successfully appended\n";
							}
							else
							{
								cout << "\nError\n";
							}
							break;
						}
						break;
					}
				}
				else
				{
					cout << "Book not found\n";
				}
				Sleep(1000);
				break;
			case 3:
				index = Search(choice, teacher.get());
				if (teacher->GetFound())
				{
					if (teacher->Delete(index, teacher->GetNameVector(index)))
					{
						cout << "Successfully deleted\n";
					}
					else
					{
						cout << "Error\n";
					}
				}
				else
				{
					cout << "Error";
				}
				Sleep(1000);
				break;
			case 4:
				teacher->List();
				break;
			case 5:
				index = Search(choice, teacher.get());
				if (teacher->GetFound())
				{
					if (teacher->ReadText(teacher->GetNameVector(index)))
					{
						cout << "\nSuccessfully loaded\n";
					}
					else
					{
						cout << "Error\n";
					}
				}
				else
				{
					cout << "Error";
				}
				Sleep(1000);
				break;
			case 6:
				return 0;
			}
			cout << "\n\n\nPress [escape] to go to the menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}

	case 2:
		system("cls");
		file = "StudentLogin";
		if (!Login(file, username))
		{
			cout << "Logging failed\n";
			Sleep(1000);
			return 0;
		}
		student = make_unique<Student>(username);
		cout << "Login successfull\n";
		Sleep(1000);
		while (true)
		{

			system("cls");
			cout << "1) Borrow book\n";
			cout << "2) Return book\n";
			cout << "3) List of books\n";
			cout << "4) Show book\n";
			cout << "5) Exit\n";
			cout << "Your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				index = Search(choice, student.get());
				if (student->GetFound())
				{
					if (student->GetAvailable(index))
					{
						student->Borrow(index, username);
					}
					else
					{
						cout << "Error\n";
					}
				}
				else
				{
					cout << "Error";
				}
				Sleep(1000);
				break;
			case 2:
				student->Return(index, username);
				break;
			case 3:
				student->List();
				break;
			case 4:
				index = Search(choice, student.get());
				if (student->GetFound())
				{
					if (student->ReadText(student->GetNameVector(index)))
					{
						cout << "\nSuccessfully loaded\n";
					}
					else
					{
						cout << "Error\n";
					}
				}
				else
				{
					cout << "Error";
				}
				Sleep(1000);
				break;
			case 5:
				return 0;
			}
			cout << "\n\n\nPress [escape] to go to the menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}

	case 3:
		return 0;
	}
}
