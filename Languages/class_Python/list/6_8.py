# 8번 B735365 이윤식

def main():
    lst = [20, 60, 40, 10, 50]
    print(lst)
    print(mySort(lst))
    
def getMax(lst):
    a = max(lst)
    lst.remove(a)
    return a, lst

def mySort(lst):
    my_list = []
    for i in range(len(lst)):   # getMax에서 max값을 my_list에 순차적으로 추가함
        a, lst = getMax(lst)
        my_list.append(a)
    my_list = my_list[::-1]
    return my_list

main()
