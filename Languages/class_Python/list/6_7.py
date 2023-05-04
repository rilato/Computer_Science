# 7번 B735365 이윤식

def main():
    lst = [20, 60, 40, 10, 50]
    m, rlst = getMax(lst)
    print(m)
    print(rlst)
    
def getMax(lst):
    a = max(lst)
    lst.remove(a)
    return a, lst

main()
