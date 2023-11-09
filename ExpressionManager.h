#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
#include <string>
using namespace std;
// ExpressionManager class
class ExpressionManager {
public:
  // constructor initialize the ExpressionManager object
  ExpressionManager();
  // denstructor destoy the ExpressionManager object
  ~ExpressionManager();
  // check if user input n has balanced parentheses.
  bool isBalanced(const string &expression);
  // convert input to postfix notation
  string infixToPostfix(const string &infixExpression);

private:
  // check if the given character is an opening parenthesiss
  bool isOpeningSymbol(char symbol);
  // check if the given character is a closing parenthesis
  bool isClosingSymbol(char symbol);
  // checks if the given opening + closing parentheses = ()
  bool isMatchingPair(char opening, char closing);
  // returns the precedence of the given operator.
  int getPrecedence(char op);
};
#endif