#include "CommandLine.h"
#pragma warning (disable : 4996)

void CommandLine::enterCommand()
{
	cin >> command;
	cin.ignore();
}

void CommandLine::setAttributes(String& sample)
{
	while (true)
	{
		cin.get(letter);

		if (letter == ' ' || letter == '\n')
			break;

		sample.push_back(letter);
	}
}

//void CommandLine::helperForSaveAndSaveas(String& fileName)
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
//
//	file.close();
//}
void CommandLine::helperToCreateNewFile()
{
	ofstream newFile(fileName.getStr()); // Създаваме празен файл, както е по условие.
	cerr << "Such file doesn't exist. A new empty file with the given name was created for you" << endl;
	newFile.close();
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

void CommandLine::exit() const
{
	cout << "Exiting the program..." << endl;
}

void CommandLine::open()
{
	cout << "Write exit to stop the program." << endl;

	String emptyFileName;
	ifstream file;

	while (strcmp(command, "exit") != 0)
	{
		enterCommand();

		if (strcmp(command, "open") == 0)
		{
			setAttributes(fileName);

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

				if (strcmp(command, "login") == 0)
				{
					login();

					while (true)
					{
						enterCommand();

						if (strcmp(command, "books") == 0)
						{
							enterCommand();

							if (strcmp(command, "all") == 0)
								booksAll();

							else if (strcmp(command, "find") == 0);
							else if (strcmp(command, "sort") == 0);
							else if (strcmp(command, "view") == 0);
							else if (strcmp(command, "add") == 0);
							else if (strcmp(command, "remove") == 0);
						}

						else if (strcmp(command, "users") == 0)
						{
							enterCommand();

							if (strcmp(command, "add") == 0);
							else if (strcmp(command, "remove") == 0);
						}

						else if (strcmp(command, "logout") == 0)
							break;
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
					return;
				}
			}
		}
	}
}

void CommandLine::login()
{
	bool userExist = false;

	String username;
	String password;

	String tempUserName;
	String tempPassword;
	String empty;

	char ch = 'a';

	setAttributes(username);
	setAttributes(password);

	ifstream file;
	file.open(fileName.getStr());

	while (!file.eof())
	{
		while (ch != ' ' && !file.eof())
		{
			file.get(ch);

			if (ch != ' ')
				tempUserName.push_back(ch);
		}
		while (ch != '\n')
		{
			file.get(ch);

			if (ch != '\n')
				tempPassword.push_back(ch);
		}

		if ((strcmp(tempUserName.getStr(), username.getStr()) == 0) &&
			(strcmp(tempPassword.getStr(), password.getStr()) == 0))
		{
			userExist = true;
			cout << "Welcome, "; username.print(); cout << "!";
			break;
		}

		tempUserName = empty;
		tempPassword = empty;
	}

	if (!userExist)
		cout << "Wrong username or password!";

	file.close();
}

void CommandLine::booksAll()
{
	ifstream file;
	file.open(fileName.getStr());

	char ch = 'a';

	while (!file.eof())
	{
		while (ch != '\n')
		{
			file.get(ch);
			cout << ch;
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

void CommandLine::booksFind()
{

}