class Solution {
    public boolean isPalindrome(int x) {
        int num=0,num1;
        num1=x;
        if(x<0)
            return false;
        while (x>0)
        {
            num*=10;
            num=num+x%10;
            x=x/10;
        }
        if(num==num1)
        {
            return true;
        }
        else 
            return false;
            
        
    }
}