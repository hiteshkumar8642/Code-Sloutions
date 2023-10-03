#User function Template for python3

class Solution:
    def colName (self, n):
        # your code here
        s="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        c=26
        ans=""
        lvl=1
        f=n
        n-=1
        while n>=c:
            n=n-c
            c=c*26
            lvl+=1
        
        
        for l in range(lvl):
            c=int(c/26)
            q=int(n/c)
            r=int(n%c)
            ans+=s[q]
            n=r
    
            
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int (input ())
for tc in range (t):
    n = int (input ())
    ob = Solution()
    print (ob.colName (n))
    

# } Driver Code Ends