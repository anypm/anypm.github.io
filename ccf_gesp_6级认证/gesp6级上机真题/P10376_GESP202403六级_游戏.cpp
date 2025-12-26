#include <iostream>
using namespace std;
const int mod = 1e9+7;

int n,a,b,c;
int ans[200005];

int dfs(int x){
    if(x <= c) return 1;
    if(ans[x] != 0) return ans[x];
    ans[x] = (dfs(x - a) % mod + dfs(x - b) % mod) % mod;
    return ans[x];
}

int main(){
    cin >> n >> a >> b >> c;
    cout << dfs(n) << endl;

    return 0;
}