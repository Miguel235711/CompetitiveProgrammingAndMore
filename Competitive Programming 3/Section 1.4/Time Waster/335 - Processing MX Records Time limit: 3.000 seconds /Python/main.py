from sys import stdin,maxsize

patternToMachines={}
availableMachies={}

def matches(pattern,page):
    if not pattern:
        return False
    if pattern[0]!='*':
        return pattern==page
    else:
        ##try every substring
        pattern = pattern[2:]
        for i in range(len(page)):
            if page[i]=='.' and page[i+1:]==pattern:
                return True
    return False
def findPage(page):
    ans,minPrior='',maxsize
    for pattern in patternToMachines:
        if matches(pattern,page):
            for tupl in patternToMachines[pattern]:
                if availableMachies[tupl[1]] and tupl[0]<minPrior:
                    minPrior=tupl[0]
                    ans=tupl[1]
    return (' ' if ans else '')+ans
def main():
    n = int(input())
    a,b,prior='','',None
    lastA=''
    global patternToMachines,availableMachies
    for _ in range(n):
        line = input().split()
        if len(line)==3:
            a=line[0]
            prior=int(line[1])
            b=line[2]
        else:
            a=lastA
            prior=int(line[0])
            b=line[1]
        lastA=a
        machinesList = []
        if a in patternToMachines:
            machinesList = patternToMachines[a]
        else:
            patternToMachines[a]=machinesList
        machinesList.append((prior,b))
        availableMachies[b]=True
    for line in stdin:
        if line[0]=='X':
            break
        try:
            command,page = line.split()
        except:
            command=line
            page=''
        if command=='A':
            print(page,' =>',findPage(page),sep='')
        else:
            availableMachies[page]=command=='U'
main()