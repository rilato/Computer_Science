# Node를 만들어줌

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
# Stack을 만들어줌
class Stack :
    
    # Head를 만들고
    def __init__(self):
        self.head = None
        
    # Stack을 쌓아줌
    def push(self, data):
        
        # Stack이 비어있을 때
        if self.head is None:
            self.head = Node(data)
        
        # Stack이 비어있지 않을 때
        else:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
        
    # Stack에서 빼주는 것들
    def pop(self):
        
        # Stack이 비어있을 때
        if self.head is None:
            return None
            
        # Stack에 데이터가 없을 때
        else:
            popped = self.head.data
            self.head = self.head.next
            return popped
    
    
    
s = Stack()

s.push("a") # ["a"]
s.push("b") # ["a", "b"]
s.push("c") # ["a", "b", "c"]
s.push("d") # ["a", "b", "c", "d"]
s.push("e") # ["a", "b", "c", "d", "e"]

print(s.pop()) # 'e'
print(s.pop()) # 'd'
print(s.pop()) # 'c'
print(s.pop()) # 'b'
print(s.pop()) # 'a'

print(s.pop()) # None
