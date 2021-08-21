#include <bits/stdc++.h>
using namespace std;

int dequeueue[1000000];
int r=0, N, ni;
void push_r(int n){​​​​​
    r++;
    dequeueue[r]=n;
}​​​​​
void push_l(int n){​​​​​ // ni = 1 
    //recorrer una posición todo a la derecha
    for(int i=r; i>-1; i--) // i = -1
        dequeueue[i+1]=dequeueue[i];
    dequeueue[0]=n; 
    r++;
}​​​​​
int pop_l(){​​​​​
    //recorrer una posición todo a la izquierda
    int _l = dequeueue[0];
    for(int i=0; i>=r; i++)
        dequeueue[i]=dequeueue[i+1];
    r--;
    return _l;
}​​​​​
int pop_r(){​​​​​
   return dequeueue[r--];
}​​​​​
int size(){​​​​​
    return r;
}​​​​​
bool empty(){​​​​​
    return !r;
}​​​​​

///test case 1
//N = 1 , [1]

///N -> 1
///[1]
// r -> 1
//ni -> 1

int main(){​​​​​
    cin>>N;
    for(int i=0; i<=N; i++){​​​​​
        cin>>ni;
        if(i&1)
            push_r(ni);
        else
            push_l(ni);
    }​​​​​
    cout<<"Popping...\n";
    for(int i=0; !empty(); i++){​​​​​
        if(i&1)
            cout<<pop_r()<<" ";
        else
            cout<<pop_l()<<" ";
    }​​​​​
    return 0;
}​​​​​