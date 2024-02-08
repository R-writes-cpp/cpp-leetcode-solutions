#include <vector>

using namespace std;
// best time: 39 ms (91st percentile), 50.84 MB (24th percentile)
// time complexity: O(n)
// memory complexity: O(1)

/* explanation:
 * at any moment, there always exists some index j that splits the array between the indexes we know are accessible and the indexes which we don't know are accessible (as far as we know)
 * for example: let there be a vector<int> v {2, 3, 1, 1, 4}. when we start off at this array, the "j index" is 2 - the indexes before it are accessible but we don't know for sure whether the indexes after it are accessible
 * as we traverse the indexes we can currently access, we discover that this maximum index can be increased and we'll end up reaching more indexes
 * for example, when we pass through the 2 indexes in front of index 0 in vector v, we find out that the new maximum index is 4, because index 1 says we can go 3 indexes ahead of it at most
 * when we discover this, we'll set the new value of j to this value since it is greater.
 * we'll repeat this process until we can't go any further. once this happens, we can check if the index we ended up on is equal to the final index of the array.
 * if that is the case, then we return true (we managed to jump to the end). otherwise, we return false
*/

bool canJump(vector<int>& nums) {
    int ahead = nums[0];
    size_t max_idx = nums.size() - 1;
    for (size_t i = 1; i <= ahead && ahead < max_idx; ++i)
        if (i + nums[i] > ahead)
            ahead = i + nums[i];

    return max_idx <= ahead;
}
