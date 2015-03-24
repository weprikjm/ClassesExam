template<typename TYPE>
struct Node
{
	TYPE data;
	Node* next;
	Node* previous;

	Node(const TYPE& value)
	{
		data = value;
		next = NULL;
		previous = NULL;
	}

};



template<class TYPE>
class DList
{
private:
	Node<TYPE>* start;
	Node<TYPE>* end;

public:
	DList()
	{
		start = NULL;
		end = NULL;
	}

	DList<TYPE>* getStart()
	{
	
		return start;
	}

	DList<TYPE>* getEnd()
	{
	
		return end;
	
	}


	void Add(const TYPE& oneNode)
	{
		if (oneNode != NULL)
		{
			Node<TYPE>* tmpNode = new Node<TYPE>(oneNode);

			if (start != NULL) //In case there's 1 or more nodes
			{
				tmpNode->previous = end;
				end->next = tmpNode;
				end = tmpNode;
			}
			else // In case the list is empty
			{
				start = tmpNode;
				end = tmpNode;
			}
			
		}

	}

	bool RemoveElement(Node<TYPE>* nodeToRemove)
	{
		if (start != NULL)
		{
			
			if (nodeToRemove->next == NULL)//If it's the end
			{

				nodeToRemove->previous->next = NULL;
				end = nodeToRemove->previous;

			}
			else if (nodeToRemove->previous == NULL)//if it's at the beginning
			{
				if (nodeToRemove->next == NULL)//If there's only one node left
				{
					start = NULL;
					end = NULL;
				}
				else//If the node is at the beginning but there's more nodes after it
				{
					nodeToRemove->next->previous = NULL;//We set null to the next node after the first that is being removed
					start = nodeToRemove->next;
				}
					

			}
			else//If it's in the middle
			{
				nodeToRemove->previous->next = nodeToRemove->next;
				nodeToRemove->next->previous = nodeToRemove->previous;
			}
		
		}
		else
		{
			return false;
		
		}

		delete nodeToRemove;
		return true;
	}

	void clear()
	{
		Node<TYPE>*   tmp_data;
		Node<TYPE>*   tmp_next;
		tmp_data = start;

		while (tmp_data != NULL)
		{
			tmp_next = tmp_data->next;
			delete (tmp_data);
			tmp_data = tmp_next;
		}

		start = end = NULL;
	}

	Node<TYPE>* getElementAtPos(unsigned int i)
	{
		Node<TYPE>* tmp = start;

		if (tmp != NULL && i < Count())
		{
			for (int c = 0; c < i; c++)
			{
				tmp = tmp->next;
			}
			return tmp;
		}

		return NULL;

	}

	void PrintNode(Node<TYPE>* n)
	{
		if (n != NULL)
		{
			printf("%d", n->data);
		}
		else
		{
			printf("No node in this position");
		}
	}




	int Count()
	{
		int count = 0;

		if (start != NULL)
		{
			Node<TYPE>* n;
			n = start;
			
			while (n!=NULL)
			{
				n = n->next;
				count++;
			}
		
		}
		else
		{
		
			return 0;
		}
	
	
	}

	~DList()
	{
		clear();
	}



};