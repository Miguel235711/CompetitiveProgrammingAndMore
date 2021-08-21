def main():
    cs=1
    while True:
        N = int(input())
        if not N:
            break
        print('Game '+str(cs)+':')
        s = list(map(int,input().split()))
        while True:
            g = list(map(int,input().split()))
            if not g[0]:
                break
            strong,weak=0,0
            numbersInS = {}
            for i in range(N):
                if s[i] == g[i]:
                    strong+=1
                else: 
                    if s[i] in numbersInS:
                        numbersInS[s[i]]+=1
                    else:
                        numbersInS[s[i]]=1
            for i in range(N):
                if s[i] != g[i] and g[i] in numbersInS:
                    weak+=1
                    if numbersInS[g[i]]==1:
                        del numbersInS[g[i]]
                    else:
                        numbersInS[g[i]]-=1
            print('    ('+str(strong)+','+str(weak)+')')
        cs+=1
main()