
#include "Student.h"
#include "Teacher.h"

bool Login(string file)
{
	string right_username = "";
	string right_password = "";
	string username;
	string password;
	cout << "Enter username: "; getline(cin, username);
	cin.ignore(256, '\n');
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
	return (right_password == password && right_username == username) ? true : false;
}

int main()
{
	string name;
	string author;
	int id;
	Student* student = new Student;
	Teacher* teacher = new Teacher;
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
	cin.ignore(256,!'\n');
	switch (choice)
	{
	case 1:
		system("cls");
		file = "TeacherLogin";
		if (!Login(file))
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
			cout << "5) Exit\n";
			cout << "Your choice: ";
			cin >> choice;
			cin.ignore(256, '\n');
			system("cls");
			switch (choice)
			{
			case 1:
				cout << "Name of the book: "; getline(cin, name);
				cin.ignore(256, '\n');
				cout << "Author of the book : "; getline(cin, author);
				cout << "Write text (write ~ to save): ";
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
				cout << "Seach book by:\n";
				cout << "1) Name\n";
				cout << "2) Author\n";
				cout << "3) ID\n";
				cout << "Your choice: "; cin >> choice;
				system("cls");
				switch (choice)
				{
				case 1:
					cout << "Name: "; getline(cin, name);
					index = teacher->FindByName(name);
					break;
				case 2:
					cout << "Author: "; getline(cin, author);
					index = teacher->FindByAuthor(author);
					break;
				case 3:
					cout << "ID: "; cin >> id;
					index = teacher->FindByID(id);
					break;
				}
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
						cout << "Enter new name of the book: "; getline(cin, name);
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
						cout << "Enter new author of the book: "; getline(cin, author);
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
						if (teacher->ModifyText(index))
						{
							cout << "Text successfully changed\n";
						}
						else
						{
							cout << "Error\n";
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
				teacher->Delete();
				break;
			case 4:
				teacher->List();
				break;
			case 5:
				return 0;
			}
			cout << "\n\n\nPress [escape] to go to the menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}

	case 2:
		system("cls");
		file = "StudentLogin";
		if (!Login(file))
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
			cout << "1) Borrow book\n";
			cout << "2) Return book\n";
			cout << "3) List of books\n";
			cout << "4) Exit\n";
			cout << "Your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				student->Borrow();
				break;
			case 2:
				student->Return();
				break;
			case 3:
				student->List();
				break;
			case 4:
				return 0;
			}
			cout << "\n\n\nPress [escape] to go to the menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}

	case 3:
		return 0;
	}
}
