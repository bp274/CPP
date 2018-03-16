#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};

class node
{
    public:
        Node* data;
        node* left;
        node* right;
};

class Deque
{
    private:
        node* front;
        node* rear;
    public:
        Deque();
        void insertAtFront(Node*);
        void insertAtEnd(Node*);
        Node* popAtFront();
        Node* popAtEnd();
        int getSize();
        bool isEmpty();
};

class BinaryTree
{
    private:
        Node* root;
    public:
        BinaryTree();
        void display();
        void summation(Node*, int);
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);
        void spiralLevelOrder(Node*);
};

BinaryTree :: BinaryTree()
{
    Deque object;
    Node* temp;
    int x, k = 1;
    char ch;
    root = new Node;
    cout << "\nEnter the data for the root node :- ";
    cin >> root->data;
    root->left = NULL;
    root->right = NULL;
    object.insertAtEnd(root);
    while(!object.isEmpty())
    {
        temp = object.popAtFront();
        cout << "\nDoes the node #" << k << " have a left child [Y/n] :- ";
        cin >> ch;
        if(ch == 'Y' || ch == 'y')
        {
            temp->left = new Node;
            cout << "\nEnter the data for the left child :- ";
            cin >> temp->left->data;
            temp->left->left = NULL;
            temp->left->right = NULL;
            object.insertAtEnd(temp->left);
        }
        else if(ch == 'N' || ch == 'n')
        {
            temp->left = NULL;
        }
        cout << "\nDoes the node #" << k << " have a right child [Y/n] :- ";
        cin >> ch;
        if(ch == 'Y' || ch == 'y')
        {
            temp->right = new Node;
            cout << "\nEnter the data for the right child :- ";
            cin >> temp->right->data;
            temp->right->left = NULL;
            temp->right->right = NULL;
            object.insertAtEnd(temp->right);
        }
        else if(ch == 'N' || ch == 'n')
        {
            temp->right = NULL;
        }
        k = k + 1;
    }
}

void BinaryTree :: display()
{
    cout << endl;
    cout << "In-order :- ";
    inOrder(root);
    cout << endl;
    cout << "Pre-order :- ";
    preOrder(root);
    cout << endl;
    cout << "Post-order :- ";
    postOrder(root);
    cout << endl;
    cout << "Spiral-order :- ";
    spiralLevelOrder(root);
    cout << endl;
    summation(root, root->data);
    cout << endl;
}

void BinaryTree :: inOrder(Node* ptr)
{
    if(ptr != NULL)
    {

        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
}

void BinaryTree :: preOrder(Node* ptr)
{
    if(ptr != NULL)
    {
        cout << ptr->data << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void BinaryTree :: postOrder(Node* ptr)
{
    if(ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " ";
    }
}

void BinaryTree :: spiralLevelOrder(Node* root)
{
    Deque object;
    int level;
    bool oddLevel = true;
    int* arr = new int[100];
    int k = -1;
    object.insertAtEnd(root);
    while(!object.isEmpty())
    {
        level = object.getSize();
        if(oddLevel)
        {
            while(level != 0)
            {
                Node* ptr;
                ptr = object.popAtFront();
                arr[++k] = ptr->data;
                if(ptr->left != NULL)
                {
                    object.insertAtEnd(ptr->left);
                }
                if(ptr->right != NULL)
                {
                    object.insertAtEnd(ptr->right);
                }
                level = level - 1;
            }
        }
        else
        {
            while(level != 0)
            {
                Node* ptr;
                ptr = object.popAtEnd();
                arr[++k] = ptr->data;
                if(ptr->right != NULL)
                {
                    object.insertAtFront(ptr->right);
                }
                if(ptr->left != NULL)
                {
                    object.insertAtFront(ptr->left);
                }
                level = level - 1;
            }
        }
        oddLevel = !oddLevel;
    }
    for(int i = k; i >=0; i--)
    {
        cout << arr[i] << " ";
    }
}

Deque :: Deque()
{
    front = rear = NULL;
}

void Deque :: insertAtEnd(Node* ptr)
{
    if(rear == NULL)
    {
        front = rear = new node;
        rear->left = NULL;
    }
    else
    {
        node* temp;
        rear->right = new node;
        temp = rear;
        rear = rear->right;
        rear->left = temp;
    }
    rear->data = ptr;
    rear->right = NULL;
}

void Deque :: insertAtFront(Node* ptr)
{
    if(front == NULL)
    {
        front = rear = new node;
        front->right = NULL;
    }
    else
    {
        node* temp;
        front->left = new node;
        temp = front;
        front = front->left;
        front->right = temp;
    }
    front->data = ptr;
    front->left = NULL;
}

Node* Deque :: popAtFront()
{
    Node* ptr;
    ptr = front->data;
    front = front->right;
    if(front == NULL)
    {
        rear = NULL;
    }
    else
    {
        front->left = NULL;
    }
    return ptr;
}

Node* Deque :: popAtEnd()
{
    Node* ptr;
    ptr = rear->data;
    rear = rear->left;
    if(rear == NULL)
    {
        front = NULL;
    }
    else
    {
        rear->right = NULL;
    }
    return ptr;
}

int Deque :: getSize()
{
    int size = 0;
    node* ptr;
    ptr = front;
    while(ptr != NULL)
    {
        size = size + 1;
        ptr = ptr->right;
    }
    return size;
}

bool Deque :: isEmpty()
{
    if(front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BinaryTree :: summation(Node* ptr, int sum)
{
    if(ptr != NULL)
    {
        if(ptr->left == NULL && ptr->right == NULL)
        {
            cout << "For node with data " << ptr->data << " the summation of values of it's parent nodes is :- " << sum << endl;
        }
        else
        {
            if(ptr->left != NULL)
            {
                summation(ptr->left, sum + ptr->left->data);
            }
            if(ptr->right != NULL)
            {
                summation(ptr->right, sum + ptr->right->data);
            }
        }
    }
}

int main()
{
    BinaryTree object;
    object.display();
    return 0;
}
