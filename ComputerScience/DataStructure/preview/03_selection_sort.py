def selectionSort(list):
    
    for i in range(len(list) - 1):  # selection Sort의 경우 for문 돌리는 횟수는 마지막 것을 돌릴 필요가 없기 때문에 -1
        
        # 가장 작은 값의 위치를 나타내는 min_index
        min_index = i
        
        # 리스트에 있는 값들을 하나하나 훑으면서 가장 작은 값을 찾아줌.
        for j in range(i + 1, len(list)):
            
            if list[min_index] > list[j]:
                
                min_index = j
                
        list[i], list[min_index] = list[min_index], list[i]
            
    
list = [64, 25, 12, 22, 11]
selectionSort(list)
print(list)
