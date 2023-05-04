def num_list():
    mylist = []
    for i in range (0,3):
        num = int(input("숫자를 입력하세요:"))
        mylist.append(num)
    return mylist

def myfunc(my_list):
    myList = []
    for i in my_list:
        if i > 7:
            myList.append(i)
    return myList