#include <stdio.h>

int main()
{
	enum origin {
		EAST,
		WEST,
		SOUTH,
		NORTH
	};

	struct  SHuman
	{
		char name[12];
		int age;
		double height;
	};

	struct SHuman hong = { "홍길동", 30, 180.5 };
	printf("이름 = %s, 나이 = %d\n", hong.name, hong.age);

	return 0;
}