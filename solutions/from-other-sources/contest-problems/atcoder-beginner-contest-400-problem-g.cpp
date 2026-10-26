#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "templates/debug.h"
#else
#define dbg(...) (void)0
#define here (void)0
#endif
#define ll long long
#define endl '\n'
#define PB emplace_back
#define PPB pop_back
#define MP make_pair
#define ALL(Name) Name.begin(),Name.end()
#define PII pair<int,int>
#define VI vector<int>
#define GI greater<int>
#define fi first
#define se second

const int N=100005;
int n,k;
array<int,3>a[N];
ll dp[N][12];
void ck(ll &x,ll y){x=max(x,y);}

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int _;cin>>_;while(_--)
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)cin>>a[i][j];
	sort(a+1,a+n+1,[](auto x,auto y){return max({x[0],x[1],x[2]})>max({y[0],y[1],y[2]});});
	memset(dp,0xc0,8*12*(n+3));
	dp[0][0]=dp[n+1][0]=0;
	for(int i=1;i<=k<<1;i++)
		for(int j=0;j<12;j++)
		{
			ck(dp[i][j],dp[i-1][j]+a[i][0]);
			ck(dp[i][j^1],dp[i-1][j]+a[i][1]);
			ck(dp[i][j^2],dp[i-1][j]+a[i][2]);
			if(j<8)ck(dp[i][j+4],dp[i-1][j]);
		}
	for(int i=n;i>k<<1;i--)
		for(int j=0;j<12;j++)
		{
			if(j<8)ck(dp[i][j+4],dp[i+1][j]+a[i][0]);
			if(j<8)ck(dp[i][(j+4)^1],dp[i+1][j]+a[i][1]);
			if(j<8)ck(dp[i][(j+4)^2],dp[i+1][j]+a[i][2]);
			ck(dp[i][j],dp[i+1][j]);
		}
	ll ans=0;
	for(int i=0;i<12;i++)ck(ans,dp[k<<1][i]+dp[(k<<1)+1][i]),dbg(i,ans);
	cout<<ans<<endl;

}

	return 0;
}
