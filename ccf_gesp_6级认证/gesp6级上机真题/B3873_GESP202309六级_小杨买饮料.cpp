#include <iostream>
using namespace std;

struct node{
    int c;
    int l;
};

int n,L;
int ans = 1e9;
node arr[505];
int dp[4005];
int main(){
    cin >> n >> L;
    for(int i = 1;i <= n;i++){
        cin >> arr[i].c >> arr[i].l;
    }
    for(int i = 1;i <= 2 * L;i++){
        dp[i] = 1e9;
    }

    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 2 * L;j >= 1;j--){
            if(j - arr[i].l >= 0) {
                dp[j] = min(dp[j],dp[j - arr[i].l] + arr[i].c);
            } else {
                dp[j] = min(dp[j],arr[i].c);
            }
        }
    }

    for(int i = L;i < 2 * L;i++){
        ans = min(ans,dp[i]);
    }

    if(ans == 1e9) cout << "no solution" << endl;
    else cout << ans << endl;

    return 0;
}