#include <iostream>

#define M 3 
#define N 3

using namespace std;

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

void flush_array(int a[][N])
{
  bool row[M];
  bool col[N];
 
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  
  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if(a[i][j] == 0) {
        row[i] = true;
        col[j] = true;
      }
    } 
  }

  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if(row[i] || col[j])
        a[i][j] = 0;
    }
  }

}

int main(int argc, char const *argv[])
{
    
  int a[M][N] = {
    {1, 2, 3}, 
    {0, 2, 1}, 
    {1, 2, 3}
  };

  cout << "original array" << endl;
  print_array(a);

  flush_array(a);
  
  cout << "modified array" << endl;
  print_array(a);
  return 0;
}
