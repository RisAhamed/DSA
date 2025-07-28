#include<bits/stdc++.h>
using  namespace std;


int  square_root(int n){
    long long low = 1,high = n;
    long long  ans =1;
    while(low<=high){
        long long  mid = (low+high)/2;
        if (mid * mid <=n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }


    return ans;
}



int main()
{
    long long n = 2098291930;
    int ans = square_root(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}