#include "CommandLine.h"
#pragma warning (disable : 4996)

void CommandLine::enterCommand()
{
	cin >> command;
	cin.ignore();
}

void CommandLine::setAttributes(String& sample, char del)
{
	while (true)
	{
		cin.get(letter);

		if (letter == del || letter == '\n')
			break;

		sample.push_back(letter);
	}
}

//void CommandLine::helperForSaveAndSaveas(String& fileUsers)
//{
//	ofstream file;
//	file.open(fileName.getStr());
//
//	int countOfRows = table.getMaxRow();
//
//	for (int i = 1; i < countOfRows; i++)
//	{
//		if (!table.getRows()[i].getIsEmpty())
//		{
//			int countOfCols = table.getRows()[i].getCapacity();
//
//			for (int j = 1; j < countOfCols; j++)
//			{
//				int len = strlen(table.getCellOnRow(i, j));
//				file.write(table.getCellOnRow(i, j), len);
//
//				if (j != countOfCols - 1)
//					file.write(",", sizeof(char));
//			}
//		}
//		file.write("\n", sizeof(char));
//	}
//	file.close();
//}

void CommandLine::helperToCreateNewFile()
{
	ofstream newFile(fileName.getStr()); // Създаваме празен файл, както е по условие.
	cerr << "Such file doesn't exist. A new empty file with the given name was created for you" << endl;
	newFile.close();
}

void CommandLine::writeBooksInFile()
{
	fileBooks.open("Books.txt", ofstream::trunc);

	int len = lib.getCount();
	for (int i = 0; i < len; i++)
	{
		int lenOfTitle = strlen(lib.getBooks()[i].getTitle());
		int lenOfAuthor = strlen(lib.getBooks()[i].getAuthor());
		int lenOfGenre = strlen(lib.getBooks()[i].getGenre());
		int lenOfDescr = strlen(lib.getBooks()[i].getDescr());
		int countOfKeyWords = lib.getBooks()[i].getKeyWords().size();
		fileBooks.write(lib.getBooks()[i].getTitle(), lenOfTitle);
		fileBooks << "|";
		fileBooks.write(lib.getBooks()[i].getAuthor(), lenOfAuthor);
		fileBooks << "|";
		fileBooks.write(lib.getBooks()[i].getGenre(), lenOfGenre);
		fileBooks << "|";
		fileBooks << lib.getBooks()[i].getUn();
		fileBooks << "|";
		fileBooks << lib.getBooks()[i].getYearOfRelease();
		fileBooks << "|";
		fileBooks << lib.getBooks()[i].getRating();
		fileBooks << "|";
		fileBooks.write(lib.getBooks()[i].getDescr(), lenOfDescr);
		fileBooks << "|";
		
		for (int j = 0; j < countOfKeyWords; j++)
		{
			int lenOfKeyWord = strlen(lib.getBooks()[i].getKeyWords().at(j).getStr());
			fileBooks.write(lib.getBooks()[i].getKeyWords().at(j).getStr(), lenOfKeyWord);

			if (j != countOfKeyWords - 1)
				fileBooks.put(',');
		}

		fileBooks.write("\n", sizeof(char));
	}

	fileBooks.close();
}
void CommandLine::writeUsersInFile()
{
	fileUsers.open("Users.txt", ofstream::trunc);

	int len = pl.getCount();
	for (int i = 0; i < len; i++)
	{
		int lenOfName = strlen(pl.getUsers()[i].getUsername());
		int lenOfPass = strlen(pl.getUsers()[i].getPassword());

		fileUsers.write(pl.getUsers()[i].getUsername(), lenOfName);
		fileUsers << ", ";
		fileUsers.write(pl.getUsers()[i].getPassword(), lenOfPass);

		if (pl.getUsers()[i].getIsAdmin())
			fileUsers << ", isAdmin";

		fileUsers.write("\n", sizeof(char));
	}

	fileUsers.close();
}

//void CommandLine::save(String& fileName)
//{
//	helperForSaveAndSaveas(fileName);
//
//	cout << "Successfully saved " << fileName.getStr() << endl;
//}

//void CommandLine::saveas()
//{
//	String userChosenFileName; // Създаваме името на файла, в което потребителят иска да запише промените.
//
//	setAttributes(userChosenFileName);
//
//	helperForSaveAndSaveas(userChosenFileName);
//
//	cout << "Successfully saved another " << userChosenFileName.getStr() << endl;
//}

void CommandLine::close() const
{
	cout << "Successfully closed" << " " << fileName.getStr();
}
void CommandLine::help() const
{
	cout << "The following commands are supported:" << endl;
	cout << "open <file>    opens <file>" << endl;
	cout << "close			closes currently opened file" << endl;
	cout << "save			saves the currently open file" << endl;
	cout << "saveas <file>	saves the currently open file in <file>" << endl;
	cout << "help			prints this information" << endl;
	cout << "exit			exists the program" << endl;
}
void CommandLine::exit()
{
	writeBooksInFile();
	writeUsersInFile();
	cout << "Exiting the program..." << endl;
}

void CommandLine::open()
{
	cout << "Write exit to stop the program." << endl;

	String emptyFileName;
	ifstream file;

	String admin;
	admin.setStr("admin");
	String adminPass;
	adminPass.setStr("i<3c++");
	pl.AddUser(admin, adminPass, true);

	while (strcmp(command, "exit") != 0)
	{
		enterCommand();

		if (strcmp(command, "open") == 0)
		{
			setAttributes(fileName, ' ');

			file.open(fileName.getStr());

			if (file.fail())
			{
				helperToCreateNewFile();

				file.open(fileName.getStr());
			}
			else
				cout << "Successfully opened " << fileName.getStr() << endl;

			file.close();

			while (true)
			{
				enterCommand();

				if (strcmp(command, "login") == 0 && login())
				{
					while (true)
					{
						enterCommand();

						if (strcmp(command, "login") == 0)
						{
							cout << "You are already logged in.";
							continue;
						}

						if (strcmp(command, "books") == 0)
						{
							enterCommand();

							if (strcmp(command, "all") == 0)
								booksAll();

							else if (strcmp(command, "find") == 0);
							else if (strcmp(command, "sort") == 0);
							else if (strcmp(command, "view") == 0);
							else if (strcmp(command, "add") == 0 )
								booksAdd();

							else if (strcmp(command, "remove") == 0 && logged.getIsAdmin());

							else
								cout << "Wrong command or the logged user is not an admin.";
						}

						else if (strcmp(command, "users") == 0 && logged.getIsAdmin())
						{
							enterCommand();

							if (strcmp(command, "add") == 0)
								usersAdd();

							else if (strcmp(command, "remove") == 0);
						}

						else if (strcmp(command, "users") == 0 && !logged.getIsAdmin())
							cout << "Wrong command or the logged user is not an admin.";

						else if (strcmp(command, "logout") == 0)
						{
							logout();
							break;
						}

						else if (strcmp(command, "printUsers") == 0)
							pl.PrintAll();

						else if (strcmp(command, "printBooks") == 0)
							lib.PrintAll();
					}
				}

				else if (strcmp(command, "save") == 0)
					;//save(fileName);

				else if (strcmp(command, "saveas") == 0)
					;//saveas();

				else if (strcmp(command, "close") == 0)
				{
					close();
					file.close();

					fileName = emptyFileName;
					break;
				}

				else if (strcmp(command, "help") == 0)
					help();

				else if (strcmp(command, "exit") == 0)
				{
					exit();
					break;
				}
			}
		}
	}
}

bool CommandLine::login()
{
	bool userExist = false;

	String username;
	String password;

	setAttributes(username, ' ');
	setAttributes(password, ' ');

	int len = pl.getCount();

	for (int i = 0; i < len; i++)
	{
		if ((strcmp(pl.getUsers()[i].getUsername(), username.getStr()) == 0) &&
			((strcmp(pl.getUsers()[i].getPassword(), password.getStr()) == 0)))
		{
			logged = pl.getUsers()[i];

			userExist = true;
			cout << "Welcome, "; 
			username.print(); 
			cout << "!";
			break;
		}
	}
	
	if (!userExist)
	{
		cout << "Wrong username or password!";
		return false;
	}
	return true;
}
void CommandLine::logout()
{
	cout << logged.getUsername() << " successfully logged out";

	User emptyUser;
	logged = emptyUser;
}

void CommandLine::booksAll()
{
	ifstream file;
	file.open(fileName.getStr());

	char ch = 'a';

	while (!file.eof())
	{
		int count = 0;
		while (ch != '\n')
		{
			file.get(ch);

			if (ch == '|')
				count++;

			if (count < 4)
			{			
				if (ch == '|')
					ch = ' ';
				cout << ch;
			}
		}
		cout << endl;

		if (ch == '\n')
		{
			file.get(ch);
			cout << ch;
		}
	}

	file.close();
}
void CommandLine::booksAdd()
{
	countOfKeyWords = 0;

	String title;
	String author;
	String genre;

	int un;
	int yearOfRelease;
	double rating;

	String description;

	Vector<String> keyWords;
	String tempWord;
	String emptyWord;

	setAttributes(title, '|');
	setAttributes(author, '|');
	setAttributes(genre, '|');

	cin.get(letter);
	cin >> un;
	cin.get(letter);
	cin >> yearOfRelease;
	cin.get(letter);
	cin >> rating;
	cin.get(letter);
	cin.get(letter);

	while ((letter > '0' && letter < '9') || letter == '.')
		cin.get(letter);

	description.push_back(letter);
	setAttributes(description, '|');
	cin.get(letter);

	tempWord.push_back(letter);
	while (letter != '\n')
	{
		cin.get(letter);

		if (letter == ',' || letter == '\n')
		{
			keyWords.push_back(tempWord);
			tempWord = emptyWord;
			countOfKeyWords++;
			continue;
		}

		tempWord.push_back(letter);
	}

	if (logged.getIsAdmin())
		lib.AddBook(title, author, genre, un, yearOfRelease, rating, description, keyWords);
	else
		cout << "User is not an admin.";
}

void CommandLine::usersAdd()
{
	String username;
	String password;
	String admin;

	setAttributes(username, ' ');
	setAttributes(password, ' ');
	setAttributes(admin, ' ');

	if (strcmp(admin.getStr(), "admin") == 0)
	{
		cout << "Successfully added another user "; username.print();
		pl.AddUser(username, password, true);
	}
	else if (strcmp(admin.getStr(), "noAdmin") == 0)
	{
		cout << "Successfully added another user "; username.print();
		pl.AddUser(username, password);
	}
	else
		cout << "You should tell what rights has the user. Write \"admin\" or \"noAdmin\" after the password.";
}