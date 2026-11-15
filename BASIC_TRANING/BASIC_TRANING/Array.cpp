#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int damage;
	int defence;
};

int main_123()
{
	//StatInfo monster[10];

	// C# int[] arr;
	int arr[5];

	// 배열은 0부터 시작 
	// 0 1 2 3 4 
	arr[0] = 0;
	arr[1] = 10;
	arr[2] = 20;
	arr[3] = 30;
	arr[4] = 40;

	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;

	return 0;

}