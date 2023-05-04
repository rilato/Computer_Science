# 9번 B735365 이윤식

str1 = str(input('문자열을 입력하시오? '))
str2 = str(input('문자를 입력하시오? '))

end_mark = '$'

count = 0   # 카운트 값 초기화
for ch in str1:
    if ch == end_mark:  # $인 경우 for문 탈출
        break
    elif ch == str2:  # $가 없는 경우, str2와 같은 문자가 나왔을 때 count값에 1을 더
        count += 1

print(count)
