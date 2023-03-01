#include <iostream>
#include <vector>
#include <string>

class SortStrategy
{
private:
public:
	virtual void sort(int* arr, int size) = 0;
	virtual void sort(std::vector<std::string>) = 0;
};

class BubbleSort : public SortStrategy
{
private:
public:
	void sort(int* arr, int size) override
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void sort(std::vector<std::string>) override
	{
		std::cout << "nothing\n";
	}
};
class QuickSort : public SortStrategy
{
private:
public:
	void sort(int* arr, int size)  override
	{ 
		long left = 0, right = size; int temp, middle; middle = arr[size / 2]; 
	do 
		{ 
			while (arr[left] < middle) 
			{ 
				left++; 
			}while (arr[right] > middle) 
			{ 
				right--; 
			}
			if (left <= right) 
			{ 
				temp = arr[left]; 
				arr[left] = arr[right];
				arr[right] = temp; 
				left++; 
				right--; 
			} 
		} while (left <= right); if (right > 0) sort(arr, right); 
	if (size > left) 
		sort(arr + left, size - left); 
	}
	void sort(std::vector<std::string>) override
	{
		std::cout << "nothing\n";
	}
};

class SortedArray
{
	std::vector<std::string> vector;
	SortStrategy* sortstrategy;
public:
	void SetSortStrategy(SortStrategy* sortstrategy)
	{
		this->sortstrategy = sortstrategy;
	}
	void Add(std::string name)
	{
		vector.push_back(name);
	}
	void Sort()
	{
		sortstrategy->sort(vector);
		for (std::string name : vector)
		{
			std::cout << " " + name << std::endl;
		}
		std::cout << std::endl;
	}
};

int main()
{
	int size = 10;
	int* test1 = new int[size];
	int* test2 = new int[size];
	for (int i = 0; i < size; i++)
	{
		test1[i] = size - i;
		test2[i] = size - i;
	}
	BubbleSort help1;
	QuickSort help2;
	help1.sort(test1, size);
	help2.sort(test2, size - 1);
	for (int i = 0; i < size; i++)
	{
		std::cout << test1[i] << ", ";
	}
	std::cout << '\n';
	for (int i = 0; i < size; i++)
	{
		std::cout << test2[i] << ", ";
	}
	std::cout << '\n';
	SortedArray ar;
	ar.Add("Strategy");
	ar.Add("Observer");
	ar.Add("Iterator");
	ar.Add("Mediator");
	ar.Add("Memento");
	ar.Add("Interpreter");
	ar.Add("State");
	ar.Add("Command");

	BubbleSort bubble;
	ar.SetSortStrategy(&bubble);
	ar.Sort();

	system("pause");
	return 0;
}