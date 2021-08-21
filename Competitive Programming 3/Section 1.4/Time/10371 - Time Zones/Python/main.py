getUTC={
    'UTC':0,
    'GMT':0,
    'BST':1,
    'IST':1,
    'WET':0,
    'WEST':1,
    'CET':1,
    'CEST':2,
    'EET':2,
    'EEST':3,
    'MSK':3,
    'MSD':4,
    'AST':-4,
    'ADT':-3,
    'NST':-3.5,
    'NDT':-2.5,
    'EST':-5,
    'EDT':-4,
    'CST':-6,
    'CDT':-5,
    'MST':-7,
    'MDT':-6,
    'PST':-8,
    'PDT':-7,
    'HST':-10,
    'AKST':-9,
    'AKDT':-8,
    'AEST':10,
    'AEDT':11,
    'ACST':9.5,
    'ACDT':10.5,
    'AWST':8
}

def parse(time):
    suffix = 'a'
    if time > 720:
        suffix = 'p'
        time -=720
    h,m = time//60,time%60
    return '{}:{:-02} {}.m.'.format((12 if h == 0 else h),m,suffix)

def main():
    for _ in range(int(input())):
        line = input().split()
        nextT=2
        time=0
        if len(line)==3:
            time = 720 if line[0]=='noon' else 0 
            nextT=1
        else:
            #normal
            tks=list(map(int,line[0].split(':')))
            time = tks[0]%12*60+tks[1]+(720 if line[1][0]=='p' else 0)
        #print(time,line[nextT],line[nextT+1])
        ans = int(time+(getUTC[line[nextT+1]]-getUTC[line[nextT]])*60)%1440
        print('midnight' if ans==0 else 'noon' if ans == 720  else parse(ans))
main()