# 8번 B735365 이윤식

mystring = str(input('문자열을 입력하시오? '))

result = ''     # 문자열 미리 초기화
for ch in mystring:
    result = ch + result

print(result)
