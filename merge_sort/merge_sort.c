int merge(int a[], int start, int mid, int end)
{
  int l1 = mid - start + 1;
  int l2 = end - mid; 
  int L[l1];
  int R[l2];
  int i, j, k; 

  for (i = 0; i < l1; ++i)
  {
    L[i] = a[start + i];
    /*printf("L is %d\t", L[i]);*/
  }
  
  for (i = 0; i < l2; ++i)
  {
    R[i] = a[mid+i+1];
  }
  i = j = 0;
  k = start;

  while(i < l1 && j < l2) {
    if (L[i] < R[j] )
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }

  while(i < l1) {
    a[k++] = L[i++]; 
  }
  while(j < l2) {
    a[k++] = R[j++]; 
  }

  return 0;
}

void merge_insertion(int a[], int start, int end)
{
  int mid = 0;

  if(start < end) {
    mid = (start + end)/2;
    merge_insertion(a, start, mid);
    merge_insertion(a, mid+1, end);
    merge(a, start, mid, end);
  }
}

