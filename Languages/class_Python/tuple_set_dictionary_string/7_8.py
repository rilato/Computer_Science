# 8번 B735365 이윤식

my_dict = {}

while True:
    name = input('이름? ')
    if name == '':
        break
    elif name not in my_dict:
        while True:
            number = input('전화번호? ')
            if number != '':
                my_dict[name] = []
                my_dict[name].append(number)
                break
    elif name in my_dict:
        while True:
            number = input('전화번호? ')
            if number != '':
                my_dict[name].append(number)
                break

my_set = set()
for i in my_dict.values():
    for j in i:
        my_set.add(j)
        
print(f'중복되지 않는 사람 수 : {len(my_dict.keys())}')
print(f'중복되지 않는 전화번호 수 : {len(my_set)}')

while True:
    find = input('찾고싶은 사람의 이름 또는 전화번호를 입력하세요? ')
    if find == '':
        print('프로그램을 종료합니다')
        break
    elif find in my_dict.keys():
        for key in my_dict[find]:
            print(key, end = ' ')
    elif find[0] == '0':
        cnt = 0
        for keys, values in my_dict.items():
            for val in values:
                if val == find:
                    cnt += 1
                    print(keys, end = ' ') 
                    break
        if cnt == 0:
            print(f'{find}는 등록되지 않았습니다')
    else:
        print(f'{find}는 등록되지 않았습니다')
