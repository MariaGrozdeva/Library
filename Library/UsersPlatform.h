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

	void AddUser(String username, String password, bool isAdmin = false);

	void PrintAll();
};