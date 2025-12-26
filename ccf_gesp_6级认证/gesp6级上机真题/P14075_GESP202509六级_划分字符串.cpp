#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;
string s;
long long a[100005];
long long dp[100005];
bool vis[30];
int main(){
    cin >> n;
    cin >> s;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        memset(vis,0,sizeof(vis));
        vis[s[i - 1] - 'a'] = true;
        int cnt = 1;
        dp[i] = dp[i - 1] + a[1];
        for(int j = i - 1;j >= 1;j--){
            if(vis[s[j - 1] - 'a'] == true) break;
            vis[s[j - 1] - 'a'] = true;
            cnt++;
            if(cnt > 26) break;
            dp[i] = max(dp[i],dp[i - cnt] + a[cnt]);
        }

    }
    cout << dp[n] << endl;

    return 0;
}