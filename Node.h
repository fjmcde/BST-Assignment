#include <iostream>

class Node {
    public:
		int data;
		Node* left;
		Node* right;

		Node(int data, Node* left=nullptr, Node* right=nullptr);

		bool isLeaf();
		void insert(int data);
		bool isFull();
		uint32_t height();
		uint32_t countNodes();

};
