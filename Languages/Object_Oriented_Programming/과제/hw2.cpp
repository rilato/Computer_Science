#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class EvenRandom
{
public:
    EvenRandom();
    int next();
    int nextInRange(int low, int high);
};

EvenRandom::EvenRandom()
{
    srand((unsigned int)time(NULL));
}

int EvenRandom::next()
{
    int myrand;

    myrand = rand();

    if (myrand % 2 == 0)
        return myrand;
    else
        return myrand + 1;
}

int EvenRandom::nextInRange(int low, int high)
{
    int myrand;

    myrand = rand() % (high - low + 1);

    if (myrand % 2 == 0)
        return myrand + 2;
    else
        return myrand + 1;
}

int main()
{
    EvenRandom r;

    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수 10 개 --" << endl;

    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
    }

    cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 짝수 정수 10 개 --" << endl;

    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 10);
        cout << n << ' ';
    }

    cout << endl;
}