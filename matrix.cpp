#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
  bool add(vector<vector<int>>& a, const vector<vector<int>>& b); //adds b to a, returns false if fails
  bool mult(vector<vector<int>>& a, const vector<vector<int>>& b); //multiplies a by b
  void print(const vector<vector<int>>& a); //prints a
};

int main() {
  cout << "started" << endl;
  //create object
  Matrix calc = Matrix();
  // Create test matrices
  vector<vector<int>> matrix1 = { {1, 0, 0},{0, 1, 0},{0, 0, 1} };
  vector<vector<int>> matrix2 = { {0, 1, 1},{1, 0, 1},{1, 1, 0} };
  vector<vector<int>> matrix3 = { {1, 0, 0},{0, 1, 0} };
  vector<vector<int>> matrix4 = { {0, 1},{1, 0},{1, 1} };
  // Print original matrices
  calc.print(matrix1);
  calc.print(matrix2);
  // Perform addition, multiplication, etc.
  calc.add(matrix1, matrix2);
  calc.print(matrix1);
  // Print results
  calc.mult(matrix1, matrix2);
  calc.print(matrix1);

  calc.mult(matrix3, matrix4);
  calc.print(matrix3);
  return 0;
}

bool Matrix::add(vector<vector<int>>& a, const vector<vector<int>>& b) {
  //check that rows and columns are same size
  if ((a.size() != b.size()) || (a[0].size() != b[0].size())) {
    cout << "Matrices must be same size to add" << endl;
    return false;
  }
  //a is the vector being added to, so we want to add every value of b
  //to its corresponding value of a
  for (unsigned int i = 0; i < a.size(); i++) {
    for (unsigned int j = 0; j < a[0].size(); j++) {
      a[i][j] += b[i][j];
    }
  }
  return true;
}

bool Matrix::mult(vector<vector<int>>& a, const vector<vector<int>>& b) {
  //check that the num of columns in a are equal to the num of rows in b
  if (a[0].size() != b.size()) {
    cout << "Matrix A and B must have the same number of columns as rows respectively" << endl;
    return false;
  }
  //we will need to create a new matrix with the correct multiplication dimensions
  vector<vector<int>> temp(a.size(), vector<int>(b[0].size(), 0));

  //for each row in a, multiply each value by the corresponding value in each column of b
  //for each row in a --> i is our row in a
  for(unsigned int i = 0; i < a.size(); i++) {
    //for each column in b --> j is our column
    for(unsigned int j = 0; j < b[0].size(); j++) {
      //for each value in each --> k is our value
      for(unsigned int k = 0; k < a[0].size(); k++) {
        temp[i][j] += (a[i][k]*b[j][k]);
      }
    }
  }
  a = temp;
  return true;
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