#include <iostream>
using namespace std;

int n,m,ans;
int a[25];
int dp[33335];
string s;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        for(int j = i;j <= 33333;j++){
            dp[j] = max(dp[j],dp[j - i] + a[i]);
        }
    }
    cin >> m >> s;

    s += "# ";
    int i = 0;
    int k = 0;
    while(i <= m){
        if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
            i += 3;
            k++;
        }
        else{
            i++;
            ans += dp[k];
            k = 0;
        }
    }
    cout << ans << endl;

    return 0;
}