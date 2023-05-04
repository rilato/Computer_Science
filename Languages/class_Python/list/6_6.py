# 6번 B735365 이윤식

import random

a = int(input('주사위를 던지는 횟수를 입력하시오 : '))
lst = [0, 0, 0, 0, 0, 0]

for i in range(a):
    n = random.randint(1, 6)
    lst[n-1] += 1       # 리스트의 0번째에 1이 나온 횟수, 1번째에 2가 나온 횟수가 들어가도록 설정

for i in range(6):
    print('주사위가 %d 인 경우는 %d 번' %(i + 1, lst[i]))
