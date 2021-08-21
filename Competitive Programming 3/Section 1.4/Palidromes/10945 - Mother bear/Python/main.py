puntuaction = {'.',',','!','?',' '}
def palindrome(s):
    i,j=0,len(s)-1
    while i < j:
        #ignore puntuactions
        while i<j and s[i] in puntuaction:
            i+=1
        while i<j and s[j] in puntuaction:
            j-=1
        #check if equivalent (ignoring casing)
        if i<j and s[i].lower()!=s[j].lower():
            return False
        i+=1
        j-=1
    return True
def main():
    while True:
        s = input()
        if s == "DONE":
            break
        print("You won't be eaten!" if palindrome(s) else "Uh oh..")
main()