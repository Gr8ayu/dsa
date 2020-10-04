#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
	    int n,W;
	    cin >> n;
	    cin >> W;
	    int val[n], weight[n], dp[n+1][W+1];
	    for(int i=0; i<n; i++){
	        int temp;
	        cin >> temp;
	        val[i] = temp;
	    }
	    for(int i=0; i<n; i++){
	        int temp;
	        cin >> temp;
	        weight[i] = temp;
	    }
	    for(int i=0;i<n+1;i++){
	        for(int j=0; j<W+1;j++){
	            if(i==0 or j==0){
	                dp[i][j]=0;
	            }
	            else if(weight[i-1]<=j){
	                dp[i][j] = max(val[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    cout << dp[n][W] << endl;
	}
	
	return 0;
}
