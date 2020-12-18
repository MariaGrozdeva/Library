#include "String.h"
using namespace std;

#pragma once

class User
{
private:
	String username; /**< Type String because each user could have a name which length is undetermined. */
	String password; /**< Type String because each user could have a password which length is undetermined. */

	bool isAdmin; /**< True if user is made an admin, false by default. */

public:
	/**
	* A default constructor and a constructor with parameters.
	* @see User(String username, String password, bool isAdmin)
	*/
	User();
	User(String username, String password, bool isAdmin);

	/**
	* Getters for the username and the password as const char*.
	* @see getPassword() const
	*/
	const char* getUsername() const;
	const char* getPassword() const;
	bool getIsAdmin() const;

	void Print();
};