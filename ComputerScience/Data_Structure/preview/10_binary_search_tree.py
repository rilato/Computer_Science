# 노드를 만들어줌
class Node:
    
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        
# 추가하기
def insert(node, val):
    
    # 만약에 root가 비어있을 때
    # node를 root로 만들어줌
    if node is None:
        return Node(val)
    
    # 만약 root의 val 값(트리의 가운데 값)이 val값 보다 클 경우
    if val < node.val :
        # val값을 왼쪽으로 이동
        node.left = insert(node.left, val)
    # 만약 root의 val 값이 val값보다 작을 경우
    else:
        # 오른쪽으로 이동
        node.right = insert(node.right, val)
    
    # root의 값을 리턴
    return node

# 작은 순서대로 출력하는 inorder
def inorder(root):
    
    if root is not None:
        
        inorder(root.left)
        print(root.val)
        inorder(root.right)
        
# 가장 작은 값 출력
def minimum(node):
    
    # 노드가 가장 왼쪽으로 가면 됨
    while (node.left is not None):
        node = node.left
        
    # 가장 왼쪽에 있는 애를 리턴
    return node.val

root = None
root = insert(root, 50)
print(root.val)  # 50
root = insert(root, 30)
print(root.val)  # 50
root = insert(root, 20)
print(root.val)  # 50
root = insert(root, 40)
print(root.val)  # 50
root = insert(root, 70)
print(root.val)  # 50
root = insert(root, 60)
print(root.val)  # 50
root = insert(root, 80)
print(root.val)  # 50

print("")
inorder(root)

print("")
print(minimum(root))

//====================================================

# 노드를 만들어줌
class Node:
    
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        
# 추가하기
def insert(node, val):
    
    # 만약에 root가 비어있을 때
    # node를 root로 만들어줌
    if node is None:
        return Node(val)
    
    # 만약 root의 val 값(트리의 가운데 값)이 val값 보다 클 경우
    if val < node.val :
        # val값을 왼쪽으로 이동
        node.left = insert(node.left, val)
    # 만약 root의 val 값이 val값보다 작을 경우
    else:
        # 오른쪽으로 이동
        node.right = insert(node.right, val)
    
    # root의 값을 리턴
    return node

# 삭제하기(remove, delete)
def remove(root, val):
    
    # 삭제를 해야하는데, 삭제할 위치를 찾아줘야 함
    
    # 만약에 삭제할 값이 root의 값 보다 작을 경우
    if val < root.val:
        # 왼쪽으로 이동
        root.left = remove(root.left, val)
    # 만약에 삭제할 값이 root의 값 보다 클 경우
    elif val > root.val:
        # 오른쪽으로 이동
        root.right = remove(root.right, val)
    # 삭제할 애를 찾아서 작업을 시작해줌
    else:
        # 케이스를 여러가지로 나눠줘야 함
        # 1, 2 자식이 하나이거나 둘일 경우를 처리해줌
        if root.left is None :
            temp_node = root.right
            return temp_node
        elif root.right is None:
            temp_node = root.left
            return temp_node
        
        # 자식 노드가 두 개일 경우도
        # 노드의 오른쪽 편에서 가장 왼쪽 것(가장 작은 값)을 찾음
        
        temp_node = minimum(root.right)
        
        #node의 값을 오른쪽 편에서 가장 작은 애를 넣어주고
        
        root.val = temp_node.val
        
        # temp_node.val에 값을 삭제해줌
        # root의 오른쪽 편에서 가장 왼쪽에 있는 값을 삭제해주면
        # root에 temp_node.val의 값이 들어가고
        # temp_node를 삭제해주면 BST형태가 갖춰짐
        root.right = remove(root.right, temp_node.val)
    
    return root

# 작은 순서대로 출력하는 inorder
def inorder(root):
    
    if root is not None:
        
        inorder(root.left)
        print(root.val)
        inorder(root.right)
        
# 가장 작은 값 출력
def minimum(node):
    
    # 노드가 가장 왼쪽으로 가면 됨
    while (node.left is not None):
        node = node.left
        
    # 가장 왼쪽에 있는 애를 리턴
    return node

root = None
root = insert(root, 50)
print(root.val)  # 50
root = insert(root, 30)
print(root.val)  # 50
root = insert(root, 20)
print(root.val)  # 50
root = insert(root, 40)
print(root.val)  # 50
root = insert(root, 70)
print(root.val)  # 50
root = insert(root, 60)
print(root.val)  # 50
root = insert(root, 80)
print(root.val)  # 50

print("")
root = remove(root, 50)

print("root :", root.val)
