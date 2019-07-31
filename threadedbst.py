class Node:
	def __init__(self,key):
		self.left = None
		self.right = None
		self.right1 = None
		self.val = key

def printInorder(root):

	if root:

		printInorder(root.left)
		print(root.val)
		printInorder(root.right)

def printPostorder(root):

	if root:

		printPostorder(root.left)
		printPostorder(root.right)
		print(root.val)

def threadedInordered(root):

	if root:
		print(root.val)
		threadedInordered(root.right1)





root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
#root.left.left.right = root.left #This is the extra threads
#root.left.right.right = root
root.left.left.right1 = root.left
root.left.right1 = root.left.right
root.left.right.right1 = root
root.right1 = root.right

print ("inorder traversal is(recursion)")
printInorder(root)

print ("postorder traversal is")
printPostorder(root)

print("inorder traversal without recursion")
threadedInordered(root.left.left)


