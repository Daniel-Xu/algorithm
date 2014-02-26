#include <iostream>
using namespace std;


struct Box {
    int h, w, d;
};

int max(int x, int y)
{
    return x>y?x:y;
}

int min(int x, int y)
{
    return x>y?y:x;
}

//for qsort
//descending order
int compare(const void* a, const void *b)
{
    return ((Box *)b)->w * ((Box *)b)->d - 
           ((Box *)a)->w * ((Box *)a)->d;

}

int maxHeight(Box a[], int n)
{

    //initiate the box
    Box allBox[n*3];

    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        allBox[j] = a[i];
        j++;

        //w < d
        allBox[j].h = a[i].w;
        allBox[j].w = min(a[i].h, a[i].d);
        allBox[j].d = max(a[i].h, a[i].d);
        j++;

        allBox[j].h = a[i].d;
        allBox[j].w = min(a[i].h, a[i].w);
        allBox[j].d = max(a[i].h, a[i].w);
        j++;

    }

    //descending order based on base area
    qsort(allBox, sizeof(allBox), sizeof(allBox[0]), compare);

    //n = 3*n;
    //for (int i = 0; i < n; ++i)
    //{
    //}





}








int main(int argc, char const *argv[])
{
    
    return 0;
}
