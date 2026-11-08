#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandNum
{
private:
    int num;

public:
    RandNum() {
        // 시드(Seed) 값 설정
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    void Generate()
    {
        // 0부터 100 사이의 난수 생성
        num = rand() % 101;
    }

    bool Compare(int input)
    {
        if (input == num) {
            cout << "맞췄습니다.\n";
            return true;
        }
        else if (input > num)
        {
            cout << "입력한 숫자보다 더 작습니다 \n";
        }
        else
        {
            cout << "입력한 숫자보다 더 큽니다 \n";
        }
        return false;
    }
};

class Ask
{
private:
    int input;

public:
    void Prompt() { cout << "\n제가 만든 숫자를 맞춰 보세요.\n"; }

    bool AskUser() {
        cout << "숫자를 입력하세요(끝낼 때는 999) : ";
        cin >> input;
        if (input == 999) {
            return true;
        }
        return false;
    }

    int GetInput() { return input; }
};

int main_0()
{
    RandNum R;
    Ask A;

    for (;;)
    {
        R.Generate();
        A.Prompt();
        for (;;)
        {
            if (A.AskUser()) {
                exit(0);
            }
            if (R.Compare(A.GetInput())) {
                break;
            }
        }
    }
    return 0;
}