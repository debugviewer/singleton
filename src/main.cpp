#include "Singleton.h"
#include <stdio.h>

class User{
public:
	User() { printf("User()\n"); }
	virtual ~User() { printf("~User()\n"); }

	void hello() { printf("hello\n"); }
};

#define singleton_user Singleton<User>::getInstance()

int main() {
	printf("main thread begin......\n");
	singleton_user->hello();
	printf("main thread end......\n");
	return 0;
}

