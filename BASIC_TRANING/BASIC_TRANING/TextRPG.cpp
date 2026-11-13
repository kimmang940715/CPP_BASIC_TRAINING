#include <iostream>

using namespace std;


enum PlayerType
{
	PT_None = 0,
	PT_KNIGHT = 1,
	PT_ARCHER = 2,
	PT_WIZARD = 3
};

PlayerType playerType;

// 추후 플레이어 스탯으로 
int hp;
int attack;
int defence;


void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();

int main()
{
	srand(time(0));
	EnterLobby();

}

void EnterLobby()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "------------------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "------------------------------" << endl;
		cout << "[1]필드 입장 [2]게임 종료" << endl;
		cout << "------------------------------" << endl;
	
		int input;
		cin >> input;

		if (input == 1)
		{
			cout << "필드에 입장했습니다!" << endl;
			EnterField();
			break;
		}
		else if (input == 2)
		{
			cout << "게임을 종료합니다!" << endl;
			exit(0);
		}
		else
		{
			cout << "잘못된 입력입니다!" << endl;
		}
		
	}
}

void SelectPlayer()
{ 
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "[1]기사 [2]궁수 [3]마법사" << endl;
		cout << "------------------------------" << endl;

		cout << "> ";

		int choice;
		cin >> choice;;

		if (choice = PT_KNIGHT)
		{
			cout << "기사 생성중..." << endl;
			hp = 150;
			attack = 10;
			defence = 5;
			playerType = PT_KNIGHT;
			break;
		}
		else if (choice = PT_ARCHER)
		{
			cout << "궁수 생성중..." << endl;
			hp = 100;
			attack = 15;
			defence = 3;
			playerType = PT_ARCHER;
			break;
		}
		else if (choice = PT_WIZARD)
		{
			cout << "마법사 생성중..." << endl;
			hp = 80;
			attack = 25;
			defence = 0;
			playerType = PT_WIZARD;
			break;
		}
	}

}

void EnterField() 
{
	cout << "------------------------------" << endl;
	cout << "필드에 입장했습니다!" << endl;
	cout << "------------------------------" << endl;

	cout << "[Player HP] : " << hp << "[Player ATT] : " << attack << "[Player DEF] : " << defence << endl;


	// 몬스터 생성
	CreateRandomMonster();


}

void CreateRandomMonster()
{
	int randomChoice = 1 + (rand() % 3);
}
