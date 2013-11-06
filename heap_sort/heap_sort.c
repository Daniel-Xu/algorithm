int swap(int a[], int src, int subs)
{
  int tmp;
  tmp = a[src];
  a[src] = a[subs];
  a[subs] = tmp;

  return 0;
}

int max_heapify(int a[], int node, int heap_size)
{
  int left_child = 2*node+1;      
  int right_child = 2*node+2; 
  int largest = node;

  if(left_child < heap_size && a[node] <  a[left_child]) {
    largest  = left_child;
  }

  if(right_child < heap_size && a[largest] < a[right_child]) {
    largest = right_child;   
  }
  
  if(largest != node) {
    swap(a, node, largest);
    max_heapify(a, largest, heap_size);
  }
  
  return 0;
}

// n/2-1 is the node that is not leaf
int build_heap(int a[], int n)
{
  for(int i = n/2-1; i >= 0; --i)
  {
    max_heapify(a, i, n);
  }
  return 0;
}


int heap_sort(int a[], int len)
{
  build_heap(a, len);

  for (int i = len-1; i > 0; --i)
  {
    swap(a, 0, i);
    
    // here i is the heap_size 
    max_heapify(a, 0, i);
  }
  return 0;
}
