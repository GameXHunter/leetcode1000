/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

*/
#include <string>
#include<unordered_map>
#include<stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for (char c : s)
        {
            //如果是左括号，压入栈
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            // 如果是右括号
            else if (mapping.count(c)) {
                if (st.empty() || st.top() != mapping[c])
                    return false;
                st.pop();
            }
        }

        return st.empty(); // 栈空则有效

    }
};

int main()
{

    return 0;
}