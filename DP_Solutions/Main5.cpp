
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
int memo[5001][5001];
int recur(string &s, string &t, int n, int m)
{
	if (n == 0)
		return m;
	if (m == 0)
		return n;
	if (memo[n][m] != -1)
		return memo[n][m];
	if (s[n - 1] == t[m - 1])
		return memo[n][m] = recur(s, t, n - 1, m - 1);

	int op1 = recur(s, t, n - 1, m - 1); //Replace
	int op2 = recur(s, t, n, m - 1); //Insert
	int op3 = recur(s, t, n - 1, m);//Delete

	return memo[n][m] = 1 + min({op1, op2, op3});

}
void solve()
{
	string s, t;
	cin >> s >> t;
	memset(memo, -1, sizeof memo);
	cout << recur(s, t, s.size(), t.size());
}

int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();



}





