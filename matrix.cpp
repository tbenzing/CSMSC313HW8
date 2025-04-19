#include <iostream>
#include <vector>

using namespace std;

class Matrix {
  private:
  vector<vector<int>> m_matrix; //matrix
  int m_rows;
  int m_columns;

  public:
  Matrix(vector<vector<int>>);
  bool add(Matrix b); //adds b to current matrix, returns false if fails
  bool mult(Matrix b); //multiplies matrix by b (matrix multiplcation)
  bool mult(int b); //multiplies matrix by b (scalar multiplication)
  void print(); //prints matrix
};

int main() {
  cout << "started" << endl;
  // Create test matrices
  Matrix matrix1 = Matrix({ {1, 0, 0},{0, 1, 0},{0, 0, 1} });
  Matrix matrix2 = Matrix({ {0, 1, 1},{1, 0, 1},{1, 1, 0} });
  Matrix matrix3 = Matrix({ {1, 0, 0},{0, 1, 0} });
  Matrix matrix4 = Matrix({ {0, 1},{1, 0},{1, 1} });
  // Print original matrices
  matrix1.print();
  matrix2.print();
  // Perform addition, multiplication, etc.
  matrix1.add(matrix2);
  matrix1.print();
  // Print results
  matrix1.mult(matrix2);
  matrix1.print();

  matrix3.mult(matrix4);
  matrix3.print();

  matrix1.mult(2);
  matrix1.print();
  return 0;
}

Matrix::Matrix(vector<vector<int>> a) {
  m_matrix = a;
  m_rows = a.size();
  m_columns = a[0].size();
}

bool Matrix::add(Matrix b) {
  //check that rows and columns are same size
  if ((m_rows != b.m_rows) || (m_rows != b.m_rows)) {
    cout << "Matrices must be same size to add" << endl;
    return false;
  }
  //a is the vector being added to, so we want to add every value of b
  //to its corresponding value of a
  for (unsigned int i = 0; i < m_rows; i++) {
    for (unsigned int j = 0; j < m_columns; j++) {
      m_matrix[i][j] += b.m_matrix[i][j];
    }
  }
  return true;
}

bool Matrix::mult(Matrix b) {
  //check that the num of columns in a are equal to the num of rows in b
  if (m_columns != b.m_rows) {
    cout << "Matrix A and B must have the same number of columns as rows respectively" << endl;
    return false;
  }
  //we will need to create a new matrix with the correct multiplication dimensions
  vector<vector<int>> temp(m_rows, vector<int>(b.m_columns, 0));

  //for each row in a, multiply each value by the corresponding value in each column of b
  //for each row in a --> i is our row in a
  for(unsigned int i = 0; i < m_rows; i++) {
    //for each column in b --> j is our column
    for(unsigned int j = 0; j < b.m_columns; j++) {
      //for each value in each --> k is our value
      for(unsigned int k = 0; k < m_columns; k++) {
        temp[i][j] += (m_matrix[i][k]*b.m_matrix[j][k]);
      }
    }
  }
  m_matrix = temp;
  m_rows = temp.size();
  m_columns = temp[0].size();
  return true;
}

bool Matrix::mult(int b) {
  //multipliy each value by b
  for (unsigned int i = 0; i < m_rows; i++) {
    for (unsigned int j = 0; j < m_columns; j++) {
      m_matrix[i][j]*=b;
    }
  }
  return true;
}

void Matrix::print() {
  cout << endl;
  for (unsigned int i = 0; i < m_rows; i++) {
    for (unsigned int j = 0; j < m_columns; j++) {
      cout << m_matrix[i][j];
    }
    cout << endl;
  }
}