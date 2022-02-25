#include "Student.h"
#include "Teacher.h"
#include "Custom functions.h"


// Search Through Books
int Search(int choice, School* teacher)
{
	string name;
	string author;
	int id;
	choice = 0;
	while (choice > 3 || choice <= 0)
	{
		cout << "Search Book By:\n";
		cout << "1) Name\n";
		cout << "2) Author\n";
		cout << "3) ID\n";
		cout << "Your Choice: "; cin >> choice;
		system("cls");
	}
	switch (choice)
	{
	case 1:
		// Searching By Name
		cout << "Name: "; getline(cin >> ws, name);
		cout << name;
		return teacher->FindByName(name);
	case 2:
		// Searching By Author
		cout << "Author: "; getline(cin >> ws, author);
		return teacher->FindByAuthor(author);
	case 3:
		// Searching By ID
		cout << "ID: "; cin >> id;
		return teacher->FindByID(id);
	}
}

int main()
{
	// Variables
	string password;
	string right_password = "";
	string right_username = "";
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
	ifstream logging;

	// Logging Menu
	do
	{
		cout << "Welcome To Library Management System\n\n";
		cout << "1) Login As Teacher\n";
		cout << "2) Login As Student\n";
		cout << "3) Exit\n";
		cout << "Your Choice: ";
		cin >> choice;
		system("cls");
	} while (choice > 3 || choice <= 0);
	switch (choice)
	{
	// Choice Teacher
	case 1:
		// Logging As Teacher
		cout << "Enter Username: "; cin >> username;
		cout << "Enter Password: "; cin >> password; cout << "\n";
		logging.open("TeacherLogin.txt");
		if (logging.is_open())
		{
			getline(logging, right_username);
			getline(logging, right_password);
			logging.close();
		}
		else
		{
			cout << "\nError\n";
			Sleep(1000);
			return 0;
		}
		if (username != right_username || password != right_password)
		{
			cout << "\nLogin Failed\n";
			Sleep(1000);
			return 0;
		}
		cout << "\nLogin Successfull\n";
		Sleep(1000);
		while (true)
		{
			// Menu
			choice = 0;
			while (choice > 6 || choice <= 0)
			{
				system("cls");
				cout << "1) Add New Book\n";
				cout << "2) Update Any Book\n";
				cout << "3) Delete A Book\n";
				cout << "4) List Of Books\n";
				cout << "5) Show Book\n";
				cout << "6) Exit\n";
				cout << "Your Choice: ";
				cin >> choice;
			}
			system("cls");
			switch (choice)
			{
			// Choice To Add
			case 1:
				cout << "Name Of The Book: "; getline(cin >> ws, name);
				cout << "Author Of The Book : "; getline(cin >> ws, author);
				cout << "Write Text: ";
				if (teacher->Add(name, author))
				{
					cout << "\nBook Added\n";
				}
				else
				{
					cout << "\nError\n";
				}
				break;
			// Choice To Modify
			case 2:
				index = Search(choice, teacher.get());
				if (teacher->GetFound())
				{
					choice = 0;
					while (choice > 3 || choice <= 0)
					{
						cout << "What Do You Want To Modify:\n";
						cout << "1) Name\n";
						cout << "2) Author\n";
						cout << "3) Text\n";
						cout << "Your Choice: "; cin >> choice;
						system("cls");
					}
					switch (choice)
					{
					case 1:
						// Modify Name
						cout << "Enter New Name Of The Book: "; getline(cin >> ws, name);
						if (teacher->ModifyName(index, name))
						{
							cout << "\nName Successfully Changed\n";
						}
						else
						{
							cout << "\nError\n";
						}
						break;
					case 2:
						// Modify Author
						cout << "Enter New Author Of The Book: "; getline(cin >> ws, author);
						if (teacher->ModifyAuthorVector(index, author))
						{
							cout << "\nAuthor Successfully Changed\n";
						}
						else
						{
							cout << "\nError\n";
						}
						break;
					case 3:
						// Modify Text
						choice = 0;
						while (choice > 2 || choice <= 0)
						{
							cout << "How Do You Want To Modify Text:\n";
							cout << "1) Completely Rewrite\n";
							cout << "2) Append\n";
							cout << "Your Choice: "; cin >> choice;
							system("cls");
						}
						switch (choice)
						{
						case 1:
							// Rewriting Text
							cout << "Write Text: ";
							if (teacher->WriteText(teacher->GetNameVector(index), true))
							{
								cout << "\nText Successfully Rewritten\n";
							}
							else
							{
								cout << "\nError\n";
							}
							break;
						case 2:
							// Appending Text
							cout << "Write Appended Text: ";
							if (teacher->WriteText(teacher->GetNameVector(index), false))
							{
								cout << "\nText Successfully Appended\n";
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
					cout << "\nBook Not Found\n";
				}
				break;
			case 3:
				// Delete Book
				index = Search(choice, teacher.get());
				if (teacher->GetFound())
				{
					if (teacher->Delete(index, teacher->GetNameVector(index)))
					{
						cout << "\nSuccessfully Deleted\n";
					}
					else
					{
						cout << "\nError\n";
					}
				}
				else
				{
					cout << "\nBook Not Found\n";
				}
				break;
			case 4:
				// List To Show Books
				teacher->List();
				break;
			case 5:
				// Read Text Of Particular Book
				index = Search(choice, teacher.get());
				if (teacher->GetFound())
				{
					if (teacher->ReadText(teacher->GetNameVector(index)))
					{
						cout << "\nSuccessfully Loaded\n";
					}
					else
					{
						cout << "\nError\n";
					}
				}
				else
				{
					cout << "\nBook Not Found\n";
				}
				break;
			case 6:
				// Exit
				return 0;
			}
			Sleep(1000);
			cout << "\n\n\nPress [Escape] For Menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}
	// Choice Student
	case 2:
		// Logging As Student
		cout << "Enter Username: "; cin >> username;
		cout << "Enter Password: "; cin >> password; cout << "\n";
		logging.open("StudentLogin.txt");
		if (logging.is_open())
		{
			while (!logging.eof())
			{
				getline(logging, right_username);
				getline(logging, right_password);
				if (username == right_username && password == right_password)
				{
					cout << "\nLogin Successfull\n";
					Sleep(1000);
					break;
				}
			}
			if (username != right_username || password != right_password)
			{
				cout << "\nLogin Failed\n";
				Sleep(1000);
				return 0;
			}
			logging.close();
		}
		else
		{
			cout << "\nError\n";
			Sleep(1000);
			return 0;
		}
		Sleep(1000);
		student = make_unique<Student>(username);
		while (true)
		{
			choice = 0;
			// Menu
			while (choice > 5 || choice <= 0)
			{
				system("cls");
				cout << "1) Borrow Book\n";
				cout << "2) Return Book\n";
				cout << "3) List Of Books\n";
				cout << "4) Show Book\n";
				cout << "5) Exit\n";
				cout << "Your Choice: ";
				cin >> choice;
			}
			system("cls");
			switch (choice)
			{
			case 1:
				// Borrowing A Book
				index = Search(choice, student.get());
				if (student->GetFound())
				{
					if (student->GetAvailable(index))
					{
						if (student->Borrow(index, username))
						{
							cout << "\nSucessfully Borrowed\n";
						}
						else
						{
							cout << "\nError\n";
						}
					}
					else
					{
						cout << "\nBook Already Borrowed\n";
					}
				}
				else
				{
					cout << "\nBook Not Found\n";
				}
				break;
			case 2:
				// Returning A Book
				if (student->GetBorrowedSize() != 0)
				{
					choice = 0;
					while (choice > student->GetBorrowedSize() || choice <= 0)
					{
						system("cls");
						student->BorrowList();
						cout << "Your Choice: ";
						cin >> choice;
					}
					if (student->Return(choice - 1, username))
					{
						cout << "\nSucessfully Returned\n";
					}
					else
					{
						cout << "\nError\n";
					}
				}
				else
				{
					cout << "No Borrowed Books\n";
				}
				break;
			case 3:
				// List To Show Books
				student->List();
				break;
			case 4:
				// Read Text Of Particular Book
				index = Search(choice, student.get());
				if (student->GetFound())
				{
					if (student->ReadText(student->GetNameVector(index)))
					{
						cout << "\nSuccessfully Loaded\n";
					}
					else
					{
						cout << "\nError\n";
					}
				}
				else
				{
					cout << "\nBook Not Found\n";
				}
				break;
				// Exit
			case 5:
				return 0;
			}
			Sleep(1000);
			cout << "\n\n\nPress [Escape] For Menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}
	case 3:
		return 0;
	}
	// End
	system("pause");
}
