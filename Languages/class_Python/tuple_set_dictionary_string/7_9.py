# 9번 B735365 이윤식

my_dict = {}

while True:
    name = input('이름? ')
    if name == '':
        break
    elif name not in my_dict:
        number = input('전화번호? ')
        my_dict[name] = []
        my_dict[name].append(number)
    elif name in my_dict:
        number = input('전화번호? ')
        my_dict[name].append(number)

my_set = set()
for i in my_dict.values():
    for j in i:
        my_set.add(j)
        
print(f'중복되지 않는 사람 수 : {len(my_dict.keys())}')
print(f'중복되지 않는 전화번호 수 : {len(my_set)}')

while True:
    delete = input('지우고 싶은 사람의 이름 또는 전화번호를 입력하세요? ')
    if delete == '':
        print('검색모드로 넘어갑니다')
        break
    elif delete[0] == '0':
        chk = 0
        for key, values in my_dict.copy().items():
            cnt = 0
            for i in range(len(values)):
                if my_dict[key][cnt] == delete:
                    del my_dict[key][cnt]
                    cnt = 0
                    chk += 1
                else:
                    cnt += 1
            if my_dict[key] == []:
                del my_dict[key]
        if chk == 0:
            continue
        else:
            num = set()
            for a in my_dict.values():
                for item in a:
                    num.add(item)
            print("중복되지 않는 전화번호 수 : ", len(num))
            for i in num:
                print(i, end = " ")
    elif delete[0] != '0':
        chk = 0
        my_set = set()
        for i in my_dict.copy().keys():
            if i == delete:
                chk += 1
                my_dict.pop(i)
                for i in my_dict.copy().keys():
                    my_set.add(i)
        if chk == 0:
            continue
        else:
            print(f'중복되지 않는 사람의 수 : {len(my_dict)}')
            for j in my_set:
                print(j, end = ' ')

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
        print(f'{find}은 등록되지 않았습니다')
