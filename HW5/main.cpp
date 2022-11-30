#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isBalanced(string s) {
  stack<char> st;
  char x;
  for(int i = 0; i<s.length();i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
      st.push(s[i]);
      continue;
    }
    if(st.empty()){
      return false;
    }

    else if(s[i] == '}'){
      x = st.top();
      st.pop();
      if (x == '(' || x == '[' ){
        return false;
      }
      continue;
    }
    else if(s[i] == ')'){
      x = st.top();
      st.pop();
      if (x == '{' || x == '[' ){
        return false;
      }
      continue;
    }
    else if(s[i] == ']'){
      x = st.top();
      st.pop();
      if (x == '(' || x == '{' ){
        return false;
      }
      continue;
    }
  }
  return st.empty();
}

int main() {
  string s;
  cin >> s;
  while (s != "-1") {
    if(isBalanced(s)) {
      cout << "Parentheses are balanced" << endl;
    } else {
      cout << "Parentheses are not balanced" << endl;
    }
    cin >> s;
  }
    
}