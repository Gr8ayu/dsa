#include <bits/stdc++.h>
using namespace std;
int t[1002][1002];

int knapsack(int val[], int weight[], int W, int n){
    if(n==0 or W==0)
        return 0;
    if(t[n-1][W-1]!=-1)
        return t[n-1][W-1];
    if(weight[n-1]<=W){
        return t[n-1][W-1]=max(val[n-1] + knapsack(val, weight, W-weight[n-1], n-1), knapsack(val, weight, W, n-1));
    }
    return t[n-1][W-1] = knapsack(val, weight, W, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    cout.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
	    memset(t, -1, sizeof(t));
	    int n,W;
	    cin >> n;
	    cin >> W;
	    int val[n], weight[n];
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
	    int res = knapsack(val, weight, W, n);
	    cout << res << endl;
	}
	
	return 0;
}
