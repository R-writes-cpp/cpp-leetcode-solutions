#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
// best time: 120 ms (95th percentile), 52.79 MB (78th percentile)

/* explanation:
 * for a word to be a subsequence of s, there must be some indices i < j < k and so on such that s[i], s[j], s[k]... are all equal to word[0], word[1], word[2]...
 * using this fact, we will store the indexes at which each character occurs in s
 * then, we'll start at the beginning of each word and try to find if any indexes i < j < k and so on satisfy the above requirements
 * to prevent "skipping" any indexes when searching for them, we'll want to use the smallest indexes for each character. to do this, we'll call upper_bound to find the smallest index ahead of the last one which corresponds to the current character
 * if we can successfully find a grouping of indexes, then we have confirmed that the word is a subsequence of s, and we add one to our counter
*/

class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        int ret {0};

        {
            array<vector<int>, 26> char_idxs {};
            constexpr char a {'a'};

            for (int i {0}, size = s.size(); i < size; ++i)
                char_idxs[s[i] - a].push_back(i);

            for (auto& word : words) {
                bool is_subseq {true};

                for (int last_idx {-1}; auto c : word)
                    if (const auto ub {upper_bound (char_idxs[c - a].begin(), char_idxs[c - a].end(), last_idx)}; ub == char_idxs[c - a].end()) {
                        is_subseq = false;
                        break;
                    } else
                        last_idx = *ub;

                if (is_subseq)
                    ++ret;
            }
        }

        return ret;
    }
};
