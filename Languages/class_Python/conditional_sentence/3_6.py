# 6번 B735365 이윤식

num1 = int(input("숫자 1: ")) # num_1부터 num_3까지는 모두 입력받는 숫자
num2 = int(input("숫자 2: "))
num3 = int(input("숫자 3: "))
print("중간값은", num1 + num2 + num3 - max(num1, num2, num3) - min(num1, num2, num3))
