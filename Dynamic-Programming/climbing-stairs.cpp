/**
 * 70. Climbing Stairs
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
**/

//C++ solution for leetcode:

class Solution {
public:

    /**
     * Fibonacci Sequence Pattern
     * Time Complexity O(n)
     * Space Complexity O(1)
    **/
    int ans(int n)
    {
        if(n == 1)
            return 1;
            
        int prev2 = 1, prev1 = 1, curr;

        for(int i=2; i<=n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int climbStairs(int n) {
        return ans(n);
    }
};