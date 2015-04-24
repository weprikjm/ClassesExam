
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
	NodeTree(TYPE _data){ data = _data; father = NULL; }//Constructor for root Node
	NodeTree(){};
	



	//Destructor
	~NodeTree(){ }







	//Methods
	void VisitAllPreOrderRecursive(DList<NodeTree<TYPE>*>* list)																						
	{ 
		list->Add(this);
		Node<NodeTree*>* tmp = siblings.getStart();

		while(tmp!=NULL)
		{
			tmp->data->VisitAllPreOrderRecursive(list);
			tmp = tmp->next;
		}
	}

	void VisitAllPostOrderRecursive(DList<NodeTree<TYPE>*>* list)
	{
		
			Node<NodeTree*>* tmp = siblings.getStart();

			while (tmp != NULL)
			{
				tmp->data->VisitAllPostOrderRecursive(list);
				tmp = tmp->next;
				
			}
			
			list->Add(this);
	}

	void VisitAllInOrderRecursive(DList<NodeTree<TYPE>*>* list)
	{

		Node<NodeTree*>* tmp = siblings.getStart();
		unsigned int count = siblings.Count()/2;

		for (int i = 0; i<count; i++, tmp = tmp->next)
		{
			tmp->data->VisitAllInOrderRecursive(list);
		}
		list->Add(this);
		for (; tmp!=NULL; tmp = tmp->next)
		{
			tmp->data->VisitAllInOrderRecursive(list);
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

	NodeTree<TYPE>* Add(const TYPE& data)
	{
		NodeTree<TYPE>* nodeToAdd = new NodeTree<TYPE>(data, root);
		root->siblings.Add(nodeToAdd);
		return nodeToAdd;
	}

	NodeTree<TYPE>* Add(const TYPE newData, NodeTree<TYPE>* newNode)
	{

	
		
			NodeTree<TYPE>* nt = new NodeTree<TYPE>(newData,newNode);

			newNode->siblings.Add(nt);
			return nt;
		

		
	}

	void TreeVisitAllNodesPreOrderRecursive(DList<NodeTree<TYPE>*>* list)const
	{
		
		root->VisitAllPreOrderRecursive(list);
	}
	void TreeVisitAllNodesPostOrderRecursive(DList<NodeTree<TYPE>*>* list)const
	{

		root->VisitAllPostOrderRecursive(list);
	}
	void TreeVisitAllNodesInOrderRecursive(DList<NodeTree<TYPE>*>* list)const
	{

		root->VisitAllInOrderRecursive(list);
	}

	void PrintTree(DList<NodeTree<TYPE>*>* list)const
	{
		

		Node<NodeTree<TYPE>*>* node1 = list->getStart();

		while (node1!=NULL)
		{
			printf("%s",node1->data);
			node1 = node1->next;
		}
	

	
	}

};

#endif