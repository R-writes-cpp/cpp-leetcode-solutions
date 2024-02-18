#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// best time: 204 ms (97th percentile), 115.02 MB (63rd percentile)

/* explanation:
 * the connections between ingredients and their recipes can be represented by a directed acyclic graph
 * we'll use a topological sort so that we can start looking for recipes we can make with the supplies we already have (keep in mind that our supplies all have in degrees of 0) and then search through the rest of the graph for recipes we can make with the recipes we just made
 * NOTE: we don't have to use a hash table / unordered map to store the in degrees - we can simply refer to the recipes' indexes without having to hash their actual string. this is very good for performance!
*/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<int> in_degree;
        unordered_map<string, vector<size_t>> dependants;
        vector<string> ret;

        {
            size_t recipes_size = recipes.size();

            in_degree.reserve(recipes_size),
            dependants.reserve(recipes_size);

            for (size_t i = 0; i < recipes_size; ++i) {
                in_degree[i] = ingredients[i].size();
                for (auto& d : ingredients[i])
                    dependants[d].push_back(i);
            }

            ret.reserve(recipes_size);
        }

        for (size_t i = 0, supplies_size = supplies.size(); i < supplies_size; ++i)
            for (auto& d : dependants[supplies[i]])
                if (--in_degree[d] == 0)
                    ret.push_back(recipes[d]);

        for (size_t i = 0, size = ret.size(); i < size; ++i)
            for (auto& d : dependants[ret[i]])
                if (--in_degree[d] == 0)
                    ret.push_back(recipes[d]),
                    ++size;

        return ret;
    }
};
