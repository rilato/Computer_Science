# 2번 B735365 이윤식

def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList(lst))
    print(lst)

def reverseList(my_list):
    new_list = my_list[::-1]
    return new_list

main()
