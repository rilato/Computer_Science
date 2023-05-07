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

	cout << "입력할려는 정수의 갯수는 ? ";
	cin >> size;

	cout << size << "개의 정수를 입력하시오 ";

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
	cout << "동적배열 정수 " << s.getSize() << "개를 출력합니다.";
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
}