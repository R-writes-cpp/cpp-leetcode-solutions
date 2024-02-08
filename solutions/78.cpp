#include <vector>
#include <cmath>

using namespace std;
// best time: 0 ms, 7.4 MB (63rd percentile)
/* explanation:
 * we can abstract each subset of a given vector into binary
 * each bit will represent whether a certain index is present in the current subset
 * e.g., 101 will represent the 0th element and the 2nd element being present in the subset, while the 1st element gets left behind
 * we'll increment an integer and check each bit to see whether we should include the element it represents in our current subset!
*/

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret (pow (2, static_cast<int>(nums.size())));
    *(ret.end() - 1) = nums;

    for (size_t i = 0, end = ret.size() - 1; i < end; ++i)
        for (int j = 0, k = i; k != 0; k /= 2, ++j)
            if (k % 2)
                ret[i].push_back(nums[j]);

    return ret;
}
