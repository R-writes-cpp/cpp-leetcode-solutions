#include <vector>

using namespace std;
// best time: 186 ms (100th percentile at the time of submitting!), 125.77 MB (100th percentile)

/* explanation:
 * by looping through the array just once, we can answer each query in O(1) time
 * to do this with dynamic programming, we will find the number of same parity pairs from [0, n] for every index n in the array
 * then, we can define queries[i] as being true if and only if the number of same parity pairs up to queries[i][0] is equal to the number of same parity pairs up to queries[i][1]
 * this works because queries[i] will only be true if there are no same parity pairs between them, and if the number of same parity points hasn't increased by queries[i][1] then that means there are no new same parity pairs between queries[i][0] and queries[i][1]
*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> same_parity_pairs (nums.size());

        for (int i {1}, size = nums.size(); i < size; ++i)
            same_parity_pairs[i] = same_parity_pairs[i-1] + (nums[i] % 2 == nums[i-1] % 2);

        vector<bool> ret (queries.size());

        for (int i {0}, size = queries.size(); i < size; ++i)
            if (same_parity_pairs[queries[i][1]] == same_parity_pairs[queries[i][0]])
                ret[i] = true;

        return ret;
    }
};
