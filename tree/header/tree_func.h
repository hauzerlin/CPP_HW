struct linknode
{
    linknode *next;
    linknode *prev;
    std::string item;
};

struct queue_post
{
    linknode *first;
    linknode *rear;
    int num;
};

struct treeNode
{
    treeNode *leftPtr;
    treeNode *rightPtr;
    //int operand;
    int data;
    std::string operate;
    bool Num_or_Op;
};

typedef linknode First_item;
typedef struct treeNode TreeNode; // synonym(alias) for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

//tree node function
linknode* restruct(treeNode *treePtr, linknode *node);
void insertNode(TreeNodePtr *treePtr, int value);
void right_insert(TreeNodePtr *treePtr, char tmp);

//if item is an operator return 1, else return 0;
bool Num_or_OP(std::string item);
void inOrder(TreeNodePtr treePtr);
bool Link_node_Switch(queue_post &q, std::string n1, std::string n2);
bool Link_node_Switch(queue_post &q, linknode * op, std::string num);
//file operate function
void M1(queue_post &Queue, std::string n1, std::string n2); //swap two operands
void M2(queue_post &Queue, int num); //complement the operator chain
void M3(queue_post &Queue, std::string num, std::string op); //swap operand and operator