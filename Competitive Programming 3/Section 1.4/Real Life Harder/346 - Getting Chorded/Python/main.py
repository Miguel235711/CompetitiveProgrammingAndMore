from sys import stdin

def getBefore(x):
    if x=='A':
        return 'G'
    return chr(ord(x)-1)

position={'A':0,'A#':1,'B':2,'C':3,'C#':4,'D':5,'D#':6,'E':7,'F':8,'F#':9,'G':10,'G#':11}
outputs=['Major chord','Minor chord','unrecognized']

def convert(s):
    s=str.upper(s)
    if len(s)==2 and s[1]=='B':
        s = getBefore(s[0])+'#'
    return s

def calcDif(a,b):
    return a-b if a >= b else 12-b+a
def main():
    for line in stdin:
        line=line.rstrip()
        splitted = line.split()
        notes=list(map(convert,splitted))
        notes.sort()
        #for each beginining
        finalVerdict = ('',2)
        for i in range(3):
            lastPos = position[notes[i]] if notes[i] in position else -1
            diffs=[]
            for j in range(1,3):
                note = notes[(i+j)%3]
                diffs.append(calcDif(position[note],lastPos))
                lastPos = position[note]
            verdict = 0 if diffs[0]==4 and diffs[1]==3 else ( 1 if diffs[0]==3 and diffs[1]==4 else 2 )
            if verdict !=2:
                finalVerdict=(notes[i],verdict)
                break
        for note in splitted:
            print(note+' ',end='')
        print('is ',('a '+finalVerdict[0]+' ') if finalVerdict[0]!='' else '',outputs[finalVerdict[1]],'.',sep='')
        
main()