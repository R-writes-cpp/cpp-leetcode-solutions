#include <array>
#include <vector>

using namespace std;
// best time: 67 ms (99.26th percentile), 107.00 MB (80th percentile)

/* explanation:
 * to find the maximum prime difference, simply subtract the leftmost prime index from the rightmost prime index. this will ensure that the indices are as far apart as possible
 * for our prime checking function, note that nums[i] is a positive integer strictly less than or equal to 100. this implies that the only potential factors of nums[i] lie between 1 and 10, and hence the only prime factors nums[i] can have are 2, 3, 5, and 7
 * thus we only need to check if 2, 3, 5 and 7 divide nums[i]
*/

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int last_idx = nums.size() - 1;

        auto leftmost_prime_idx = [this, &nums, last_idx] {
            for (int i {0}; i < last_idx; ++i)
                if (is_prime(nums[i]))
                    return i;

            return last_idx;
        }();

        auto rightmost_prime_idx = [this, &nums, last_idx] {
            for (int i {last_idx}; i != 0; --i)
                if (is_prime(nums[i]))
                    return i;

            return 0;
        }();

        return std::move(rightmost_prime_idx) - std::move(leftmost_prime_idx);
    }

private:
    static constexpr array<int, 4> primes_to_check {2, 3, 5, 7};

    bool is_prime (int n) {
        if (n == 1)
            return false;

        for (auto p : primes_to_check)
            if (p >= n)
                return true;
            else if (n % p == 0)
                return false;

        return true;
    }
};
