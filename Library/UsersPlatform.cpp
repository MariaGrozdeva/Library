#include "UsersPlatform.h"

void UsersPlatform::CopyFrom(const UsersPlatform& other)
{
	capacity = other.capacity;
	count = other.count;

	for (int i = 0; i < count; i++)
		users[i] = other.users[i];
}
void UsersPlatform::Free()
{
	delete[] users;
}

void UsersPlatform::Resize()
{
	capacity *= 2;
	User* helper = new User[capacity];

	for (int i = 0; i < count; i++)
		helper[i] = users[i];

	Free();
	users = helper;
}

UsersPlatform::UsersPlatform()
{
	capacity = 4;
	count = 0;

	users = new User[capacity];
}

UsersPlatform::UsersPlatform(const UsersPlatform& other)
{
	CopyFrom(other);
}
UsersPlatform& UsersPlatform::operator=(const UsersPlatform& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
UsersPlatform::~UsersPlatform()
{
	Free();
}

User* UsersPlatform::getUsers() const
{
	return users;
}
int UsersPlatform::getCount() const
{
	return count;
}

void UsersPlatform::AddUser(String username, String password, bool isAdmin)
{
	if (count == capacity)
		Resize();

	users[count++] = *new User(username, password, isAdmin);
}

void UsersPlatform::PrintAll()
{
	for (int i = 0; i < count; i++)
	{
		users[i].Print();
		cout << endl;
	}
}