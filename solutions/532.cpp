#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
// best time: 17 ms (80th percentile), 13.1 MB (73rd percentile)

/* explanation:
 * we'll use an unordered set to keep track of all the unique elements in the vector
 * we'll then go through this unordered set (instead of the original vector, which will have a greater or equal size) and see if there exists an element which is k greater than the current element
 * if there is, then that's a new k-diff pair to add to our return counter
*/

int findPairs(vector<int>& nums, int k) {
    int ret = 0;

    if (k) {
        unordered_set<int> nums_s (nums.begin(), nums.end());

        for (auto& i : nums_s)
            if (nums_s.count(i + k))
                ++ret;

        return ret;
    }

    unordered_map<int, int> freqs (nums.size());
    for (int& i : nums)
        ++freqs[i];

    for (auto& [i, val] : freqs)
        if (val > 1)
            ++ret;

    return ret;
}
