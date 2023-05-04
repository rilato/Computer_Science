# 6번 B735365 이윤식

def main():
    value = getRange(0, 23)
    print("OK")

def getRange(low, high):
    a = int(input('숫자를 입력하시오(' + str(low) + '에서 ' + str(high) + '까지 가능) '))
    while True:
        if a > high or a < low:     # 조건에 맞지 않은 경우
            a = int(input('숫자를 입력하시오(' + str(low) + '에서 ' + str(high) + '까지 가능) '))
        else:       # 조건에 맞는 경우
            break

main()
