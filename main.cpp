#include <iostream>
#include"LinkedList.h"



int main()
{
    LinkedList L;
    L.add_tail_node(4);
    L.add_tail_node(5);
    L.add_tail_node(6);
    std::cout<< "L= ";
    L.print_list() ;
    std::cout<< std::endl;

    LinkedList L2;
    L2.add_tail_node(2);
    L2.add_tail_node(3);
    L2.add_tail_node(6);
    std::cout<< "L2= ";
    L2.print_list();
    std::cout<< std::endl;

    add_two_list(&L,&L2)->print_list();
    add_rev_two_list(&L,&L2)->print_list();

    return 0;
}
