#include<bits/stdc++.h>
using namespace std ;

#include <iostream>
#include <string>
using namespace std;

// Recursive function to generate permutations
void permute(string &s, int index) {
    // Base case: If the current index equals the string's length,
    // we've formed a complete permutation.
    if (index == s.size()) {
        cout << s << endl;  // Print the permutation at the leaf node.
        return;
    }

    // This loop "chooses" a character to fix at the current index.
    for (int i = index; i < s.size(); i++) {
        // Swap the character at 'i' with the character at 'index'
        // to fix it at the current position.
        swap(s[index], s[i]);

        // Recursively permute the remaining substring (from index+1 onward).
        permute(s, index + 1);

        // Backtrack: undo the swap, restoring the original string,
        // so that the next iteration of the loop (next branch of the tree) starts fresh.
        swap(s[index], s[i]);
    }
}

int main() {
    string str = "ABC";
    cout << "All permutations of " << str << " are:\n";
    // Start the recursive permutation with index 0.
    permute(str, 0);
    return 0;
}
