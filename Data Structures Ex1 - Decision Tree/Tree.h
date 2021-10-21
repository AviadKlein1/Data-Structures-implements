#pragma once
#include <iostream>
#include <list>
#include <string>
#include <iterator>
using namespace std;

class Node;

//Answer: for each answer, the string, and the pointer to the node where to continue
class Answer
{
public:
	string ans;
	Node* son;
	Answer(string s, Node* p) { ans = s; son = p; }
};

//Node: each node in the decision tree
class Node
{
public:
	list<Answer*> answersList;
	string value;
	bool isLeaf;
	Node(string v) { isLeaf = true;  value = v; }
	friend class Tree;
};


//Tree: the Decision Tree
class Tree
{
	Node* parent = root;
	Node* root;
	void print(Node* p, int level = 0);
	void process(Node* p);
	bool _searchAndPrint(Node* p,string val);


public:
	//constractor
	Tree() { root = NULL; parent = NULL; }
	//destractor
	~Tree() {
		deleteSubTree(root->value);
		root = 0;
	}
	//public func to search
	Node* search(Node* p, string val, Node*& parent);// public func that pass the string to searching with pr withnt node	
	void deleteAllSubTree(Node* t);
	void addRoot(string newval);
	bool addSon(string fatherquestion, string newanswer, string newval);
	void searchAndPrint(string val)
	{
		if (!_searchAndPrint(root, val)) cout << "ERROR\n" << endl;
	}
	void searchAndPrintArea(string val)
	{
		Node* parent;
		Node* area = search(root, val, parent);
		if (area) print(root);
	}
	void printAllTree() { print(root); }
	string printToString(Node* p);
	string printToString() { return printToString(root); }
	void deleteSubTree(string val);
	void process() { process(root); }

};

