#include <vector>
#include <stdlib.h>

using namespace std;
// best time: 42 ms (98th percentile), 55.79 MB (100th percentile)
// time complexity: O(n)

class Solution {
public:
    Solution(vector<int>& nums) : nums(nums) {
        shuffled = nums,
        size = nums.size(),
        begin = shuffled.begin();
    }

    vector<int>& reset() { // return by reference! we never modify the original nums copy we have stored
        return nums;
    }

    vector<int>& shuffle() { // you can return by reference here as well because the return value is only checked once
        for (size_t i = 0; i < size; ++i) // the idea is to swap with a random iterator ahead of the current one - this allows us to shuffle all the element pairs without worrying about which elements we've used.
		    iter_swap (begin + i, begin + rand() % (size - i));

        return shuffled;
    }

private:
    vector<int>& nums;
    vector<int> shuffled;
    vector<int>::iterator begin;
    size_t size;
};
