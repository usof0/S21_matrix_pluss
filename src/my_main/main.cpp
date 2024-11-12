#include <iostream>

#include "../s21_matrix_oop.h"

void print(S21Matrix a) {
  std::cout << "[";
  for (int i = 0; i != a.GetRows(); ++i) {
    if (i > 0)
      std::cout << " [";
    else
      std::cout << "[";
    for (int j = 0; j != a.GetCols(); ++j) {
      std::cout << a(i, j) << ", ";
    }
    std::cout << "],\n";
  }
  std::cout << "]\n";
}

int main(void) {
  S21Matrix a(3, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 1;
  a(1, 2) = 4;
  a(2, 0) = 5;
  a(2, 1) = 6;
  a(2, 2) = 0;
  print(a);
  double det = a.Determinant();
  print(a);

  S21Matrix cl = a.CalcComplements();
  print(cl);
  std::cout << std::endl << det << std::endl;
  a(0, 0) = 4;
  a(0, 1) = 2;
  a(0, 2) = 1;
  a(1, 0) = 3;
  a(1, 1) = 5;
  a(1, 2) = 2;
  a(2, 0) = 1;
  a(2, 1) = 1;
  a(2, 2) = 3;
  det = a.Determinant();
  print(a);
  std::cout << std::endl << det << std::endl;

  S21Matrix inv = a.InverseMatrix();
  print(inv);
  std::cout << "..........................\n";
  S21Matrix b(a);  // = std::move(a);

  // if (a.matrix_ != nullptr)
  print(a);
  print(b);
  S21Matrix c = a + b;
  print(c);
  S21Matrix d = c.Transpose();
  print(d);
  d.SetRows(4);
  print(d);
  d.SetRows(2);
  print(d);
  d.SetCols(4);
  print(d);
  d.SetCols(2);
  print(d);
  S21Matrix e = std::move(d);
  print(e);
  return 0;
}