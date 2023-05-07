#include <iostream>
#include <string>

using namespace std;

class BaseArray {
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) { this->capacity = capacity; mem = new int[capacity]; }
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack :public BaseArray {
	int tos;
public:
	MyStack(int capacity) : BaseArray(capacity) { tos = 0; }
	void push(int n);
	int pop();
	int capacity();
	int length();
};

void MyStack::push(int n) {
	if (tos > getCapacity())
		return;
	put(tos, n);
	++tos;
}

int MyStack::pop() {
	if (tos < 0)
		return -1;
	--tos;
	return get(tos);
}

int MyStack::capacity() {
	return getCapacity();
}

int MyStack::length() {
	return tos;
}

int main() {
	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}