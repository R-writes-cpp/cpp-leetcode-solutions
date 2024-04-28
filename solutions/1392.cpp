#include <string>

using namespace std;
// best time: 27 ms (93rd percentile), 17.24 MB (91st percentile)
// time complexity: O(n)
// space complexity: O(1) auxiliary

/* explanation:
 * to solve the problem, one might check all the possible prefixes of a given length and compare them with their suffixes of the same length via string comparison (==)
 * however, this is suboptimal and has a quadratic time complexity. a smarter solution would be to use a rolling hash
 * we know that we can use a rolling hash because all the prefixes build upon the previous. so for example the (n+1)th prefix will be equal to the nth prefix, plus the (n+1)th character in s
 * in this solution, we will use a polynomial rolling hash with p set to 31
 * for each prefix length, we'll check whether the prefix and suffix have an equal hash. if they do then only then will we actually compare the two strings. this is done to filter out collisions
*/

class Solution {
public:
    string longestPrefix(string& s) {
        string ret {""};
        if (s.size() == 1)
            return ret;

        constexpr char a {'a'};
        unsigned int prefix_hash = s.front() - a,
                     suffix_hash = s.back()  - a;

        if (prefix_hash == suffix_hash)
            ret = s.substr(0, 1);

        constexpr unsigned int p {31};
        auto p_multiplier {p};

        const auto begin {s.begin()};

        for (unsigned int prefix_len {2}, size = s.size(); prefix_len < size; ++prefix_len) {
            prefix_hash += (s[prefix_len - 1] - a) * p_multiplier;
            suffix_hash = (s[size - prefix_len] - a) + p * suffix_hash;
            p_multiplier *= p;

            if (prefix_hash == suffix_hash) {
                if (const auto ret_size {ret.size()}; equal (begin + ret_size, begin + prefix_len, begin + size - prefix_len + ret_size)) // we know that the existing value of ret is the longest happy prefix and suffix seen so far, hence the prefix and suffix are equal until the end of ret. so for the current prefix, we just need to checked the unseen part of the current prefix (i.e. the part of the current prefix that's after the value of ret)
                    ret += s.substr(ret_size, prefix_len - ret_size);
            }
        }

        return ret;
    }
};
