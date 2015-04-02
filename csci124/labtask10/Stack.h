typedef int T;

class stack
{
    public:
        stack();
        bool isempty();
        int size();
        bool push(const T&);
        bool pop(T&);
    private:
        struct node;
        typedef node* nodeptr;
        struct node
        {
            T data;
            nodeptr next;
        };
        nodeptr head;
        int ssize;
};

