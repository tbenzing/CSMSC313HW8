#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
  bool add(const vector<vector<int>>& a, const vector<vector<int>>& b);
  void print(const vector<vector<int>>& a);
};

int main() {
  //create object
  Matrix calc();
  // Create test matrices
  vector<vector<int>> matrix1 = { {1, 0, 0},{0, 1, 0},{0, 0, 1} };
  vector<vector<int>> matrix2 = { {0, 1, 1},{1, 0, 1},{1, 1, 0} };
  // Print original matrices
  calc.print(matrix1);
  // Perform addition, multiplication, etc.

  // Print results

  return 0;
}

bool Matrix::add(const vector<vector<int>>& a, const vector<vector<int>>& b) {
  //check that rows and columns are same size
  if ((a.size() != b.size()) || (a[0].size() != b[0].size())) {
    cout << "Matrices must be same size to add" << endl;
    return false;
  }
  //a is the vector being added to, so we want to add every value of b
  //to its corresponding value of a
  for (unsigned int i = 0; i < a.size(); i++) {
    for (unsigned int j = 0; j < a[0].size(); j++) {
      return true;
    }
  }
  return false;
}

void Matrix::print(const vector<vector<int>>& a) {
  cout << endl;
  for (unsigned int i = 0; i < a.size(); i++) {
    for (unsigned int j = 0; j < a[0].size(); j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}