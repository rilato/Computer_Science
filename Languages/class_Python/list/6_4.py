# 4번 B735365 이윤식

def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList3(lst))
    print(lst)

def reverseList3(my_list):
    my_list.reverse()
    my_list.remove(max(my_list))
    return my_list

main()
