#include <iostream>
using namespace std;

struct node{
    int a;
    int b;
};

int n;
int ans = 1e9;
bool vis[15];
node arr[15];

void dfs(int father,int x,int dis){
    if(x == n){
        ans = min(ans,dis);
        return ;
    }
    if(dis >= ans) return ;

    for(int i = 1;i <= n;i++){
        if(vis[i] == true) continue;
        vis[i] = true;
        dfs(i,x + 1,dis + max(arr[father].b,arr[i].a ) + 1);
        vis[i] = false;
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i].a;
    }
    for(int i = 1;i <= n;i++){
        cin >> arr[i].b;
    }

    for(int i = 1;i <= n;i++){
        vis[i] = true;
        dfs(i,1,1);
        vis[i] = false;
    }
    cout << ans << endl;

    return 0;
}