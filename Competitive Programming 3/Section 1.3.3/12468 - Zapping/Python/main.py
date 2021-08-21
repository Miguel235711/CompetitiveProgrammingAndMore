def main():
    while True:
        a,b=map(int,input().split())
        if a==-1:
            break
        if b > a :
            a,b=b,a 
        print(min(a-b,100-a+b))
main()