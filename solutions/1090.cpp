#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
// best time: 23 ms (99.3rd percentile), 19.9 MB (93rd percentile)

/* explanation:
 * we'll create a new vector of pairs which cointain the values and labels of each item
 * we'll sort this new vector in decreasing order each item's value - this ensures that we'll be using the optimal items with the highest values
 * we'll keep track of however many times we've used an item with a specific label and ensure this value does not go over the use limit
 * while we have used less than numWanted items, we'll check if the current label's number of usages is under the use limit, and if so, we'll add its value to the return counter
*/

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
    vector<pair<int, int>> sorted_pairs (values.size());
    for (size_t i = 0, v_size = values.size(); i < v_size; ++i)
        sorted_pairs[i] = {values[i], labels[i]};

    sort (sorted_pairs.begin(), sorted_pairs.end(), [](pair<int, int> p, pair<int, int> q) {
        return p.first > q.first;
    });

    unordered_map<int, int> used_lbls {};
    int ret = 0, picked = 0;

    for (auto& p : sorted_pairs) {
        if (numWanted == picked)
            break;

        if (used_lbls[p.second] < useLimit) {
            ++used_lbls[p.second];
            ++picked;
            ret += p.first;
        }
    }

    return ret;
}
