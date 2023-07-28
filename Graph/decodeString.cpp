#include "bits/stdc++.h"
using namespace std;

// It's stack based problem
// if input = "2[ab4[x]]"
// then output = "abxxxxabxxxx"


// Code is super easy 
// We push element to stack if it is not a "]"
// if it is a closing bracket then we apply our logic
// else we greedily push char according to top element of the stack

string decodeString(string s)
{
    stack<string> st;
    int N = s.size();
    for (int i = 0; i < N; ++i)
    {
        if (st.empty())
        {
            char c = s[i];
            string str = "";
            str = c;
            st.push(str);
        }
        else
        {

            if (s[i] == '[')
                st.push("[");
            else if (s[i] == ']')
            {
                string str = "";
                int num;

                string top = st.top(); // jo ki ek string hoga for sure
                str += top;
                st.pop(); // string ko pop kiye
                if (!st.empty())
                    st.pop(); // opening bracket "[" pop kar diye

                num = stoi(st.top()); // opening bracket se pehle mujhe number milenge for sure
                st.pop();             // number ko store karwa k pop kar diya

                string finalStr = "";
                for (int i = 0; i < num; ++i)
                    finalStr += str;

                if (!st.empty() && st.top() != "[")
                {
                    string temp = st.top();
                    st.pop();
                    st.push(temp + finalStr);
                }
                else
                {
                    st.push(finalStr);
                }
            }
            else
            {
                string top = st.top();
                char x = top[0];
                if (((x >= '0' && x <= '9') && (s[i] >= '0' && s[i] <= '9')) ||
                    ((x >= 'a' && x <= 'z') && (s[i] >= 'a' && s[i] <= 'z')))
                {
                    st.pop();
                    char c = s[i];
                    string str = "";
                    str = c;

                    st.push(top + str);
                }
                else
                {
                    char c = s[i];
                    string str = "";
                    str = c;

                    st.push(str);
                }
            }
        }
    }
    return st.top();
}
int main()
{

    return 0;
}