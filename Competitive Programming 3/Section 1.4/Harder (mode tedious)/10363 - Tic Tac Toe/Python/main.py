matrix=[[ '\0' for _ in range(3) ] for _ in range(3) ]
movs=[(1,0),(0,1),(-1,0),(0,-1),(-1,-1),(1,1),(1,-1),(-1,1)]

def main():
    n=int(input())
    for c in range(n):
        if c:
            input()
        dif=0
        for i in range(3):
            for ch in input():
                dif += -1 if ch == 'O' else (1 if ch == 'X' else 0)
        print("yes" if -1<dif and dif<2 else "no")
main()