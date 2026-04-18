#include <string>
#include <cctype>
#include "tstack.h"

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int apply(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b; 
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> ops;
    std::string result;

    for (size_t i = 0; i < inf.size(); ++i) {
        char c = inf[i];

        if (c == ' ') continue;

        if (isdigit(c)) {
            while (i < inf.size() && isdigit(inf[i])) {
                result += inf[i];
                i++;
            }
            result += ' ';
            i--; // откат
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.isEmpty() && ops.top() != '(') {
                result += ops.top();
                result += ' ';
                ops.pop();
            }
            ops.pop();
        } else {
            while (!ops.isEmpty() && priority(ops.top()) >= priority(c)) {
                result += ops.top();
                result += ' ';
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.isEmpty()) {
        result += ops.top();
        result += ' ';
        ops.pop();
    }

    return result;
}

int eval(const std::string& post) {
    TStack<int, 100> st;

    for (size_t i = 0; i < post.size(); ++i) {
        char c = post[i];

        if (c == ' ') continue;

        if (isdigit(c)) {
            int num = 0;
            while (i < post.size() && isdigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            st.push(num);
            i--;
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int res = apply(a, b, c);
            st.push(res);
        }
    }

    return st.top();
}
