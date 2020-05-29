using namespace std;

#include "String.h"

class User
{
private:
	String username;
	String password;

	bool isAdmin;

public:
	User();
	User(String username, String password, bool isAdmin);

	void Print();
};