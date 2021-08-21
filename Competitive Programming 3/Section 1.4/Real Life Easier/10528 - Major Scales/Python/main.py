chromatics=['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A','A#', 'B']
increments=[0,2,2,1,2,2,2,1]
scales=[]

def generateScales():
    chrLen = len(chromatics)
    for i in range(chrLen):
        scaleKey = chromatics[i]
        scale=set()
        j = i
        for inc in increments:
            j=(j+inc)%chrLen
            scale.add(chromatics[j])
        scales.append((scaleKey,scale))
def main():
    generateScales()
    while True:
        line = input()
        if line == 'END':
            return
        line = line.split()
        #print('line:',line)
        notFirst = False
        for scale in scales:
            validKey = True
            for c in line:
                #print(c)
                if c not in scale[1]:
                    validKey = False
                    break
            if validKey:
                if notFirst:
                    print(end=' ')
                else:
                    notFirst = True
                print(end=scale[0])
        print()
main()