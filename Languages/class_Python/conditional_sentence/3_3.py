# 3번 B735365 이윤식

weight = float(input("무게(킬로그램): ")) # weight는 사용자의 몸무게를 측정하는 변수
height = float(input("키(미터): ")) # height는 사용자의 키를 측정하는 변수
BMI = weight / (height ** 2)
print("당신의 BMI: %f" %BMI)
if BMI >= 30:
    print("비만입니다.")
elif BMI >= 25:
    print("과체중입니다.")
elif BMI >= 20:
    print("정상입니다.")
