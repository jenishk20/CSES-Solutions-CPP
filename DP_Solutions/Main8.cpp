#include<bits/stdc++.h>

using namespace std;


#define ff              first
#define ss              second

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

#define ldd long double
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
//int dp[1001][100001];
// int recur(int idx, int p[], int pa[], int n, int have)
// {
// 	if (idx == n || have < 0)
// 		return 0;

// 	if (dp[idx][have] != -1)
// 		return dp[idx][have];
// 	if (have >= p[idx])
// 	{
// 		int op1 = pa[idx] + recur(idx + 1, p, pa, n, have - p[idx]);
// 		int op2 = recur(idx + 1, p, pa, n, have);

// 		return dp[idx][have] = max(op1, op2);
// 	}
// 	return dp[idx][have] = recur(idx + 1, p, pa, n, have);
// }
void solve()
{
	int n, x;
	cin >> n >> x;
	//memset(dp, -1, sizeof dp);
	int p[n + 1], pa[n + 1];
	int dp[n + 1][x + 1];
	//vector<vi>dp(n + 1, vi(x + 1));
	int i, j;
	for (i = 1; i <= n; i++)
		cin >> p[i];
	for (i = 1; i <= n; i++)
		cin >> pa[i];


	for (i = 0; i <= n; i++)
	{
		for (int money = 0; money <= x; money++)
		{
			if (money == 0 || i == 0)
			{
				dp[i][money] = 0;
			}
			else
			{
				int op1 = (i == 1) ? 0 : dp[i - 1][money];
				int op2 = (p[i] <= money) ? pa[i] + dp[i - 1][money - p[i]] : 0;
				dp[i][money] = max(op1, op2) ;
			}
		}
	}
	cout << dp[n][x] << endl;
	//cout << recur(0, p, pa, n, x);
}

int32_t main()
{

	c_p_c();

	int tt = 1;
	//w(t)
	solve();

}