/*
Given a string containing only characters (, ), [, ] {, }.
Write a program that check whether the string is correct in expression.
Example:
      ([]{()}()[]): correct
      ([]{()]()[]): incorrect
Input: One line contains the string (the length of the string is less than or equal to 10^6)
Output: Write 1 if the sequence is correct, and write 0, otherwise
Example:
      input: (()[][]{}){}{}[][]({[]()})
      output: 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  std::string p;
  std::cin >> p;
  while (true) {
    bool found = false;
    if (p.find("()") != std::string::npos) {
		p.erase(p.find("()"), 2);
		found = true;
    }
    if (p.find("[]") != std::string::npos) {
		p.erase(p.find("[]"), 2);
		found = true;
    }
    if (p.find("{}") != std::string::npos) {
		p.erase(p.find("{}"), 2);
		found = true;
    }
    if (!found) {
      	break;
    }
	}
	if (p.empty()) {
    std::cout << 1 << std::endl;
  	} else {
    std::cout << 0 << std::endl;
  	}
  return 0;
}
