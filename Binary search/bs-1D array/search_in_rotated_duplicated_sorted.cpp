#include<bits/stdc++.h>
using namespace std;


bool searchInARotatedSortedArrayII(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n - 1;
    while(low<=high){
        int mid = low+ (high-low)/2;
        if (arr[mid]==x)  return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
        // if left half is sorted
        if ( arr[low]<=arr[mid]){

            if (x >=arr[low] && x< arr[mid]){
                high = mid - 1;
            }
            else{
                low= mid+1;
            }
        }
        // if right half is sorted
        else{
            if (x>=arr[mid] && x< arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 7;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}