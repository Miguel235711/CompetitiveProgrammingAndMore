from sys import stdin
import math

def main():
    song=["Happy","birthday","to","you"]
    people=[]
    n=int(input())
    for line in stdin:
        people.append(line.rstrip())
    lines = math.ceil(float(n)/16)*16
    for moment in range(0,lines):
        print(people[moment%n]+": "+(song[moment%4] if moment%16!=11 else "Rujia"))
main()