#include <vector>
#include <unordered_map>

using namespace std;
// best time: 99 ms (97th percentile)

/* explanation:
 * the first step is to record the frequencies of the different numbers in the array
 * once this is done, we can find the optimal number of operations to remove all occurences of each number
 * we should immediately try to perform as many three element removal operations as possible - this is the more efficient operation of the two, i.e. it removes more elements in one go
 * the number of three element removal operations we immediately perform is represented by the frequency divided by 3 (integer floor)
 * the number of operations we must perform after this depends on the frequency modulo 3. for example, in the case of 8, we'll perform that three element removal operation twice and have 2 elements remaining. we then perform the two element removal operation to reach 0. so we just do freq / 3 + 1 - this is the formula for the minimum operations of a frequency with a remainder of 2 when dividing by 3. it can be proved more formally with proof by induction.
 * in the case of the frequency modulo 3 being 1, using 10 as an example, we'll get 10 -> 7 -> 4 -> 1. we've performed 3 of these operations (freq / 3). the thing is, we can't remove a single element now, so we need to go "back up" to 4, where we'll perform 2 operations to remove two elements. thus the formula is freq / 3 - 1 + 2 = freq / 3 + 1.
 * now we'll just sum the minimum operations for each number's frequency to get the final answer
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freqs{};
        for (int& n : nums)
            ++freqs[n];

        int ret = 0;
        for (auto& p : freqs)
            if (auto& freq = p.second; freq == 1)
                return -1;
            else
                ret += freq / 3 + (freq % 3 != 0 ? 1 : 0);

        return ret;
    }
};
