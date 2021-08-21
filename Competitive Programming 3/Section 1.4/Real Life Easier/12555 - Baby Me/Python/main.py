from sys import stdin

def main():
    t = int(input())+1
    for cs in range(1,t):
        tokens = input().rstrip().split(' ')
        print('Case ',cs,': ','{}'.format(int(tokens[0])/2+(int(tokens[2])/20 if len(tokens)>2 else 0)).rstrip('0').rstrip('.'),sep='')    
main()