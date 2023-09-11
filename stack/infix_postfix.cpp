#include <iostream>
#include <string>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm ưu tiên của các toán tử
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Hàm chuyển đổi từ infix sang postfix
string infixToPostfix(const string& infix) {
    string postfix = "";
    string operatorStack = "";

    // Vòng lặp range-based:
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack += c;
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.back() != '(') {
                postfix += operatorStack.back();
                operatorStack.pop_back();
            }
            if (!operatorStack.empty() && operatorStack.back() == '(') {
                operatorStack.pop_back();
            }
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && precedence(operatorStack.back()) >= precedence(c)) {
                postfix += operatorStack.back();   
                operatorStack.pop_back();
            }
            operatorStack += c;
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.back();
        operatorStack.pop_back();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Nhap bieu thuc infix: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Bieu thuc postfix tuong ung: " << postfixExpression << endl;

    return 0;
}
