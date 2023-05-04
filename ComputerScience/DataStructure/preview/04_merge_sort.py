def mergeSort(list):
    
    if len(list) > 1:
        
        # 리스트가 완전히 다 쪼개질 때 까지 실행
        mid = len(list) // 2
        
        left = list[:mid]
        right = list[mid:]
        
        # 왼쪽, 오른쪽 부분 쪼개기
        mergeSort(left)
        mergeSort(right)
        
        # 크기 순으로 다시 합치는 과정
        i = 0
        j = 0
        k = 0
        
        # 일단 임시로 정렬
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                list[k] = left[i]
                i += 1
            else:
                list[k] = right[j]
                j += 1
            k += 1
            
        # 정렬 후 남은 애가 있는지 확인
        # 왼쪽에 남은 애들이 있을 때 정렬
        while i < len(left):
            list[k] = left[i]
            i += 1
            k += 1
        
        # 오른쪽에 남은 애들이 있을 때 정렬
        while j < len(right):
            list[k] = right[j]
            j += 1
            k += 1
            
    
list = [38, 27, 43, 3, 9, 82, 10]
mergeSort(list)
print(list)
