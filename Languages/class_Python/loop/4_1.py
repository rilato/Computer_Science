# 1번 B735365 이윤식

interest = float(input("이자율 입력하시오? "))
multi = float(input("목표 배율을 입력하시요? "))
a = interest / 100      # 이자율을 소수점으로 나타낸 값을 a로 설정
year = 1

while (1 + a) ** year < multi:  # 원래 복리 공식에서는 원금을 곱하지만, 좌변과 우변에 모두 원금이 포함되어있어서 약분했음
    year += 1   # 좌변이 우변 값보다 작은 경우 연도에 1을 더하고, 좌변이 우변과 같아지거나 커지는 순간 while문 탈출
    
print("이자율이", str(a), "일때 원금의", str(multi), "배가 되기위해", str(year), "년이 걸립니다")
