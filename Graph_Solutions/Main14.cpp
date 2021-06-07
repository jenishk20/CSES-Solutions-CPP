
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
vi  graph[(int)1e5 + 2];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void solve()
{

	int n, m;
	cin >> n >> m;

	char a[n][m];

	int vis[n][m];
	memset(vis, 0, sizeof vis);
	queue<pii>q;

	int sr, sc, er, ec;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'A')
			{
				sr = i;
				sc = j;
			}
			if (a[i][j] == 'B')
			{
				er = i;
				ec = j;
			}
		}
	}
	q.push({sr, sc});

	vis[sr][sc] = 1;
	map<pii, pair<pii, char>>ma;
	while (!q.empty())
	{
		pii p = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = p.ff + dx[k];
			int ny = p.ss + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] != '#')
			{

				char dir;
				if (dx[k] == -1 && dy[k] == 0)
					dir = 'U';
				if (dx[k] == 1 && dy[k] == 0)
					dir = 'D';
				if (dx[k] == 0 && dy[k] == 1)
					dir = 'R';
				if (dx[k] == 0 && dy[k] == -1)
				{
					dir = 'L';
				}

				ma[ {nx, ny}] = {{p.ff, p.ss}, dir};
				if (a[nx][ny] == 'B')
				{
					pii end = {nx, ny};
					string res = "";
					while (true)
					{
						res += ma[end].ss;
						end = ma[end].ff;

						if (end.ff == sr && end.ss == sc)
							break;
					}
					reverse(res.begin(), res.end());
					cout << "YES\n";
					cout << res.size() << endl;
					cout << res << endl;
					return;
				}
				q.push({nx, ny});
				vis[nx][ny] = 1;


				//path[nx][ny] = {dx[k], dy[k]};
			}

		}
	}

	if (!vis[er][ec])
	{
		cout << "NO";
		return;
	}


}


int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}






