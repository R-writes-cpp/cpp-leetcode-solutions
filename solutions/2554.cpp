#include <vector>

using namespace std;
// best time: 123 ms (98th percentile), 116.52 MB (94th percentile)

/* explanation:
 * to select as many integers as possible, we will choose the smallest ones possible. this is because the smallest ones will contribute less to the overall sum than the rest, but will still count as one more integer (greedy)
 * to do this, we can loop through all the integers from 1 to n in order and add them to our total if and only if they aren't banned
 * to check whether an integer is banned or not, we'll use a vector<bool> which will have all the values in banned set to true
*/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> is_allowed (n, true);
        for (auto& b : banned)
            if (b <= n)
                is_allowed[b-1] = false;

        int ret = 0;
        for (int sum = 0, i = 1; i + sum <= maxSum && i <= n; ++i)
            if (is_allowed[i - 1])
                ++ret,
                sum += i;

        return ret;
    }
};
