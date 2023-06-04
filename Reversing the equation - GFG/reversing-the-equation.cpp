//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string s1="",s2="";
            for(int i=s.size()-1;i>=0;i--)
            {
                if(isdigit(s[i]))
                {
                    s2+=s[i];
                }
                else
                {
                    reverse(s2.begin(), s2.end());
                    s1=s1+s2;
                    s1+=s[i];
                    s2="";
                }
            }
            reverse(s2.begin(), s2.end());
            s1=s1+s2;
            return s1;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends