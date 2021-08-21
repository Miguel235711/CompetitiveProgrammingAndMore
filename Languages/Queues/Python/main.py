from queue import Queue
#import Queue
 
myQueue = Queue()
 
n = int(input())
 
for _ in range(n):
    i = int(input())
    myQueue.put(i)
 
print("Dequeuing elements: ")
print(myQueue.qsize())
 
while not myQueue.empty():
    print(myQueue.get())