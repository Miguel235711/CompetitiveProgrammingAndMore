def main():
    while True:
        a,b=map(int,input().split())
        if a==0 and b == 0:
            break
        pointer,amountA,amountB=0,0,0
        nums=input().split()
        aArr=[int(tk) for i,tk in enumerate(nums) if tk!=nums[i-1]]
        last=0
        bArr=map(int,input().split())
        for x in bArr:
            if x != last:
                while pointer<len(aArr) and aArr[pointer] < x:
                    pointer+=1
                    amountA+=1
                if pointer == len(aArr) or aArr[pointer] !=x:
                    amountB+=1
                if pointer < len(aArr) and aArr[pointer] == x:
                    pointer+=1
                last = x
        while pointer < len(aArr):
            pointer+=1
            amountA+=1
        print(min(amountA,amountB))
main()