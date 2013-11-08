int swap(int a[], int src, int subs)
{
  int tmp;
  tmp = a[src];
  a[src] = a[subs];
  a[subs] = tmp;

  return 0;
}

//here end need to be len-1
int partition(int a[], int start, int end)
{
  // i records smaller element, j records bigger elments.
  int i = start -1; 
  int j = start;
  int key = a[end];

  while(j < end) {
    if(a[j] <= key) {
      i++;
      swap(a, i, j);
    }
    ++j;
  }

  swap(a, j, i+1);

  return i+1;
}


int quick_sort(int a[], int start, int end)
{
  int pivot = 0;
  if(start < end) {
    pivot = partition(a, start, end);
    quick_sort(a, start, pivot-1);
    quick_sort(a, pivot+1, end);
  }
  return 0;
}
