# 2번 B735365 이윤식

import random


x = random.randint(1, 100)
y = random.randint(1, 100)

plus = int(input("%d + %d의 값은?" %(x,y)))    # x와 y값의 합을 변수 plus로 설정

while plus != x + y:    # 임의로 입력 받은 x와 y의 합이 plus와 같지 않으면 while문 계속 반복
    print("틀렸습니다.")
    plus = int(input("%d + %d의 값은?" %(x,y)))

print("맞았습니다.")
