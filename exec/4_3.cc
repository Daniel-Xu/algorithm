#include <iostream>
#include <cmath>
using namespace std;

typedef struct node {
    int val;
    struct node *left, *right;
    bool visited;
}node, *link;

link create_minimal_tree(int arry[], int start, int end)
{
    if (start > end) {
        return NULL;
    } 

    int mid = (start+end)/2;
    link n = new node();
    n->val = arry[mid];
    n->visited = false;
    n->left = create_minimal_tree(arry, start, mid-1);
    n->right = create_minimal_tree(arry, mid+1, end);

    return n;
}

//dfs print
void print_DFS(link n)
{
    if(n == NULL) return;
    cout << n->val << endl;
    n->visited = true;     
    
    link adjacent[] = {n->left, n->right};
    for (int i = 0; i < 2; ++i)
    {
        if(adjacent[i] && adjacent[i]->visited == false) {
            print_DFS(adjacent[i]);
        }
    }
}

int height(link n)
{
    if(n == NULL) return 0;
    return max(height(n->left), height(n->right)) +1;
}

int main(int argc, char const *argv[])
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    link p = create_minimal_tree(a, 0, 8);

    cout << "height of the tree is: " << height(p) << endl;;

    print_DFS(p);
    return 0;
}
