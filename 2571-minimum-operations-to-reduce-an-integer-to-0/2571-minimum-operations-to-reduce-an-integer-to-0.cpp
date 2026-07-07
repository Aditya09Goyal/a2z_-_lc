class Solution {
public:
    int solve(int num)
    {
        int power = log2(num) ; 
        int lower = 1<<power ; 
        int upper = 1<<(power+1) ; 
        return (num-lower <= upper - num) ? lower : upper ; 
    }
    int minOperations(int n) {
        int cnt = 0 ; 
        while(n!=0)
        {
            int nearest_power_of_2 = solve(n); 
            n = abs(nearest_power_of_2 - n) ; 
            cnt++;
        }
        return cnt ; 
    }
};