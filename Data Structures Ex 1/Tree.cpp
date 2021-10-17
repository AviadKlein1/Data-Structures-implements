#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "Tree.h"
using namespace std;

Node* Tree::search(Node* p, string val, Node*& parent)
{
	//if this is the node we looked for, it returns a pointer to this node
	if (p->value == val) return p;
	//if not found
	if (p->isLeaf) return NULL;
	//else checks the entire list of answers and if it was not find returns null
	for (list<Answer*>::iterator iter = p->answersList.begin(); iter != p->answersList.end(),((*iter)->son!= NULL); iter++)
		if (search((*iter)->son, val, p)) return search((*iter)->son, val, p);
	
	return NULL;
}
// start to print from spesific node
bool Tree::_searchAndPrint(Node* p, string val)
{
	if (p->value == val)
	{
		cout << p->value << endl;
		return true;
	}
	list<Answer*>::iterator it = p->answersList.begin();
	//iterator to tree which contains the wanted value
	while (search((*it)->son, val, p) == NULL)
		it++;
	//print the answer
	cout << p->value << "\n" << (*it)->ans << endl;
	_searchAndPrint((*it)->son, val);
	return true;
	return true;
}
// recrusiv func to print 
void Tree::print(Node* p, int level)
{
	if (p) {
		for (int size = 0; size < level; size++) 
		{//print space (i=0 at first)
			cout << "  ";
		}
		cout << p->value << endl;  //print current string

	//it goes through the whole list and adds 3 each time to the space
		for (list<Answer*>::iterator iter = p->answersList.begin(); iter != p->answersList.end(); ++iter)
		{
			for (int i = 0; i < level; i++)
			{
				cout << " : ";
			}	
			cout << (*iter)->ans << endl;
			print((*iter)->son, level + 1);
		}
	}
}
// begin the dst procces
void Tree::process(Node* p)
{
	list<Answer*>::iterator iter;
	cout << p->value << endl;
	string ans;
	//while process hasen't ended
	while (!p->isLeaf)
	{
		iter = p->answersList.begin();
		//recieve user's answer
		cin >> ans;
		//promote iterator to right answer
		while (ans != (*iter)->ans)
			iter++;
		//print next question/decision
		cout << (*iter)->son->value << endl;
		//resume process
		p = (*iter)->son;
	}
}
// func to add new tree
void Tree::addRoot(string newval)
{
	root = new Node(newval);
}
//gets the question the new answer and its value, and create an new node, son of the father - question.
bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	Node* help = search(root, fatherquestion,root); // help is now the q node
	if (help == NULL) return false;

	Node* p = new Node(newval); // new node for the new son
	Answer* a = new Answer(newanswer, p);//create new answer;
	help->answersList.push_back(a);
	help->isLeaf = false;
	return true;
}
// to delete the node and all of what after him. i assum that we need to delete himself also from his parent answerlist;
void Tree::deleteAllSubTree(Node* t)
{
	deleteSubTree(root->value);
}

void Tree::deleteSubTree(string val)
{
	Node* help = search(root, val, parent);
	//delete the node from his fathers list
	while (!help->answersList.empty())
		help->answersList.pop_front();
	return;
}

