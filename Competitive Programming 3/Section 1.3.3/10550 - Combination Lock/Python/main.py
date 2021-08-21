from sys import stdin

def difPositions(orig,dest,clockwise):
    if(clockwise):
       orig,dest = dest,orig
    return orig-dest if dest<orig else 40 - dest + orig 

def main():
    for line in stdin:
        init,a,b,c = map(int,line.split())
        if(init!=0 or a!=0 or b!=0 or c!=0): 
            print((difPositions(init,a,False)+difPositions(a,b,True)+difPositions(b,c,False)) * 9 + 1080)
main()