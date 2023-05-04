def gugudan(n):
    for i in range(1,10):
        print(f'{n} X {i} = {n * i}')
        
def is_odd(a):
    if (a % 2 == 1):
        print("홀수 구구단입니다")
        return
    else:
        print("짝수 구구단입니다")
        return