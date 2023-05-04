# 6번 B735365 이윤식

my_dict = {}

while True:
    name = input('이름? ')
    if name == '':
        print('프로그램을 종료합니다')
        break
    else:
        if name in my_dict:
            print(f'{name}의 전화번호는 {my_dict[name]}')
        else:
            while True:
                number = input('전화번호? ')
                if number != '':
                    break
                
    my_dict[name] = number
