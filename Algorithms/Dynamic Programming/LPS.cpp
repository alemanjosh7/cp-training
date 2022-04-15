
string longestPalindrome(string s) {
    int n = s.size();
    int maxi = 0;
    bool dp[n][n];
    string ans = "";
    bool ok;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= j; i++) {
            ok = s[i] == s[j];
            dp[i][j] = j - i + 1 > 2 ? dp[i + 1][j - 1] && ok : ok;
            if (dp[i][j] && j - i + 1 > maxi) {
                maxi = j - i + 1;
                ans = s.substr(i, j - i + 1);
            }
        }
    }
    return ans;
}