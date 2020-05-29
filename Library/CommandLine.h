#include <fstream>
#include "UsersPlatform.h"

const int MAX_SIZE_OF_COMMAND = 13;
class CommandLine
{
private:
	String fileName;
	//String value;

	char command[MAX_SIZE_OF_COMMAND];
	char letter;

	void setAttributes(String& sample);

	//void helperForSaveAndSaveas(String& diffFileName);
	void helperToCreateNewFile();

public:
	void enterCommand();

	void save(String& fileName);
	void saveas();
	void close() const;
	void help() const;
	void exit() const;

	void open();
	void login();

	void booksAll();
	void booksFind();
};