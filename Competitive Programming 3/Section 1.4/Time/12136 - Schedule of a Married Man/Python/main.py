def convert(a):
    return a[0]*60 + a[1]
def parse(a):
    return convert(list(map(int,a.split(':'))))

def main():
    for cs in range(1,int(input())+1):
        el=[]
        for _ in range(2):
            be=input().split()
            el.append(be)
            be[0] = parse(be[0])
            be[1] = parse(be[1])
        print('Case '+str(cs)+': '+('Hits' if el[0][1]<el[1][0] or el[0][0] > el[1][1] else 'Mrs')+' Meeting')
main()