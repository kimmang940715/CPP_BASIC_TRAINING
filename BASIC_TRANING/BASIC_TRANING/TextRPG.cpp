#include <iostream>

using namespace std;


enum PlayerType
{
	PT_None = 0,
	PT_KNIGHT = 1,
	PT_ARCHER = 2,
	PT_WIZARD = 3
};

enum MonsterType
{
	MT_None = 0,
	MT_SLIME = 1,
	MT_ORC = 2,
	MT_SKELETON = 3
};

struct StatInfo 
{	
	int hp;
	int attack;
	int defence;
};
PlayerType playerType;
StatInfo playerStat;

MonsterType monsterType;
StatInfo monsterStat;



void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
void WaitForNextKey();


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
			EnterField();
			break;
		}
		else if (input == 2)
		{
			cout << "게임을 종료합니다!" << endl;
			return;
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

		if (choice == PT_KNIGHT)
		{
			cout << "기사 생성중..." << endl;
			playerStat.hp = 150;
			playerStat.attack = 10;
			playerStat.defence = 5;
			playerType = PT_KNIGHT;
			break;
		}
		else if (choice == PT_ARCHER)
		{
			cout << "궁수 생성중..." << endl;
			playerStat.hp = 100;
			playerStat.attack = 15;
			playerStat.defence = 3;
			playerType = PT_ARCHER;
			break;
		}
		else if (choice == PT_WIZARD)
		{
			cout << "마법사 생성중..." << endl;
			playerStat.hp = 80;
			playerStat.attack = 25;
			playerStat.defence = 0;
			playerType = PT_WIZARD;
			break;
		}
	}

}

void EnterField() 
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "------------------------------" << endl;

		cout << "[Player HP] : " << playerStat.hp << "[Player ATT] : " << playerStat.attack << "[Player DEF] : " << playerStat.defence << endl;


		// 몬스터 생성
		CreateRandomMonster();

		cout << "------------------------------" << endl;
		cout << "[1]전투 [2]도주" << endl;
		cout << "------------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (playerStat.hp == 0)
			{
				cout << "게임오버!" << endl;
				WaitForNextKey();
				return;
			}
		}
		else if (input == 2)
		{
			return;
		}
	}

}

void CreateRandomMonster()
{
	int randomChoice = 1 + (rand() % 3);

	switch (randomChoice)
	{
		case MT_SLIME:
			cout << "슬라임 생성중... (HP : 30 / ATT : 2 / DEF : 0)" << endl;
			monsterStat.hp = 30;
			monsterStat.attack = 2;
			monsterStat.defence = 0;
			monsterType = MT_SLIME;
			break;
		case MT_ORC:
			cout << "오크 생성중... (HP : 40 / ATT : 10 / DEF : 3)" << endl;
			monsterStat.hp = 40;
			monsterStat.attack = 10;
			monsterStat.defence = 3;
			monsterType = MT_ORC;
			break;
		case MT_SKELETON:
			cout << "해골 생성중... (HP : 80 / ATT : 15 / DEF : 5)" << endl;
			monsterStat.hp = 80;
			monsterStat.attack = 15;
			monsterStat.defence = 5;
			monsterType = MT_SKELETON;
			break;

	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerStat.attack - monsterStat.defence;
		if(damage < 0)
		{
			damage = 0;
		}

		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)
		{
			monsterStat.hp = 0;
		}

		cout << "몬스터의 남은 체력 : " << monsterStat.hp << endl;

		if (monsterStat.hp == 0)
		{
			cout << "몬스터를 처치했습니다!" << endl;
			return;
		}

		// 몬스터 반격
		damage = monsterStat.attack - playerStat.defence;
		playerStat.hp -= damage;
		if (playerStat.hp < 0)
		{
			playerStat.hp = 0;
		}
		cout << " 플레이어의 남은 체력 : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << "플레이어가 사망했습니다!" << endl;
			return;
		}

	}
}

void WaitForNextKey()
{
	cout << "계속하려면 1을 눌러주세요" << endl;
	cout << "> ";

	int input;
	cin >> input;

	system("cls");
}
