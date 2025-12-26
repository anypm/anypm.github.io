#include <iostream>
#include <vector>
using namespace std;

int n,even,odd;
int vis[200005];
vector<int> arr[200005];

void dfs(int father,int x,int dis){
    vis[x] = dis;
    if(dis % 2 == 0) even++;
    else odd++;

    for(int i = 0;i < arr[x].size();i++){
        if(arr[x][i] != father){
            dfs(x,arr[x][i],dis + 1);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    dfs(0,1,0);
    for(int i = 1;i <= n;i++){
        if(vis[i] % 2 == 0) cout << even << " ";
        else cout << odd << " ";
    }
    cout << endl;

    return 0;
}