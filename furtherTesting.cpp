#include <iostream>

//------ MapReduceFilter functions ------
template <typename T>
T* map(const T* list, int size, T(f)(const T&))
{
	T* result = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		result[i] = f(list[i]);
	}
	return result;
}
template <typename T>
T* filter(const T* list, int size, bool(predicate)(const T&), int& filterSize)
{
	filterSize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (predicate(list[i]))
			filterSize++;
	}
	T* result = new T[filterSize];
	int l = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (predicate(list[i]))
			result[l++] = list[i];
	}
	return result;
}
template <typename T>
T reduce(const T* list, int size, T(f)(const T&, const T&), T initial)
{
	T result = initial;
	for (size_t i = 0; i < size; i++)
	{
		result = f(result, list[i]);
	}
	return result;
}
//--------------------------------

//------ Median ------
template <typename T>
T median(const T* collection, int size)
{
	if (size % 2 == 0)
	{
		return ((collection[size / 2 - 1] + collection[size / 2]) / 2);
	}
	return collection[size / 2];
}
//--------------------------------

//------ Mode -------
template <typename T>
T mode(T* collection, int size)
{
	T mode;
	int maxCount = 0;
	for (size_t i = 0; i < size; i++)
	{
		int curCount = 0;
		for (size_t j = 0; j < size; j++)
		{
			if (collection[j] == collection[i]) 
				curCount++;
		}
		if (curCount > maxCount)
		{
			maxCount = curCount;
			mode = collection[i];
		}
	}
	return mode;
}
//--------------------------------

//------ Accumulates ------
template <typename T>
T sumOfTwo(const T& a, const T& b)
{
	return a + b;
}
template <typename T>
T accumulates(T* collection, int size, int initial)
{
	return reduce<T>(collection, size, sumOfTwo, initial);
}
//--------------------------------

//------ Average ------
template <typename T>
T average(T* collection, int size, int initial)
{
	T sum = accumulates(collection, size, initial);
	return sum / size;
}
//--------------------------------

//------ All ------ untested
template <typename T>
bool all(T* collection, int size, T zero)
{
	//zero is the 'zero' of the type T
	for (size_t i = 0; i < size; i++)
	{
		if (collection[i] == zero)
			return false;
	}
	return true;
}
//--------------------------------

//------ Max ------ untested
template <typename T>
T bigger(const T& a, const T& b)
{
	if (a > b) return a;
	return b;
}
template <typename T>
T max(T* collection, int size)
{
	return reduce(collection, size, bigger, collection[0]);
}
//--------------------------------

//------ Min ------ untested
template <typename T>
T smaller(const T& a, const T& b)
{
	if (a < b) return a;
	return b;
}
template <typename T>
T min(T* collection, int size)
{
	return reduce(collection, size, smaller, collection[0]);
}
//--------------------------------

void furtherTesting()
{
	double doubleArr[] = { 1, 2, 3, 4, 5, 6, 7, 10, 9, 10 };
	char charArr[] = { 'a', 'b', 'c', 'c', 'c', 'd', 'd', 'f' };
	//sizes of intArr and charArr2 have been alteretd throughout the testing process
	int intArr[] = { 1, 1 };
	char charArr2[] = { 'A' };


	////------ tests for Median -------
	//std::cout << "Median of doubleArr: " << median(doubleArr, 10) << std::endl;
	//std::cout << "Median of charArr: " << median(charArr, 8) << std::endl;

	////------ tests of Mode -------
	//std::cout << "Mode of doubleArr: " << mode(doubleArr, 10) << std::endl;
	//std::cout << "Mode of charArr: " << mode(charArr, 8) << std::endl;

	//------ tests of Accumulates -------
	//std::cout << "Accumulation of doubleArr: " << accumulates(doubleArr, 10, 0) << std::endl;
	//std::cout << "Accumulation of charArr: " << accumulates(charArr, 8, 0) << std::endl;
	//std::cout << "Accumulation of intArr: " << accumulates(intArr, 2, 0) << std::endl;
	//std::cout << "Accumulation of charArr2: " << accumulates(charArr2, 1, 0) << std::endl;
	
	////------ tests of Average -------
	//std::cout << "Average of doubleArr: " << average(doubleArr, 10, 0) << std::endl;
	//std::cout << "Average of charArr: " << average(charArr, 8, 0) << std::endl;
	//std::cout << "Average of intArr: " << average(intArr, 2, 0) << std::endl;
	//std::cout << "Average of charArr2: " << average(charArr2, 1, 0) << std::endl;
}
