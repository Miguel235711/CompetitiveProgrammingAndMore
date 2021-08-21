#include<bits/stdc++.h>
#define nodesLim 502
using namespace std ; 

int n;


map<string,int>mapToInt;
string mapToString[nodesLim];
int floyd[nodesLim][nodesLim],nextJumpFloyd[nodesLim][nodesLim];

bool process(int fileNameId,const string & statement){
    string currentFileName = "";
    for(int i = 7 ; i < statement.size(); i ++){
        if(statement[i]!=' ' && statement[i]!=','){
            currentFileName.push_back(statement[i]);
        }else{
            //separator
            if(!currentFileName.empty()){
                //push currentFileName
                if(mapToInt[currentFileName] == fileNameId){
                    return true;
                }
                floyd[fileNameId][mapToInt[currentFileName]]=1;
                nextJumpFloyd[fileNameId][mapToInt[currentFileName]]=mapToInt[currentFileName];
                currentFileName ="";
            }
        }
    }
    if(!currentFileName.empty()){
        //push currentFileName
        if(mapToInt[currentFileName] == fileNameId){
            return true;
        }
        floyd[fileNameId][mapToInt[currentFileName]]=1;
        nextJumpFloyd[fileNameId][mapToInt[currentFileName]]=mapToInt[currentFileName];
    }
    return false;
}
int bestBeg,bestEnd,minArrival=INT_MAX;

void printCycle(){
    int node = bestBeg;
    for(; node!=bestEnd; node = nextJumpFloyd[node][bestEnd]){
        cout << mapToString[node] << " ";
    }
    cout << mapToString[node] ;
}

void calcFloyd(){
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            if(i==j){
                floyd[i][i]=0;
                nextJumpFloyd[i][i]=i;
            }else if(!floyd[i][j]){
                floyd[i][j]=nodesLim;
            }
        }
    }
    for(int aux = 1 ; aux <= n ; aux ++){
        for(int orig = 1 ; orig <= n ; orig++){
            for(int dest = 1 ; dest <= n ; dest ++){
                if(floyd[orig][aux] + floyd[aux][dest] < floyd[orig][dest]){
                    floyd[orig][dest]=floyd[orig][aux]+floyd[aux][dest];
                    nextJumpFloyd[orig][dest]=nextJumpFloyd[orig][aux];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string fileName;
    cin >> n ; 
    for(int i = 1 ; i <= n ; i ++){
        cin >> fileName ; 
        mapToInt[fileName]=i;
        mapToString[i]=fileName;
    }
    for(int i = 1 ; i <= n ; i ++){
        int k ; 
        cin >> fileName >> k ; 
        cin.ignore();
        int fileNameId = mapToInt[fileName];
        string statement;
        while(k--){
            //cout << "reading import:\n";
            getline(cin,statement); // read import statement
            //cout << "currentStament:  " << statement << "\n";
            if(process(fileNameId,statement)){
                //cycle of 1
                cout << fileName << "\n";
                return 0 ;
            }
        }
    }
    calcFloyd();
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++){
            if(floyd[i][j]!=nodesLim&& floyd[j][i]==1 && floyd[i][j]<minArrival){//does not work for cycle of 1
                //cycle
                minArrival = floyd[i][j] , bestBeg = i, bestEnd = j ;  
            }
        }
    }
    if(!bestBeg){
        cout << "SHIP IT";
    }else{
        printCycle();
    }
    cout << "\n";

    return 0;
}