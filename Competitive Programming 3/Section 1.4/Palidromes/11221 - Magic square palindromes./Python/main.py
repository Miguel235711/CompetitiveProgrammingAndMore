from  sys import stdin
import math

sqrtLength = int()
def specialPos(i):
    return sqrtLength * (i%sqrtLength) + i // sqrtLength
def magicPalindrome(s):
    for i1 in range(len(s)):
        i3,i2=len(s)-1-i1,specialPos(i1)
        i4 = specialPos(i3)
        if s[i1]!=s[i2] or s[i1]!=s[i3] or s[i1]!=s[i4]:
            return False
    return True 
def main():
    global sqrtLength
    input()
    for cs,s in enumerate(stdin,1):
        s=s.rstrip()
        s=s.translate({ord(i):None for i in ' +,.?!()'})
        sqrtLength = int(math.sqrt(len(s)))
        print("Case #{}:\n{}".format(cs,sqrtLength if sqrtLength*sqrtLength==len(s)and magicPalindrome(s) else "No magic :("))
main()