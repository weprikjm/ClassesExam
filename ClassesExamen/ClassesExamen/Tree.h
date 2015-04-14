



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
	void VisitAll(DList<TYPE>* list)
	{ 
		list->Add(data);
		Node<TYPE>* tmp = siblings.getStart();

		while(tmp != NULL)
		{
			tmp->data->VisitAll(list);
			tmp = tmp->next;
		}
	}
};

template <class TYPE>
class Tree
{
public:	
	//Properties
	NodeTree<TYPE>* root;
	Tree(TYPE data){ root = new NodeTree<TYPE>; root->data = data; }
	~Tree(){ delete root; }

	NodeTree<TYPE>* Add(const TYPE data)
	{
		NodeTree<TYPE>* nodeToAdd = new NodeTree<TYPE>(data, root);
		root->siblings.Add(nodeToAdd);
		return nodeToAdd;
	}

	NodeTree<TYPE>* Add(TYPE newData, NodeTree<TYPE>* newNode)
	{

		if (root == NULL)
			root = newNode;
		else
		{
			root->siblings.Add(newNode);
		}

		return newNode;
	}

	void VisitAllNodes(DList<TYPE>* list)const
	{
		
		root->VisitAll(list);
	
	}


};

#endif