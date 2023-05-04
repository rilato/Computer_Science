# 10번 B735365 이윤식

def main():
    s = ["aaa", ["bbb", ["ccc", ["ddd", "eee", 45]]]]
    d = mydeepcopy(s)
    
    d[1][1][1][1] = 'xxxxx'
    
    print(d)
    print(s)

def mydeepcopy(s):
    d = s.copy()
    if type(d[1]) in (str,int,float):
        return d
    elif type(d[1]) is list:
        return [d[0]] + [mydeepcopy(d[1])]


main()
