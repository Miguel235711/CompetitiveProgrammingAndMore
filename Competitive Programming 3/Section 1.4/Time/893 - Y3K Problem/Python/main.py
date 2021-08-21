from calendar import calendar

def main():
    while 1:
        delta,d,m,y = map(int,input().split())
        if delta==0:
            break
        ans=calendar(y,m,d)+tim(days=delta)
        print(ans.day,ans.month,ans.year)
main()