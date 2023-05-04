# 5번 B735365 이윤식

N = int(input("3보다 큰 홀수를 입력하시오? "))
plus = 0    #  합계를 미리 초기화

for i in range(1, N-1, 2):
    plus += i / (i + 2)

print(plus)
