#include<bits/stdc++.h>

using namespace std;

map<char,int> mapSpecials = {
    make_pair('/',12),
    make_pair('X',13)
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line;
    while(getline(cin,line)&&line[0]!='G'){
        vector<int> arr;
        for(auto x:line)
            if(x!=' ')
                arr.push_back(isdigit(x)?x-'0':mapSpecials[x]);
        int ans=0,count=0;
        bool trail=false;
        for(int i=0;i<arr.size();i++){
            if((i+1==arr.size()||arr[i+1]!=12)&&count<10)
                ans+=min(10,arr[i]);
            int lim = count < 10 ? min(i+max(arr[i]-10,0),(int)arr.size()) : i+1;
            if(trail||arr[i]==13){
                count++;
                trail=false;
            }else
                trail=true;
            int before = -1;
            for(int next=i+1;next<lim;next++){
                ans+=min(10,arr[next]);
                if(arr[next]==12&&before!=-1)
                    ans-=before;
                before=arr[next];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}