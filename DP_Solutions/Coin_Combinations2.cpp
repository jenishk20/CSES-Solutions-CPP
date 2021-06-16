
#include<bits/stdc++.h>

using namespace std;


#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(a)      (a).begin(),(a).end()

#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

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
int  add(int a, int b)
{
	return mod(mod(a) + mod(b));
}
bool comp(pii a, pii b)
{

	return  a.ss < b.ss;
}
bool f(int x, int y)
{
	return x > y;
}
const int N = 100000 + 3;
bool check(int x, int y, int a, int b, int sum)
{
	int low = 0;
	int high = sum;

	while (low <= high)
	{
		int m = (low + high) / 2;

		int s1 = m;
		int s2 = sum - m;

		int tred = a * s1 + b * s2;
		int tblue = a * s2 + b * s1;

		if (tred <= x && tblue <= y)
		{
			return 1;
		}
		else if (tred > x)
		{
			if (a > b)
			{
				high = m - 1;
			}
			else
			{
				low = m + 1;
			}
		}
		else
		{
			if (b > a)
			{
				high = m - 1;

			}
			else
			{
				low = m + 1;
			}
		}
	}
	return 0;
}
void solve()
{


	int n, x;
	cin >> n >> x;

	int a[n];
	int i;
	for (i = 0; i < n; i++)
		cin >> a[i];

	vi dp(x + 1, 0);
	dp[0] = 1;
	for (int sum = 0; sum <= x; sum++)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i] <= sum)
			{
				dp[sum] = (dp[sum] + dp[sum - a[i]]) % M;
			}
		}
	}
	cout << dp[x] << endl;

}


int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}






