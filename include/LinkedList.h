#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node{
    int val =0;
    node *next_p = nullptr;
};

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();
        void add_tail_node(int x);
        void add_head_node (int x);
        void del_tail_node();
        void print_list();
        void insert_position(int pos, int val); // attention, on decide que l index de la list demmare a 0.
        friend LinkedList* add_two_list(LinkedList *l1, LinkedList *l2);
        friend LinkedList* add_rev_two_list(LinkedList *l1, LinkedList *l2);

    protected:

    private:
        node *m_head_p;
        node *m_tail_p;
};

#endif // LINKEDLIST_H
