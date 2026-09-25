class Solution {
public:
    bool isPalindrome(int n) {
        long long rev=0;
        int dup=n;
        if(n<0){
            return false;
        }
        while(n>0){
            int lastdigi=n%10;
            rev= rev*10+lastdigi;
            n=n/10;
        }
        return rev==dup;
        

        

    }
};