# 1번 B735365 이윤식

def main():
    score = int(input("점수를 입력하세요: "))
    print("성적은", getGrade(score), "입니다")
    
def getGrade(score):
    if score >= 90:
        return "A"
    elif score >= 80:
        return "B"
    elif score >= 70:
        return "C"
    elif score >= 60:
        return "D"
    else:
        return "F"

main()
