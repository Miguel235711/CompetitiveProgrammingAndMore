correctPlaces,wrongPlaces,guess=0,0,0
def getNumberOfDigits(x):
    i=0
    while x:
        i+=1
        x//=10
    return i
def getOnes(n):
    ans=0
    for _ in range(n):
        ans = ans*10+1
    return ans
def isCorrect(ans):
    correctP,wrongP,inAns=0,0,[0]*10
    guessC,ansC = guess,ans
    while ansC:
        digitA = ansC % 10
        if digitA == guessC % 10:
            correctP+=1
            if correctP > correctPlaces:
                return False
        else:
            inAns[digitA]+=1
        ansC//=10
        guessC//=10
    guessC=guess
    while ans:
        digitG = guessC % 10
        if digitG!=ans%10 and inAns[digitG]:
            wrongP+=1
            if wrongP > wrongPlaces:
                return False
            inAns[digitG]-=1
        ans//=10
        guessC//=10
    return correctP == correctPlaces and wrongP == wrongPlaces
def noZeros(x):
    while x:
        if x % 10 == 0:
            return False
        x//=10
    return True
def main():
    global guess,correctPlaces,wrongPlaces
    for _ in range(int(input())):
        guess,correctPlaces,wrongPlaces=map(int,input().split())
        initial=getOnes(getNumberOfDigits(guess))
        last,ans=initial * 9 + 1,0
        while initial < last:
            if noZeros(initial) and isCorrect(initial):
                ans+=1
            initial+=1
        print(ans)
main()