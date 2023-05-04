# 9번 B735365 이윤식

def main():
    lst = [20, 60, 40, 10, 50]
    print(lst)
    print(sortList(lst))
    
def sortList(lst):
    if len(lst) == 0:
        return []
    else:
        a = max(lst)
        lst.remove(a)
        return sortList(lst) + [a]

main()
