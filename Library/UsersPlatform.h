#include "User.h"

class UsersPlatform
{
private:
	User* users;

	int capacity;
	int count;

	void CopyFrom(const UsersPlatform& other);
	void Free();

	void Resize();

public:
	UsersPlatform();
	
	UsersPlatform(const UsersPlatform& other);
	UsersPlatform& operator=(const UsersPlatform& other);
	~UsersPlatform();

	User* getUsers() const;
	int getCount() const;

	void AddUser(String username, String password, bool isAdmin = false);
	void usersRemove(String title);

	void PrintAll();
};