#include "ExpressionManager.h" // header file
#include <iostream>            //necessary library
using namespace std;
int main() {
  ExpressionManager expressionManager;
  cout << "Hello!\n";
  while (true) {
    string infixExpression;
    // user input
    cout << "\nPlease enter an infix expression: ";
    getline(cin, infixExpression);
    // check if balanced parentheses
    if (expressionManager.isBalanced(infixExpression)) {
      // convert infix to postfix
      string postfixExpression =
          expressionManager.infixToPostfix(infixExpression);
      // display
      cout << "\nThe postfix expression: " << postfixExpression << endl;
      break; // exit when finished
    } else {
      cout << "\nInvalid expression/input! Please enter a valid expression "
              "with balanced parentheses....\n";
    }
  }
  return 0;
}