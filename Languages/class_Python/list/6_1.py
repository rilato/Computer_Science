# 1번 B735365 이윤식

integers = []
plus = 0
count = 0

while True:         # 양의 정수 입력 받고 integers 리스트에 추가하기
    value = int(input('정수를 입력하세요: '))
    if value >= 0:
        plus += value
        count += 1
        integers.append(value)
    else:
        break
    
average = plus / count      # 입력 받은 양의 정수들의 평균 구하기

count2 = 0
for i in integers:          # 리스트 안에서 평균을 넘는 숫자들의 개수 구하기
    if i > average:
        count2 += 1

print('평균=', average)
print('평균을 상회하는 숫자의 개수=', count2)
