#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MAXN 2001
#define MAXW 2001

using namespace std;

int n, S;
vector<int> a, w;
int dp[MAXN][MAXW];
int pred[MAXN][MAXW];


int main(){
	while(cin >> S){
		cin >> n;
		a = vector<int>(n);
		w = vector<int>(n);
		for(int i=0; i<n; i++)
			cin >> a[i] >> w[i];
		
		memset(dp, 0, sizeof(dp));
		memset(pred, 0, sizeof(dp));
		for(int i=0; i<n; i++){
			for(int j=0; j<=S; j++){
				//take
				if( j >= w[i] && dp[i][j] + a[i] > dp[i+1][j-w[i]] ){
					dp[i+1][j-w[i]] = dp[i][j] + a[i];
					pred[i+1][j-w[i]] = 1; 
				}
				// no take
				if( dp[i][j] > dp[i+1][j] ){
					dp[i+1][j] = dp[i][j];
					pred[i+1][j] = 0;
				}
			}
		}
		int bestj = 0;
		for(int j=0; j<=S; j++){
			if(dp[n][j] > dp[n][bestj])
				bestj = j;
		}
		vector<int> ans;
		for(int i=n; i>0; i--){
			if(pred[i][bestj]){
				ans.push_back(i-1);
				bestj += w[i-1];
			}
			else bestj = bestj;
		}
		cout << ans.size() << endl;
		for(int ii : ans) cout << ii << " ";
		cout << endl;
	}
	
}
