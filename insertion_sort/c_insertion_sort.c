int insertion_sort(int array[], int num)
{
  int val = 0;

  for (int i = 1; i < num; ++i)
  {
    int j = i-1;
    val = array[i];

    while(j>=0 && array[j] > val) {
      array[j+1] = array[j];
      --j;  
    }
    array[j+1] = val;
  }
   
  return 0;
}
