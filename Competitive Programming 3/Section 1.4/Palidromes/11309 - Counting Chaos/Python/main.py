def toInteger(h,m):
    return h*60 + m
def toSingleString(x):
    return ('0' if x<10 else '') + str(x)
def toString(h,m):
    return toSingleString(h)+toSingleString(m)
def toFString(h,m):
    return toSingleString(h)+':'+toSingleString(m)
def isPalindrome(h,m):
    s = toString(h,m)
    if s[0]=='0':
        s = s[next((i for i,val in enumerate(s)  if val!='0'),len(s)):]
    for i in range(len(s) >> 1):
        if s[i]!=s[len(s)-1-i]:
            return False
    return True
def main():
    nextPal = [''] * 1440
    nextP = '00:00'
    for h in range(23,-1,-1):
        for m in range(59,-1,-1):
            #print('what: ',h,m)
            nextPal[toInteger(h,m)]=nextP
            if isPalindrome(h,m):
                nextP=toFString(h,m)
    for _ in range(int(input())):
        s = input()
        h,m = [ int(s[i-1:i+1]) for i in range(1,len(s),3) ]
        print(nextPal[toInteger(h,m)])

main()