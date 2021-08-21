from sys import stdin

def main():
    totalCs=int(input())
    input()
    for cs in range(totalCs):
        #input() #blank line separating data sets
        #process case
        if(cs):
            print()
        waitingCars,origPos = [],[] # - for final position
        #read waiting positions
        while True:
            waitingPos = int(input())
            if waitingPos == 99:
                break
            waitingCars.append(waitingPos-1)
            origPos.append(waitingPos)
        #process each position
        vacateI=0
        for line in stdin:
            if not len(line.rstrip()):
                #print('vacateI:',vacateI)
                #end  positions vacated, end of dataset
                break
            vPos,minDistance,bestIW = int(line)-1,20,0
            if vacateI < len(waitingCars):
                for i,wPos in enumerate(waitingCars):
                    if waitingCars[i]>-1:
                        distance = vPos - wPos if vPos >= wPos else 20 - wPos + vPos
                        if distance < minDistance:
                            minDistance,bestIW = distance,i
                waitingCars[bestIW]=-(vPos+1)
                for i in range(len(waitingCars)):
                    if waitingCars[i]>-1:
                        #add distance
                        waitingCars[i]=(waitingCars[i]+minDistance)%20
                        #print('waiting cars: ',waitingCars[i])
            vacateI+=1
        for i,oPos in enumerate(origPos):
            print('Original position {} {}'.format(oPos,'did not park' if waitingCars[i]>-1 else 'parked in {}'.format(-waitingCars[i])))
main()