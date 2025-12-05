/*将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
*/
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, (int)s.size()));//列
        int row = 0;
        bool goingDown = false;//向上或者向下

        for (char c : s)
        {
            rows[row] += c;
            //改换方向了
            if (row == 0 || row == numRows - 1)
            {
                goingDown = !goingDown;
            }
            row += goingDown ? 1 : -1;
        }

        string result;

        for (string& r : rows)
        {
            result += r;
        }
        return result;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;

    Solution solution;

    cout << solution.convert("AB",1) << endl;

    return 0;
}