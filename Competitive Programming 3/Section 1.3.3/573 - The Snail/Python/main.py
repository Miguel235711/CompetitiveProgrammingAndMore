def main():
    while True:
        H,U,D,F=map(int,input().split())
        if H == 0:
            return
        pos = 0 
        F = U * F / 100
        day = 0
        while 0<=pos and pos <= H:
            day+=1
            pos += max(0,U) 
            if pos > H:
                break
            pos -= D
            U -= F
        print(("failure" if pos<0 else "success")+" on day "+str(day))
main()