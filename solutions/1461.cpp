#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;
// best time: 128 ms (89th percentile), 40.10 MB (90th percentile)

/* explanation:
 * we can use a rolling hash to keep track of the binary strings we've seen so far. in this solution we'll use the polynomial rolling hash function
 * we'll keep track of the unique hashes with an unordered set and once we find 2^k binary strings, we'll return true
 * this is because there will be exactly 2^k binary strings, since for each character in the string of length k there are exactly 2 options for that character (either 0 or 1)
 * if we don't have 2^k binary strings by the end of the string, then we wouldn't have found all of them. hence the string doesn't have all the codes
*/

class Solution {
public:
    bool hasAllCodes(string& s, int k) {
        const int unique_codes {static_cast<int>(pow(2, k))};
        if (s.size() + 1 < k + unique_codes)
            return false;

        unordered_set<int> codes_seen;
        codes_seen.reserve(unique_codes);
        int code_hash {0};

        for (int i {0}, p {1}; i < k; ++i) {
            if (s[i] & 1) // the string only consists of '0' and '1' characters. the rightmost bit of '1' is 1 but the rightmost bit of '0' is 0. so this is just a hash asking if s[i] == '1'
                code_hash += p;
            p *= 2;
        }

        codes_seen.insert(code_hash);

        for (int i {1}, i_max {static_cast<int>(s.size()) - k}, last_char_pow {unique_codes / 2}; i <= i_max; ++i) {
            code_hash = (code_hash - (s[i - 1] & 1)) / 2 + (s[i + k - 1] & 1 ? last_char_pow : 0);
            codes_seen.insert(code_hash);

            if (codes_seen.size() == unique_codes)
                return true;
        }

        return false;
    }
};
