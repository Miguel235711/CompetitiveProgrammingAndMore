#include<iostream>

#define maxV 2000

using namespace std;

int problemAntiscore[maxV],solvedProblems[maxV],n,t,p;
bool solved[maxV][maxV];

int calcScore(int person){
    int score = 0;
    for(int j = 0 ; j < t; j++)
        if(solved[person][j])
            score += n - problemAntiscore[j];
    return score;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> t >> p;
    p--;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < t ; j++){
            cin >> solved[i][j];
            if(solved[i][j]){
                problemAntiscore[j]++;
                solvedProblems[i]++;
            }
        }
    }
    int philipScore = calcScore(p),rank=1;
    for(int i = 0 ; i < n ;i++){
        if(i!=p){
            int scoreTemp = calcScore(i);
            if(scoreTemp>philipScore||(scoreTemp==philipScore&&solvedProblems[i]>solvedProblems[p])||(scoreTemp==philipScore&&solvedProblems[i]==solvedProblems[p]&&i<p))
                //i goes before philip
                rank++;
        }
    }
    cout << philipScore << " " << rank << "\n";
    return 0;
}