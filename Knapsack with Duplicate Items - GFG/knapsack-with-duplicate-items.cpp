//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n,int w,int val[],int wt[],vector<int> &dp){
        // bagc = bag capacity of dp
        // curbagc = current bag capacity in wts array
        // rbc = remaining bag capacity
        // rbcv = remaining bag capacity value =  dp[rbcv]
        // modifying the dp[of bag capacity]
        
        for(int bagc = 0;bagc<=w;bagc++){   
            int max = 0;
            for(int curbagc = 0;curbagc<n;curbagc++){    
                if(wt[curbagc]<=bagc){
                    int rbc = bagc - wt[curbagc];        
                    int rbcv = dp[rbc];                  
                    dp[bagc] = rbcv + val[curbagc];     
                    if(dp[bagc]>max) max = dp[bagc];
                }
            }
            dp[bagc] = max;  
        }
        int max = 0;
        for(auto it:dp){
            if(it>=max)max = it;
        }
        return max;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> dp(W+1,0);
        int ans = solve(N,W,val,wt,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends