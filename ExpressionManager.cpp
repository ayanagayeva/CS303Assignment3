#include "ExpressionManager.h"
#include <stack>
using namespace std;
// constructor initialize the ExpressionManager object
ExpressionManager::ExpressionManager() {}
// denstructor destory the ExpressionManager object
ExpressionManager::~ExpressionManager() {}
// check if user input n has balanced parentheses.
bool ExpressionManager::isBalanced(const string &expression) {
  stack<char> stack;
  // go through each symbol in the expression
  for (char symbol : expression) {
    // check if the given character is an opening parenthesis
    if (isOpeningSymbol(symbol)) {
      stack.push(symbol);
    }
    // check if the given character is a closing parenthesis
    else if (isClosingSymbol(symbol)) {
      // check if there is a matching opening parenthesis at the top of the
      // stack
      if (stack.empty() || !isMatchingPair(stack.top(), symbol)) {
        return false; // unbalanced parentheses
      }
      stack.pop(); // pop the matching opening parentheesis
    }
  }
  // check if there are remaining opening parentheses
  return stack.empty();
}
// convert the given infix expression to postfix notation
string ExpressionManager::infixToPostfix(const string &infixExpression) {
  string postfix;
  stack<char> stack;
  // go thru each symbol in the infix expression
  for (char symbol : infixExpression) {
    // check if the symbol is an alphanumeric character
    if (isalnum(symbol)) {
      postfix += symbol;
    }
    // check if the symbol is an opening parenthesis
    else if (isOpeningSymbol(symbol)) {
      stack.push(symbol);
    }
    // check if the symbol is a closing parenthesis
    else if (isClosingSymbol(symbol)) {
      // pop + append operators from the stack until found an opening
      // parenthesis
      while (!stack.empty() && stack.top() != '(' &&
             getPrecedence(stack.top()) >= getPrecedence(symbol)) {
        postfix += stack.top();
        stack.pop();
      }
      stack.pop(); // pop the opening parenthesis
    }
    // check if the symbol i= operator
    else {
      // pop + append operators from the stack w/ equal/higher precedence
      while (!stack.empty() &&
             getPrecedence(stack.top()) >= getPrecedence(symbol)) {
        postfix += stack.top();
        stack.pop();
      }
      stack.push(symbol); // push the current operator onto the stack
    }
  }
  // pop + append operators from the stack
  while (!stack.empty()) {
    postfix += stack.top();
    stack.pop();
  }
  return postfix;
}
// check if the given character is an opening parenthesis
bool ExpressionManager::isOpeningSymbol(char symbol) {
  return symbol == '(' || symbol == '{' || symbol == '[';
}
// check if the given character is a closingg parenthesis
bool ExpressionManager::isClosingSymbol(char symbol) {
  return symbol == ')' || symbol == '}' || symbol == ']';
}
// check if the given opening and closing parentheses = ()
bool ExpressionManager::isMatchingPair(char opening, char closing) {
  return (opening == '(' && closing == ')') ||
         (opening == '{' && closing == '}') ||
         (opening == '[' && closing == ']');
}
// return the precedence of the given operato
int ExpressionManager::getPrecedence(char op) {
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/' || op == '%') {
    return 2;
  }
  return 0;
}