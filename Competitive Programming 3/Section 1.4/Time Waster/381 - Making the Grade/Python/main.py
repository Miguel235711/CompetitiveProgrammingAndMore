def calcLetter(mean,sd,grade):
    return 1 if grade < mean-sd else (4 if mean+sd <= grade else (2 if mean-sd <= grade and grade < mean else 3))  
def adjustLetter(letter,upDown):
    adjustment = min(4,letter+upDown)
    return max(0,adjustment)
def main():
    print('MAKING THE GRADE OUTPUT')
    for _ in range(int(input())):
        s,t=map(int,input().split())
        students=[]
        tCalc=t+(-1 if t > 2 else 0) 
        classAverage=0
        for i in range(s):
            line = input().split()
            acumGrade = 0
            minGrade=101
            for grade in line[:-2]:
                grade = int(grade)
                if minGrade>grade:
                    minGrade=grade
                acumGrade+=grade
            if t>2:
                acumGrade-=minGrade
            absences = int(line[-1])
            students.append([round(acumGrade/tCalc,1),int(line[-2])//2*3, -(absences//4) if absences else 1])
            classAverage+=students[i][0]
        #print(students)
        classAverage = round(classAverage/s,1)
        #print(classAverage)
        #calc std
        sumStd=0
        for student in students:
            sumStd+=(student[0]-classAverage)**2
        sd = max(round((sumStd/s)**0.5,1),1)
        #print('sd',sd)
        #add bonus points to grade and adjusted letter
        avGrP = 0
        for student in students:
            student[0]=min(100,student[0]+student[1])
            letterValue = adjustLetter(calcLetter(classAverage,sd,student[0]),student[2])
            avGrP += letterValue
        print(round(avGrP/s,1))
    print('END OF OUTPUT')
main()