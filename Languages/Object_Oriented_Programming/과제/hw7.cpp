#include <iostream>
#include <string>

using namespace std;

class Histogram {
	int count[26] = {0,};
	string str;
public:
	Histogram(string s);
	void makeHisto();
	void operator !();
	Histogram& operator << (string s);
	Histogram& operator << (char c);
};

Histogram::Histogram(string s) {
	str = s;
    cout << str;
}

void Histogram::makeHisto() {

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a')
            ++count[0];
        if (str[i] == 'b')
            ++count[1];
        if (str[i] == 'c')
            ++count[2];
        if (str[i] == 'd')
            ++count[3];
        if (str[i] == 'e')
            ++count[4];
        if (str[i] == 'f')
            ++count[5];
        if (str[i] == 'g')
            ++count[6];
        if (str[i] == 'h')
            ++count[7];
        if (str[i] == 'i')
            ++count[8];
        if (str[i] == 'j')
            ++count[9];
        if (str[i] == 'k')
            ++count[10];
        if (str[i] == 'l')
            ++count[11];
        if (str[i] == 'm')
            ++count[12];
        if (str[i] == 'n')
            ++count[13];
        if (str[i] == 'o')
            ++count[14];
        if (str[i] == 'p')
            ++count[15];
        if (str[i] == 'q')
            ++count[16];
        if (str[i] == 'r')
            ++count[17];
        if (str[i] == 's')
            ++count[18];
        if (str[i] == 't')
            ++count[19];
        if (str[i] == 'u')
            ++count[20];
        if (str[i] == 'v')
            ++count[21];
        if (str[i] == 'w')
            ++count[22];
        if (str[i] == 'x')
            ++count[23];
        if (str[i] == 'y')
            ++count[24];
        if (str[i] == 'z')
            ++count[25];
    }        
}

void Histogram::operator !() {
	int countAlphabet = 0;

	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);

		if (isalpha(str[i]))
			++countAlphabet;
	}

    cout << endl << endl << "ÃÑ ¾ËÆÄºª ¼ö " << countAlphabet << endl;

    makeHisto();

    int alphabet;

    for (int i = 0; i < 26; i++) {
        cout << char('a' + i) << ":";

        alphabet = count[i];

        for (int j = 0; j < alphabet; j++)
            cout << "*";
        cout << endl;
    }
}

Histogram& Histogram::operator << (string s) {
	this->str = this->str + s;
    cout << s;
	return *this;
}

Histogram& Histogram::operator << (char c) {
	this->str = this->str + c;
    cout << c;
	return *this;
}

int main() {
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "- by ";
	song << 'k' << 'i' << 't';
	!song;
}