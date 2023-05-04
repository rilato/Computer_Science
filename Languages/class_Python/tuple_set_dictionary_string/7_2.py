# 2번 B735365 이윤식

string = input('문자열을 입력하시오: ')
word = input('문자를 입력하시오: ')

count = 0
for i in string:
    if i == word:
        count += 1

print(f'"{word}" 문자의 빈도는 {count} 이다')
