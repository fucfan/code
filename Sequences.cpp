    #include<bits/stdc++.h>
    #define fi first
    #define se second
    #define ull unsigned long long
    #define ll long long
    #define pii pair<int, int>
    #define mp make_pair
    #define pb push_back
    #define nl cout << "\n";
    #define mem(a, b) memset((a), (b), sizeof((a)))
    #define all(c) (c).begin(), (c).end()
    #define file "P:\\cpp\\phuc"
    using namespace std;

    const int oo = 1e9 + 7;
    const int mod = 1e9 + 7;
    const int N = 2e5 + 5;
    int n , a[N] , b[N] , length , c[N] , ans1[N] , ans2[N] , ans;
    int bs(int l , int r , int x , int find[N]){
        int mid = (l + r) / 2;
        if(x == find[mid]) return mid;
        if(r - l <= 1){
            if(find[l] >= x) return l;
            return r;
        }
        if(find[mid] > x) return bs(l , mid , x , find);
        if(find[mid] < x) return bs(mid , r , x , find);
    }
    void inp()
    {
        cin >> n ;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }
    }

    void solve()
    {
        for(int i = 1 ; i <= n ; i++){
            b[i] = oo;
            c[i] = oo;
        }
        length = 1;
        b[1] = c[1] = -oo;
        for(int i = 1 ; i <= n ; i++){
            int pos = bs(1 , length , a[i] , b);
            if(pos == length){
                b[pos] = a[i];
                ans1[i] = length;
                length++;
            }
            else{
                b[pos] = a[i];
                ans1[i] = pos;
            }
        }
        // cout << length;
        reverse(a + 1 , a + n + 1);
        length = 1;
        for(int i = 1 ; i <= n ; i++){
            int pos = bs(1 , length , a[i] , c);
            if(pos == length){
                c[pos] = a[i];
                ans2[i] = length;
                length++;
            }
            else{
                c[pos] = a[i];
                ans2[i] = pos;
            }
        }
        reverse(ans2 + 1 , ans2 + 1 + n);
        for(int i = 1 ; i <= n ; i++){
            ans = max((min(ans1[i] , ans2[i]) - 1) * 2 + 1 , ans);
        }
        cout << ans;
    }

    void run_with_file()
    {
    if(fopen(file".inp","r")){
        freopen(file".inp","r", stdin);
        freopen(file".out", "w", stdout);
    }
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        run_with_file();
        inp();
        solve();
    }