#include <string>
#include <array>

using namespace std;
// best time: 14 ms (92nd percentile), 9.60 MB (76th percentile)
// time complexity: O(n)
// space complexity: O(1)

/* explanation:
 * the minimum number of frogs can be defined as one plus the maximum number of croaks that have been interrupted and are waiting to continue at any time during the croak string
 * this is because for a croak to be interrupted, there must be one frog that is interrupting and another frog being interrupted
 * for example, the string "crcoakroak" has one interruption ("cr" -> "c" (start of a new string, one interruption) -> "oak" (back to the old one, finishes when we hit 'k', one interruption) -> "roak" (the other string has been finished))
 * similarly, the minimum number of frogs from the string "croakcroak" is 1 because there's 0 interruptions present
 * with this definition, we now need to eliminate invalid croak strings:
 * 1) a croak string is invalid if by the end of the string, not all croaks have been finished (e.g. "crocroak" or "croakcroa")
 * 2) a croak string is invalid if at any point, a croak that hasn't been started before tries to interrupt a croak (e.g. "crakoak". the interruption is "cr" -> "ak" -> "oak". "ak" does not belong to any previous croak)
 * now that we have these definitions, we can store the number of croaks that have been interrupted and are currently waiting to continue. this will allow us to check against these definitions to return the correct answer
*/

class Solution {
public:
    int minNumberOfFrogs(string& croakOfFrogs) {
        size_t i_max = croakOfFrogs.size() - 1;
        if (croakOfFrogs[i_max] != 'k') // tests invalidity definition 1
            return -1;

        int max_stopped = 0, stopped_croaks = 0;
        array<int, 4> croaks_stopped_before {}; // NOTE: the array here only holds 4 integers because it's impossible for a croak to be stopped before it reaches 'c'

        for (size_t i = 0, i_max = croakOfFrogs.size() - 1; i < i_max; ++i)
            if (auto& current = croakOfFrogs[i], next = croakOfFrogs[i+1]; current != 'k') {
                if (next != croak(croak_idx(current) + 1)) {
                    if (next == 'c')
                        max_stopped = max (max_stopped, ++stopped_croaks),
                        ++croaks_stopped_before[croak_idx(current)];
                    else if (croaks_stopped_before[croak_idx(next) - 1]) // tests if an interrupting croak has been interrupted before
                        --croaks_stopped_before[croak_idx(next) - 1],
                        ++croaks_stopped_before[croak_idx(current)]; // since we're adding 1 and subtracting 1 from two different elements in the array, the overall net change is 0. thus we don't change the stopped_croaks variable
                    else
                        return -1;
                }
            } else if (next != 'c')
                --croaks_stopped_before[croak_idx(next) - 1],
                --stopped_croaks;

        for (int& i : croaks_stopped_before)
            if (i != 0)
                return -1;

        return max_stopped + 1;
    }

private:
    size_t croak_idx(char& c) {
        switch (c) {
            case 'c':
                return 0;
            case 'r':
                return 1;
            case 'o':
                return 2;
            case 'a':
                return 3;
            case 'k':
                return 4;
        }

        return 0;
    }

    char croak(size_t i) {
        switch (i) {
            case 0:
                return 'c';
            case 1:
                return 'r';
            case 2:
                return 'o';
            case 3:
                return 'a';
            case 4:
                return 'k';
        }

        return 0;
    }
};
