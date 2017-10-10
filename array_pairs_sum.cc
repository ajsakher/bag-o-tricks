/* Find all pairs of elements in a vector
   that sum to a value k and print them to
   stdout. The assumption is that there
   will be no negative numbers in the vector
*/
#include <iostream>
#include <vector>
#include <ctime>

void FindPairs(const std::vector<int>& input, int k)
{
	// keep track of how many are skipped for bookkeeping
	int skipped = 0;
	for(auto& element : input)
	{
		// We can skip any element whose first element > k.
		// Saves computation time since we avoid comparing
		// element to every other element in the input vector
		if (element > k)
		{
			++skipped;
			continue;
		}
		for (auto& second_element : input)
		{
			/* 
			   Doing the skip check here wouldn't save time
			   since we'd be doing a second comparison
			   for each element. It's better to just do
			   the one comparison.
			*/

			// output if it's a match
			if (element + second_element == k)
			{
				std::cout << element << " " <<
				  second_element << std::endl;
			}
		}
	}
	std::cout << "Number of elements skipped: " << skipped << std::endl;
}

// test drive
int main()
{
	std::vector<int> test;

	srand((unsigned)time(0));

	for (int i = 0; i < 10; i++)
	{
		test.push_back(rand() % 10 + 1);
		std::cout << test[i] << " ";
	}
	std::cout << std::endl;
	FindPairs(test, 6);
	return 0;
}
