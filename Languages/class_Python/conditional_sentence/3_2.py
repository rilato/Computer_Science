# 2번 B735365 이윤식

import random

x = random.randint(0, 100)
y = random.randint(0, 100)

plus = int(input("%d + %d의 값은?" %(x,y))) # plus는 랜덤하게 받은 x와 y의 합을 사용자가 입력하는 변수
if plus == x + y:
    print("맞았습니다.")
else:
    print("틀렸습니다.")
