#include <fstream>
#include "UsersPlatform.h"
#include "BooksLibrary.h"

const int MAX_SIZE_OF_COMMAND = 13;
class CommandLine
{
private:
	User logged;
	UsersPlatform pl;
	BooksLibrary lib;

	ofstream fileUsers;
	String fileName;

	char command[MAX_SIZE_OF_COMMAND];
	char letter;

	void setAttributes(String& sample);

	//void helperForSaveAndSaveas(String& diffFileName);
	void helperToCreateNewFile();
	void writeUsersInFile();

public:
	void enterCommand();

	void save(String& fileName);
	void saveas();
	void close() const;
	void help() const;
	void exit();

	void open();

	bool login();
	void logout();

	void booksAll();
	void booksAdd();

	void usersAdd();
};