t,n,solved,problemAntiScore=0,0,[],[]
def calcScore(person):
    score = 0
    for j in range(t):
        if solved[person][j]:
            score += n - problemAntiScore[j]
    return score
def main():
    global t,n,problemAntiScore
    n,t,p=map(int,input().split())
    p-=1
    problemAntiScore,solvedProblems=[0] * t,[0]*n
    for i in range(n):
        row = list(map(int,input().split()))
        solved.append(row)
        for j,number in enumerate(row):
            if number == 1:
                problemAntiScore[j]+=1
                solvedProblems[i]+=1
    philipScore,rank = calcScore(p),1
    for i in range(n):
        if i!=p:
            scoreTemp = calcScore(i)
            if scoreTemp>philipScore or (scoreTemp==philipScore and solvedProblems[i]>solvedProblems[p]) or (scoreTemp==philipScore and solvedProblems[i]==solvedProblems[p] and i<p):
                #i goes before philip
                rank+=1
    print(str(philipScore)+' '+str(rank))
main()