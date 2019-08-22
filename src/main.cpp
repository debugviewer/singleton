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
	printf("singleton demo\n");
	Singleton<User>::getInstance()->hello();

	return 0;
}

