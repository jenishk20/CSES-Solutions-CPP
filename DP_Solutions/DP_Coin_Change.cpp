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
struct  Project
{
	int st, en, rwd;
};
bool cmp(Project p1, Project p2)
{
	return p1.en < p2.en;
}
int find(vi &endPoints, int val)
{
	auto it = lower_bound(endPoints.begin(), endPoints.end(), val);

	if (it == endPoints.begin())
		return 0;
	else
	{
		it--;
		return 1 + distance(endPoints.begin(), it);
	}
}
void solve()
{
	int n;
	cin >> n;
	vector<Project>proj(n + 1);
	vector<int>endPoints;
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		cin >> proj[i].st >> proj[i].en >> proj[i].rwd;
	}
	sort(proj.begin() + 1, proj.end(), cmp);
	n = proj.size();
	for (i = 1; i < n; i++)
	{
		//cout << proj[i].st << " " << proj[i].en << " " << proj[i].rwd << endl;
		endPoints.pb(proj[i].en);
	}
	int dp[n + 1];
	dp[0] = 0;

	for (i = 1; i < n; i++)
	{
		int op1 = dp[i - 1];
		int op2 = proj[i].rwd;


		j = find(endPoints, proj[i].st);
		//cout << j << endl;
		op2 += dp[j];

		dp[i] = max(op1, op2);
		//cout << dp[i] << endl;
	}
	cout << dp[n - 1] << endl;
}

int32_t main()
{

	c_p_c();

	int tt = 1;
	//w(t)
	solve();

}