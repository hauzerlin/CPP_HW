struct treeNode
{
    treeNode *leftPtr;
    treeNode *rightPtr;
    int operand;
    int data;
    char operater;
    bool Num_or_OP;
};

typedef struct treeNode TreeNode; // synonym(alias) for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
