# 3번 B735365 이윤식

def isPrime(n):
    for i in range(2, n):
        if n % i == 0:
            return False    # 소수가 아닌 경우 False 반환
    return True             # 소수인 경우 True 반환

n = int(input('정수 입력하시오: '))
for i in range(2, n + 1):
    if isPrime(i) == True:
        print(i, end = ' ')
