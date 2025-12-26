#include <iostream>
#include <vector>
using namespace std;

int q;

void change(int x,vector<int> & a){
    a.push_back(x);
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0){
            while(x % i == 0){
                x /= i;
                a.push_back(x);
            }
        }
    }

    if(x != 1) a.push_back(1);
    reverse(a.begin(),a.end());
}

int main(){
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        vector<int> a,b;
        change(x,a);
        change(y,b);
        int cnt = 0;
        for(int i = 0;i < min(a.size(),b.size());i++){
            if(a[i] == b[i]) cnt++;
            else break;
        }
        cout << a.size() + b.size() - cnt * 2 << endl;
    }

    return 0;
}