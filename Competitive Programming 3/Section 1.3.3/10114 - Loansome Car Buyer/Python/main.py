class es:
    def __init__(self, month, percentage):
        self.month = month
        self.percentage = percentage
def main():   
    while(True):
        inTok = input().split()
        months = int(inTok[0])
        if(months<0):
            break
        downPayment,loanAmount,numberOfDepreRecords = float(inTok[1]), float(inTok[2]), int(inTok[3])
        carValue = downPayment + loanAmount
        downPayment = loanAmount / months
        currentMonth = 0 
        records = []
        for _ in range(0,numberOfDepreRecords):
            tk = input().split()
            records.append(es(int(tk[0]),float(tk[1])))
        records.append(es(months+1,0))
        for i in range(1,numberOfDepreRecords+1):
            done = False
            while(currentMonth<records[i].month):
                carValue *= 1 - records[i-1].percentage
                if loanAmount-currentMonth * downPayment < carValue :
                    print(str(currentMonth)+" month"+('s'if currentMonth!=1 else ''))
                    done = True
                    break
                currentMonth+=1
            if done : 
                break
main()