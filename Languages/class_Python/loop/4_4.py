# 4번 B735365 이윤식

x = int(input("첫번째 정수: "))
y = int(input("첫번째 정수: "))

small = min(x, y)   # 두 수중 작은 수 추출

for i in range(small, 0, -1):       # small값 부터 1씩 작아지면서, x와 y로 동시에 나누어지는 i가 나오는 순간 for문 탈출
    if x % i == 0 and y % i == 0:
        print(i)
        break
