#include <iostream>
using namespace std;

int n;
int a[1005];
long long dp[1005];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        for(int j = i;j <= n;j++){
            dp[j] = max(dp[j],dp[j - i] + a[i]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}