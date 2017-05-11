#include <iostream>
#include <string>
template <typename T>
void printArr(T* collection, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << collection[i] << " ";
	}
	std::cout << std::endl;
}
template <typename T>
T median(const T* collection, int size)
{
	if (size % 2 == 0)
	{
		return ((collection[size / 2 - 1] + collection[size / 2]) / 2);
	}
	return collection[size / 2];
}

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

template <typename T>
T average(T* collection, int size)
{
	T sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum = sum + collection[i];
	}
	return sum / size;
}

template <typename T>
T accumulates(T* collection, int size)
{
	T sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum = sum + collection[i];
	}
	return sum;
}

template <typename T>
bool all(T* colletion, int size)
{
	for (size_t i = 0; i < size; i++)
		if (colletion[i] == 0) return false;
	return true;
}

template <typename T>
bool any(T* collection, int size)
{
	for (size_t i = 0; i < size; i++)
		if (collection[i] != 0) return true;
	return false;
}

template <typename T, typename T2>
T2* cast(T* collection, int size)
{
	T2* collection2 = new T2[size];
	for (size_t i = 0; i < size; i++)
	{
		collection2[i] = collection[i];
	}
	return collection2;
}

template <typename T>
T max(T* collection, int size)
{
	T max = collection[0];
	for (size_t i = 1; i < size; i++)
	{
		if (collection[i] > max)
			max = collection[i];
	}
	return max;
}

template <typename T>
T min(T* collection, int size)
{
	T min = collection[0];
	for (size_t i = 1; i < size; i++)
	{
		if (collection[i] < min)
			min = collection[i];
	}
	return min;
}

template <typename T>
T* reverse(T* collection, int size)
{
	T* rev = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		rev[i] = collection[size - 1 - i];
	}
	return rev;
}

template <typename T>
T* take(T* collection, int size, int n)
{
	T* firstN = new T[n];
	for (size_t i = 0; i < n; i++)
	{
		firstN[i] = collection[i];
	}
	return firstN;
}

template <typename T>
T* skip(T* collection, int size, int n)
{
	T* skipN = new T[size - n];
	for (size_t i = n; i < size; i++)
	{
		skipN[i - n] = collection[i];
	}
	return skipN;
}

int main()
{
	//double doubleArr[] = { 1, 2, 3, 4, 5, 6, 7, 10, 9, 10 };
	//char charArr[] = { 'a', 'b', 'c', 'c', 'c', 'd', 'd', 'f' };

	////------ tests for Median -------
	//std::cout << "Median of doubleArr: " << median(doubleArr, 10) << std::endl;
	//std::cout << "Median of charArr: " << median(charArr, 8) << std::endl;

	////------ tests for Mode -------
	//std::cout << "Mode of doubleArr: " << mode(doubleArr, 10) << std::endl;
	//std::cout << "Mode of charArr: " << mode(charArr, 8) << std::endl;

	////------ tests for Average -------
	//double testArr[] = { 1, 2, 2 };
	//std::cout << average(testArr, 3) << std::endl;

	////------ tests for Accumulates -------
	//double testArr[] = { 1, 2, 3.2 };
	//std::cout << accumulates(testArr, 3) << std::endl;

	////------ tests for All -------
	//double testArr[] = { 0, 2, 3.2 };
	//std::cout << all(testArr, 3) << std::endl;

	////------ tests for Any -------
	//double testArr[] = { 1, 0, 0 };
	//std::cout << any(testArr, 3) << std::endl;

	////------ tests for Cast ------
	//double doubleArr[] = { 1.2, 2.7, 100.00 };
	//int* intArr = cast<double, int>(doubleArr, 3);
	//printArr(intArr, 3);
	//delete[] intArr;
	//
	//char charArr[] = { 'a', 'b', 'c' };
	//int* intArr2 = cast<char, int>(charArr, 3);
	//printArr(intArr2, 3);
	//delete[] intArr2;

	////------ tests for Max / Min -------
	//double doubleArr[] = { 1.2, 100, 89.789, 5000.29 };
	//std::cout << max(doubleArr, 4) << " " << min(doubleArr, 4) << std::endl;
	//char charArr[] = { 'a', 'b', 'c' };
	//std::cout << max(charArr, 3) << " " << min(charArr, 3) << std::endl;

	////------ tests for Reverse ------
	//double doubleArr[] = { 1.2, 2.7, 100.00 };
	//double* revArr = reverse(doubleArr, 3);
	//printArr(revArr, 3);
	//delete[] revArr;

	////------ tests for Take/Skip ------
	//int intArr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
	//int* takeThree = take(intArr, 10, 3);
	//printArr(takeThree, 3);
	//delete[] takeThree;
	//
	//int* skipSix = skip(intArr, 10, 6);
	//printArr(skipSix, 4);
	//delete[] skipSix;

	//------------- Tests from the task -------------
	int numbers[] = { 0, 1, 2, 3, 4, 4, 5, 6, 7 };
	std::string strings[] = { "batman", "superman", "mickey mouse", "spinderman", "uti bachvarov" };
	int zeros[] = { 0, 0, 0, 0, 0 };

	int numbers_len = 9,
	strings_len = 5,
	zeros_len = 5;

	//--- Passed tests ---
	//std::cout << mode(numbers, numbers_len) << std::endl; // 4 - works
	//std::cout << average(numbers, numbers_len) << std::endl; // 3 - works
	//std::cout << accumulates(numbers, numbers_len) << std::endl; // 32 - works
	//std::cout << all(zeros, zeros_len) << std::endl; // false - works
	//std::cout << all(numbers, numbers_len) << std::endl; // false - works
	//std::cout << all(&numbers[1], numbers_len - 1) << std::endl; // true - works
	//std::cout << any(zeros, zeros_len) << std::endl; // false - works
	//std::cout << any(numbers, numbers_len) << std::endl; // true - works
	//std::cout << max(numbers, numbers_len) << std::endl; // 7 - works
	//std::cout << min(numbers, numbers_len) << std::endl; // 0 - works
	//std::string* reversed = reverse(strings, strings_len); // reversed now contains { "uti bachvarov", "spinderman",  "mickey mouse", "superman", "batman"};
	//std::string* taken = take(strings, strings_len, 2); // taken now contains { "batman", "superman" }
	//std::string* skipped = skip(strings, strings_len, 2); // skipped  now contains { "mickey mouse", "spinderman", "uti bachvarov" }
	//printArr(reversed, strings_len);
	//printArr(taken, 2);
	//printArr(skipped, 3);
	//delete[] reversed;
	//delete[] skipped;
	//delete[] taken;

	//--- Not passed ---
	//std::cout << median(strings, strings_len); // mickey mouse
	//problem : median tries to devide a string with / 

	//std::cout << accumulates(strings, strings_len) << std::endl; // "batmansupermanmickey mousespindermanuti bachvarov"
	//problem : std::string sum = 0 in accumulates causes pointer problems
	return 0;
