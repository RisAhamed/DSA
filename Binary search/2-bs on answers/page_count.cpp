#include<bits/stdc++.h>
using namespace std;


int student_count(vector<int> &arr, int pages){
    int student = 1,pages_count = 0;
    int n = arr.size();
    for (int i=0;i<n;i++){
        if (arr[i]+pages_count <=pages){
            pages_count+=arr[i];
        }
        else{
            student++;
            pages_count = arr[i];
        }
    }
    return student;
}

int findPages(vector<int>&arr, int students){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(),arr.end(), 0);
    cout<<low<<" "<<high<<endl;
    for (int i=low;i<=high-1;i++){
        if (student_count(arr,i)<=students){
            return i;
        }
    }
    return -1;
}


int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};

    int m = 4;
    int ans = findPages(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
