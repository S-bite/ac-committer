#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;

struct point{
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
};


int main(){

    int K, X, Y;
    cin >> K >> X >> Y;

    bool xnegative = false;
    if(X < 0){
        X = -X;
        xnegative = true;
    }
    bool ynegative = false;
    if(Y < 0){
        Y = -Y;
        ynegative = true;
    }
    bool swapped = false;
    if(X < Y){
        swap(X, Y);
        swapped = true;
    }

    int D = X + Y;
    if(K % 2 == 0 and D % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    int step = 0;

    if(D < K and D % 2 == 1){
        return 0;
    } else {
        step=0;
        int down = (D - K * step) / 2;
        point now(0, 0);
        while(now.y - K >= down){
            now.y -= K;
        }
        now.x = K - (now.y - down);
        now.y = down;
        while(now.x + K <= X){
            now.x += K;
        }
        now.y = down + K - (X - now.x);
        now.x = X;
        int tmp = (Y - now.y) / K;
        //assert(tmp * K + now.y == Y); //ここまではREにならない
        rep(i, tmp){
            now.y = now.y + K;
        }
        assert(now.y == Y); //ここでRE
    
        return 0;
    }

}
