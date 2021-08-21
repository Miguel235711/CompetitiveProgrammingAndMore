from sys import stdin

def main():
    input()
    for cs,line in enumerate(stdin,1):
        byteArray = [0] * 100
        pointer = 0
        for c in line:
            if c == '>':
                pointer=(pointer+1)%100
            elif c == '<':
                pointer-=1
                if(pointer<0):
                    pointer=99
            elif c == '+':
                byteArray[pointer]=(byteArray[pointer]+1)%256
            elif c == '-':
                byteArray[pointer]-=1
                if byteArray[pointer]<0:
                    byteArray[pointer]=255
        print('Case '+str(cs)+':',end='')
        for num in byteArray:
            print(' '+'{:02X}'.format(num),end='')
        print()
main()