# 2번 B735365 이윤식

def main():
    x = int(input("첫 번째 정수: "))
    y = int(input("두 번째 정수: "))
    print(getGCD(x, y))

def getGCD(x, y):       # 유클리드의 호제법을 이용한 풀이
    while y:
        x, y = y, x % y
    return x

main()
