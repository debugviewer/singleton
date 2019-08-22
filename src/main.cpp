#include "Singleton.h"
#include <stdio.h>

class User {
	friend class Singleton<User>;
public:
	void hello() { printf("hello\n"); }
private:
	User() { printf("User()\n"); }
	virtual ~User() { printf("~User()\n"); }
};

#define singleton_user Singleton<User>::getInstance()

int main() {
	printf("main thread begin......\n");
	singleton_user->hello();
	printf("main thread end......\n");
	return 0;
}

