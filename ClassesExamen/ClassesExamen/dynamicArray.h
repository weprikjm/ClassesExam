#include <assert.h>


template<class TYPE>
class dynamicArray
{
	//Properties
private:
	TYPE* content;
	int numElements;
	int allocatedMemory;

public:

	dynamicArray()
	{
		Reallocate(1);
		numElements = 0;
		allocatedMemory = 0;
	}

	~dynamicArray()
	{
		Clear();
	}

	int GetElements(){ return numElements; }
	int GetMemory(){ return allocatedMemory; }




	void Reallocate(const int size)
	{
		if (size > 0)//new doesn't accept a size 0 or less
		{
			content = new TYPE [size];
			numElements = size;
			allocatedMemory = size;
		}
	}

	


	void PushBack(const TYPE value)
	{
		if (numElements > 0) //In case the content has been reallocated at least once.
		{
			if (allocatedMemory > numElements)
			{
				content[numElements] = value;
				numElements++;
			}
			else
			{
				TYPE* tmp = new TYPE[numElements + 1];
				CopyArray(tmp, content, 0, numElements-1);
				tmp[numElements]=value;
				delete[] content;
				content = tmp;
				numElements++;
				allocatedMemory++;
			}

		}
		else//In case the content is post constructed and not allocated (empty) 
		{
			//Reallocate(1);
			numElements++;
			allocatedMemory++;
			content[0] = value;
		}
	
	}

	const TYPE Pop()
	{
		if (numElements > 0)
		{
			numElements--;
			return content[numElements - 1];
		}
	}

	void Insert(const int position, const TYPE value)
	{
		if (position >= 0 && position <= numElements && allocatedMemory != 0)
		{ 
					TYPE* tmp = new TYPE[numElements+1];
					
					/*
					 * we construct a tmp array in 3 steps,
					 * 1: We copy content to tmp from start until the position that is going to be filled with value.
					 * 2: We copy the value to tmp position (where we want it)
				     * 3: We copy the rest of the array to tmp
					 */
					CopyArray(tmp, content, 0, position);
					tmp[position] = value;
					numElements++;
					CopyArray(tmp, content, position+1, numElements);


					
					//Once tmp is fully constructed..
					if (allocatedMemory == 0)
						delete[] content;

					content = tmp;//!!!!!
					
					allocatedMemory++;
				
				
		}
		if (allocatedMemory == 0)//If there's any
		{
			content[0] = value;
			numElements++;
			allocatedMemory++;
		}
	}

	void Clear()
	{
	
		delete[] content;
	
	}





	void CopyArray(TYPE* dst,TYPE* src, const unsigned int offset, const unsigned int until)
	{
		int j=0;

		for (int i = offset; i <= until; i++, j++)
		{
			dst[j] = src[i];
		}
	
	}

	//Debug purposes only

	void PrintArray()
	{
		if (numElements == 0)
			printf("The array is empty"); 

		for (int i = 0; i < numElements; i++)
		{
			printf("%d",content[i]);//We manually change % because i don't know how to make the program detect its type (it doesn't really matter cause its for debugging)
		}
	}


	void Trim()
	{
		int i = 0;
		TYPE* tmp = new TYPE;

		while (content[i] == ' ')
		{
			i++;
		}

		CopyArray(tmp,content, i, numElements-i);

		content = tmp;

		numElements -= i;

		
		int counter=0;
		i = numElements;

		while (content[i] == ' ')
		{
			i--;
			counter++;
		}

		CopyArray(tmp, content, 0, (numElements-counter));

		//content = tmp;

		
	}





	const dynamicArray<TYPE>& operator+=( dynamicArray<TYPE>& string2)
	{
		
		dynamicArray<TYPE>* tmp = new dynamicArray<TYPE>;
		
		tmp->Reallocate(GetElements());

		int size = tmp->GetElements();
		
		for (int i = 0; i < numElements; i++) // We copy 
		{
			tmp->content[i] = content[i];
		}


		Reallocate(numElements+string2.GetElements());

		for (int i = 0; i < numElements; i++)
		{
			content[i] = tmp->content[i];
		}


		for (int j = 0 ,i = size; i < this->GetElements(); i++, j++)
		{
			content[i] = string2.content[j];
		
		}
		
		delete tmp;
	
		return (*this);
	}



	TYPE& operator[](unsigned int index)
	{
		assert(index < numElements);
		return content[index];
	}

	const TYPE& operator[](unsigned int index) const
	{
		assert(index < numElements);
		return content[index];
	}




	void Mirror()
	{
		for (int i = 0, j = numElements - 1; i < j; i++, j--)
			Swap(content[i], content[j]);
	
	}

	void Swap(TYPE &a, TYPE &b)
	{
		TYPE tmp = a;
		a = b;
		b = tmp;
	}




};