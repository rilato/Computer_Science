#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
	string name;
public:
	Player(string name = "") {
		this->name = name;
	}
	void setName(string name) { this->name = name; }	// 저장
	string getName() { return name; }
	void getEnterKey() {	// 엔터 키 입력
		char buf[100];
		cin.getline(buf, 99);
	}
};

class GamblingGame {
	Player p[2];
	int num[3];
	bool matchAll();
public:
	GamblingGame();
	void run();
};

bool GamblingGame::matchAll() {
	if (num[0] == num[1] && num[1] == num[2]) // num[0] == num[1] == num[2] 쓰면 이상하게 나옴!!
		return true;
	else
		return false;
}

GamblingGame::GamblingGame() {
	for (int i = 0; i < 3; i++)
		num[i] = 0;
	srand((unsigned int)time(NULL));
}

void GamblingGame::run() {
	string name;
	int random;

	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;

	cout << "첫번째 선수 이름>>";
	cin >> name;	// 저장을 위한 입력
	p[0].setName(name);

	cout << "두번째 선수 이름>>";
	cin >> name;
	p[1].setName(name);

	p[0].getEnterKey();

	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << p[i].getName() << ":";
			p[i].getEnterKey();

			for (int j = 0; j < 3; j++)
			{
				random = rand() % 3;
				num[j] = random;
				cout << '\t' << num[j];
			}

			if (matchAll() == true)
			{
				cout << '\t' << p[i].getName() << "님 승리!!" << endl;
				break;
			}

			cout << '\t' << "아쉽군요!" << endl;
		}

		if (matchAll() == true)
			break;
	}
}

int main()
{
	GamblingGame game;
	game.run();
}