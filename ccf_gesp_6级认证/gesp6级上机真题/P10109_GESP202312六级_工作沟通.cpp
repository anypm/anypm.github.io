#include <iostream>
#include <cstring>
using namespace std;

int n,q;
int vis[305];
int fa[305];

void change(int x){
    vis[x]++;
    while(x != 0){
        x = fa[x];
        vis[x]++;
    }
    vis[0]++;
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        cin >> fa[i];
    }
    cin >> q;
    while(q--){
        int ans = 0;
        memset(vis,0,sizeof(vis));
        int m;
        cin >> m;
        for(int i = 1;i <= m;i++){
            int num;
            cin >> num;
            change(num);
        }
        for(int i = 1;i <= n;i++){
            if(vis[i] == m){
                ans = max(ans,i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}