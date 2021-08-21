#include<bits/stdc++.h>

#define rows 5
#define cols 6
#define spacePos 26
#define n 60

using namespace std;

string c5[27][rows]={
    {//A
        ".***..",
        "*...*.",
        "*****.",
        "*...*.",
        "*...*."
    },
    {//B
        "****..",
        "*...*.",
        "****..",
        "*...*.",
        "****.."
    },
    {//C
        ".****.",
        "*...*.",
        "*.....",
        "*.....",
        ".****."
    },
    {//D
        "****..",
        "*...*.",
        "*...*.",
        "*...*.",
        "****.."
    },
    {//E
        "*****.",
        "*.....",
        "***...",
        "*.....",
        "*****."
    },
    {//F
        "*****.",
        "*.....",
        "***...",
        "*.....",
        "*....."
    },
    {//G
        ".****.",
        "*.....",
        "*..**.",
        "*...*.",
        ".***.."
    },
    {//H
        "*...*.",
        "*...*.",
        "*****.",
        "*...*.",
        "*...*."
    },
    {//I
        "*****.",
        "..*...",
        "..*...",
        "..*...",
        "*****."
    },
    {//J
        "..***.",
        "...*..",
        "...*..",
        "*..*..",
        ".**..."
    },
    {//K
        "*...*.",
        "*..*..",
        "***...",
        "*..*..",
        "*...*."
    },
    {//L
        "*.....",
        "*.....",
        "*.....",
        "*.....",
        "*****."
    },
    {//M
        "*...*.",
        "**.**.",
        "*.*.*.",
        "*...*.",
        "*...*."
    },
    {//N
        "*...*.",
        "**..*.",
        "*.*.*.",
        "*..**.",
        "*...*."
    },
    {//O
        ".***..",
        "*...*.",
        "*...*.",
        "*...*.",
        ".***.."
    },
    {//P
        "****..",
        "*...*.",
        "****..",
        "*.....",
        "*....."
    },
    {//Q
        ".***..",
        "*...*.",
        "*...*.",
        "*..**.",
        ".****."
    },
    {//R
        "****..",
        "*...*.",
        "****..",
        "*..*..",
        "*...*."
    },
    {//S
        ".****.",
        "*.....",
        ".***..",
        "....*.",
        "****.."
    },
    {//T
        "*****.",
        "*.*.*.",
        "..*...",
        "..*...",
        ".***.."
    },
    {//U
        "*...*.",
        "*...*.",
        "*...*.",
        "*...*.",
        ".***.."
    },
    {//V
        "*...*.",
        "*...*.",
        ".*.*..",
        ".*.*..",
        "..*..."
    },
    {//W
        "*...*.",
        "*...*.",
        "*.*.*.",
        "**.**.",
        "*...*."
    },
    {//X
        "*...*.",
        ".*.*..",
        "..*...",
        ".*.*..",
        "*...*."
    },
    {//Y
        "*...*.",
        ".*.*..",
        "..*...",
        "..*...",
        "..*..."
    },
    {//Z
        "*****.",
        "...*..",
        "..*...",
        ".*....",
        "*****."
    },
};

string getNextArg(const string &s,int & i){
    string arg;
    for(; ;i++){
        if(s[i]==' '&&!arg.empty())
            return arg;
        else if(s[i]!=' ')
            arg.push_back(s[i]);
    }
}

string getS(const string &s,int & i){
    string ans;
    for(;s[i]!='|';i++);
    for(i=i+1;s[i]!='|';i++)
        ans.push_back(s[i]);
    return ans;
}

char matrix[n][n];

void fillCom(int R,int C,char font, const string &s){//give corresponding substring
    int h=1,w=1;
    if(font=='5')
        h=5,w=6;
    int rowE = min(R + h,n);
    for(int i = 0 ; i < s.size() ; i ++){
        int columnB = C+w*i , columnE = min(n,C + w*(i+1));
        for(int row = R, k = 0 ; row < rowE ; row++,k++)
            for(int col = columnB, l = 0 ; col < columnE ; col++,l++)
                if(row>-1&&col>-1)
                    if(h==1){
                        if(s[i]!=' ')
                            matrix[row][col]=s[i];
                    }else{ 
                        char x = s[i]==' ' ? '.' : c5[s[i]-'A'][k][l];
                        if(x!='.')
                            matrix[row][col]=x;
                    }
    }
}

int calculateC(int length){
    return 30 - length/2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line;
    while(1){
        memset(matrix,'.',sizeof(matrix));
        while(1){
            if(!getline(cin,line))
                return 0;
            if(line[1]=='E')
                break;
            int i = 0 ;
            char com = getNextArg(line,i)[1], font = getNextArg(line,i)[1];
            int row = stoi(getNextArg(line,i))-1,col=-1;
            string s;
            if(com=='P'){
                col = stoi(getNextArg(line,i))-1;
                s = getS(line,i);
            }else{ 
                s = getS(line,i);
                int chWidth = s.size()*(font=='1'?1:cols);
                col = com=='L'?0: (com=='R'?60-chWidth:calculateC(chWidth));
            }
            fillCom(row,col,font,s);
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++)
                cout << matrix[i][j];
            cout << "\n";
        }
        cout << "\n" << string(n,'-') << "\n\n";
    }
    return 0;
}