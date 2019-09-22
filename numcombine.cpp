#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution {
    private:
        const string letterMap[10] = {
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno"
        };
        vector<string> res;

        void findCombination(const string &digits, int index, const string &s)
        {
            if (index == digits.size())
            {
                res.push_back(s);
                return;
            }
            char c = digits[index];
            string letters = letterMap[c - '0'];

            for (int i = 0; i < letters.size(); i++)
            {
                findCombination(digits, index + 1, s + letters[i]);
            }
            return;

        }
    public:
        vector<string> letterCombinations(string digits)
        {
            res.clear();
            if (digits.size() == 0)
            {
                return res;
            }
            findCombination(digits, 0, "");
            return res;
        }
};

int main()
{
    Solution ans;
    string digits = "23";
    vector<string> res = ans.letterCombinations(digits);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] <<endl;
    }
    return 0;
}
