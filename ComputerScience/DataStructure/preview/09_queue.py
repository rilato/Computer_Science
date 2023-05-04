# Node 생성

class Node :
    
    def __init__(self, data):
        self.data = data
        self.next = None
    
# Queue 만들기

class Queue:
    
    def __init__(self):
        self.head = None
        self.tail = None
        
    # 비어 있는지 확인하는 isEmpty
    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False
    
    # euqueue (Add)
    def enqueue(self, data):
        
        # queue가 비어있을 때
        if self.tail is None:
            self.head = self.tail = Node(data)
            
        # queue가 비어있지 않을 때
        else:
            # 새로운 node를 생성해서 뒤에 붙이고
            self.tail.next = Node(data)
            # tail의 위치를 조정해줌
            self.tail = self.tail.next
            
    # dequeue (Remove)
    def dequeue(self):
        
        # queue가 비어있을 때
        if self.head is None:
            return None

        # queue가 비어있지 않을 때
        else:
            dequeue_data = self.head.data
            self.head = self.head.next
            return dequeue_data
        
q = Queue()

q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)

print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
print(q.isEmpty())
print(q.dequeue())
print(q.isEmpty())
