#include <iostream>
#include <cstdlib>
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

    n = 3*n;
    //initiate the mh array
    int mh[n];
    for (int i = 0; i < n; ++i)
    {
        mh[i] = allBox[i].h;
    }
    
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            //mh[j] is previous max
            //mh[i] is current max
            if(allBox[j].w > allBox[i].w &&
               allBox[j].d > allBox[i].d &&
               mh[i] < mh[j] + allBox[i].h
              )
                mh[i] = mh[j] + allBox[i].h;
        }
    }

    int max = mh[0];
    //now we need to find the max
    for (int i = 1; i < n; ++i)
    {
        if(mh[i] > max)
            max = mh[i];
    }

    return max;
}


int main(int argc, char const *argv[])
{

    Box a[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};

    cout << "max height is: " << maxHeight(a, 4) << endl;

    
    return 0;
}
