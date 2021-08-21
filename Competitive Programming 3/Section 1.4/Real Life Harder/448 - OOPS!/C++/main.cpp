#include<bits/stdc++.h>

using namespace std;

int operandN[16]={2,2,2,2,2,1,1,1,1,1,1,1,3,3,3,1};
string preffix [4]={"R","$","PC+",""};
string op[16]={"ADD","SUB","MUL","DIV","MOV","BREQ","BRLE","BRLS","BRGE","BRGR","BRNE","BR","AND","OR","XOR","NOT"};

int convert(char c){
    return c-(isdigit(c) ? '0':'A'-10);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    char c;
    while(cin>>c){
        int cV = convert(c);
        cout << op[cV] << " ";
        int lim = operandN[cV];
        for(int ope = 0 ; ope < lim ;ope++){
            cin >> c;
            int value = convert(c);
            int preffixI = value >> 2;
            int acum = value&3 ;
            for(int i = 0 ; i < 3 ; i ++){
                acum <<=4;
                cin >> c;
                acum+=convert(c);
            }
            cout << (ope?",":"") << preffix[preffixI] << acum;   
        }
        cout << "\n";
    }
    return 0;
}