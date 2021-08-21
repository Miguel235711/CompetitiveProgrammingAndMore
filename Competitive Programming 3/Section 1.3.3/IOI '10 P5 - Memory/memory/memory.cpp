#include "grader.h"
#include "memory.h"
#include<bits/stdc++.h>

using namespace std;

vector<int>matchedPairs[100];

void play() {
   for(int i = 1 ; i <= 50 ; i ++){
      matchedPairs[faceup(i)].push_back(i);
   }
   for(char i = 'A'; i < 'Z' ; i ++){
      faceup(matchedPairs[i][0]);
      faceup(matchedPairs[i][1]);
   }
}
