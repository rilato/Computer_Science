# 5번 B735365 이윤식

import random
lotteryNumber = random.randint(10, 99)
num = int(input("복권 번호(10-99사이)를 입력하시오: ")) # num은 입력받는 복권 번호를 나타내는 변수

if num == lotteryNumber:    # 숫자 모두 맞았을 때
    print("복권번호는 %d입니다. 상금은 100만원입니다." %lotteryNumber)
elif num // 10 == lotteryNumber // 10 or num % 10 == lotteryNumber % 10: # 숫자 하나만 맞았을 때
    print("복권번호는 %d입니다. 상금은 50만원입니다." %lotteryNumber)
else:           # 틀렸을 때
    print("복권번호는 %d입니다. 상금은 없습니다." %lotteryNumber)
