from sys import stdin

def leap(y):
    return y%4==0 and (y%100!=0 or y%400==0)

def main():
    for i,line in enumerate(stdin):
        if i:
            print()
        preffix='This is '
        suffix=' year.'
        y = int(line)
        isLeap = leap(y)
        entered=False
        if isLeap:
            print(preffix+'leap'+suffix)
            entered=True
        if y%15==0:
            print(preffix+'huluculu festival'+suffix)
            entered=True
        if y%55==0 and isLeap:
            print(preffix+'bulukulu festival'+suffix)
            entered=True
        if not entered:
            print(preffix+'an ordinary'+suffix)
main()