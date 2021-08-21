#include <bits/stdc++.h>

using namespace std;

int sumDigits(int number){
    while(number>9){
        int digitSum = 0;
        while(number){
            digitSum += number % 10; 
            number /= 10;
        }
        number = digitSum;
    }
    return number;
}
int calcValue (const string & s){
    int sum=0;
    for(char c : s){
        c = tolower(c);
        if('a'<=c&&c<='z')
            sum+=c-'a'+1;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line;
    while(getline(cin,line)){
        int sumDigitsA = sumDigits(calcValue(line));
        getline(cin,line);
        int sumDigitsB = sumDigits(calcValue(line));
        if(sumDigitsA>sumDigitsB)
            swap(sumDigitsA,sumDigitsB);
        //sumDigitsA <= sumDigitsB
        cout << fixed << setprecision(2) << (float) sumDigitsA / sumDigitsB * 100 << " %\n";
    }
    return 0;
}