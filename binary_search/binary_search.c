int binary_search(int a[], int start, int end, int num)
{

  if(start > end) 
      return -1;

  int mid = (start+end)/2;
  if(a[mid] == num) {
      return mid;
  } else if(a[mid] < num){
      return binary_search(a, mid+1, end, num);
  } else {
      return binary_search(a, start, mid-1, num);
  }
}

// loop
#if 0
int binary_search(int a[], int start, int end, int num)
{
  while(start <= end) {
    int mid = (start+end)/2;

    if(a[mid] > num) {
      end = mid - 1;
    } else if(a[mid] < num) {
      start = mid + 1; 
    } else {
      return mid; 
    }
  }

  return -1;
}
#endif
