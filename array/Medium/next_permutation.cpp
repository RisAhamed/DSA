#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to generate all permutations of the array
vector<vector<int>> generatePermutations(vector<int> arr) {
    vector<vector<int>> allPerms;
    sort(arr.begin(), arr.end()); // Ensure the array is sorted initially

    do {
        allPerms.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));

    return allPerms;
}

// Function to find the next permutation
vector<int> nextPermutation(vector<int> arr) {
    // Generate all permutations
    vector<vector<int>> allPerms = generatePermutations(arr);

    // Find the current permutation's index
    int currentIndex = -1;
    for (int i = 0; i < allPerms.size(); ++i) {
        if (allPerms[i] == arr) {
            currentIndex = i;
            break;
        }
    }

    // Return the next permutation if it exists, otherwise return the first permutation
    if (currentIndex != -1 && currentIndex + 1 < allPerms.size()) {
        return allPerms[currentIndex + 1];
    } else {
        return allPerms[0];
    }
}

vector<int> nexxt_permutaion(vector<int> arr){
    int n = arr.size();
    int index=-1;
    for(int i= n-2;i>=0;i--){
        if (arr[i]<arr[i+1]){
            index =i;
            break;
        }
    }
    if (index ==-1){
        sort(arr.begin(),arr.end());
        return arr;

    }
    for (int i=n-1;i>index;i--){
        if (arr[i]>arr[index]){
            swap(arr[index],arr[i]);
        }
        break;
    }
    reverse(arr.begin()+index+1,arr.end());
    return arr;


}
int main() {
    vector<int> arr = {1, 2, 3};

    // Generate and print all permutations
    vector<vector<int>> allPerms = generatePermutations(arr);
    cout << "All permutations:\n";
        for (const auto& perm : allPerms) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "\n";
    }

    // Find and print the next permutation
    vector<int> nextPerm = nextPermutation(arr);
    cout << "Next permutation:\n";
    for (int num : nextPerm) {
        cout << num << " ";
    }
    cout << "\n";
    vector<int> nextPerm2 = nexxt_permutaion(arr);
    cout << "Next permutation 2 :\n";
    for (int num : nextPerm2) {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}
