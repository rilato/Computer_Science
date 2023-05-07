#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random {
public:
	static void seed();
	static int nextInt(int min, int max);
	static char nextAlphabet();
	static double nextDouble();
};

void Random::seed() {
	srand((unsigned int)time(NULL));
}

int Random::nextInt(int min, int max) {
	int random;
	random = (rand() % (max - min + 1)) + min;
	return random;
}

char Random::nextAlphabet() {
	char random;

	while (true) {
		random = rand() % 58 + 'A';
		if (random <= 'Z' || random >= 'a')
			break;
	}
	return random;
}

double Random::nextDouble() {
	double random;

	random = rand() / (double)32767;

	return random;
}


int main() {
	Random::seed();
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextInt(1, 100) << ' ';
	cout << endl;
	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << ' ';
	cout << endl;
	cout << "������ �Ǽ��� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 5; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;
}