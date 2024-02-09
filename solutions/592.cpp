#include <string>
#include <numeric>

using namespace std;
// best time: 0 ms, 7.44 MB
// space complexity: O(1)

/* explanation:
 * first, let's define the addition of two fractions:
 * a/b + c/d = (a+c) / lcm (b, d), where lcm (b, d) denotes their lowest common multiple
 * to work this out from a string, we need to find the position of the slash character that separates the numerators from the denominators, and the sign that indicates whether we'll be adding or subtracting
 * the second for loop we have with the size_t variable j allows us to traverse slightly ahead of our current index in order to retrieve this info
 * once that's done, we can separate the strings, get the numerators and denominators of the fractions, and sum them together with the definition above
 * now we just need to keep "chaining" these fraction additions together. the best way to do this is to store 2 integers which represent the numerator and denominator of our current overall sum
 * the process then repeats till we reach the end of the string.
 * now we'll just find the greatest common divisor of our numerator and denominator, and divide them both by it (remember, our answer should be an irreducible fraction). once we appropriately format this fraction, we can return it!
*/

class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, denom = 1;

        {
            bool is_pos = true;
            for (size_t i = 0, size = expression.size(); i < size;)
                if (is_digit(expression[i])) {
                    size_t div = 0, end;
                    for (size_t j = i + 1; j < size; ++j)
                        if (expression[j] == '/')
                            div = j;
                        else if (div != 0 && is_digit(expression[j]) && (j+1 == size || !is_digit(expression[j+1]))) {
                            end = j+1;
                            break;
                        }

                    int add_denom = stoi (string (expression.begin() + div + 1, expression.begin() + end)),
                        denom_lcm = lcm (denom, add_denom);

                    num = (denom_lcm / denom) * num + (denom_lcm / add_denom) * (is_pos ? 1 : -1) * stoi (string (expression.begin() + i, expression.begin() + div)),
                    denom *= denom_lcm / denom,
                    i = end;
                } else
                    is_pos = expression[i++] == '+';
        }

        {
            int num_denom_gcd = gcd(num, denom);
            num /= num_denom_gcd,
            denom /= num_denom_gcd;
        }

        return to_string(num) + '/' + to_string(denom);
    }

private:
    bool is_digit (char& c) {
        return c <= '9' && c >= '0';
    }
};
