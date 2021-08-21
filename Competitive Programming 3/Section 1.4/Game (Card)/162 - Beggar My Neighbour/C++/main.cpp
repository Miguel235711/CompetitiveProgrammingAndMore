#include<bits/stdc++.h>

using namespace std;

queue<int> personQueue[2];
queue<int>deck;
map<char,int> mapToInteger = {make_pair('A',4),make_pair('J',1),make_pair('Q',2),make_pair('K',3)};
int convert(const string & x){
    char c = x[1];
    if(isdigit(c)||c=='T'){
        return 0;
    }
    return mapToInteger[c];
}

int simulation(){
    int beforeFace=0;
    bool takeDeck=false;
    for(int person = 1 ; ; person=!person){
        if(takeDeck){
            while(!deck.empty()){
                personQueue[person].push(deck.front());
                deck.pop();
            }
            takeDeck=false;
            person = !person; //because it will be the turn of this person
        }else{
            int amountToPut=1;
            if(beforeFace){
                amountToPut = beforeFace;
                beforeFace=0;
                takeDeck=true;
            }
            //simulate puting
            while(amountToPut--){
                if(personQueue[person].empty())
                    //person losses, therefore !person wins
                    return !person;
                int frontValue = personQueue[person].front();
                deck.push(personQueue[person].front());
                personQueue[person].pop();
                //pop
                if(frontValue){
                    //no normal card
                    beforeFace=frontValue;
                    takeDeck=false;
                    break;
                }
                
            }
        }
    }
}

void emptyQueue(queue<int> & q){
    while(!q.empty())
        q.pop();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string card;
    while(1){
        for(int i = 0 ; i < 2;i++)
            emptyQueue(personQueue[i]);
        emptyQueue(deck);
        for(int i = 0 ; i < 52 ; i ++){
            cin >> card;
            if(card=="#"){
                return 0;
            }
            personQueue[!(i&1)].push(convert(card));   
        }
        //reverse
        for(int i = 0 ; i < 2 ; i ++){
            stack<int>tempS;
            while(!personQueue[i].empty()){
                tempS.push(personQueue[i].front());
                personQueue[i].pop();
            }
            while(!tempS.empty()){
                personQueue[i].push(tempS.top());
                tempS.pop();
            }
        }
        int winner = simulation();
        cout << winner+1 << " " << setw(2) << personQueue[winner].size() << "\n";
    }
    return 0;
}