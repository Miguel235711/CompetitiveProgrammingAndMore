from queue import *
from heapq import heapify,heappush,heappop 

def main():
    n,m = map(int,input().split())
    costPerKilo,available,weight,slotTaken=[],[],[],[0]*m
    heapify(available)
    cost=0
    waitingLine = Queue()
    for i in range(0,n):
        costPerKilo.append(int(input()))
        heappush(available,i)
    for i in range(0,m):
        weight.append(int(input()))
    for i in range(0,m<<1):
        car = int(input())
        if car < 0:
            heappush(available,slotTaken[abs(car)-1])
        else:
            waitingLine.put(car-1)
        while available and not waitingLine.empty():
            slot = heappop(available)
            carRemoved = waitingLine.get()
            cost += costPerKilo[slot] * weight[carRemoved]
            slotTaken[carRemoved] = slot
    print(cost)
main()