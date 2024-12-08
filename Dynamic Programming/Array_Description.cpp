#include<bits/stdc++.h>
using namespace std;
// 2 
// 8
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 2, 0));
    if (a[0] == 0)
        for (int i = 1; i <= m; i++) dp[1][i] = 1;
    else
        dp[1][a[0]] = 1;

    for (int i = 2; i <= n; i++) {
        if (a[i - 1] != 0) {
            dp[i][a[i - 1]] = dp[i - 1][a[i - 1]] 
                            + dp[i - 1][a[i - 1] - 1] 
                            + dp[i - 1][a[i - 1] + 1];
            dp[i][a[i - 1]] = (dp[i][a[i - 1]] + 1000000007) % 1000000007;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
            dp[i][j] = (dp[i][j] + 1000000007) % 1000000007;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + dp[n][i]) % 1000000007;
    ans = (ans + 1000000007) % 1000000007;
    cout << ans << endl;
}
