# 4번 B735365 이윤식

def main():
    x = int(input("10진수: "))
    print(deci2bin(x))
    
def deci2bin(x):
    answer = ''         # 나올 문자열을 미리 초기화
    while x > 0:
        answer = str(x % 2) + answer
        x = x // 2
    return '0b' + answer

main()
