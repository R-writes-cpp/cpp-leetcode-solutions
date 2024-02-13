#include <vector>

using namespace std;
// best time: 16 ms (92nd percentile)

/* explanation:
 * to efficiently store the connections between each city as a graph, we can use a disjoint set / union find
 * we'll loop through the 2D vector provided and if there is a connection between two cities i and j, we'll union their graphs, but only if j is strictly greater than i
 * this will prevent us from unioning the same graphs twice, and therefore prevent creating two-way connections between graphs (e.g. city 1 being the parent of 0, and city 0 being the parent of city 1), which would lead to incorrect graphs and thus incorrect answers
 * once we've unioned all the graphs of cities, we'll count the number of provinces by counting the number of unique representatives
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        size_t size = isConnected.size();
        disjoint_set d(size);

        for (size_t i = 0; i < size; ++i)
            for (size_t j = i + 1; j < size; ++j)
                if (isConnected[i][j])
                    d.set_union(i, j);

        vector<bool> provinces (size);
        int ret = 0;
        for (int i = 0; i < size; ++i)
            if (auto p = provinces[d.find(i)]; !p)
                ++ret,
                p = true;

        return ret;
    }

    struct disjoint_set {
        vector<int> parent {};

        disjoint_set(int size) {
            parent.resize(size);
            for (int i = 0; i < size; i++)
                parent[i] = i;
        }

        int find(int v) {
            while (v != parent[v]) // using a while loop instead of recursion to lessen memory usage
                v = parent[v];

            return v;
        }

        void set_union(int a, int b) {
            parent[find(b)] = find(a);
        }
    };
};
