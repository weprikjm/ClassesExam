#include <string>

class myString
{

private:
	int allocatedMemory;
	char* str;

public:

	myString()
	{
		Alloc(1);
		Clear();
	}

	myString(int size)
	{
		if (size>0)
			Alloc(size);
		
		else
			Alloc(1);
			
		Clear();
	}

	void setString(const char* string)
	{
		if (string != NULL)
		{
			if (strlen(string) < allocatedMemory)
			{
				Clear();
				strcpy_s(str, strlen(string),string);
				allocatedMemory = strlen(string)+1;
			}
			
			else
			{
				str = new char[strlen(string)+1];
				strcpy_s(str, strlen(string)+1, string);
				allocatedMemory = strlen(string)+1;
			}
		}
		
	
	}

	const char* getString()const{ return str; }



	//Operators
	myString& operator+=(const myString& string)
	{
		if (string.str != NULL)
		{
			int size = strlen(string.str) + strlen(str) + 1;

			if (size > allocatedMemory)//If there's no enough space
			{
				char* tmp = str;
				Alloc(size);
				strcpy_s(str, strlen(tmp)+1, tmp);
				delete[] tmp;
			}
			
			strcat_s(str, allocatedMemory, string.str);
			
			
			return (*this);
		}
	}

	const myString& operator+= (const char* string)
	{
		if (string != NULL)
		{
			int size = strlen(string) + strlen(str) + 1;

			if (size > allocatedMemory)//If there's no enough space
			{
				char* tmp = str;
				Alloc(size);
				strcpy_s(str, strlen(tmp) + 1, tmp);
				delete[] tmp;
			}

			strcat_s(str, allocatedMemory, string);


			return (*this);
		}
	

	
	}

	const myString& operator= (const myString& string)
	{
		if (string.str != NULL)
		{
			if (allocatedMemory < strlen(string.str + 1))
			{
				delete[] str;
				Alloc(strlen(string.str)+1);
			}
			else
			{
				Clear();
			
			}

			strcpy_s(str, strlen(string.str)+1, string.str);
			
		}
		return (*this);
	}


	bool operator==(const char* string)
	{
		return (strcmp(str, string) == 0);
	}

	bool operator==(const myString& string)
	{
		return (strcmp(str, string.str)==0);
	}

	bool operator!=(const char* string)
	{
		return (strcmp(str, string) == 1);
	}
	bool operator!=(const myString& string)
	{
		return (strcmp(str, string.str)==1);
	}


	//Utilities
private: 
	void Alloc(int size)
	{
		if (size > 0)
		{
			str = new char[size];
			Clear();
			allocatedMemory = size;
		}
	}

	int getCapacity()
	{
		return allocatedMemory;
		
	}

	void Clear()
	{
		str[0] = '\0';
	}
public:
	void PrintString()
	{
	
		printf("%s",str);
	
	}


	virtual ~myString()
	{
		if (str != NULL)
		{
			delete[] str;
		}
	
	}


	void Trim()
	{
		int i = 0;
		int j = 0;
		int counter = 0;

		while (str[i] == ' ')
		{
			i++;
		}

		for (; i < allocatedMemory; i++, j++)
		{
			str[j] = str[i];
		}

		i = strlen(str)-1;
		
		while (str[i] == ' ')
		{ 
			i--;
			counter++;
		}

		



	
	}

	void Cut(const int start, const int end)
	{
		int difference = end - start;
		int size = strlen(str);
		char* tmp = new char[strlen(str)+1];
	


		strcpy_s(tmp, strlen(str)+1, str);

		printf("%s", tmp);
	}




};