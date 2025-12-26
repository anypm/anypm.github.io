#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n,k;
int dis,maxn;
int a[100005];
vector<int> arr[100005];

bool compare(int A,int B){
    return A > B;
}

int main(){
    cin >> m >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int num;
        cin >> num;
        arr[a[i]].push_back(num);
    }
    for(int i = 1;i <= m;i++){
        sort(arr[i].begin(),arr[i].end(),compare);
        int sum = 0;
        int cnt = 0;;
        for(int j = 0;j < arr[i].size();j++){
            sum += arr[i][j];
            dis++;
            cnt++;
            if(sum >= k) break;
        }
        if(sum < k){
            cout << -1 << endl;
            return 0;
        }
        maxn = max(maxn,cnt);
    }

    if(maxn - 1 > n - maxn) cout << -1 << endl;
    else cout << max(maxn + maxn - 1,dis) << endl;

    return 0;
}