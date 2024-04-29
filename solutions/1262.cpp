#include <vector>
#include <array>

using namespace std;
// best time: 19 ms (99.14th percentile), 27.44 MB (90th percentile)

/* explanation:
 * to find the maximum sum divisible by 3, we can keep track of the entire sum of nums and then try to remove the smallest numbers possible to make the sum divisible by 3
 * so for example, if the sum of nums has a remainder of 1 when divided by 3, then we can remove a subsequence with a sum that also has that remainder (e.g. [4, 3]) to make nums' new sum divisible by 3
 * if sum % 3 == 1, then we can either remove the smallest number with a remainder of 1 when divided by 3 or we can remove the two smallest numbers with a remainder of 2 when divided by 3.
 * in the former case the subsequence sum is 3n + 1 for some positive integer n. this, modulo 3, is equivalent to 1, and so when we take it away from sum, the sum will be divisible by 3 (it has a remainder of 0)
 * in the latter case the subsequence sum is 3n + 2 and 3m + 2 for some positive integers m and n. when added together we get 3(n + m) + 4 which, modulo 3, is equivalent to 1. so when we take
 * we can employ a similar technique when sum has a remainder of 2 divided by 3: we can either remove the smallest number with a remainder of 2 or remove two numbers with a remainder of 1
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        array<int, 2> smallest_mod_1 {10001, 10001};
        array<int, 2> smallest_mod_2 {10001, 10001};

        int sum {0};
        for (int n : nums) {
            sum += n;
            if (n % 3 == 1) {
                if (smallest_mod_1.front() > n) {
                    swap (smallest_mod_1.back(), smallest_mod_1.front());
                    smallest_mod_1.front() = n;
                } else
                    smallest_mod_1.back() = min (smallest_mod_1.back(), n);
            } else if (n % 3 == 2) {
                if (smallest_mod_2.front() > n) {
                    swap (smallest_mod_2.back(), smallest_mod_2.front());
                    smallest_mod_2.front() = n;
                } else
                    smallest_mod_2.back() = min (smallest_mod_2.back(), n);
            }
        }

        switch (sum % 3) {
            case 0:
                return sum;
            case 1:
                return sum - min(smallest_mod_1.front(), smallest_mod_2.front() + smallest_mod_2.back());
            default:
                return sum - min(smallest_mod_2.front(), smallest_mod_1.front() + smallest_mod_1.back());
        }
    }
};
