#ifndef __p2Qeue2_H__
#define __p2Qeue2_H__

#include "p2Defs.h"
#include "DList.h"

template<class VALUE>
class arrayList
{
public:

	uint left_index = 0;

	DList<VALUE> data;

	/**
	* Get Size
	*/
	unsigned int Count() const
	{
		return data.Count() - left_index;
	}

	/**
	* push up front
	*/
	void Push(const VALUE& item)
	{
		bool swapped = true;

		if (data.Count<=0)
		{ 
			data.Add(item);
		}
		else
		{
			Node<VALUE>* tmp = data.getStart();

			while (swapped)
			{
				swapped = false;
				while (!tmp->NULL)
				{
					Swap(tmp,tmp->next);
					tmp = tmp->next;

					swapped = true;
				}
				tmp = data.getStart();
			}
		}
		




	}

	/**
	* Pops last item
	*/
	bool Pop(VALUE& item)
	{
		if (left_index < data.Count())
		{
			item = data[left_index++];
			return true;
		}

		return false;
	}

	/**
	* Reads one of the values
	*/
	const VALUE* Peek(unsigned int index) const
	{
		index += left_index;
		if (index < data.Count())
			return &data[index];

		return NULL;
	}

	/**
	* Destroy and free all mem
	*/
	void Clear()
	{
		data.Clear();
	}

};
#endif /*__p2Qeue2_H__*/