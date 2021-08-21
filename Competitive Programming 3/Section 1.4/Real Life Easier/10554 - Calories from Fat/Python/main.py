
lim=5
amounts=[[]]*lim
caloryGram = [9,4,4,4,7]

def main():
    while True:
        s = input()
        if s[0]=='-':
            return
        totalCalories,fatCalories = 0.0,0.0
        while s[0]!='-':
            q,caloriesKnown = 100.0,0.0
            s = s.split()
            for i in range(lim):
                lg = len(s[i])
                amounts[i] = [float(s[i][:lg-1]),s[i][lg-1:]]
                if amounts[i][1]=='g':
                    amounts[i][1]='C'
                    amounts[i][0]*=caloryGram[i]
                if amounts[i][1]=='C':
                    caloriesKnown += amounts[i][0]
                else:
                    #percent
                    q -= amounts[i][0]
            caloryPercent = caloriesKnown/q
            for amount in amounts:
                if amount[1] == '%':
                    amount[0] *= caloryPercent
                totalCalories += amount[0]
            fatCalories += amounts[0][0] 
            s = input()
        print(round(fatCalories/totalCalories*100),'%',sep='')   
main()