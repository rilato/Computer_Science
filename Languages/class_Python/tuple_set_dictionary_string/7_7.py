# 7번 B735365 이윤식

def main():
    mydict = {}
    while True:
        a = input("이름 또는 전화번호? ")
        if a in mydict.keys():
            print("{}의 전화번호는 {}".format(a, mydict[a]))
        elif len(a) == 11:
            for i in mydict.keys():
                if mydict[i] == a:
                    print("전화번호 {} 의 소유주는 {}".format(mydict[i], i))
                else:
                    ("없는 전화번호입니다.")
        elif a == "":
            print("프로그램을 종료합니다.")
            break
        else:
            mydict[a] = input("전화번호? ")
            while mydict[a] == "":
                mydict[a] = input("전화번호? ")
                
main()


my_dict = {}
new_dict = {}

while True:
    a = input('이름 또는 전화번호? ')
    if a == '':
        print('프로그램을 종료합니다')
        break
    else:
        if a in my_dict:
            print(f'{a}의 전화번호는 {my_dict[a]}')
        elif len(a) == 11:
            if a in my_dict.values():
                print(f'전화번호 {a}의 소유주는 {new_dict[b]}')
            else:
                print('없는 전화번호입니다.')
        else:
            while True:
                b = input('전화번호? ')
                if b != '':
                    my_dict[a] = b
                    new_dict[b] = a
                    break
