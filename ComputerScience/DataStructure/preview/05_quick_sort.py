# pivot을 기준으로 쪼갬
def splits (list, low, high):

    # pivot 값 정하기
    pivot = list[high]
    
    # i는 pivot을 기준으로
    # list를 정렬해주는 역할
    i = low - 1
    print("")
    print("pivot : ", pivot)
    
    for j in range(low, high) :
        
        if list[j] < pivot:
            
            i = i + 1
            #Swap
            list[i], list[j] = list[j], list[i]
            print("list : ", list)
            
    # 마지막으로
    # pivot이 들어갈 위치를 바꿔줌
    list[i + 1], list[high] = list[high], list[i + 1]
    print("list_after_pivot : ", list)
    
    # pivot의 위치를 return
    return i + 1
    
def quickSort(list, low, high):
    
    # pivot이 알맞은 위치에 있어서
    # quickSort를 실행해줘도 되는지 확인하는 부분
    
    if low < high:
        # pivot 기준으로 쪼개기 위해서, pivot 위치를 가져옴
        pivot_position = splits(list, low, high)
        
        # 그리고 왼쪽과 오른쪽 부분을 쪼갬
        quickSort(list, low, pivot_position - 1)
        quickSort(list, pivot_position + 1, high)
            
    
list = [10, 80, 30, 90, 40, 50, 70]
n = len(list)
quickSort(list, 0, n - 1)
print(list)
