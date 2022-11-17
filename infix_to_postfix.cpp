#include <iostream>
#include <stack>

using namespace std;

int prec(char c){
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}
void to_postfix(string str){
    stack<char> st;
    string res;

    for (auto i : str){
        char c = i;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            res +=c;
        else if (c == '(') 
            st.push('(');
        else if (c == ')'){
            while (st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(c) <= prec(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()){
        res += st.top();
        st.pop();
    }
    cout<<"Infix -> "<< str <<endl;
    cout<<"Postfix -> "<< res <<endl;
}
int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    to_postfix(exp);
    return 0;
}