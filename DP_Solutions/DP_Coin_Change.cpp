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
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	int i;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	int dp[n + 2][m + 2];
	memset(dp, 0, sizeof dp);

	int j;
	for (i = 1; i <= n; i++)
	{

		for (j = 1; j <= m; j++)
		{
			if (i == 1)
			{
				if (a[i] == 0 || a[i] == j)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = 0;
				}
			}
			else
			{
				if (a[i] == 0 || a[i] == j)
				{
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % M;
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}
	}
	int ans = 0;

	for (i = 1; i <= m; i++)
	{
		ans = (ans + dp[n][i]) % M;
	}
	cout << ans << endl;


}

int32_t main()
{

	c_p_c();

	int tt = 1;
	//w(t)
	solve();

}