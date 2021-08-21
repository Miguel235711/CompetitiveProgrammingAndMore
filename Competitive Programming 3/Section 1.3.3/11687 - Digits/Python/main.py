from sys import stdin

def countDigits(number):
    ans = 0 
    while(number):
        ans+=1
        number//=10
    return ans
def countUntil1(number):
    ans = 0
    while number!=1:
        ans+=1
        number = countDigits(number)
    print(ans+2)

def main():
    for line in stdin:
        if line[0]=='E':
            break
        if line[0]=='1' and len(line.rstrip())==1:
            print(1)
        else:
            countUntil1(len(line.rstrip()))
main()