#include <iostream>
#define NULL 0
using namespace std;

struct BST
{
    int data;
    BST *left, *right;
};

BST *root, *temp, *ttemp, *p;
int node_count = 0;
int lev = 0;

void init()
{
    root = temp = ttemp = NULL;
}

void create_Root(int x)
{
    root = new BST;
    root->data = x;
    root->left = root->right = NULL;
}

void addNode(int x)
{
    if (root == NULL) {
        create_Root(x);
        return;
    }

    temp = root;
    while (temp != NULL)
    {
        ttemp = temp;
        if (temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    p = new BST;
    p->data = x;
    p->left = p->right = NULL;
    if (ttemp->data > x)
        ttemp->left = p;
    else
        ttemp->right = p;
}

void Inorder(BST *p){
    if(p!=NULL){
        Inorder(p->left);
        cout << p->data;
        cout << endl;
        Inorder(p->right);
    }
}
void Preorder(BST *p){
    if(p!=NULL){
        cout << p->data;
        cout << endl;
        Preorder(p->left);
        Inorder(p->right);
    }
}
void Postorder(BST *p){
    if(p!=NULL){
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data;
        cout << endl;
    }
}

void count_nodes(BST *p){
    if(p!=NULL){
        node_count++;
        count_nodes(p->left);
        count_nodes(p->right);
    }
}

int get_level(BST *p,int n){
    if(p==NULL){
        return -1;
    }

    if (p->data==n){
        return lev;
    }
    lev++;

    int left = get_level(p->left, n);
    lev--;

    if(left!=-1)
        return left;
    lev++;
    int right = get_level(p->right, n);
    lev--;
    return right;
}

int width_at_level(BST *p,int k){
    if(p==NULL){
        return 0;
    }

    if(k==0){
        return 1;
    }

    return width_at_level(p->left, k - 1) + width_at_level(p->right, k - 1);
}

int height_of_tree(BST *p){
    if(p==NULL){
        return 0;
    }

    int left = height_of_tree(p->left);
    int right = height_of_tree(p->right);

    return 1+max(left, right);
}

int main(){
    init();
    create_Root(50);
    addNode(30);
    addNode(70);
    addNode(90);
    addNode(20);
    addNode(10);
    addNode(100);
    addNode(60);
    addNode(80);
    addNode(55);
    addNode(85);
    addNode(25);
    addNode(15);
    addNode(35);
    addNode(45);
    addNode(59);
    addNode(24);

    // cout << "Inorder : " << endl;
    // Inorder(root);

    // cout << endl;
    // cout << "Preorder : " << endl;
    // Preorder(root);

    // cout << endl;
    // cout << "Postorder : " << endl;
    // Postorder(root);

    // cout << "Number of Nodes : " << endl;
    // count_nodes(root);
    // cout << node_count << endl;

    // cout << "Level of the given data : " << endl;
    // cout << get_level(root, 100) << endl;

    // cout << "Width of the Tree at given Level : " << endl;
    // cout << width_at_level(root, 3);

    cout << "Height of the Tree : " << endl;
    cout << height_of_tree(root) << endl;

}