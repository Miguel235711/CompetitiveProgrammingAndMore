from sys import stdin

def main():
    noFirst = False
    while True:
        try:
            n = int(input())
        except:
            break
        if noFirst:
            print()
        noFirst=True
        gainLoss=[]
        toPosition={}
        #register people
        personNames=input().split()
        for i,personName in enumerate(personNames):
            gainLoss.append(0)
            toPosition[personName]=i
        #simulate
        for _ in range(0,n):
            tk = input().split()
            person,money,numberOfGifts = tk[0],int(tk[1]),int(tk[2])
            evenMoney = money//numberOfGifts if numberOfGifts!=0 else 0
            position = toPosition[person]
            gainLoss[position]+=-evenMoney*numberOfGifts
            for j in range(0,numberOfGifts):
                gainLoss[toPosition[tk[3+j]]]+=evenMoney
        for personName,gainLossI in zip(personNames,gainLoss):
            print(str(personName)+" "+str(gainLossI))
main()