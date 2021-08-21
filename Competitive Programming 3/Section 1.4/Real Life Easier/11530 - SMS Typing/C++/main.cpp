#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    string line;
    cin >> t;
    cin.ignore();
    for(int cs = 1 ; cs <= t ; cs++){
        getline(cin,line);
        int total = 0 ;
        for(char c: line){
            if(c==' ')
                total++;
            else if(c=='s'||c=='z'){
                total+=4;
            }else{
                int value = c-'a';
                if(c>'s')
                    value--;
                total += (value%3)+1;
            }
        }
        cout << "Case #" << cs << ": " << total << "\n";
    }
    return 0;
}