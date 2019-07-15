#include <bits/stdc++.h>
 
using namespace std;
 
string input_str;
int idx;
 
bool is_operator(int i) {
  return input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '*' || input_str[i] == '/' || input_str[i] == '%';
}
 
bool is_correct() {
  if (is_operator(0) || is_operator(input_str.length() - 1)) {
    return false;
  }
 
  int left_par = 0;
  for (int i = 0; i < input_str.length(); ++i) {
    if (input_str[i] == '(') {
      left_par++;
    } else if (input_str[i] == ')') {
      if (left_par < 1) {
        return false;
      }
      left_par--;
    }
  }
  if (left_par != 0) {
    return false;
  }
 
  for (int i = 1; i < input_str.length(); ++i) {
    if (is_operator(i) && (is_operator(i - 1))) {
      return false;
    }
    if (islower(input_str[i]) && (islower(input_str[i - 1]))) {
      return false;
    }
  }
 
//  cout << "hi" << endl;
  for (int i = 0; i < input_str.length() - 1; ++i) {
    if (is_operator(i) && input_str[i + 1] == ')') {
      return false;
    }
  }
  for (int i = 1; i < input_str.length(); ++i) {
    if (is_operator(i) && input_str[i - 1] == '(') {
      return false;
    }
  }
//  cout << "hi" << endl;
 
  for (int i = 0; i < input_str.length() - 1; ++i) {
    if (input_str[i] == '(' && input_str[i + 1] == ')') {
      return false;
    }
  }
//  cout << "hi" << endl;
 
  return true;
}
 
bool is_proper() {
  // left operand
  if (islower(input_str[idx])) {
    idx++;
  } else if (input_str[idx] == '(') {
    idx++;
    if (!is_proper()) {
      return false;
    }
    if (input_str[idx] != ')') {
      return false;
    }
    idx++;
  } else {
    return false;
  }
 
  // operator
  if (!is_operator(idx)) {
    return false;
  }
  idx++;
 
  // right operand
  if (islower(input_str[idx])) {
    idx++;
  } else if (input_str[idx] == '(') {
    idx++;
    if (!is_proper()) {
      return false;
    }
    if (input_str[idx] != ')') {
      return false;
    }
    idx++;
  } else {
    return false;
  }
 
  return true;
}
 
int main() {
  getline(cin, input_str);
  string::iterator end_pos = remove(input_str.begin(), input_str.end(), ' ');
  input_str.erase(end_pos, input_str.end());
//  cout << input_str << endl;
  if (!is_correct()) {
    cout << "error" << endl;
  } else {
    idx = 0;
    if (is_proper() && idx == input_str.length()) {
      cout << "proper" << endl;
    } else {
      cout << "improper" << endl;
    }
  }
 
  return 0;
}