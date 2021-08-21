#include<bits/stdc++.h>

using namespace std;

struct NoteEvent{
    int note,code,m,b,t;
    NoteEvent(int note,int code,int m, int b, int t){
        this->note=note;
        this->code=code;
        this->m=m;
        this->b=b;
        this->t=t;
    } 
};
int n,code,note,m,b,t;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n&&n!=-1){
        int finalN = n;
        vector<NoteEvent> events;
        map<int,int> mapCodeToPositionInEvents;
        for(int i=0;i<n;i++){
            cin>>code>>note>>m>>b>>t;
            //convert
            if(t>449){
                //especial case, increment to next beat and/or measure
                t=0;
                if(b==4){
                    b=1;
                    m++;
                }else
                    b++;
            }else
                t=(t+30)/60*60%480; 
            auto newEvent = NoteEvent(note,code,m,b,t);
            if(code==1)
                //push code
                mapCodeToPositionInEvents[note]=events.size();
            else{
                //pop code
                int positionInVector = mapCodeToPositionInEvents[note];
                auto openedBef = events[positionInVector];
                if(openedBef.m==newEvent.m&&openedBef.b==newEvent.b&&openedBef.t==newEvent.t){
                    //filter both
                    events[positionInVector].m=newEvent.m=-1; 
                    finalN-=2;
                }
            }
            events.push_back(newEvent);
        }
        cout<<finalN<<"\n";
        for(auto event:events)
            if(event.m!=-1)
                cout << event.code << " " << event.note << " " << event.m << " " << event.b << " " << event.t << "\n";
    }
    cout << "-1\n";
    return 0;
}