#include <iostream>
using namespace std;

int n,m;
int ans = -1e9;
int a[105];
int b[20005];
int dp[20005];
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> b[i];
    }
    for(int i = 1;i <= 2 * n;i++){
        dp[i] = -1e9;
    }

    dp[1] = b[1];
    for(int i = 1;i <= 2 * n;i++){
        for(int j = 1;j <= m;j++){
            if(i - a[j] > 0){
                dp[i] = max(dp[i],dp[i - a[j]] + b[i]);
            }
        }
    }

    // for(int i = 1;i <= n;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    
    for(int i = n;i < 2 * n;i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;

    return 0;
}