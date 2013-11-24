#include <iostream>

using namespace std;

#define M 4
#define N 4

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

void rotate_90(int a[][N])
{
  //reverse diagonal line 
  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N-1-i; ++j)
    {
      swap(a[i][j], a[N-j-1][M-1-i]);
    }
  }

  // i  and M-1-i 
  for (int i = 0; i < M/2; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      swap(a[i][j], a[M-i-1][j]);
    }
  }
}

void print_array(int a[][N])
{
  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }
}


int main(int argc, char const *argv[])
{
  
  int a[M][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
 
  
  cout << "original matrix" << endl;
  print_array(a);
  rotate_90(a);
  cout << "rotated matrix" << endl;
  print_array(a);
  

  return 0;
}
