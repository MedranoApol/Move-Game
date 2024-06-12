#ifndef NODE_H
#define NODE_H

struct Node{
	int data;
    char space;
	Node* up;
	Node* down;
	Node* left;
	Node* right;
	Node(): data(0), space('\0'), up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
};

#endif