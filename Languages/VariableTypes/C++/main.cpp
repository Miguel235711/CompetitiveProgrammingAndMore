#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int aI=INT_MAX,bI=INT_MIN;
  cout<<aI<<" "<<bI<<"\n";
  int64_t a64I=LLONG_MAX,b64I=LLONG_MIN;
  cout<<a64I<<" "<<b64I<<"\n";
  float aF=numeric_limits<float>::max();
  float bF=numeric_limits<float>::min();
  cout<<aF<<" "<<bF<<"\n";
  double aD=numeric_limits<double>::max();
  double bD=numeric_limits<double>::min();
  cout<<aD<<" "<<bD<<"\n";
  string s="hello ICPC contestants";
  char c='e';
  bool bb=true;
  cout<<s<<" "<<bb<<" "<<c<<"\n";
  long double aLD = numeric_limits<long double>::max();
  long double bLD = numeric_limits<long double>::min();
  cout<<aLD<<" "<<bLD<<"\n";
  return 0;
}