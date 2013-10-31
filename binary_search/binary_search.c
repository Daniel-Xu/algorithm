int binary_search(int a[], int start, int end, int num)
{
  if (start <= end) {
    int mid = (start+end)/2;
    if(a[mid] == num) {
      // I don't know better method
      exit(mid);
    } else if(a[mid] < num){
      binary_search(a, mid+1, end, num);
    } else {
      binary_search(a, start, mid-1, num);
    }
  }

  return -1;
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
