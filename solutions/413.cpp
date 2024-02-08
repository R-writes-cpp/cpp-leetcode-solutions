#include <vector>

using namespace std;
// best time: 0 ms, 7.3 MB (91st percentile)
// time complexity: O(n)

int numberOfArithmeticSlices(vector<int>& nums) {
    int ret = 0, current = 0;

    auto add_to_ret = [&ret, &current] {
        ret += current + (current * current - current) / 2;
        current = 0;
    };

    for (int i = 0; i + 2 < nums.size(); ++i)
        if (nums[i+2] == 2 * nums[i+1] - nums[i])
            ++current;
        else
            add_to_ret();

    if (current)
        add_to_ret();
    return ret;
}
