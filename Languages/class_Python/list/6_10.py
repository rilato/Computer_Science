# 10번 B735365 이윤식

all_list = []

while True:
    name = input('이름? ')
    if name == '':
        break
    else:
        number = int(input('전화번호? '))
        my_list = [name, str(number)]
        all_list.append(my_list)
        
print('\n전화번호책 :', all_list,'\n')

while True:
    name = input('전화번호 찾고싶은사람의 이름을 입력하세요? ')
    if name == '':
        break
    else:
        for i in range(len(all_list)):
            if all_list[i][0] == name:
                print(name, '의 전화번호는', all_list[i][1], '입니다.')
                break
        else:
            print(name, '는 등록되지 않았습니다')
