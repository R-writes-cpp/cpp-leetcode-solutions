#include <vector>
#include <algorithm>

// best time: 50ms (98th percentile), 67.2 MB (99th percentile)
// time complexity: O(n log n)

/* explanation:
 * we'll count the number of points in each rectangle and push it back to a vector of integers
 * we'll then generate a random number that corresponds to a certain point, and we'll find which rectangle it belongs to via an upper bound call to our original vector
 * from there, we can now generate a random point in that rectangle and return it
*/

using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        int prev_sum = 0;
        for (auto& r : rects) {
            int new_points = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            this->points.push_back (prev_sum + new_points);
            prev_sum += new_points;
        }

        this->points_total = prev_sum;
    }

    vector<int> pick() {
        auto ret_idx = upper_bound (points.begin(), points.end(), rand() % this->points_total) - points.begin();
        return {this->rects[ret_idx][0] + rand() % (1 + this->rects[ret_idx][2] - this->rects[ret_idx][0]),
                this->rects[ret_idx][1] + rand() % (1 + this->rects[ret_idx][3] - this->rects[ret_idx][1])};
    }

private:
    vector<vector<int>>& rects;
    vector<int> points;
    int points_total;
};
