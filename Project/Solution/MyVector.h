#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <cassert> // for assert()
#include <random>

template<typename T>
class MyVector
{
	T* m_pData;
	int m_nSize;

public:
	// Constructor
	MyVector(void): m_pData(nullptr), m_nSize(0){ };

	// Copy Constructor
	MyVector(const MyVector& other) : m_pData (nullptr), m_nSize(0)
	{
		MyVector<T> temporal(other.m_nSize);
		CopyContent(temporal, other, other.m_nSize);
		Swap(temporal);
	};

	// Copy Assignment Operator
	MyVector& operator=(const MyVector& other)
	{
		//m_pData (nullptr), m_nSize(0)
		MyVector<T> temporal(other.m_nSize);
		CopyContent(temporal, other, other.m_nSize);
		Swap(temporal);
		return *this;
	};

	// Destructor
	~MyVector(void){ Release(); };

	//Releases the MyVector
	void Release(void){
		if(this->m_pData != nullptr)
		{
			delete[] this->m_pData;
			this->m_pData = nullptr;
			this->m_nSize = 0;
		}
	};
	
	// Returns the size of the vector
	int GetSize(void) const{ return this->m_nSize; };
	
	// Push data on the vector
	void Push(const T input){
		MyVector temporal( this->m_nSize + 1);
		CopyContent(temporal, *this, this->m_nSize);
		temporal.m_pData[temporal.m_nSize -1] = input;
		Swap(temporal);	
	};

	// Swap the top two values if the one we pushed is bigger
	void swapTop(){
		T temp = this->getTop();
		m_pData[GetSize()-1] = m_pData[GetSize()-2];
		m_pData[GetSize()-2] = temp;
		
	}

	// Finds a random value within, removes it, and returns it
	T retrieveRandom(int num)
	{
		MyVector<T> temporal = MyVector<T>();
		int temporalSize = 0;

		T temporary;
		int randomNum;

		// Using the size, find a random value to pull
		if(num !=0){
			randomNum = rand() % num +1;
		}
		else { randomNum = 0;}


		// Now we need to get at that number in the vector: 
		// pop things off and back on to temporal
		for(int i=GetSize(); i>randomNum; i--)
		{
			temporal.Push(getTop()); temporalSize++;
			Pop();
		}
		// Now put temporal back onto the MyVector
		temporary = getTop();

		Pop();


		for(int i=temporalSize; i>=0; i--)
		{
			Push(temporal.getTop()); 
			temporal.Pop(); temporalSize--;
		}
		return temporary;
	};

	// Pop data out of the vector
	void Pop(void)
	{
		if(m_nSize > 0)
		{
			MyVector temporal(this->m_nSize - 1);
			CopyContent(temporal, *this, temporal.m_nSize);
			Swap(temporal);	
		}
	};

	// GetTop
	T getTop(){
		if(!IsEmpty())
		{
			return m_pData[GetSize()-1];
		}
	}

	// Operator [] overloaded to access an element on the vector
	T& operator[](const unsigned int nIndex)
	{
		assert(nIndex < static_cast <unsigned int> (this->m_nSize));
	
		return this->m_pData[nIndex];
	};

	// Returns true if no elements are in the vector, false otherwise
	bool IsEmpty(void){
		return (this->m_pData == nullptr ? true : false);
	}

	// friend <<
	friend std::ostream& operator<<(std::ostream& os, MyVector& other)
	{
		//(friend needs to be kept in the header)
		other.Print();
		return os;
	}

	// Constructor with parameter
	MyVector(int nSize): m_pData(new T[nSize]), m_nSize(nSize){ };


	// Swaps contents of data members with those of an incoming object
	void Swap(MyVector& other)
	{
		std::swap( this->m_nSize, other.m_nSize);
		std::swap( this->m_pData, other.m_pData);
	};

	// Copy the content of m_data from one object to other, from 0 to nLimit (inclusive)
	void CopyContent(MyVector& destiny, const MyVector& origin, const unsigned int nLimit)
		{
		if((int) nLimit > destiny.m_nSize || (int) nLimit > origin.m_nSize)
			return;
		
		for(int i = 0; i < nLimit; i++)
		{
			destiny.m_pData[i] = origin.m_pData[i];
		}
	};

	// Prints the data of the vector
	void Print(void){
		//std::cout << "[" << typeid(*this).name() << "] ";
		std::cout << "[ ";
		for(int i = 0; i < m_nSize; i++)
		{
			std::cout << m_pData[i] << ", ";
		}
		if(m_nSize > 0)
		{
			std::cout << static_cast <char> (8);
			std::cout << static_cast <char> (8);
		}
		std::cout << " ]";
	};


};

#endif