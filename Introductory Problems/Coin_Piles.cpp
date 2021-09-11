#include<bits/stdc++.h>

using namespace std;


#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>

#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(a)      (a).begin(),(a).end()
#define inf 1e17
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 1000001
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const long long   M = 1e9 + 7;


void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
}

int mod(int x) {
	return (x % M + M) % M;
}
bool f(int x, int y)
{
	return x > y;
}
int  add(int a, int b)
{
	return mod(mod(a) + mod(b));
}


void solve()
{
	int a, b;
	cin >> a >> b;

	int k1 = 2 * a - b;
	int k2 = 2 * b - a;
	if (k1 >= 0 && k1 % 3 == 0 && (k2) % 3 == 0 && k2 >= 0)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}


}

int32_t main()
{

	c_p_c();

	int tt = 1;
	w(t)
	solve();

}
