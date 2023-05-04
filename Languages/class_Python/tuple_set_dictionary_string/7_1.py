# 1번 B735365 이윤식

birth = input('생년월일을 입력하시오: ')

days31_month = [1,3,5,7,8,10,12]
days30_month = [4,6,9,11]

year = int(birth[:4])
month = int(birth[4:6])
day = int(birth[6:])

if len(birth) != 8:
    print('올바른 생년월일이 아닙니다.')
else:
    if ((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0):
        if month == 2 and 1 <= day <= 29:
            print('올바른 생년월일입니다.')
        elif month in days31_month and 1 <= day <= 31:
            print('올바른 생년월일입니다.')
        elif month in days30_month and 1 <= day <= 30:
            print('올바른 생년월일입니다.')
        else:
            print('올바른 생년월일이 아닙니다.')
    else:
        if month == 2 and 1 <= day <= 28:
            print('올바른 생년월일입니다.')
        elif month in days31_month and 1 <= day <= 31:
            print('올바른 생년월일입니다.')
        elif month in days30_month and 1 <= day <= 30:
            print('올바른 생년월일입니다.')
        else:
            print('올바른 생년월일이 아닙니다.')
