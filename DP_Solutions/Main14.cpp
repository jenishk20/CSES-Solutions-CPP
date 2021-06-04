
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
void solve()
{
	int n;
	cin >> n;
	char a[n + 1][n + 1];
	int dp[n + 1][n + 1];
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			char ch;
			cin >> ch;

			if (ch == '.')
				a[i][j] = 0;
			else
				a[i][j] = 1;

		}
	}
	if (a[n][n] == 1)
	{
		cout << "0";
		return;
	}

	for (i = n ; i >= 1; i--)
	{
		for (j = n ; j >= 1; j--)
		{

			if (i == n && j == n)
			{
				dp[i][j] = 1;
			}
			else
			{
				int op1 = (i + 1 <= n) ? dp[i + 1][j] : 0;
				int op2 = (j + 1 <= n) ? dp[i][j + 1] : 0;

				dp[i][j] = (op1 + op2) % M;

				if (a[i][j])
				{
					dp[i][j] = 0;
				}

			}
		}

	}
	// for (i = 1; i <= n; i++)
	// {
	// 	for (j = 1; j <= n; j++)
	// 	{
	// 		cout << dp[i][j] << " ";

	// 	}
	// 	cout << endl;
	// }
	cout << dp[1][1] << endl;
}

int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}





