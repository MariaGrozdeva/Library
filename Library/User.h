#include "String.h"
using namespace std;

#pragma once

class User
{
private:
	String username;
	String password;

	bool isAdmin;

public:
	User();
	User(String username, String password, bool isAdmin);

	const char* getUsername() const;
	const char* getPassword() const;
	bool getIsAdmin() const;

	void Print();
};