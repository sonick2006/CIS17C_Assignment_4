#include <iostream>

struct TreeNode {
	std::string name;
	int age;
	TreeNode* left;
	TreeNode* right;
	TreeNode(std::string nam, int ag) : name(nam), age(ag), left(nullptr), right(nullptr) {};
};


class FamilyTree {
public:
	TreeNode* root;

	FamilyTree() : root(nullptr) {};

	FamilyTree(TreeNode* per) : root(per) {};

	TreeNode* insert(TreeNode* root, std::string name, int age) {
		if (!root) return new TreeNode(name, age);

		if (age < root->age) {
			root->left = insert(root->left, name, age);
		}
		else if (age > root->age) {
			root->right = insert(root->right, name, age);
		}

		return root;
	}


	TreeNode* search(TreeNode* root, const std::string name) {
		if (!root) {
			return nullptr;
		}

		if (root->name == name) {
			return root;
		}

		TreeNode* leftSide = search(root->left, name);
		if (leftSide) return leftSide;

		return search(root->right, name);

	}


	TreeNode* findMin(TreeNode* node) {
		while (node && node->left) {
			node = node->left;
		}

		return node;
	}


	TreeNode* remove(TreeNode* root, int age) {
		if (!root) return nullptr;

		if (age < root->age) {
			root->left = remove(root->left, age);
		}
		else if (age > root->age) {
			root->right = remove(root->right, age);
		}
		else {
		
			if (!root->left && !root->right) {
				delete root;
				return nullptr;
			}

			
			if (!root->left) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}

			
			if (!root->right) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}

			
			TreeNode* successor = root->right;
			while (successor->left) {
				successor = successor->left;
			}
			
			root->name = successor->name;
			root->age = successor->age;

			root->right = remove(root->right, successor->age);
		}
		return root;
	}
	

	void add_member(std::string name, int age) {
		root = insert(root, name, age);
	}


	void remove_member(int age) {
		root = remove(root, age);
	}


	void inorder(TreeNode* root) {
		if (!root) return;

		inorder(root->left);
		std::cout << root->name << " (" << root->age << ")" << std::endl;
		inorder(root->right);
	}

};