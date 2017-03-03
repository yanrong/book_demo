#include "btree_node.hpp"

int main()
{
    bin_tree<int> tree;
    int array[]={7,4,2,3,15,35,6,45,55,20,1,14,56,57,58};
    size_t k=sizeof(array)/sizeof(array[0]);
    cout<<"create binary tree!"<<endl;
    cout<<"array is:";
    for(size_t i=0;i<k;i++)
    {
        cout<<array[i]<<" ";
        tree.create_tree(array[i]);
    }

    cout<<"\n\nprevious order display:";
    tree.display_mode(PREORDER);

    cout<<"\n\ninorder display:";
    tree.display_mode(INORDER);

    cout<<"\n\npost order display:";
    tree.display_mode(POSTORDER);

    cout<<"\n\nlevel order treverse:";
    tree.display_mode(LEVEL);
    return 0;
}
