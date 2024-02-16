#include <vector>
#include <numeric>
#include <deque>

using namespace std;
// best time: 68 ms (96th percentile), 46.22 MB (63rd percentile)

/* explanation:
 * we know that if x represents a person who isn't definitely poorer than anyone else, then answer[x] = x
 * if there are people who are richer than x, then answer[x] will be equal to the least quiet person out of all the people richer than x
 * so if we start with the people who aren't definitely poorer than anyone else, we can define all the other elements recursively via dynamic programming
 * to start with these people, we can use a topological sort! in this solution, Kahn's algorithm is used.
*/

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        auto size = quiet.size();
        vector<int> in_degree (size);
        vector<vector<int>> descendants (size);

        for (auto& r : richer)
            ++in_degree[r[1]],
            descendants[r[0]].push_back(r[1]);

        vector<int> ret (size);
        iota (ret.begin(), ret.end(), 0);
        deque<size_t> dq;

        for (size_t i = 0; i < size; ++i)
            if (in_degree[i] == 0)
                dq.push_front(i);

        while (dq.size()) {
            auto& front = dq.front();
            for (auto& d : descendants[front]) {
                if (quiet[ret[front]] < quiet[ret[d]])
                    ret[d] = ret[front];

                if (--in_degree[d] == 0)
                    dq.push_back(d);
            }

            dq.pop_front();
        }

        return ret;
    }
};
