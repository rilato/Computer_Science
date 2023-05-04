# 6번 B735365 이윤식

import random

plus = int(input("원하는 두 주사위의 합을 입력하시오? "))

while True:
    x = random.randint(0, 6)
    y = random.randint(0, 6)
    print("첫번째 주사위= %d 두번째 주사위= %d 합 = %d" %(x, y, x + y))
    if x+y == plus:     # 랜덤하게 나온 두 값과 내가 입력한 plus값이 같으면 while문 탈출
        print("원하는 합이 나왔습니다. 합 = %d" %plus)
        break
