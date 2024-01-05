class node:
    
    def __init__(self, value):
        self.data=value
        self.left=None
        self.right=None

def insert(root, value):
        if root is None:
            return node(value)

        if(value<root.data):
            root.left=insert(root.left, value)
        else:
            root.right=insert(root.right, value)
        
        return root
    
def inorder(root):
        if(root is None):
            return
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

def preorder(root):
        if(root is None):
            return
        print(root.data, end=" ")
        inorder(root.left)
        inorder(root.right)

def postorder(root):
        if(root is None):
            return
        inorder(root.left)
        inorder(root.right)
        print(root.data, end=" ")

def main():
    root=None
    print("1. Insert \n2. Inorder \n3. Preorder \n4. Postorder \n5. Exit")
    while(True):
        choice=int(input("\nEnter choice: "))
        
        if(choice==1):
             value=int(input("Enter value: "))
             root=insert(root, value)
        
        elif (choice==2):
             print("Inorder: ", end='')
             inorder(root)
             print("\n")
        
        elif(choice==3):
             print("Preorder: ", end='')
             preorder(root)
             print("\n")

        elif(choice==4):
             print("Postorder: ", end='')
             postorder(root)
             print("\n")
        
        elif(choice==5):
             break
        
        else:
             print("\nEnter correct option!!\n")


if(__name__=="__main__"):
    main()