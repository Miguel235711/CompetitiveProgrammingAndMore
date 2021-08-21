
candidates={}
discarded=set()

def process(s,expected):
    for c in s:
        if c in candidates and candidates[c]!=expected:
            discarded.add(c)
        else:
            candidates[c]=expected
def main():
    for _ in range(int(input())):
        global discarded,candidates
        discarded=set()
        toDiscard=set()
        candidates={}
        alreadyNotEven=False
        for _ in range(3):
            a,b,signal=input().split()
            if signal == 'even':
                #discard
                for c in a+b:
                    discarded.add(c)
            else:
                if signal=='up':
                    a,b=b,a
                # a is for ligther (True) , b is for heavier (False)
                process(a,True)
                process(b,False)
                nextToDiscard=set()
                for c in a+b:
                    nextToDiscard.add(c)
                    if c in toDiscard:
                        toDiscard.remove(c)
                    elif alreadyNotEven:
                        discarded.add(c)
                for c in toDiscard:
                    discarded.add(c)
                toDiscard = nextToDiscard
                alreadyNotEven=True
        for c in candidates:
            if c not in discarded:
                print(c,' is the counterfeit coin and it is ','light' if candidates[c] else 'heavy','.',sep='')
                break
main()