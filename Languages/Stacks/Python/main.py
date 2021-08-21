from queue import LifoQueue
 
myStack = LifoQueue()
 
n = int(input())
 
for _ in range(n):
    i = int(input())
    myStack.put(i)
 
print("Dequeuing elements: ")
print(myStack.qsize())
 
while not myStack.empty():
    print(myStack.get())