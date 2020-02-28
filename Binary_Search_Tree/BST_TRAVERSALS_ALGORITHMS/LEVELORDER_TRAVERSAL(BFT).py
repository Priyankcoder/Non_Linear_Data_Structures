"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
def levelOrder(root):
    #Write your code here
    q = [root,None]
    while len(q)>1:
        current = q[0]
        q.pop(0)
        if current == None:
            q.append(None)
        else:
            print(current,end = ' ')
            if current.left:
                q.append(current.left)
            if current.right:
                q.append(current.right)
      
         

