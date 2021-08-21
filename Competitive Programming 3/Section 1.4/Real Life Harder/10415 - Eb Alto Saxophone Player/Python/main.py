ranges={
    'c':[(2,4),(7,10)],
    'd':[(2,4),(7,9)],
    'e':[(2,4),(7,8)],
    'f':[(2,4),(7,7)],
    'g':[(2,4)],
    'a':[(2,3)],
    'b':[(2,2)],
    'C':[(3,3)],
    'D':[(1,4),(7,9)],
    'E':[(1,4),(7,8)],
    'F':[(1,4),(7,7)],
    'G':[(1,4)],
    'A':[(1,3)],
    'B':[(1,2)]
}
def notContained(i,c):
    if c == '\0':
        return True
    for Range in ranges[c]:
        if Range[0]<=i and i <= Range[1]:
            return False
    return True

def main():
    for _ in range(int(input())):
        last = '\0'
        output=[0]*10
        for c in input():
            for Range in ranges[c]:
                for i in range(Range[0],Range[1]+1):
                    if notContained(i,last):
                        output[i-1]+=1
            last = c
        print(str(output).replace(',','')[1:-1])
        
main()