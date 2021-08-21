import random
single={
    'A':'A',
    'AB':'AB',
    'A':'AO',
    'B':'BO',
    'O':'O'
}
plusMinusSingle ={
    '+':'+-',
    '-':'-'
}
def separate(s):
    leftP,rightP = '',''
    if len(s)==2:
        leftP = s[0]
        rightP = s[1]
    else:
        leftP = s[0:2]
        rightP = s[2]
    return (leftP,rightP)
def getSingle(s):
    #return array with options
    separated = separate(s)
    return (single[separated[0]],plusMinusSingle[separated[1]])
transABO={
    'AA':'A',
    'AB':'AB',
    'AO':'A',
    'BB':'B',
    'BO':'B',
    'OO':'O'
}
def transform(abo,rh):
    return transABO[''.join(sorted(abo))]+('+' if rh[0]=='+'or rh[1]=='+' else '-')
def getPossibleChildren(el):
    first,second = getSingle(el[0]),getSingle(el[1])
    children=set()
    for abo1 in first[0]:
        for rh1 in first[1]:
            for abo2 in second[0]:
                for rh2 in second[1]:
                    children.add(transform(abo1+abo2,rh1+rh2))
                    children.add(transform(abo1+abo2,rh2+rh1))
                    children.add(transform(abo2+abo1,rh1+rh2))
                    children.add(transform(abo2+abo1,rh2+rh1))
    return str(children).replace("'","") if len(children) > 1 else random.sample(children,1)[0]
ts=[]
def getPossibleParents(el):
    parents=set()
    for parentProposed in ts:
        if el[1] in getPossibleChildren([el[0],parentProposed]):
            parents.add(parentProposed)
    return str(parents).replace("'","") if len(parents)>1 else random.sample(parents,1)[0] if parents else 'IMPOSSIBLE'
 
def main():

    tsL=['A','AB','A','B','B','O']
    tsR=['+','-']
    global ts
    ts=[ tsl+tsr for tsr in tsR for tsl in tsL]
    cs=1
    while True:
        el=input().split()
        if len(el)==3:
            if el[0]=='E':
                break
            print('Case ',cs,':',sep='',end=' ')
            if el[2][0] == '?':
                #child conversion
                print(el[0],el[1],getPossibleChildren(el[:2]))
            else:
                whichParent= 0 if el[0][0]=='?' else 1 if el[1][0]=='?' else -1
                possibleParents = getPossibleParents([el[1-whichParent],el[2]])
                print(el[0] if whichParent else possibleParents,el[1] if not whichParent else possibleParents,el[2])
            cs+=1
main()