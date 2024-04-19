#include <vector>
#include <algorithm>

using namespace std;
// best time: 214 ms (95th percentile)

/* explanation:
 * to minimise the number of rectangles we use, we must put as many points in each rectangle as possible
 * to do this, we can find all the nearby points for each point p and put them together into the same rectangle
 * the leftmost point out of all of the points must be the starting corner for the first rectangle. to ensure that this point doesn't get left out in the process, we must loop through the points in order from left to right
 * this is why we sort the vector before doing our loop. in the loop, if we find a new point which can't fit into the last rectangle, only then will we make a new rectangle for it
*/

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort (points.begin(), points.end());

        int ret {0};

        for (int max_x {-1}; auto& p : points)
            if (p[0] > max_x)
                max_x = p[0] + w,
                ++ret;

        return ret;
    }
};
