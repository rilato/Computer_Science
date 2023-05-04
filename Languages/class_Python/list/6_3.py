# 3번 B735365 이윤식

def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList2(lst))
    print(lst)

def reverseList2(my_list):
    new_list = my_list[::-1]
    a = max(my_list)
    new_list.remove(a)
    return new_list

main()
