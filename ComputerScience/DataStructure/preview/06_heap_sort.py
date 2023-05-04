# pivot을 기준으로 쪼갬
def heapify(list, n, i):
    
    print("")
    print("heapify")
    print("list:", list, "n:",n, "i:", i)
    
    root_largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    # 왼쪽 애가 존재하고
    # 왼쪽 애가 루트보다 더 클 때
    
    if left < n and list[i] < list[left]:
        
        print("왼쪽 애가 더 큽니다.")
        print("list[i] list[left] :", list[i], list[left])
        root_largest = left
        
    # 오른쪽 애가 존재하고
    # 오른쪽 애가 루트보다 더 클 때
    
    if right < n and list[root_largest] < list[right]:
        
        print("오른쪽 애가 더 큽니다.")
        print("list[root_largest] list[right] :", list[root_largest], list[right])
        root_largest = right
    
    # 왼쪽, 오른쪽 자식들과 바꿔줘야 할 위치를 찾았을 때
    
    if root_largest != i:
        
        print("swap")
        print("list:", list, "n:", n, "root_largest:", root_largest)
        # 찾아낸 값이랑 SWAP 해줌
        list[i], list[root_largest] = list[root_largest], list[i]
        
        # 계속 heap의 형태를 갖출 때까지 실행
        heapify(list, n, root_largest)
        
    print("nothing")

def heapSort(list):
    
    print("heapSort")
    
    n = len(list)
    
    # heap의 형태로 데이터를 정렬
    
    for i in range(n, -1, -1):
        
        print("heapSort heapify")
        heapify(list, n, i)
    
    # root에 있는 애랑, 마지막에 있는 애를 바꿔서 정렬해주고
    # 바뀐 애를 기준으로 다시 heapify를 실행
    for i in range(n-1, 0, -1):
        
        print("heapSort swap")

        list[i], list[0] = list[0], list[i]
        
        heapify(list, i, 0)

    
list = [4, 10, 3, 5, 1]
heapSort(list)
n = len(list)
print("result : ", list)
