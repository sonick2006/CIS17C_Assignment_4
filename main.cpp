#include "FamilyTree.h"



int main() {
    FamilyTree tree;

    //adding members
    tree.add_member("Alice", 50);
    tree.add_member("Bob", 30);
    tree.add_member("Carol", 70);
    tree.add_member("Dave", 40);
    tree.add_member("Eve", 60);

    std::cout << "Family tree (inorder by age):" << std::endl;
    tree.inorder(tree.root);

    //search
    std::cout << std::endl << "Searching for Carol..." << std::endl;
    TreeNode* result = tree.search(tree.root, "Carol");

    if (result) {
        std::cout << "Found: " << result->name << " (" << result->age << ")" << std::endl;
    }
    else {
        std::cout << "Carol no existo" << std::endl;
    }

    //removing members
    std::cout << "Alice is exiled from the family!! Get rid of her!" << std::endl;
    tree.remove_member(50);



    std::cout << std::endl << "Tree after we got rid of silly Alice:" << std::endl;
    tree.inorder(tree.root);


    return 0;
}