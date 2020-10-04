#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    int n,sum;
	    cin >> n;
	    cin >> sum;
	    int weight[n];
	    bool dp[n+1][sum+1];
	    
	    for(int i=0; i<n; i++){
	        int temp;
	        cin >> temp;
	        weight[i] = temp;
	    }
	    for(int i=1;i<=sum;i++)
	        dp[0][i] = false;
	    for (int i=0;i<=n;i++)
	        dp[i][0] = true;
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++){
                if(weight[i-1]<=j)
                    dp[i][j] = dp[i-1][j-weight[i-1]] or dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        if(dp[n][sum]==true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
            
	    
	}
	
	return 0;
}
