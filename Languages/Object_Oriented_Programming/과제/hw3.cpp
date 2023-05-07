#include <iostream>

using namespace std;

class Sample {
	int* p;
	int capacity;
	int size;
public:
	Sample(int n) {
		capacity = n;
		p = new int[n];
	}
	void read();
	void write();
	int big();
	int getSize() { return size; }
	~Sample() { delete[] p; }
};

void Sample::read() {
	int inputnum;

	cout << "�Է��ҷ��� ������ ������ ? ";
	cin >> size;

	cout << size << "���� ������ �Է��Ͻÿ� ";

	for (int i = 0; i < size; i++)
	{
		cin >> inputnum;
		p[i] = inputnum;
	}
}

void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';

	cout << endl << endl;
}

int Sample::big() {
	int max = p[0];

	for (int i = 0; i < size; i++)
	{
		if (max < p[i])
			max = p[i];
	}

	return max;
}

int main()
{
	Sample s(10);
	s.read();
	cout << "�����迭 ���� " << s.getSize() << "���� ����մϴ�.";
	s.write();
	cout << "���� ū ���� " << s.big() << endl;
}