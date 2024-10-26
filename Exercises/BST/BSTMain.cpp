#include <iostream>
#include "BST.h"

int main(){
    // ***************************************************************** // 
    // ****************** LECTURE  15 ********************************** // 
    // ***************************************************************** // 
    BST<int> tree;
    tree.insert(4);
    tree.insert(10);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(12);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    std::cout << "The size is: " << tree.size() << std::endl;
    std::cout << "least to greatest: " << std::endl;
    tree.printInOrder();
    std::cout << std::endl;
    std::cout << "post order: " << std::endl;
    tree.printPostOrder();
    std::cout << std::endl;

    std::cout << "Contains 10: " << tree.contains(10) << std::endl;
    std::cout << "Contains 5: " << tree.contains(5) << std::endl;
    std::cout << std::endl;
    std::cout << "Testing extrema..." << std::endl;
    std::cout << "Max: " ;
    std::cout << tree.max() << std::endl;
    std::cout << "Min: " ;
    std::cout << tree.min() << std::endl;
    std::cout << std::endl;

    tree.insert(6);
    tree.insert(13);
    tree.insert(16);
    std::cout << "Print in order after some inserts: " << std::endl; 
    tree.printInOrder();
    std::cout << std::endl;

//     // ***************************************************************** // 
//     // ****************** LECTURE  16 ********************************** // 
//     // ***************************************************************** //
    tree.remove(4);
    std::cout << "Result of remove" << std::endl;
    tree.printInOrder();
    std::cout << std::endl;
    std::cout <<  "naive median (only works if tree is full): " << tree.naiveMedian() << std::endl;
    return 0;
}