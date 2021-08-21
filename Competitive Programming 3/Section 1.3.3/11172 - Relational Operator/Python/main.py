def main():
    t = int(input())
    for _ in range(0,t):
        a,b = map(int,input().split()) 
        print('<' if a<b else ('=' if a==b else '>'))
main()