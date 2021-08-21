from sys import stdin

def main():
    for cs,line in enumerate(stdin,1):
        if(line[0]=='*'):
            break
        print("Case "+str(cs)+": Hajj-e-"+("Akbar" if line[0]=='H' else "Asghar"))
main()