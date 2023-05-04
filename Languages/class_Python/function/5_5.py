# 5번 B735365 이윤식

def main():
    x = int(input("첫 번째 정수: "))
    y = int(input("두 번째 정수: "))
    print(getSorted(x, y))

def getSorted(x, y):
    if x > y:
        x, y = y, x
    return x, y

main()
