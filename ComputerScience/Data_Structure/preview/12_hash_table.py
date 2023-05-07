# Hash table 만들기
hash_table = [[] for _ in range(10)]
print(hash_table)
# Output:
# [[], [], [], [], [], [], [], [], [], []]

# 삽입
def insert(hash_table, key, value):
    # Key값
    hash_key = key % len(hash_table)
    
    # 중복확인을 위한 애
    key_exists = False
    bucket = hash_table[hash_key]
    
    # bucket 안에 여러개가 들어있으면 반복문으로 돌리면서 확인
    for i, kv in enumerate(bucket):
        # kv(key, value)
        k, v = kv
        if key == k:
            # 중복을 확인했다면 if else중 if로 가기
            key_exists = True
            break
    # 중복되는 것이 있을 때
    if key_exists:
        bucket[i] = ((key, value))
    # 중복되는 것이 없으면 그냥 넣으면 됨
    else:
        bucket.append((key, value))
        
insert(hash_table, 10000000, '민수')
insert(hash_table, 10000005, '철수')
insert(hash_table, 20000000, '민지')
# Output :
# [[(10000000, '민수'), (20000000, '민지')], [], [], [], [], [(10000005, '철수')], [], [], [], []]
insert(hash_table, 20000000, '민지')
# Output :
# [[(10000000, '민수'), (20000000, '민지')], [], [], [], [], [(10000005, '철수')], [], [], [], []]
print(hash_table)
