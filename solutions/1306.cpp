#include <vector>
#include <stack>

using namespace std;
// best time: 20 ms (99th percentile), 33.83 MB (68th percentile)

/* explanation:
 * we can use a simple depth-first search to solve this problem, since it involves searching for a value in a path whose next element is currently unknown
 * we'll implement our depth-first-search with a stack that starts at the starting index and a cache of visited indices which we shouldn't revisit
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int& start) {
        size_t size = arr.size(); // used for checking if the indices we can jump to are out-of-bounds
        vector<bool> visited(size); // keep track of visited indices to prevent getting stuck in a loop
        stack<int> s;
        s.push(start);

        while (s.size()) {
            auto& top = s.top();
            if (arr[top] == 0)
                return true;

            visited[top] = true;
            if (auto next = top - arr[top]; next >= 0 && !visited[next])
                s.push(next);
            else if (next = top + arr[top]; next < size && !visited[next])
                s.push(next);
            else
                s.pop();
        }

        return false;
    }
};
