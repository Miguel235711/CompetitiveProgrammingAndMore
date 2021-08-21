def passsedBirthday(d1,m1,d2,m2):
    return m1 > m2 or (m1==m2 and d1 > d2)

def main():
    for cs in range(1,int(input())+1):
        print("Case #",cs,': ',sep='',end='')
        input()
        d1,m1,y1=map(int,input().split('/'))
        d2,m2,y2=map(int,input().split('/'))
        didBirthdayPass = passsedBirthday(d1,m1,d2,m2)
        yearDif = y1 -y2
        if yearDif > 0 or (didBirthdayPass and yearDif==0):
            if not didBirthdayPass and (d1!=d2  or m1!=m2):
                yearDif-=1
            print('Check birth date' if yearDif > 130 else yearDif)
        elif yearDif==0 and d1==d2 and m1 == m2:
            print(0)
        else:
            print('Invalid birth date')
main()