//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        int ten=0,fiv=0,twenty=0;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
                fiv++;
            else if(bills[i]==10)
            {
                ten++;
                if(fiv>0)
                    fiv--;
                else
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                twenty++;
                if(fiv>0 && ten>0)
                {
                    fiv--;
                    ten--;
                }
                else if(fiv>1)
                    fiv-=3;
                else 
                {
                    flag=1;
                    break;
                }
            }
        }
        return flag==0;
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends