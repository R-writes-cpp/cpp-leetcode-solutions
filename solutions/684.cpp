#include <vector>

using namespace std;
// best time: 0 ms

/* explanation:
 * the problem can be solved with a disjoint set / union find
 * at the very start of the solution, we'll initialise an isolated graph for each vertex
 * as we traverse the given edges, we'll start to union different graphs together in order to get closer to the final graph
 * however, we'll eventually notice (this is guaranteed by the problem) that two vertices in the same edge will have a common representative. this means that we can already move between the two vertices without the current edge - i.e., the edge is redundant because the vertices are already part of the same graph!
 * in this case we'll simply return said edge as it is the answer to the problem
*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        disjoint_set d (edges.size());

        for (auto& e : edges) {
            auto v0_rep = d.find(e[0]),
                 v1_rep = d.find(e[1]);

            if (v0_rep == v1_rep) // check whether the representatives of the two vertices are equal - if they are then return the current edge
                return e;
            d.parent[v1_rep] = v0_rep; // otherwise, union the graphs via their representatives
        }

        return {};
    }

    struct disjoint_set {
        vector<int> parent {};

        disjoint_set(int size) {
            parent.resize(size + 1);
            for (int i = 1; i <= size; i++)
                parent[i] = i;
        }

        int find(int v) {
            while (v != parent[v])
                v = parent[v];

            return v;
        }
    };
};
