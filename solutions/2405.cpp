#include <string>
#include <bitset>

using namespace std;
// best time: 14 ms (98th percentile), 10.56 MB (96th percentile)

/* explanation:
 * one way to solve this problem is to use a greedy approach - we'll only add a new substring to our partition if we absolutely have to (i.e. if the current character has already been used in the current substring and we have to start a new substring)
 * this "bare minimum" approach will prevent us from forming more substrings than is necessary, which is the crux of the problem
 * in this implementation a bitset of length 26 (which accomodates for the 26 lowercase letters used by the test cases) is used to keep track of whether a character has been used or not
 * bitsets, which are typically overshadowed by array<bool> and similar containers in high-performance contexts, are actually faster than said containers on average in the case of this problem
*/

class Solution {
public:
    int partitionString(string& s) {
        bitset<26> is_present;

        int ret = 1;
        for (char& c : s) {
            if (is_present[c - 'a'])
                is_present.reset(),
                ++ret;

            is_present[c - 'a'] = true;
        }

        return ret;
    }
};
