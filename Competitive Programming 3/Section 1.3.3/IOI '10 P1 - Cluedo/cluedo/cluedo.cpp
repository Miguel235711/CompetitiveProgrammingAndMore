#include "grader.h"
#include "cluedo.h"

void Solve(){
   int m=1,l=1,w=1;
   int x;
   while(x=Theory(m,l,w)){
      if(x==1){
         m++;
      }else if(x==2){
         l++;
      }else{
         w++;
      }
   }
}
