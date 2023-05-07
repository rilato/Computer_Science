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
	void setName(string name) { this->name = name; }	// ����
	string getName() { return name; }
	void getEnterKey() {	// ���� Ű �Է�
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
	if (num[0] == num[1] && num[1] == num[2]) // num[0] == num[1] == num[2] ���� �̻��ϰ� ����!!
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

	cout << "***** ���� ������ �����մϴ�. *****" << endl;

	cout << "ù��° ���� �̸�>>";
	cin >> name;	// ������ ���� �Է�
	p[0].setName(name);

	cout << "�ι�° ���� �̸�>>";
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
				cout << '\t' << p[i].getName() << "�� �¸�!!" << endl;
				break;
			}

			cout << '\t' << "�ƽ�����!" << endl;
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