#include <vector>

using namespace std;
// best time: 22 ms (92nd percentile)

/* explanation:
 * let sol(n) be the smallest number of squares that sum to n
 * we know that one potential way to get a number of squares that sum to n+1, n+4, n+9, etc. is to simply take n and add another square number on, giving a total of sol(n) + 1 square numbers (note that we only check numbers whose difference from n is a square number - this is because adding a square will only add 1 to the total number of squares needed but adding a non-square will take multiple extra squares, which is definitely not optimal)
 * however, this isn't guaranteed to be optimal - for example, even though the solution combination for 7 is 4 + 1 + 1 + 1, which means that sol(7) is 4, sol(8) is NOT 5, as its optimal sum is 4 + 4, rather than 4 + 1 + 1 + 1 + 1.
 * one way to use this recursive definition to get the optimal solution is to check all these combinations and then find the one with the minimum length
 * this results in the formula sol(n) = min {1 + sol(n-1), 1 + sol(n-4), 1 + sol(n-9) ...}
 * we can use bottom-up dynamic programming to apply this formula and obtain the solution for the integer n provided
*/

class Solution {
public:
    int numSquares(int& n) {
        size_t size = n + 1;
        vector<int> dp (size);

        for (size_t i = 1; i < size; ++i) {
            int i_sol = i;
            for (size_t j = 1, square = j; square <= i; square += 2 * (j++) + 1) // this for loop uses the fact that the difference between the (n+1)th square and the nth square is equal to the nth odd number
                i_sol = min (i_sol, dp[i-square] + 1);

            dp[i] = i_sol;
        }

        return dp[n];
    }
};
