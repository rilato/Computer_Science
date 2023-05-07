#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void print_message();
int check_and_count_alphabet(char str[]);
void count_alphabet(char str[], int alphabet[], int len);
void print_format(int alphabet[], int len);
void get_star(int alphabet);

int main()
{
    int count = 0;
    char str[10000] = { 0, };
    int alphabet[26] = { 0, };

    print_message();

    cin.getline(str, 10000, ';');
    count = check_and_count_alphabet(str);
    cout << "총 알파벳 수 " << count << endl << endl;

    count_alphabet(str, alphabet, strlen(str));
    print_format(alphabet, strlen(str));

    return 0;
}

void print_message()
{
    cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
    cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
}

int check_and_count_alphabet(char str[])
{
    int i;
    int count = 0;

    for (i = 0; i < 10000; i++)
    {
        if (isalpha(str[i]))
        {
            ++count;
            str[i] = tolower(str[i]);
        }
    }

    return count;
}

void count_alphabet(char str[], int alphabet[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (str[i] == 'a')
            ++alphabet[0];
        if (str[i] == 'b')
            ++alphabet[1];
        if (str[i] == 'c')
            ++alphabet[2];
        if (str[i] == 'd')
            ++alphabet[3];
        if (str[i] == 'e')
            ++alphabet[4];
        if (str[i] == 'f')
            ++alphabet[5];
        if (str[i] == 'g')
            ++alphabet[6];
        if (str[i] == 'h')
            ++alphabet[7];
        if (str[i] == 'i')
            ++alphabet[8];
        if (str[i] == 'j')
            ++alphabet[9];
        if (str[i] == 'k')
            ++alphabet[10];
        if (str[i] == 'l')
            ++alphabet[11];
        if (str[i] == 'm')
            ++alphabet[12];
        if (str[i] == 'n')
            ++alphabet[13];
        if (str[i] == 'o')
            ++alphabet[14];
        if (str[i] == 'p')
            ++alphabet[15];
        if (str[i] == 'q')
            ++alphabet[16];
        if (str[i] == 'r')
            ++alphabet[17];
        if (str[i] == 's')
            ++alphabet[18];
        if (str[i] == 't')
            ++alphabet[19];
        if (str[i] == 'u')
            ++alphabet[20];
        if (str[i] == 'v')
            ++alphabet[21];
        if (str[i] == 'w')
            ++alphabet[22];
        if (str[i] == 'x')
            ++alphabet[23];
        if (str[i] == 'y')
            ++alphabet[24];
        if (str[i] == 'z')
            ++alphabet[25];
    }
}

void print_format(int alphabet[], int len)
{
    cout << "a (" << alphabet[0] << ") : ";
    get_star(alphabet[0]);
    cout << "b (" << alphabet[1] << ") : ";
    get_star(alphabet[1]);
    cout << "c (" << alphabet[2] << ") : ";
    get_star(alphabet[2]);
    cout << "d (" << alphabet[3] << ") : ";
    get_star(alphabet[3]);
    cout << "e (" << alphabet[4] << ") : ";
    get_star(alphabet[4]);
    cout << "f (" << alphabet[5] << ") : ";
    get_star(alphabet[5]);
    cout << "g (" << alphabet[6] << ") : ";
    get_star(alphabet[6]);
    cout << "h (" << alphabet[7] << ") : ";
    get_star(alphabet[7]);
    cout << "i (" << alphabet[8] << ") : ";
    get_star(alphabet[8]);
    cout << "j (" << alphabet[9] << ") : ";
    get_star(alphabet[9]);
    cout << "k (" << alphabet[10] << ") : ";
    get_star(alphabet[10]);
    cout << "l (" << alphabet[11] << ") : ";
    get_star(alphabet[11]);
    cout << "m (" << alphabet[12] << ") : ";
    get_star(alphabet[12]);
    cout << "n (" << alphabet[13] << ") : ";
    get_star(alphabet[13]);
    cout << "o (" << alphabet[14] << ") : ";
    get_star(alphabet[14]);
    cout << "p (" << alphabet[15] << ") : ";
    get_star(alphabet[15]);
    cout << "q (" << alphabet[16] << ") : ";
    get_star(alphabet[16]);
    cout << "r (" << alphabet[17] << ") : ";
    get_star(alphabet[17]);
    cout << "s (" << alphabet[18] << ") : ";
    get_star(alphabet[18]);
    cout << "t (" << alphabet[19] << ") : ";
    get_star(alphabet[19]);
    cout << "u (" << alphabet[20] << ") : ";
    get_star(alphabet[20]);
    cout << "v (" << alphabet[21] << ") : ";
    get_star(alphabet[21]);
    cout << "w (" << alphabet[22] << ") : ";
    get_star(alphabet[22]);
    cout << "x (" << alphabet[23] << ") : ";
    get_star(alphabet[23]);
    cout << "y (" << alphabet[24] << ") : ";
    get_star(alphabet[24]);
    cout << "z (" << alphabet[25] << ") : ";
    get_star(alphabet[25]);
}

void get_star(int alphabet)
{
    int i;

    for (i = 0; i < alphabet; i++)
        cout << "*";
    cout << endl;
}