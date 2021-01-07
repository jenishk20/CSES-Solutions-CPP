#include<bits/stdc++.h>

using namespace std;
#define PI              3.1415926536

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

#define inf             1e15
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
const int M = 1e9 + 7;
long long mod(long long x) {
	return ((x % M + M) % M);
}
long long add(long long a, long long b) {
	return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b) {
	return mod(mod(a) * mod(b));
}
bool f(int x, int y)
{
	return x > y;
}


void solve()
{
	int n, m, q;
	cin >> n >> m >> q;

	int mat[n + 1][n + 1];

	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				mat[i][j] = 0;

			}
			else
			{
				mat[i][j] = inf;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;

		mat[p][q] = min(r, mat[p][q]);
		mat[q][p] = min(r, mat[q][p]);
	}

	for (int k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}


	while (q--)
	{
		int x, y;
		cin >> x >> y;

		if (mat[x][y] == inf)
		{
			cout << "-1\n";
		}
		else
		{
			cout << mat[x][y] << endl;
		}
	}
}

int32_t main()
{
	//c_p_c();
	FIO;
	//w(t)
	solve();
}