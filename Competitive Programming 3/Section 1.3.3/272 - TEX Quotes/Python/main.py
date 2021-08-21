from sys import stdin

def main():
    time = 0
    for line in stdin:
        #process line
        transLine=""
        for x in line:
            if x=='"' :
                if (time&1)==1:
                    transLine+="''"
                else:
                    transLine+="``"
                time = (time+1) & 1 ; 
            else:
                transLine+=x
        print(transLine,end='')
main()