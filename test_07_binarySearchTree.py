#노드생성
class Node :
    def __init__(self,value):
        self.value = value
        self.left=None
        self.right=None

#노드삽입
class BST:
    def __init__(self, root):
        self.root=root

    def insert(self,value):
        self.current_node=self.root
        while True:
            if value < self.current_node.value:
                if self.current_node.left != None:
                    self.current_node=self.current_node.left
                else:
                    self.current_node.left=Node(value)
                    break
            else:
                if self.current_node.right != None:
                    self.current_node=self.current_node.right
                else:
                    self.current_node.right=Node(value)
                    break

#노드 탐색
    def search(self, value):
        self.current_node = self.root
        while self.current_node:
            if self.current_node.value== value:
                return True 
            elif self.current_node.value> value:
                self.current_node=self.current_node.left
            else:
                self.current_node=self.current_node.right
        return False

#노드 삭제
    def delete(self, value):
        #삭제할 노드가 있는지 검사하고 없으면 false
        #검사한 후 삭제할 노드가 current_node, 삭제할 노드의 부모 노드가 parent
        is_search=False
        self.current_node=self.root
        self.parent=self.root
        while self.current_node:
            if self.current_node.value==value:
                is_search=True
                break
            elif value < self.current_node.value:
                self.parent=self.current_node
                self.current_node=self.current_node.left
            else:
                self.parent=self.current_node
                self.current_node=self.current_node.right
        if is_search == False:
            return False


        #삭제할 노드가 자식 노드를 갖고 있찌 않을 때
        if self.current_node.left==None and self.current_node.right==None:
            if value < self.parent.value:
                self.parent.left=None
            else :
                self.parent.right=None
        #삭제할 노드가 자식 노드를 한 개 가지고 있을 때(왼쪽 자식노드)
        if self.current_node.left != None and self.current_node.right==None:
            if value < self.parent.value:
                self.parent.left=self.current_node.left
            else:
                self.parent.right=self.current_node.left

        #삭제할 노드가 자식 노드를 한 개 가지고 있을 때(오른쪽 자식노드)
        if self.current_node.right != None and self.current_node.left==None:
            if value < self.parent.value:
                self.parent.left=self.current_node.right
            else:
                self.parent.right=self.current_node.right

        #삭제할 노드가 자식 노드를 두개 가지고 있을 때
        if self.current_node.left!=None and self.current_node.right!=None:
            self.change_node=self.current_node.right
            self.change_node_parent=self.current_node.right
            while self.change_node.left!=None:
                self.change_node_parent = self.change_node
                self.change_node=self.change_node.left
            if self.change_node.right!=None:
                self.change_node.parent.left=self.change.right
            else:
                self.change_node_let=None

            if value < self.parent.value:
                self.parent.left=self.change_node
                self.change_node.right=self.current_node.right
                self.change_node.left = self.current_node.left

            else:
                self.parent.right=self.change_node
                self.change_node.left=self.current_node.lefe
                self.change_node.right=self.current_node.right
        return True

    def preorder(self,n):
        if n!=None:
            print(n.value,' ', end=' ') #노드방문
            if n.left:
                self.preorder(n.left) #이번엔 왼쪽 서브트리 순회
            if n.right:
                self.preorder(n.right) #오른쪽으로 서브트리 순회

    def inorder(self,n):
        if n!=None:
            if n.left:
                self.inorder(n.left) #이번엔 왼쪽 서브트리 순회
            print(n.value,' ', end=' ') 
            if n.right:
                self.inorder(n.right) #오른쪽으로 서브트리 순회

    def postorder(self,n):
        if n!=None:
            if n.left:
                self.postorder(n.left) #이번엔 왼쪽 서브트리 순회
            if n.right:
                self.postorder(n.right) #오른쪽으로 서브트리 순회
            print(n.value,' ', end=' ') 
                                                         

    def levelorder(self,n):
         q=[]
         q.append(root)
         while q:
            t=q.pop(0)
            print(t.value,' ', end=' ') 
            if t.left!=None:
                q.append(t.left)
            if t. right != None:
                q.append(t.right)
                

                 
arr= [5,2,4,22,10,12,15,60,44,9]
root=Node(30)
bst=BST(root)
for i in arr:
    bst.insert(i)

print(bst.search(22))
print(bst.search(61))
print(bst.search(60))
print(bst.delete(60))
print(bst.search(60))
print(bst.delete(22))
print(bst.delete(44))
print(bst.search(22))
print(bst.search(44))

print("전위순회 :", end=' ')
bst.preorder(bst.root)

print("\n중위순회 :", end=' ')
bst.inorder(bst.root)

print("\n후위순회 :", end=' ')
bst.postorder(bst.root)

print("\n레벨순회 :", end=' ')
bst.levelorder(bst.root)