#include <iostream>

using namespace std;

void AddHp(int hp, int value)
{

}

int main()
{

	int hp = 100;

	// [타입]*[이름];
	// - * = 포인터
	// - 주소값을 담는 바구니
	// - &뒤의 변수의 주소값을 알려주세요
	// - type : 주소값을 타고 가면 무엇이있느냐 (type 으로 주장)

	int* ptr = &hp;

	cout << *ptr << endl;
	cout << &ptr << endl;


	AddHp(hp, 10);
}