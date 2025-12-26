#include <iostream>
using namespace std;

int n;
long long a[200005];
long long dpma[200005],dpmi[200005];
long long ans,maxn = LLONG_MIN,minn = LLONG_MAX,maxnum = LLONG_MIN,sum = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
        maxnum = max(maxnum,a[i]);
    }

    dpma[0] = 0;
    dpmi[0] = 0;
    for(int i = 1;i <= n;i++){
        dpma[i] = max(dpma[i - 1] + a[i],a[i]);
        maxn = max(maxn,dpma[i]);
        dpmi[i] = min(dpmi[i - 1] + a[i],a[i]);
        minn = min(minn,dpmi[i]);
    }

    ans = max(maxn,sum - minn);
    if(ans == 0) cout << maxnum << endl;
    else cout << ans << endl;

    return 0;
}