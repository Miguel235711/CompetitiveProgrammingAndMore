#include<bits/stdc++.h>

using namespace std;

map<string,pair<string,int> > areas;
string code;

typedef pair<string,pair<string,pair<string, int> > > sp;

sp separate(string x){
    sp ans;
    if(x[0]!='0')
        ans.second.first=x;
    else{ 
        size_t lim = min((int)x.size()-1,x[1]!='0'?6:5);
        for(size_t i = 0 ; i < lim ; i ++){
            string code = x.substr(0,i+1);
            auto it = areas.find(code);
            int l = x.size()-i-1;
            if(it!=areas.end()&&((x[1]!='0'&&4<=l&&l<=7)||(x[1]=='0'&&4<=l&&l<=10))){
                ans = make_pair(code,make_pair(x.substr(i+1,l),make_pair(it->second.first,it->second.second)));
                break;
            }
            if(i+1==lim)
                ans.first="Unknown";
        }
        if(lim==0)
            ans.first="Unknown";
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> code && code!="000000"){
        string areaName,packet;
        int price=0;
        cin.ignore();
        getline(cin,packet);
        size_t i = 0;
        for( ; packet[i]!='$';i++)
            areaName.push_back(packet[i]);
        for(i=i+1 ; i < packet.size() ; i ++){
            price*=10;
            price+=packet[i]-'0';
        }
        areas[code]=make_pair(areaName,price);
    }
    int duration;
    while(cin >> code && code[0]!='#'){
        cin >> duration;
        sp codeNumber = separate(code);
        float costPerMinute = codeNumber.second.second.second / 100.0; 
        bool unknown = codeNumber.first == "Unknown";
        string s2=unknown ? "Unknown" : codeNumber.first.empty() ? "Local" : codeNumber.second.second.first;
        cout << left << setw(16) << code << s2  << " ";
        stringstream stream;
        stream << fixed << setprecision(2) << costPerMinute;
        cout << right << setw(34-s2.size()) << (unknown?"":codeNumber.second.first) << setw(5) << duration << setw(6) << (unknown?"":stream.str()) << setw(7) << fixed << setprecision(2) << (unknown ? -1.00 : (codeNumber.first.empty()?0.00:costPerMinute*duration))<<"\n";
    }
    return 0;
}