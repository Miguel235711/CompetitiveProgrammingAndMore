from sys import stdin

def main():
    i = 0
    for line in stdin:
        if (i & 1) == 1:
            ans = 0 
            #process numbers
            for number in map(int,line.split()):
                ans += -1 if number == 0 else 1
            print("Case "+ str((i>>1)+1) + ": " + str(ans))
        i+=1
main()