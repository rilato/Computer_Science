def bubbleSort(list):
    
    # 크기 = 5
    length = len(list)
    
    for i in range(0, length - 1):
        
        print("")
        print("i : ", i)
        
        swap = False
        
        for j in range(0, length - 1 - i):
            
            print("j : ", j)
            
            if(list[j] > list[j + 1]):
                list [j], list [j + 1] = list [j + 1], list[j]
                swap = True

        if swap == False:
            break

list = [5,1,4,2,8]
bubbleSort(list)
print(list)
