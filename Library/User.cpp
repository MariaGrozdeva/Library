#include "User.h"

User::User()
{
	this->username.setStr("Unnamed");
	this->password.setStr("Password");
	this->isAdmin = false;
}

User::User(String username, String password, bool isAdmin)
{
	this->username.setStr(username.getStr());
	this->password.setStr(password.getStr());
	this->isAdmin = isAdmin;
}

const char* User::getUsername() const
{
	return username.getStr();
}
const char* User::getPassword() const
{
	return password.getStr();
}
bool User::getIsAdmin() const
{
	return isAdmin;
}

void User::Print()
{
	username.print();
	cout << " ";
	password.print();
	cout << " ";

	if (isAdmin)
		cout << "isAdmin";
}