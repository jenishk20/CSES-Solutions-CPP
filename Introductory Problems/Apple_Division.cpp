
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
bool f(int x, int y)
{
	return x > y;
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

	int a[n];
	int i;
	int j;
	int sum = 0;
	int ans = INT_MAX;
	for (i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	//cout << sum << endl;

	for (i = 0; i < (1 << n) - 1; i++)
	{
		int tsum = 0;
		for (j = 0; j < n; j++)
		{
			if (i & (1 << j))
				tsum += a[j];

		}
		ans = min(ans, abs(sum - tsum - tsum));

	}
	cout << ans << endl;




}



int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}






