
def main():
    letter,morse='',''
    for c in input():
        if c!='.' and c !='-':
            if letter:
                print("'{}':'{}',".format(morse,letter))
                morse=''
            letter=c
        else:
            morse+=c
main()