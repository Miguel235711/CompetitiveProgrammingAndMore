monthToInt={
    'pop':0, 
    'no':1, 
    'zip':2, 
    'zotz':3, 
    'tzec':4,
    'xul':5,
    'yoxkin':6, 
    'mol':7,
    'chen':8, 
    'yax':9,
    'zac':10, 
    'ceh':11, 
    'mac':12,
    'kankin':13,
    'muan':14,
    'pax':15,
    'koyab':16,
    'cumhu':17,
    'uayet':18
}
s=[
    'imix',
    'ik',
    'akbal',
    'kan',
    'chicchan',
    'cimi',
    'manik',
    'lamat',
    'muluk',
    'ok',
    'chuen',
    'eb',
    'ben',
    'ix',
    'mem',
    'cib',
    'caban',
    'eznab',
    'canac',
    'ahau'
]

#'f d f'
# 0 1 2
#-3 -2 -1
def main():
    t = int(input())
    print(t)
    for _ in range(t):
        line = input().split(' ')
        day = int(line[0][:-1])
        month = monthToInt[line[1]]
        year = int(line[2])
        x = 365*year + 20*month + day
        print(x%13+1,s[x%20],x//260)
main()