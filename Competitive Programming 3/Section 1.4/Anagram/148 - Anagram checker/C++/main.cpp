#include<bits/stdc++.h>
#define letters 26
#define maxDictSZ 2000

using namespace std;

string dict[maxDictSZ],s;
int sBucket[letters];
int sBucketTotal;
int dictBuckets[maxDictSZ][letters];
int wordsIndexStack[maxDictSZ];
int limS,dictSize;
set<string> originalWords;

bool possible(int currentWord){
    for(int i = 0 ;i < letters ; i++){
        if(sBucket[i]<dictBuckets[currentWord][i])
            return false;
    }
    return true;
}

void substractBucket(int currentWord){
    for(int i = 0 ; i < letters ; i ++)
        sBucket[i] -= dictBuckets[currentWord][i];
}

void addBucket(int currentWord){
    for(int i = 0 ; i < letters ; i ++)
        sBucket[i] += dictBuckets[currentWord][i];
}

void f(int i,int currentWord){
    if(i==sBucketTotal){
        //finished,print posibility        
        auto originalWordsCp = originalWords ;
        for(int i=0;i<limS;i++)
            originalWordsCp.erase(dict[wordsIndexStack[i]]);
        if(!originalWordsCp.empty()){
            cout << s << " =";
            for(int i=0;i<limS;i++)
                cout << " " << dict[wordsIndexStack[i]];
            cout << "\n";
        }
        return;
    }
    if(currentWord==dictSize)
        //possibilities blocked
        return;
    //try taking/not taking if possible
    //taking
    if(possible(currentWord)){
        wordsIndexStack[limS++]=currentWord;
        substractBucket(currentWord);
        f(i+dict[currentWord].size(),currentWord+1);
        addBucket(currentWord);
        limS--;
    }
    //not taking
    f(i,currentWord+1);
}

void fillBucket(int i){
    for(char x: s)
        dictBuckets[i][x-'A']++;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //read dict
    for(;cin>>s&&s[0]!='#';dictSize++){
        fillBucket(dictSize);
        dict[dictSize]=s;
    }
    //read phrases
    cin.ignore();
    while(getline(cin,s)&&s[0]!='#'){ 
        sBucketTotal=0;
        memset(sBucket,0,sizeof(sBucket));
        string currentWord = "";
        originalWords.clear();
        for(auto c : s){
            if(c!=' '){
                currentWord.push_back(c);
                sBucket[c-'A']++;
                sBucketTotal++;
            }else if(!currentWord.empty()){
                originalWords.insert(currentWord);
                currentWord="";
            }
        }
        if(!currentWord.empty())
            originalWords.insert(currentWord);
        f(0,0);
    }
    return 0;
}