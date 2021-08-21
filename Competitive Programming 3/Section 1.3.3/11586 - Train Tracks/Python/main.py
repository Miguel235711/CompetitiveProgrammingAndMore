def main():
    cases = int(input())
    for _ in range(0,cases):
        FFs,MMs=0,0
        tks = input().split()
        for piece in tks:
            if piece == 'FF':
                FFs+=1
            elif piece == 'MM':
                MMs+=1
        print('NO LOOP' if len(tks)==1 or abs(FFs-MMs)>0 else 'LOOP')
main()