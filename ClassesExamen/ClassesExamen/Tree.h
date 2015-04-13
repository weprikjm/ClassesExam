



#include "DList.h"

#ifndef TREE_H
#define TREE_H
template <class TYPE>
class NodeTree
{
public:
	//Properties
	TYPE data;
	NodeTree* father;
	DList<NodeTree*> siblings;
	//Constructor
	NodeTree(TYPE _data, NodeTree<TYPE>* _father){ data = _data; father = _father; }//Constructor for normal Node
	NodeTree(TYPE _data){ data = _data; }//Constructor for root Node
	NodeTree(){};
	
	//Destructor
	~NodeTree(){ }

	//Methods
	
};

template <class TYPE>
class Tree
{
public:	
	//Properties
	NodeTree<TYPE>* root;
	Tree(){ root = new NodeTree<TYPE>; }
	~Tree(){ delete root; }

	void Add(TYPE& nodeToAdd)
	{
		nodeToAdd->father = root;
		root->siblings->Add(nodeToAdd);
	}

	void Add(TYPE& newData, NodeTree<TYPE>* newNode)
	{
		NodeTree<TYPE>* newNode = new NodeTree(newData);
		if (rootNode == NULL)
			rootNode = newNode;
		else
		{
			rootNode->sons
		}
	}




};

#endif