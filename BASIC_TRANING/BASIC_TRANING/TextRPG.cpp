#include <iostream>
#include <cstdlib>
#include <ctime>

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
	MT_SKELETON = 3,
	MT_BOSS = 4
};

struct StatInfo
{
	int level;
	int hp;
	int maxHp;
	int attack;
	int defence;
	int exp;
	int gold;
	int potionCount;
};

PlayerType playerType;
StatInfo playerStat;

MonsterType monsterType;
StatInfo monsterStat;

int currentStage = 1;
int monsterKillCount = 0;

void EnterLobby();
void SelectPlayer();
void EnterShop();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
void CheckLevelUp();
void WaitForNextKey();

int main()
{
	srand(time(0));
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "\n------------------------------" << endl;
		cout << " [로비] 에 입장했습니다! " << endl;
		cout << "------------------------------" << endl;
		cout << "1. 캐릭터 생성 및 직업 선택" << endl;
		cout << "2. 필드 입장" << endl;
		cout << "3. 상점 방문" << endl;
		cout << "4. 게임 종료" << endl;
		cout << "------------------------------" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			SelectPlayer();
		}
		else if (input == 2)
		{
			if (playerType == PT_None)
			{
				cout << "먼저 직업을 선택해주세요!" << endl;
				continue;
			}
			EnterField();
		}
		else if (input == 3)
		{
			if (playerType == PT_None)
			{
				cout << "먼저 직업을 선택해주세요!" << endl;
				continue;
			}
			EnterShop();
		}
		else if (input == 4)
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
		cout << "\n------------------------------" << endl;
		cout << " 직업을 골라주세요!" << endl;
		cout << "[1] 기사 (체력 높음, 방어력 우수)" << endl;
		cout << "[2] 궁수 (균형 잡힌 능력치)" << endl;
		cout << "[3] 마법사 (공격력 극대화)" << endl;
		cout << "------------------------------" << endl;
		cout << "> ";

		int choice;
		cin >> choice;

		if (choice == PT_KNIGHT)
		{
			cout << "기사 생성 완료!" << endl;
			playerStat = { 1, 150, 150, 15, 5, 0, 100, 3 };
			playerType = PT_KNIGHT;
			break;
		}
		else if (choice == PT_ARCHER)
		{
			cout << "궁수 생성 완료!" << endl;
			playerStat = { 1, 100, 100, 20, 3, 0, 100, 3 };
			playerType = PT_ARCHER;
			break;
		}
		else if (choice == PT_WIZARD)
		{
			cout << "마법사 생성 완료!" << endl;
			playerStat = { 1, 80, 80, 30, 1, 0, 100, 3 };
			playerType = PT_WIZARD;
			break;
		}
		else
		{
			cout << "올바른 번호를 입력하세요." << endl;
		}
	}
}

void EnterShop()
{
	while (true)
	{
		cout << "\n------------------------------" << endl;
		cout << " [상점] 어서오세요! 무엇을 도와드릴까요?" << endl;
		cout << " 보유 골드 : " << playerStat.gold << " G" << endl;
		cout << " 보유 포션 : " << playerStat.potionCount << "개" << endl;
		cout << "------------------------------" << endl;
		cout << "[1] 체력 포션 구매 (50 G)" << endl;
		cout << "[2] 공격력 강화서 (100 G) - 공격력 +5" << endl;
		cout << "[3] 로비로 돌아가기" << endl;
		cout << "------------------------------" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			if (playerStat.gold >= 50)
			{
				playerStat.gold -= 50;
				playerStat.potionCount++;
				cout << "체력 포션을 구매했습니다!" << endl;
			}
			else
			{
				cout << "골드가 부족합니다!" << endl;
			}
		}
		else if (input == 2)
		{
			if (playerStat.gold >= 100)
			{
				playerStat.gold -= 100;
				playerStat.attack += 5;
				cout << "공격력이 강화되었습니다! (현재 공격력: " << playerStat.attack << ")" << endl;
			}
			else
			{
				cout << "골드가 부족합니다!" << endl;
			}
		}
		else if (input == 3)
		{
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "\n------------------------------" << endl;
		cout << " [스테이지 " << currentStage << "] 필드에 입장했습니다!" << endl;
		cout << "------------------------------" << endl;
		cout << "[Lv." << playerStat.level << "] HP: " << playerStat.hp << "/" << playerStat.maxHp
			<< " | ATT: " << playerStat.attack << " | DEF: " << playerStat.defence
			<< " | EXP: " << playerStat.exp << "/100 | Gold: " << playerStat.gold << "G | 포션: " << playerStat.potionCount << "개" << endl;
		cout << "------------------------------" << endl;
		cout << "[1] 전투 시작" << endl;
		cout << "[2] 포션 사용 (HP 회복)" << endl;
		cout << "[3] 로비로 돌아가기" << endl;
		cout << "------------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			CreateRandomMonster();
			EnterBattle();

			if (playerStat.hp <= 0)
			{
				cout << "\n[GAME OVER] 플레이어가 사망했습니다..." << endl;
				playerType = PT_None; // 초기화
				WaitForNextKey();
				return;
			}
		}
		else if (input == 2)
		{
			if (playerStat.potionCount > 0)
			{
				if (playerStat.hp == playerStat.maxHp)
				{
					cout << "이미 체력이 가득 찼습니다!" << endl;
				}
				else
				{
					playerStat.potionCount--;
					playerStat.hp += 50;
					if (playerStat.hp > playerStat.maxHp) playerStat.hp = playerStat.maxHp;
					cout << "포션을 사용하여 체력을 회복했습니다! (현재 HP: " << playerStat.hp << ")" << endl;
				}
			}
			else
			{
				cout << "보유한 포션이 없습니다!" << endl;
			}
		}
		else if (input == 3)
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	// 3마리 처치할 때마다 보스 등장
	if (monsterKillCount > 0 && monsterKillCount % 3 == 0)
	{
		cout << "\n[!] 강력한 보스 몬스터가 나타났습니다!" << endl;
		monsterStat = { 150, 25, 8 };
		monsterType = MT_BOSS;
		return;
	}

	int randomChoice = 1 + (rand() % 3);

	switch (randomChoice)
	{
	case MT_SLIME:
		cout << "슬라임이 나타났습니다! (HP : 30 / ATT : 8 / DEF : 1)" << endl;
		monsterStat = { 30, 8, 1 };
		monsterType = MT_SLIME;
		break;
	case MT_ORC:
		cout << "오크가 나타났습니다! (HP : 60 / ATT : 15 / DEF : 3)" << endl;
		monsterStat = { 60, 15, 3 };
		monsterType = MT_ORC;
		break;
	case MT_SKELETON:
		cout << "해골이 나타났습니다! (HP : 90 / ATT : 20 / DEF : 5)" << endl;
		monsterStat = { 90, 20, 5 };
		monsterType = MT_SKELETON;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		cout << "\n------------------------------" << endl;
		cout << "[전투 중] 플레이어 HP: " << playerStat.hp << " vs 몬스터 HP: " << monsterStat.hp << endl;
		cout << "[1] 기본 공격  [2] 직업 스킬 사용  [3] 포션 사용  [4] 도주" << endl;
		cout << "------------------------------" << endl;
		cout << "> ";

		int choice;
		cin >> choice;

		if (choice == 1)
		{
			// 플레이어 -> 몬스터 공격
			int damage = playerStat.attack - monsterStat.defence;
			if (damage < 0) damage = 0;
			monsterStat.hp -= damage;
			if (monsterStat.hp < 0) monsterStat.hp = 0;
			cout << "플레이어의 공격! 몬스터에게 " << damage << "의 피해를 주었습니다." << endl;
		}
		else if (choice == 2)
		{
			// 직업별 스킬
			int skillDamage = 0;
			if (playerType == PT_KNIGHT)
			{
				skillDamage = (playerStat.attack * 1.5) - monsterStat.defence;
				cout << "[철벽 베기] 스킬 발동!" << endl;
			}
			else if (playerType == PT_ARCHER)
			{
				skillDamage = (playerStat.attack * 1.8) - monsterStat.defence;
				cout << "[더블 샷] 스킬 발동!" << endl;
			}
			else if (playerType == PT_WIZARD)
			{
				skillDamage = (playerStat.attack * 2.2) - (monsterStat.defence / 2);
				cout << "[파이어볼] 스킬 발동!" << endl;
			}

			if (skillDamage < 0) skillDamage = 0;
			monsterStat.hp -= skillDamage;
			if (monsterStat.hp < 0) monsterStat.hp = 0;
			cout << "스킬 적중! 몬스터에게 " << skillDamage << "의 강력한 피해를 주었습니다." << endl;
		}
		else if (choice == 3)
		{
			if (playerStat.potionCount > 0)
			{
				playerStat.potionCount--;
				playerStat.hp += 50;
				if (playerStat.hp > playerStat.maxHp) playerStat.hp = playerStat.maxHp;
				cout << "전투 중 포션을 사용했습니다! 현재 HP: " << playerStat.hp << endl;
			}
			else
			{
				cout << "포션이 부족합니다!" << endl;
				continue; // 턴 소모 안 함
			}
		}
		else if (choice == 4)
		{
			cout << "전투에서 도주했습니다!" << endl;
			return;
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 몬스터 처치 확인
		if (monsterStat.hp == 0)
		{
			cout << "\n 몬스터를 처치했습니다!" << endl;
			monsterKillCount++;

			int rewardExp = (monsterType == MT_BOSS) ? 60 : 35;
			int rewardGold = (monsterType == MT_BOSS) ? 80 : 30;

			playerStat.exp += rewardExp;
			playerStat.gold += rewardGold;
			cout << "보상 획득 -> 경험치: +" << rewardExp << ", 골드: +" << rewardGold << "G" << endl;

			CheckLevelUp();

			if (monsterType == MT_BOSS)
			{
				cout << "축하합니다! 스테이지 보스를 물리쳤습니다! 다음 스테이지로 진입합니다." << endl;
				currentStage++;
			}
			return;
		}

		// 몬스터 반격
		int monsterDamage = monsterStat.attack - playerStat.defence;
		if (monsterDamage < 0) monsterDamage = 0;
		playerStat.hp -= monsterDamage;
		if (playerStat.hp < 0) playerStat.hp = 0;
		cout << "몬스터의 반격! 플레이어에게 " << monsterDamage << "의 피해를 주었습니다. (남은 HP: " << playerStat.hp << ")" << endl;

		if (playerStat.hp == 0)
		{
			return;
		}
	}
}

void CheckLevelUp()
{
	if (playerStat.exp >= 100)
	{
		playerStat.level++;
		playerStat.exp -= 100;
		playerStat.maxHp += 30;
		playerStat.hp = playerStat.maxHp; // 레벨업 시 체력 완전 회복
		playerStat.attack += 5;
		playerStat.defence += 2;

		cout << "\n ★★★ LEVEL UP! (Lv." << playerStat.level << ") ★★★" << endl;
		cout << " 최대 체력, 공격력, 방어력이 상승했으며 체력이 모두 회복되었습니다!" << endl;
	}
}

void WaitForNextKey()
{
	cout << "\n로비로 돌아가려면 아무 숫자나 입력하세요: ";
	int input;
	cin >> input;
}