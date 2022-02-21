
#include "Student.h"
#include "Teacher.h"

bool Login(string file)
{
	string right_username = "";
	string right_password = "";
	string username;
	string password;
	cout << "Enter username: "; cin >> username; cout << "\n";
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
	Student* student = new Student;
	Teacher* teacher = new Teacher;
	string file;
	int choice;
	while (true)
	{
		system("cls");
		cout << "\nWelcome to Library Management System\n\n";
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
			if (!Login(file))
			{
				cout << "Logging failed\n";
				Sleep(1000);
				return 0;
			}
			cout << "Login successfull\n";
			Sleep(1000);
			system("cls");
			cout << "1) Add new book\n";
			cout << "2) Update any book\n";
			cout << "3) Delete a book\n";
			cout << "4) List of books\n";
			cout << "5) Exit\n";
			cout << "Your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				teacher->Add();
				break;
			case 2:
				teacher->Update();
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
			cout << "\nPress [escape] to go to the menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
			break;

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
			cout << "\nPress [escape] to go to the menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
			break;

		case 3:
			return 0;
		}
	}
}
