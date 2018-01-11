#include "LinkedList.h"
#include <iostream>
#include"math.h"

LinkedList::LinkedList()
{
    m_head_p = nullptr;
    m_tail_p = nullptr;
}

LinkedList::~LinkedList()
{
    //dtor
}

void LinkedList::add_tail_node(int x)
{
    node *current_p= m_head_p;

    if (current_p==nullptr)
    {
        m_head_p = new node;
        m_tail_p = m_head_p;
        m_head_p->next_p = nullptr;
        m_head_p->val = x;
    }
    else
    {
        while (current_p->next_p != nullptr)
        {
        current_p = current_p->next_p;
        }
    current_p->next_p = new node;
    current_p->next_p->val = x;
    m_tail_p = current_p->next_p;
    }
}

void LinkedList::add_head_node(int val)
{
    node *current_p = new node;
    current_p->next_p = m_head_p;
    current_p->val = val;
    m_head_p = current_p;
}

void LinkedList::print_list()
{
    node *current_p = m_head_p;
    while (current_p->next_p != nullptr)
    {
        std::cout<< current_p->val << ", ";
        current_p = current_p->next_p;
    }
        std::cout<< current_p->val << std::endl;
}

void LinkedList::del_tail_node()
{
    node *current_p = m_head_p;
    while (current_p->next_p != m_tail_p)
    {
        current_p = current_p->next_p;
    }
    delete current_p->next_p;
    current_p->next_p = nullptr;
}

void LinkedList::insert_position(int pos, int value)  // pos doit etre positif // marche par avec appel depuis pointer
{
    node *current_p = m_head_p;
    node *previous_p = nullptr;
    int conter =0;

    while ((current_p->next_p != nullptr) & (conter!=pos))
    {
        previous_p = current_p;
        current_p = current_p->next_p;
        conter++;
    }
    if ((pos==conter) & (pos > 0))
        {
        previous_p->next_p = new node;
        previous_p->next_p->val = value;
        previous_p->next_p->next_p = current_p;
        }
    if (pos==0)
        {
        node *temp = m_head_p;
        m_head_p= new node;
        m_head_p->next_p = temp;
        m_head_p->val = value;
        }

    //else la list est plus petite que pos
}

LinkedList*  add_two_list(LinkedList *l1, LinkedList *l2) // 2-4-6 + 2-7-3 = 5-1-9 parceque 246+273=519
{
   int L1=0,L2 =0, L3=0;

   node *current1 = l1->m_head_p;
   node *current2 = l2->m_head_p;
   while (current1  !=nullptr)
   {
       L1 = 10 * L1 + current1->val;
       current1 = current1->next_p;
   }

   while (current2  !=nullptr)
   {
       L2 = 10 * L2 + current2->val;
       current2 = current2->next_p;
   }

   L3 = L1+L2;
    std::cout<< L3 << std::endl;
    LinkedList *l3 = new LinkedList;
   while (L3!=0)
   {
       l3->add_head_node(L3%10);
       L3 = L3/10;
   }
    return l3;
}

LinkedList*  add_rev_two_list(LinkedList *l1, LinkedList *l2) // 2-4-6 + 2-7-3 = 4-1-0-1 parceque 642+372=1014
{
int L1=0,L2 =0, L3=0;
int c =0;
   node *current1 = l1->m_head_p;
   node *current2 = l2->m_head_p;
   while (current1  !=nullptr)
   {
       L1 =  L1 + pow(10,c)*  current1->val;
       current1 = current1->next_p;
       c++;
   }

    c=0;
   while (current2  !=nullptr)
   {
       L2 =  L2 + pow(10,c)*  current2->val;
       current2 = current2->next_p;
   }

   L3 = L1+L2;
   std::cout<< L3 << std::endl;
    LinkedList *l3 = new LinkedList;
   while (L3!=0)
   {
       l3->add_head_node(L3%10);
       L3 = L3/10;
   }
    return l3;
}

