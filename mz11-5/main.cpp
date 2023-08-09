//
//  main.cpp
//  mz11-5
//
//  Created by Kirill Vititnev on 25.04.2022.
//

#include <iostream>
#include <stack>
bool
check_c(char c)
{
    return (c<='z' && c>='a') ? true : false;
}
bool
is_op(char c)
{
    return (c == '+' || c=='-' || c == '*' || c == '/') ? true:false;
}
using std::stack, std::string, std::cout, std::endl, std::cin;
int main(int argc, const char * argv[]) {

    char c;
    stack<string> st;
    while(cin>>c) {
        if(check_c(c)) {
            string s1;
            s1.push_back(c);
            st.push(s1);
        } else if (is_op(c)) {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push('(' + s2 + c + s1+ ')');
        }
    }
    string ans = st.top();
    st.pop();
    cout << ans << endl;
    return 0;
}
