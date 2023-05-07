# 코드와 출력 결과를 캡쳐해서 pdf파일로 변환 후 제출

def tree(n):
    if (n == 0 or n == 1):
        return 1
 
    tree = [0] * (n+1)
 
    tree[0] = 1
    tree[1] = 1
 
    for i in range(2, n + 1):
        for j in range(i):
            tree[i] += tree[j] * tree[i-j-1]
 
    return tree[n]

for i in range(100):
    print(tree(i), end="\n")
