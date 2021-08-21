from sys import stdin

def isPalindrome(s):
    return s == s[::-1]
def reverseAndAdd(s):
    return str(int(s)+int(s[::-1]))

def main():
    input()
    for s in stdin:
        ite = 0
        while(not isPalindrome(s)):
            s = reverseAndAdd(s)
            ite+=1
        print(ite,s)
main()