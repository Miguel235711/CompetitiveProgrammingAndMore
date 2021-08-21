from sys import stdin

durations = {
    'W':1,
    'H':0.5,
    'Q':0.25,
    'E':0.125,
    'S':0.0625,
    'T':0.03125,
    'X':0.015625
}

def isRight(s):
    summ = 0
    for c in s:
        summ+=durations[c]
    return summ==1
def main():
    for line in stdin:
        if line[0] == '*':
            break
        ans=0
        for meassure in line.rstrip().split('/'):
            if meassure and isRight(meassure):
                ans+=1
        print(ans)
main()