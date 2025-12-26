#include <iostream>
#include <deque>
using namespace std;

long long n,s;
deque<char> arr;
int main(){
    cin >> n >> s;
    for(int i = 1;i <= n;i++){
        char ch;
        cin >> ch;
        if(ch == 'U' && !arr.empty() && (arr.back() == 'L' || arr.back() == 'R')) arr.pop_back();
        else arr.push_back(ch);
    }

    while(!arr.empty()){
        char ch = arr.front();
        arr.pop_front();
        if(ch == 'U'){
            if(s == 1) continue;
            s /= 2;
        }
        if(ch == 'L') s = s * 2;
        if(ch == 'R') s = s * 2 + 1;
    }
    cout << s << endl;

    return 0;
}