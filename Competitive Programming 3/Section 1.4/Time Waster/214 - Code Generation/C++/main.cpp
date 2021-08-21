#define mp make_pair

#include<bits/stdc++.h>


using namespace std;

map<char,char> opToAs = {
    mp('+','A'),
    mp('-','S'),
    mp('*','M'),
    mp('/','D'),
    mp('@','@')
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    for(int cs=0;cin >> s;cs++){
        if(cs)
            cout << "\n";
        if(s.size()==1){
            cout << "L " << s[0] << "\n";
            continue;
        }
        deque<char>tk2;
        int sC = -1,at=0;
        char lastC='\0',beforeLast='\0',negate=false;
        int i = 0 ; 
        for(char x:s){
            auto opIt = opToAs.find(x);
            if(opIt!=opToAs.end()){
                char ope = opIt->second;
                if(ope!='@'){
                    //binary operator
                    if(tk2.size()==2){
                        cout << "L " << tk2.front()<< "\n"; 
                        tk2.pop_front(); 
                        cout << ope << " " << tk2.front() << "\n";
                        negate=false;
                        tk2.pop_front();
                    }else{
                        bool extraScMinus = false;
                        if(ope=='S'&&opToAs.find(lastC)!=opToAs.end()){
                            cout << "N\n";
                            ope='A';
                        }else if(ope=='D'){
                            if(!tk2.empty()){
                                cout << "L " << tk2.front()<< "\n"; 
                                tk2.pop_front();
                            }
                            cout << "ST $" << ++sC << "\n";
                            cout << "L $" << sC-1 << "\n";
                            extraScMinus=true;
                        }
                        if(tk2.empty())
                            cout << ope << " $" << sC-- << "\n";
                        else{
                            cout << ope << " " << tk2.front() << "\n";
                            tk2.pop_front();
                        }
                        negate=false;
                        if(extraScMinus)
                            sC--;
                    }
                }else{
                    //unary operator (@->-)
                    if(negate){
                        cout << "ST $" << ++sC << "\n";
                        negate=false;
                    }
                    if(tk2.size()==2){
                        cout << "L " << tk2.front() << "\n";
                        cout << "ST $" << ++sC << "\n";
                        negate=false;
                        tk2.pop_front();
                    }
                    auto back = tk2.back();
                    tk2.pop_back();
                    cout << "L " << back << "\nN\n";
                    negate=true;
                }
            }else{
                //operand
                tk2.push_back(x);
                //cout << "x: " << x << " lastC: " << lastC << " beforeLast: " << beforeLast << "\n";
                if(i&&opToAs.find(s[i-1])!=opToAs.end()&&s[i-1]!='@'&&(i+1<s.size()&&opToAs.find(s[i+1])==opToAs.end()||(i+1<s.size()&&s[i+1]=='@'&&i+2<s.size()&&opToAs.find(s[i+2])==opToAs.end()))){
                    cout  << "ST $" << ++sC << "\n";
                    negate=false;
                }
                if(tk2.size()==3){
                    cout << "L " << tk2.front() << "\n";
                    cout  << "ST $" << ++sC << "\n";
                    tk2.pop_front();
                    negate=false;
                }   
            }
            if(lastC!='@')
                beforeLast=lastC;
            if(x!='@')
                lastC=x;
        }
        i++;
    }
    return 0;
}