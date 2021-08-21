#include<bits/stdc++.h>
#define limit 10002
#define maxPrime 9999

using namespace std ; 

string dest;

struct st{
    string num;
    int steps;
    st(){}
    st(string num,int steps){
        this->num=num;
        this->steps=steps;
    }
};
std::string::size_type sz;

bool vis[limit],isNoPrime[limit]; //precalculate prime numbers

bool prime(string & num){
    return !isNoPrime[stoi(num,&sz)];
}

int BFS(string & x){
    memset(vis,0,sizeof(vis));
    queue<st> states;
    states.push(st(x,0));
    while(!states.empty()){
        st act = states.front();
        states.pop();
        if(act.num==dest){//number reached
            return act.steps;
        }
        act.steps++;
        //try all adjacent
        for(int i = 0 ; i < 4 ; i ++){
            string newNum = act.num ; 
            for(char c = '0' ; c <= '9' ; c ++){
                if((i!=0 || c!='0')&&c!=act.num[i]){
                    //try with this
                    newNum[i]=c;
                    int newNumVal = stoi(newNum,&sz);
                    if(prime(newNum) && !vis[newNumVal]){
                        vis[newNumVal]=true;
                        states.push(st(newNum,act.steps));
                    }
                }
            }
        }
    }
    return -1 ; 
}

void initializePrimes(){
    isNoPrime[1]=true;
    for(int i = 4 ; i <= maxPrime ; i +=2){
        isNoPrime[i]=true;
    }
    for(int i = 3 ; i <= maxPrime ; i+=2){
        if(!isNoPrime[i]){
            for(int j = i * i ; j <= maxPrime ; j += i){
                isNoPrime[j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    initializePrimes();
    int t ; 
    cin >> t ; 
    string orig; 
    while(t--){
        cin >> orig >> dest;
        int ans  = BFS(orig);
        cout << (ans == -1 ? "Impossible":to_string(ans)) << "\n";
    }
    return 0;
}