// #include <iostream>
// #include <string>

// using namespace std;

// int lcs(string &S1, string &S2, int m, int n){
//     if (m == 0 || n == 0)
//         return 0;

//     if (S1[m - 1] == S2[n - 1])
//         return 1 + lcs(S1, S2, m - 1, n - 1);

//     else {
//         return max(lcs(S1, S2, m, n - 1), lcs(S1, S2, m - 1, n));
//     }
// }

// int main() {
//     string S1 = "AGGTAB";
//     string S2 = "GXTXAYB";
//     int m = S1.size();
//     int n = S2.size();

//     cout << "Length of LCS is " << lcs(S1, S2, m, n);

//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the length of LCS and construct the LCS
pair<int, string> lcs(string &S1, string &S2) {
    int m = S1.size();
    int n = S2.size();

    // Create a 2D vector to store lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of LCS is in dp[m][n]
    int length = dp[m][n];

    // Now, let's construct the LCS string
    string lcsStr;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsStr.push_back(S1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // The LCS is constructed in reverse order, so reverse it
    reverse(lcsStr.begin(), lcsStr.end());

    return {length, lcsStr};
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";

    auto result = lcs(S1, S2);
    cout << "Length of LCS is " << result.first << endl;
    cout << "Longest Common Subsequence is: " << result.second << endl;

    return 0;
}
