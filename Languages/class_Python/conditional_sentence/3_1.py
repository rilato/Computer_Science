# 1번 B735365 이윤식

nation = input("국가를 입력하시오: ") # nation은 입력받는 국가

if nation != "한국":
    print ("배송료는 20000원입니다.")
else:
    region = input("도를 입력하시오: ") # region은 입력받는 도
    if region == "제주도":
        print("배송료는 10000원입니다.")
    else:
        print("배송료는 5000원입니다.")
