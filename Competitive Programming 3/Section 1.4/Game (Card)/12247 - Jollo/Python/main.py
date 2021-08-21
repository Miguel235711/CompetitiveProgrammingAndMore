def main():
    while True:
        line = input().split()
        if int(line[0]) == 0:
            break
        princess,prince,taken,defeatedMe=[int(tk) for i,tk in enumerate(line) if i < 3],[int(tk) for i,tk in enumerate(line) if i > 2],[False]*52,[False]*3
        for el in line:
            taken[int(el)-1]=True
        princess.sort()
        prince.sort()
        index,lost=0,0
        for princeElement in prince:
            while index<3 and princess[index] < princeElement:
                index+=1
            if index < 3:
                defeatedMe[index]=True
                index+=1
                lost+=1
        ans = -1
        if lost==0:
            #smallest not taken card
            for i,tk in enumerate(taken):
                if not tk:
                    ans = i + 1
                    break
        elif lost==1:
            for i in range(2,-1,-1):
                if not defeatedMe[i]:
                    ans = princess[i]+1
                    while ans<=52 and taken[ans-1]:
                        ans+=1
                    if ans>52:
                        ans = -1
                    break
        print(ans)
main()