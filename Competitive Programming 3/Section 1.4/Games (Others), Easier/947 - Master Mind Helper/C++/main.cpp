#include<bits/stdc++.h>

using namespace std;

int correctPlaces=0,wrongPlaces=0,guess=0,inAns[10],t;
int getNumberOfDigits(int x){
    int i=0;
    for(;x;x/=10,i++);
    return i;
}
int getOnes(int n){
    int ans=0;
    for(int i=0;i<n;i++,ans=ans*10+1);
    return ans;
}
bool isCorrect(int ans){
    int correctP=0,wrongP=0;
    memset(inAns,0,sizeof(inAns));
    for(int guessC=guess,ansC=ans;ansC;ansC/=10,guessC/=10){
        int digitA = ansC % 10;
        if(digitA == guessC % 10){
            correctP++;
            if(correctP>correctPlaces)
                return false;
        }else
            inAns[digitA]++;
    }
    for(int guessC=guess;ans;ans/=10,guessC/=10){
        int digitG = guessC % 10;
        if(digitG!=ans%10&&inAns[digitG]){
            wrongP++;
            if(wrongP>wrongPlaces)
                return false;
            inAns[digitG]--;
        }
    }
    return correctP == correctPlaces && wrongP == wrongPlaces;
}
bool noZeros(int x){
    for(;x;x/=10)
        if(x%10==0)
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> guess >> correctPlaces >> wrongPlaces;
        int initial = getOnes(getNumberOfDigits(guess)),last = initial*9+1,ans=0;
        for(;initial<last;initial++)
            if(noZeros(initial)&&isCorrect(initial))
                ans++;
        cout << ans << "\n";
    }
    return 0;
}