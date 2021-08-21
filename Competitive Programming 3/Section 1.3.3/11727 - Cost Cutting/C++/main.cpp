#include <bits/stdc++.h>

using namespace std;

int t,nums[3];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    for(int cs = 1 ; cs <= t ; cs ++){
        for(int i = 0 ; i < 3 ; i ++){
            cin >> nums[i];
        }
        sort(nums,nums+3);
        cout << "Case " << cs << ": " << nums[1] << "\n";
    }
    return 0;
}