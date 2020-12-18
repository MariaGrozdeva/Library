#include "User.h"

class UsersPlatform
{
private:
	User* users; /**< Dynamically allocated array of objects of type User. */

	int capacity;
	int count;

	void CopyFrom(const UsersPlatform& other);
	void Free();

	void Resize();

public:
	/**
	* Big 4.
	* @see UsersPlatform(const UsersPlatform& other) @see UsersPlatform& operator=(const UsersPlatform& other)
	* @see ~UsersPlatform()
	*/
	UsersPlatform();
	
	UsersPlatform(const UsersPlatform& other);
	UsersPlatform& operator=(const UsersPlatform& other);
	~UsersPlatform();

	/**
	* Getters for the array of users and the number of users, which increases when the function AddUser() is called
	* and a new user is added successfully.
	*/
	User* getUsers() const;
	int getCount() const;

	void AddUser(String username, String password, bool isAdmin = false); /**< Adds a new user, based on the given parametres. */

	void usersRemove(String title); /**< Removes the user with the given parametres if such exist. */

	void PrintAll();
};