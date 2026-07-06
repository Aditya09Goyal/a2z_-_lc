class Solution {
public:
    using ll = long long ; 
    long long minimumSteps(string s) {
        int len = s.length(); 
        ll pos_w = 0 ; 
        ll ans = 0 ; 
        for(int i=0;i<len;i++)
        {
            if(s[i]=='0') {
                ans += (i - pos_w) ; 
                pos_w++;
            }
        }
        return ans;
    }
};
        // example : 1 0 1 0 1 0 1
        // ans :     0 0 0 1 1 1 1 
        // just find sum of position of zeros 