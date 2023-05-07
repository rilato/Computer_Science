#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	Book(Book& b);
	~Book();
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}

void Book::set(const char* title, int price) {
	if (this->title)
		delete[] this->title;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::Book(Book& b) {
	this->price = b.price;
	int len = strlen(b.title);
	this->title = new char[len + 1];
	strcpy(this->title, b.title);
}

Book::~Book() {
	delete[] title;
}




int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}