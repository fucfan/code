#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int , int>
#define pb push_back
#define BIT(x , i) (((x) >> (i)) & 1)
#define flip(x , i) ((x) ^ (1 << (i)))
#define add(x , y) ((x) + (y) >= mod ? (x) + (y) - mod : (x) + (y))
#define all(c) (c).begin() , (c).end()
#define mem(a , b) memset((a) , (b) , sizeof(a))
#define nl inp << '\n'
#define file "test"
template <typename T1, typename T2> bool mini(T1 &a, T2 b) {if (a > b) {a = b; return 1;} return 0;}
template <typename T1, typename T2> bool maxi(T1 &a, T2 b) {if (a < b) {a = b; return 1;} return 0;}

const char dir[] = {'L' , 'R' , 'U' , 'D'};
const char dir1[] = {'A' , 'T' , 'G' , 'X' , '?' , '?'};

using namespace std;

const ll oo = 1e9;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

void run_with_file(){
    if(fopen(file".inp" , "r")){
        freopen(file".inp" , "r" , stdin);
        freopen(file".out" , "w" , stdout);
    }
}

ll Rand(ll l , ll r){
    return l + 1ll * rd() % (r - l + 1);
}

struct Point{
    ll x , y;
    bool in_q , use;
    int id;

    void input(int num){
        cin >> x >> y;
        // x += 1e9;
        // y += 1e9;
        id = num;
    }

    bool operator<(Point b){
        if(x == b.x) return y < b.y;
        return x < b.x;
    }

    bool operator>(Point b){
        return x > b.x;
    }
};

ll s(Point p1 , Point p2 , Point p3){
    return  (p2.y + p1.y) * (p2.x - p1.x) +
            (p2.y + p3.y) * (p3.x - p2.x) -
            (p3.y + p1.y) * (p3.x - p1.x);
}

vector <Point> ch(vector <Point> vt){
    sort(all(vt));
    stack <Point> up;

    for(auto j : vt){
        if(up.size() < 2){
            up.push(j);
        }
        else{
            Point p2 = up.top();
            up.pop();
            Point p1 = up.top();
            Point p3 = j;

            while(s(p1 , p2 , p3) <= 0 && up.size() >= 2){
                p2 = up.top();
                up.pop();
                p1 = up.top();
            }

            if(s(p1 , p2 , p3) > 0){
                up.push(p2);
                up.push(p3);
            }
            else up.push(p3);
        }
    }

    stack <Point> down;

    for(auto j : vt){
        if(down.size() < 2){
            down.push(j);
        }
        else{
            Point p2 = down.top();
            down.pop();
            Point p1 = down.top();
            Point p3 = j;

            while(s(p1 , p2 , p3) >= 0 && down.size() >= 2){
                p2 = down.top();
                down.pop();
                p1 = down.top();
            }

            if(s(p1 , p2 , p3) < 0){
                down.push(p2);
                down.push(p3);
            }
            else down.push(p3);
        }
    }


    vector <Point> poligon;

    Point Min = {100000 , 100000};
    int st = 0;

    long double ans = 0;

    while(down.size()){
        // cout << down.top().x << ' ' << down.top().y << '\n';
        Point _p = down.top();
        down.pop();
        // if(down.size())cout << down.top().x << ' ' << down.top().y << '\n';
        if(_p.y < Min.y){
            Min = _p;
            st = poligon.size();
        }
        else if(_p.y == Min.y && _p.x < Min.x){
            Min = _p;
            st = poligon.size();
        }
        poligon.pb(_p);
        if(down.size()) ans -= (_p.y + down.top().y) * (_p.x - down.top().x);
    }

    reverse(all(poligon));
    st = poligon.size() - st - 1;
    bool tmp = 0;

    while(up.size()){
        // cout << up.top().x << ' ' << up.top().y << '\n';
        Point _p = up.top();
        up.pop();
        // if(up.size())cout << up.top().x << ' ' << up.top().y << '\n';
        if(up.size()) ans += (_p.y + up.top().y) * (_p.x - up.top().x);
        if(!tmp){
            tmp = 1;
        }
        else{
            if(_p.y < Min.y){
                Min = _p;
                st = poligon.size();
            }
            else if(_p.y == Min.y && _p.x < Min.x){
                Min = _p;
                st = poligon.size();
            }
            poligon.pb(_p);
        }
        if(up.size() == 1) break;
    }

    return poligon;
}

int a[50];
int b[50];
int c[50][50];
vector <int> v;
vector <pii> edge;

int main(){
    srand(time(NULL));
    set <pair <int , char>> st;
    for(int itest = 1 ; itest <= 1000000 ; itest++){
        ofstream inp("test.inp");
        int lef = Rand(10, 20);
        int rig = Rand(lef + 20, lef + 30);
        int judge = Rand(lef, rig);
        int length = rig - lef;
        vector <int> vt;
        while(length){
            int x = Rand(1, min(5, length));
            length -= x;
            vt.pb(x);
        }
        int n = Rand(1, vt.size());
        inp << n << ' ' << lef << ' ' << rig << ' ' << judge << '\n';
        for(int i = 0; i < n; i++) 
            inp << vt[i] << ' ' << Rand(1, 10) << '\n';
        inp.close();
        system("sol.exe");
       system("trau.exe");

        // ifstream tOut("test.out");
        // ifstream tAns("test.ans");
        // ll A;
        // tOut >> A;
        // ll B;
        // tAns >> B;
        // system("cd Desktop/P:/cpp");
        // system("python sol_py.py");
        // if(system("fc ok.txt test.ans") == 0){
        //     system("cd Desktop/P:/cpp");
        //     system("python trau_py.py");
            if(system("fc test.ans test.out") == 0){
                cout << "test " << itest << " :" << "AC\n";
            }
            else{
                cout << "test " << itest << " :" << "WA\n";
               return 0;
            }
        // }
        // else{
        //     cout << "test " << itest << " :" << "WA\n";
        //     return 0;
        // }
    }
}


/*
4 19 29 29
7 8
1 2
1 1
1 4


*/
