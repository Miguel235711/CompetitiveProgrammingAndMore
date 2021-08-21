from sys import maxsize
from copy import copy

instructions={
    'b':(0,-maxsize),
    'd':(1,0),
    'h':(-maxsize,-maxsize),
    'l':(0,-1),
    'r':(0,1),
    'u':(-1,0)
}

def insert(r,c,screen,x):
    screen[r] = (screen[r][:c]+x+screen[r][c:])[:-1]
def overwrite(r,c,screen,x):
    screen[r] = screen[r][:c]+x+screen[r][c+1:]
def processChar(r,c,screen,x,mode):
    if mode:
        insert(r,c,screen,x)
    else:
        overwrite(r,c,screen,x)
    c +=1
    c = min(9,c)
    return  c
def adjustLim(x):
    x = max(0,x)
    x = min(9,x)
    return x
def main():
    cs=1
    strLimits = '+'+'-'*10+'+'
    initScreen = [' '*10]*10
    while True:
        n = int(input())
        if not n:
            break
        screen=copy(initScreen)
        r,c=0,0
        mode=0
        for _ in range(n):
            line = input()
            last='\0'
            waitForCMoveTo = False
            for ch in line:
                if waitForCMoveTo and str.isdigit(ch):
                    #ch digit
                    c = ord(ch)-ord('0')
                    waitForCMoveTo=False
                elif ch =='^':
                    if last =='^':
                        #write literal ^
                        c=processChar(r,c,screen,'^',mode)
                elif last == '^':
                    #process command
                    if ch in instructions:
                        tupIns = instructions[ch]
                        r+=tupIns[0]
                        c+=tupIns[1]
                        r=adjustLim(r)
                        c=adjustLim(c)
                    if ch == 'c':
                        #clear all screen
                        screen=copy(initScreen)
                    elif ch == 'e':
                        #erase chars to right
                        screen[r] = screen[r][:c]+' '*(10-c)
                    elif ch == 'i':
                        #insert mode
                        mode = 1
                    elif ch == 'o':
                        #overwrite mode
                        mode = 0
                    elif str.isdigit(ch):
                        r = ord(ch)-ord('0')
                        waitForCMoveTo=True
                else:
                    #process char
                    c=processChar(r,c,screen,ch,mode)
                last = ch
        print('Case {}'.format(cs))
        cs+=1
        print(strLimits)
        for row in screen:
            print('|'+row+'|')
        print(strLimits)
main()