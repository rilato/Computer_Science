#include <iostream>

using namespace std;

int col[4] = { 0, };

bool check(int num, int index)
{
    col[num] = index; // 해당 위치에 퀸을 배치
    bool flag = false;
    for (int i = 0; i < num; i++) {
        //col[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
        if (col[i] == col[num] || abs(col[num] - col[i]) == num - i)// 동일 선상에 있거나, 대각선에 위치하면 false를 반환한다.
            flag = true;
        else
            continue;
    }

    if (flag == true)
        return false;
    else
        return true;
}

void nqueen(int number)
{
    cout << "-----start nqueen-----\n";
    if (number == 4) { // 4 Queen에서 x가 4개여야 4퀸이 완성된 상황을 의미한다.
        for (int i = 0; i < 4; i++)
            cout << "(" << i + 1 << "," << col[i] + 1 << ") ";
        cout << '\n';
    }

    else    // 4 Queen에서 x가 4가 아니면 4 Queen을 만족하지 못하는 상황이다.
    {
        for (int i = 0; i < 4; i++)
        {
            bool flag = false;
            if (check(number, i)) // 조건을 만족한다면 다음행에 퀸을 배치, 조건을 만족하지 않는다면 다른 위치로 퀸의 배치를 변경한다.
                flag = true;  // 조건을 만족한다면 재귀 함수를 통해 다음행에 퀸을 배치한다.
            else
                flag = false;

            if (flag == true)
                nqueen(number + 1);
            else
                flag = false;
        }
    }
}

int main() {
    nqueen(0);  // 맨 처음 놓이는 경우부터 조사하기 위해 nqueen의 인자로 0을 설정한다.
}
