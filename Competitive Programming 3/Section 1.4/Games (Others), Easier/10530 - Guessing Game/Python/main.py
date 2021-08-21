def main():
    while True:
        guesses=[]
        while True:
            guessN=int(input())
            if guessN == 0:
                return
            response=input()[4]
            if response=='t':#print answer
                honest=True
                for el in guesses:
                    if (el[1]=='h'and el[0]<=guessN)or(el[1]=='l'and el[0]>=guessN):
                        honest=False
                        break
                print('Stan '+('may be honest' if honest else 'is dishonest'))
                break
            else:
                guesses.append((guessN,response))
main()