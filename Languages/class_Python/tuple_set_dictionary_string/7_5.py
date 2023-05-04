# 5번 B735365 이윤식

string = int(input('문자열의 길이를 입력하시오 : '))

possibleCases = 26 ** string
if string % 2 == 0:
    palindrome = int(26 ** (string / 2))
else:
    palindrome = int(26 ** ((string + 1) / 2))

print(f'전체 가능한 소문자 알파벳 문자열 {possibleCases} 개 중 회문의 개수는 {palindrome}개입니다.')
