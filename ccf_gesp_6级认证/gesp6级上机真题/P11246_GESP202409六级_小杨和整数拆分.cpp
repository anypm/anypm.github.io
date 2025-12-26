#include <iostream>
using namespace std;

int n;
int dp[100005];
int main(){
    cin >> n;
    dp[0] = 0;
    for(int i = 1;i <= n;i++) dp[i] = i;
    for(int i = 1;i * i <= n;i++){
        for(int j = i * i;j <= n;j++){
            dp[j] = min(dp[j],dp[j - i * i] + 1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}