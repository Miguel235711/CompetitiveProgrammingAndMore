#include<bits/stdc++.h>

#define mp make_pair 
#define pb push_back 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define SQR(x) ((LL)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define PERMUTE next_permutation
#define fi first 
#define se second

#define MOD 1000000009 //1E9+9

using namespace std;

typedef int64_t i64;

typedef pair<i64,i64> p64;
typedef vector<i64> v64;
typedef vector<p64>  v6464;
typedef vector < v64 > vv64;

typedef double dle;
typedef long double ldle;

typedef pair<int,int> pii; 
typedef vector<int> vi;
typedef vector< pii > vii;
typedef vector< vi > vvi;


typedef pair<string,string> pss;
typedef vector<string> vs;
typedef vector<pss> vss;

typedef pair<int,string> pis;
typedef vector<pis> vis;
typedef pair<string,int> psi;
typedef vector<psi> vsi;

typedef map<string,string> mss;
typedef map<int,string> mis;
typedef map<string,int> msi;

int L,C;
char matrix[48][48];
bool visited[48][48][28]; /// visit with index of word
int ans=0;
int countVisited[48][48];
int movs[4][2]={{1,0},{0,1},{1,1},{1,-1}};
map<string,int> words;

void insertionSortEnd(string & currentSorted){
    for(int i = currentSorted.size()-1; i>0 ; i--){
        if(currentSorted[i]<currentSorted[i-1])
            swap(currentSorted[i],currentSorted[i-1]);
        else
            break;
    }
}
int handleEveryWord(const string & currentSorted){
    auto it = words.find(currentSorted);
    if(it!=words.end()){
        ///found and visit all cells
        return it->second;
    }
    return -1;
        
}

bool insideLimits(int i, int j){
    return  -1 < i && i < L && -1 < j && j < C ;
}

void precalc(){
    //cout << "L: " << L << " C: " << C << "\n";
    for(int i =  0 ; i < L ; i ++){
        for(int j = 0 ; j < C ; j ++){
            //each begin
            for(int m = 0 ; m < 4 ; m ++){
                ///each direction
                string currentSorted;
                for(int cI = i , cJ = j,count = 0;insideLimits(cI,cJ);cI+=movs[m][0],cJ+=movs[m][1],count++){
                    //cout << "cI: " << cI << " cJ: " << cJ << "\n";
                    if(count>15) ///because words are not longer that 15
                        break;
                    currentSorted.push_back(matrix[cI][cJ]);
                    insertionSortEnd(currentSorted);
                    int wordIndex = handleEveryWord(currentSorted);
                    if(wordIndex!=-1){
                        ///visit every cell
                        for(int ii = i, jj = j ; ; ii+=movs[m][0],jj+=movs[m][1]){
                            if(!visited[ii][jj][wordIndex]){
                                visited[ii][jj][wordIndex]=true;
                                countVisited[ii][jj]++;
                                if(countVisited[ii][jj]==2)
                                    ans++;
                            }
                            if(ii == cI && jj == cJ) ///after reaching ends
                                break;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> L >> C ; 
    for(int i = 0 ; i < L ; i ++){
        for(int j = 0 ; j < C ; j ++){
            cin >> matrix[i][j];
        }
    }
    cin >> N ;
    for(int i = 0 ; i < N ; i ++){
        string word;
        cin >> word;
        ///sort word
        sort(word.begin(),word.end());
        words[word]=i;
    }
    precalc();
    cout << ans << "\n";
    return 0;
}