#include <vector>

using namespace std;
// best time: 14 ms (98th percentile), 21.87 MB (99.96th percentile)

/* explanation:
 * to find the interval intersections between the two lists, we need to first find all the intervals in the two lists that overlap with each other
 * to do this, we'll start at the beginning of both lists, and using two pointers, we'll keep incrementing the current indexes of the lists till we reach two overlapping intervals
 * we'll increment the index of the interval that's behind the other interval. this is because we want the intervals to be close to each other as possible to obtain overlap, so increasing the smaller one is our best option
 * once we find two intervals that overlap, we'll push their overlap back to the 2D "ret" vector and repeat the process
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        ret.reserve (max (firstList.size(), secondList.size())); // in ret, we can have at most the maximum

        for (int i {0}, j {0}, i_max = firstList.size(), j_max = secondList.size(); i < i_max && j < j_max;) {
            while (firstList[i][1] < secondList[j][0] || secondList[j][1] < firstList[i][0])
                if (firstList[i][1] < secondList[j][0]) {
                    if (++i == i_max)
                        return ret;
                } else if (++j == j_max)
                    return ret;

            bool i_ends_first {firstList[i][1] < secondList[j][1]};
            ret.push_back ({max (firstList[i][0], secondList[j][0]), i_ends_first ? firstList[i][1] : secondList[j][1]});

            if (i_ends_first)
                ++i;
            else
                ++j;
        }

        return ret;
    }
};
