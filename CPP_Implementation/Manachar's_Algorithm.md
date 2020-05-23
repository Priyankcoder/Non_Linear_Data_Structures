# Manacher's Algorithm( Longest palindrome in string)
Manacher's Algorithm has one single application. It is used to find the Longest Palindromic Sub-string in any string. This algorithm is required to solve sub-problems of some very hard problems.

## Implementation in c++
``` c++
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000000 + 5

int P[SIZE];

// Transform S into new string with special
// characters inserted.
string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += string("#") + s[i];
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;               
    // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) {
    // find the corresponding letter in
   // the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome 
       //centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length 
    //in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - 
maxPalindrome) / 2, maxPalindrome);
 //Subtracted 1 for @ and divided it
// by 2 because the   index in s will be of half 
//of Q as Q contains #. 
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromeSubstring(s);
    return 0;
}
```
## Time Complexity
Time complexity is O(2*n) which is equivalent to **O(n)**.