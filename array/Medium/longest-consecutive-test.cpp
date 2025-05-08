#include<bits/stdc++.h>
using namespace std;

void longest_subarray_better(vector<int> arr) {
    if (arr.empty()) {
        cout << "No longest Subarray" << endl;
        return;
    }
    
    sort(arr.begin(), arr.end());
    int count = 1;
    int longest = 1;
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1] + 1) {
            count++;
            longest = max(longest, count);
        }
        else if (arr[i] != arr[i-1]) {
            count = 1;
        }
    }
    
    cout << longest << " is the longest consecutive subsequence length" << endl;
}

int main() {
    // Test set with multiple sequences and edge cases
    vector<int> test1 = {5, 7, 3, 4, 6, 8, 9, 1, 2, 10, 15, 16, 17, 18, 19, 20, 25, 26, 27, 30};
    // Expected: 8 (1-10)
    
    vector<int> test2 = {100, 4, 200, 1, 3, 2, 5, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113};
    // Expected: 13 (100-113)
    
    vector<int> test3 = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    // Expected: 1 (all duplicates)
    
    vector<int> test4 = {1 ,2 ,2, 1};
    // Expected: 1 (no consecutive sequences)
    
    cout << "Test 1: ";
    longest_subarray_better(test1);
    
    cout << "Test 2: ";
    longest_subarray_better(test2);
    
    cout << "Test 3: ";
    longest_subarray_better(test3);
    
    cout << "Test 4: ";
    longest_subarray_better(test4);
    
    return 0;
}
