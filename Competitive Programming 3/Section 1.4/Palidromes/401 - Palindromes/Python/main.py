from sys import stdin
from copy import copy

ans=[("is not a palindrome","is a mirrored string"),("is a regular palindrome","is a mirrored palindrome")]
reverse={
    'A':'A',
    'E':'3',
    'H':'H',
    'I':'I',
    'J':'L',
    'L':'J',
    'M':'M',
    'O':'O',
    'S':'2',
    'T':'T',
    'U':'U',
    'V':'V',
    'W':'W',
    'X':'X',
    'Y':'Y',
    'Z':'5',
    '1':'1',
    '2':'S',
    '3':'E',
    '5':'Z',
    '8':'8'
}
def getPalindromeValue(s):
    lim = len(s) >> 1
    for i in range(lim):
        if s[i]!=s[len(s)-1-i]:
            return 0
    return 1
def getMirroredString(s):
    sChars = list(s)
    for i in range(len(sChars)):
        if s[i] in reverse:
            sChars[i]=reverse[s[i]]
        else:
            return None
    return ''.join(sChars)
def getMirroredPalindromeValue(s):
    mirroredString = getMirroredString(s)
    if not mirroredString:
        return 0
    #compared if mirroredString backwards is the same as s
    for i in range(len(s)):
        if s[i]!=mirroredString[len(s)-1-i]:
            return 0
    return 1
def main():
    for s in stdin:
        s=s.rstrip()
        isPalindrome,isMirrored = getPalindromeValue(s),getMirroredPalindromeValue(s)
        print("{} -- {}.\n".format(s,ans[isPalindrome][isMirrored]))
main()