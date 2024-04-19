#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
// best time: 95 ms (98th percentile), 90.45 MB (97th percentile)

/* explanation:
 * by definition of the GCD, the GCD of all the numbers in numsDivide will divide all the numbers in numsDivide
 * however, in this problem, we're not looking for the GCD (GREATEST common divisor), we're looking for the SMALLEST common divisor which is in the vector nums
 * note that any common divisor of all the numbers in numsDivide must divide the GCD. given this, to find the smallest common divisor of numsDivide in the vector nums, we can loop through nums and simply find the smallest number which divides the GCD previously described. this value will be the new minimum of nums
 * to calculate the minimum number of delete operations, we can simply count the number of numbers smaller than the new minimum. this works because after we delete all these smaller numbers, the minimum in nums can only be the new minimum
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int new_min {INT_MAX};

        {
            int nums_divide_gcd = [&numsDivide] {
                int size = numsDivide.size();
                if (size == 1)
                    return numsDivide[0];

                int ret {gcd(numsDivide[0], numsDivide[1])};

                for (int i {2}; i < size; ++i)
                    ret = gcd (numsDivide[i], ret); // using the fact that gcd (a, b, c) = gcd (a, gcd(b, c))

                return ret;
            }();

            for (int n : nums)
                if (n < new_min && nums_divide_gcd % n == 0)
                    new_min = n;
        }

        if (new_min == INT_MAX)
            return -1;
        else
            return count_if (nums.begin(), nums.end(), [new_min](int n) {
                return n < new_min;
            });
    }
};
