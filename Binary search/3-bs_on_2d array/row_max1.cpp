#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int rowwithmaxones(vector<vector<int>> &arr, int n, int m ){
    int index = 0;
    int count_ones = 0;
    for( int i=0;i<n;i++){
        int count = 0;
        for (int j=0;j<m;j++){
            count+=arr[i][j];
            if (count>count_ones){
                count_ones = count;
                index = i;
            }
        }

    }
    return  index;
}

int first_occurence(vector<int>& arr, int element){
    int low = 0, high = arr.size()-1;
    int result = -1;
    while (low<=high){
        int mid = (low+high)/2;
        if (arr[mid]==element ){
            result = mid;
            low =mid+1;
        }
        else if (arr[mid]<element){
            low = mid+1;

        }
        else{
            high = mid-1;
        }
    }
    return result;
}



int binary_search(vector<vector<int>> &matrix, int n, int m) {
    int max_ones_row = -1;
    int max_ones = 0;
    
    for (int i = 0; i < n; i++) {
        // Find the first occurrence of 1 in the row
        int first_one = lower_bound(matrix[i].begin(), matrix[i].end(), 1) - matrix[i].begin();
        
        // Count number of 1's in this row
        int ones_count = m - first_one;
        
        // Update max row if current row has more 1's
        if (ones_count > max_ones) {
            max_ones = ones_count;
            max_ones_row = i;
        }
    }
    
    return max_ones_row;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         binary_search(matrix, n, m) << '\n';
}