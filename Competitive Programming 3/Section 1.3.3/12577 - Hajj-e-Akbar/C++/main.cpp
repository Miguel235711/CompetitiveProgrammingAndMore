#include <iostream>

using namespace std;

string line;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs=1;getline(cin,line)&&line[0]!='*';cs++){
        cout << "Case " << cs  << ": Hajj-e-" << (line[0]=='U'?"Asghar":"Akbar") << "\n";
    }
    return 0;
}