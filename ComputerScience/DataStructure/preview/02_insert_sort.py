def insertSort(list):
    
    for i in range(1, len(list)):   #0부터 시작하지 않는 이유는, 첫번째 것은 비교하지 않기 때문.
        
        key = list[i]   #비교를 위해 선택하는 숫자를 키 값으로 설정
        
        j = i - 1

        while j >= 0 and key < list[j]: #키 값과 앞에있는 값들을 비교하며 앞의 숫자가 작을 경우 뒤로 한 칸씩 밀어냄.
            
            list[j + 1] = list[j]
            
            j -= 1
            
        list[j + 1] = key
    
list = [12, 11, 13, 5, 6]
insertSort(list)
print(list)
