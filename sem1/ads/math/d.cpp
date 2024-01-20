/*
**    Firstly,I bow my head to Vishnu 
**            The preserver lord of the triple world. 
**    And enunciate the code of regal conduct
**            From numerous scriptures called. 
*/

#include<bits/stdc++.h>
#include<chrono>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef bool bl;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vector<ll>> vvll;

typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pair<ll, vector<ll>>> vpllvll;

typedef map<ll, ll> mll;
typedef map<ll, vector<ll>> mllvll;
typedef map<ll, pair<ll, ll>> mllpll;

typedef set<ll> sll;
typedef multiset<ll> msll;
typedef deque<ll> dll;
typedef stack<ll> stll;
typedef queue<ll> qll;
typedef vector<bool> vbl;

#define nline '\n'
#define deci(x, y)     fixed<<setprecision(y)<<x
#define gcd           __gcd
#define ff first
#define ss second
#define mod0 998244353
#define mod1 1000000007
#define mod2 998244353
#define pi 3.1415926535897932384626433832795
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)(x).size()
#define lb lower_bound
#define ub upper_bound
// LOOPS------------------------------------------------------------------------------------------------------------------------
#define repg(i, a, b, c) for(ll i = a; i < b; i += c)
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i > b; i--)
#define rrepg(i, a, b, c) for(ll i = a; i > b; i -= c)
#define trav(a,x) for (auto& a : x)
// DEBUG------------------------------------------------------------------------------------------------------------------------
#define testdebug(tc) cerr << "TEST CASE: " << tc << "----------" << endl;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "Line No. " << __LINE__ << ": " #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
//void _print(Mint t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(queue <T> q);
template <class T> void _print(deque <T> q);
template <class T> void _print(stack <T> s);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.FI); cerr << ","; _print(p.SE); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.front()); cerr << " "; q.pop();} cerr << "]";}
template <class T> void _print(deque <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.front()); cerr << " "; q.pop_front();} cerr << "]";}
template <class T> void _print(stack <T> s) {cerr << "[ "; while (!s.empty()) {_print(s.top()); cerr << " "; s.pop();} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// -----------------------------------------------------------------------------------------------------------------------------
const ll mod=mod1;
void ckmin(ll &a,ll b){
    a=min(a,b);
}
void ckmax(ll &a,ll b){
    a=max(a,b);
}
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// m/n = a/b + c/d 
void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll gcd_ab = gcd(a, b), gcd_cd = gcd(c, d);
    a /= gcd_ab;
    b /= gcd_ab;
    c /= gcd_cd;
    d /= gcd_cd;
    
    ll ad_cb = a * d + c * b;
    ll bd = b * d;
    ll gcd_ans = gcd(ad_cb, bd);
    cout << ad_cb / gcd_ans << " " << bd / gcd_ans;
}
int main(){
    FAST
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<nline;
    }
    return 0;
}