diffs=[0,2,2,1,2,2,2]
#list of dicts
notesN = 12
notes = [['C','C#','D','D#','E','F','F#','G','G#','A','A#','B'],['C','Db','D','Eb','Fb','F','Gb','G','Ab','A','Bb','Cb']]
scales={}
ordinalToN={'OCTAVE':0,'SECOND':1,'THIRD':2,'FOURTH':3,'FIFTH':4,'SIXTH':5,'SEVENTH':6}
def generateScales():
    for i in range(len(notes[0])):
        s = 0 if len(notes[0][i])==1 or notes[0][i][1]!='#' else 1
        j = i
        scale={}
        scalePos=[]
        for c,dif in enumerate(diffs):
            j=(j+dif)%notesN
            chosen = notes[s][j]
            if chosen=='A#' and notes[s][i]=='F':
                chosen='Bb'
            scale[chosen]=c
            scalePos.append(chosen)
        scales[notes[s][i]]=(scale,scalePos)
    #print(scales)
def adjust(x):
    return 7 + x if x < 0 else x%7 
def main():
    generateScales()
    while True:
        scaleKey=None
        try:
            scaleKey=input()
        except:
            return
        print('Key of',scaleKey)
        #scaleKey=scaleKey
        scalePair = scales[scaleKey]
        for query in [ [ tk for tk in query.split()] for query in input().split(';')]:
            print(query[0],':',sep='',end=' ')
            if query[0] not in scalePair[0]:
                print('invalid note for this key')
            else:
                print(query[1],query[2],'>',scalePair[1][adjust((scalePair[0][query[0]]+ordinalToN[query[2]]*(1 if query[1]=='UP' else -1)))])
        print()
main()