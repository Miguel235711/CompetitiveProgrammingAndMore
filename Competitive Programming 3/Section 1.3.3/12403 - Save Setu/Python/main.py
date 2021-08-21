def main():
    t,k = int(input()),0
    for _ in range(0,t):
        lineT = input().split()
        if(lineT[0]=='donate'):
            k+= int(lineT[1])
        else:
            print(k)
main()