#include <iostream>
using namespace std;

int p;
int l;
long long ans;
string s;
int dp[130],arr[130];
int main(){
    cin >> p;
    cin >> s;
    l = s.length();

    for(int i = 0;i < l;i++){
        int q = (s[i] - '0') % p;
        for(int j = 0;j < p;j++){
            arr[j] = dp[j];
            dp[j] = 0;
        }
        for(int j = 0;j < p;j++){
            dp[(j * 10 + q) % p] += arr[j];
        }
        dp[q]++;
        ans += dp[0];
    }
    cout << ans << endl;

    return 0;
}