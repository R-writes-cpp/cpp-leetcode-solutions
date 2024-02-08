#include <vector>
#include <algorithm>
using namespace std;
// best time: 0 ms, 9.12 MB (37th percentile)
// time complexity: O(n)

/* explanation:
 * before defining the main problem: the max number of houses we should skip is 2
 * if we skip 3 houses, say {i, j, k}, so that we can reach house l, we can still go to house j.
 * there's no reason not to go to house j because the money in the houses is always non-negative
 * now, the problem can be defined recursively:
 * the maximum money at a house with an index i is equal to the amount of money at i + max(max money at i-2, max money at i-3)
 * to get to i from i-2 we make 1 house skip (we skip i-1) and to get to i from i-3 we make 2 house skips (we skip i-1 and i-2).
 * these are the only houses we need to include in our recursive definition because there's no point in checking indexes which need 3 or more house skips, since that's not optimal
 * use dynamic programming!
 * dp[i] = nums[i] + max (dp[i-2], dp[i-3]);
*/

int rob(vector<int>& nums) {
    if (nums.size() < 3)
        return *max_element (nums.begin(), nums.end());

    nums[2] += nums[0];
    size_t i = 3;

    for (auto size = nums.size(); i < size; ++i)
        nums[i] += max (nums[i-2], nums[i-3]);

    return nums[i-1] > nums[i-2] ? nums[i-1] : nums[i-2];
}
