
#include "PmergeMe.hpp"

int PmergeMe::comparisons = 0;

bool PmergeMe::comp(int a, int b)
{
    comparisons++;
    return a < b;
}

bool PmergeMe::already_sorted(const std::vector<int>& v)
{
    for (size_t i = 1; i < v.size(); i++)
        if (v[i] < v[i - 1])
            return false;
    return true;
}

std::vector<size_t> PmergeMe::jacobsthal(size_t n)
{
    std::vector<size_t> j;
    j.push_back(1);
    j.push_back(3);
    while (j.back() < n)
    {
        size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
        j.push_back(next);
    }
    return j;
}

std::vector<int> PmergeMe::ford_johnson(std::vector<int> input) {
    size_t n = input.size();
	if (n <= 1)
		return input;

	// Base case: one comparison, done.
	if (n == 2)
	{
		if (comp(input[1], input[0]))
		    std::swap(input[0], input[1]);
		return input;
	}

	// ---- Step 1: form pairs, keep track of which small goes with which large ----
	std::vector<Pair> pairs;
	int odd = -1;

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		Pair p;
		if (comp(input[i], input[i + 1]))
		{
		    p.large = input[i + 1];
		    p.small = input[i];
		}
		else
		{
		    p.large = input[i];
		    p.small = input[i + 1];
		}
		    pairs.push_back(p);
	}
	if (n % 2)
		odd = input.back();

	// ---- Step 2: recursively sort the large values ----
	std::vector<int> larges;
	larges.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].large);

	std::vector<int> sorted_larges = ford_johnson(larges);

	// Restore pair order so pairs[i].large == sorted_larges[i]
	pairs = reorder_pairs(pairs, sorted_larges);

	// ---- Step 3: build main chain from sorted large values ----
	std::vector<int> chain(sorted_larges);

	// ---- Step 4: insert b1 for free (b1 <= a1 is guaranteed) ----
	chain.insert(chain.begin(), pairs[0].small);

	// ---- Step 5: insert remaining smalls using Jacobsthal order ----
	if (pairs.size() > 1)
	{
	    std::vector<size_t> j = jacobsthal(pairs.size());

	    for (size_t k = 1; k < j.size(); ++k)
	    {
	        size_t start = j[k - 1];
	        size_t end   = std::min(j[k], pairs.size());

	        // Insert in DESCENDING index order within each Jacobsthal block.
	        // This keeps the search ranges small and yields the optimal count.
	        for (size_t i = end; i > start; --i)
		    {
		        size_t idx = i - 1;   // 0-based index into pairs[]

		        // pairs[idx].small < pairs[idx].large is GUARANTEED.
		        // Therefore the upper bound is the position OF pairs[idx].large
		        // (exclusive) — we must NOT go past it, so no ++limit here.
		        std::vector<int>::iterator limit = std::find(chain.begin(), chain.end(), pairs[idx].large);
                binary_insert(chain, pairs[idx].small, limit);
		    }
		}
	}

	// ---- Step 6: insert the leftover odd element (no known upper bound) ----
	if (odd != -1)
	    binary_insert(chain, odd, chain.end());

	return chain;
}

std::vector<Pair> PmergeMe::reorder_pairs(const std::vector<Pair>&  pairs, const std::vector<int>&   sorted_larges) {
    std::vector<bool> used(pairs.size(), false);
    std::vector<Pair> result;
    result.reserve(pairs.size());
    for (size_t i = 0; i < sorted_larges.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].large == sorted_larges[i])
            {
                result.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    return result;
}

void PmergeMe::run(char **argv)
{
    std::set<int> seen;
    std::vector<int> vec;

    for (int i = 1; argv[i]; ++i)
    {
        char *endptr = NULL;
        errno = 0;

        long val = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0') // checks for grabage input
            throw std::runtime_error("Error");

        if (errno == ERANGE || val > INT_MAX || val < INT_MIN) // checks for limits
            throw std::runtime_error("Error");

        int num = static_cast<int>(val); // now the number is safe

        if (num < 0) // check negative numbers
            throw std::runtime_error("Error");

        if (!seen.insert(num).second) //check duplicates
            throw std::runtime_error("Error");

        vec.push_back(num);
    }

    if (vec.empty()) // check empty input
        throw std::runtime_error("Error");

    if (already_sorted(vec)) 
        throw std::runtime_error("Error");

    // Print input
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // --- Sort with std::vector ---
    //comparisons = 0;
    clock_t start_vec = clock();
    std::vector<int> sorted_vec = ford_johnson(vec);
    clock_t end_vec = clock();
    //int vec_comparisons = comparisons;

    // --- Sort with std::deque (convert to vector, sort, result is correct) ---
    // The algorithm is vector-based internally; we time the deque conversion path.
    //comparisons = 0;
    std::deque<int> deq(vec.begin(), vec.end());
    clock_t start_deq = clock();
    std::vector<int> tmp(deq.begin(), deq.end());
    std::vector<int> sorted_tmp = ford_johnson(tmp);
    std::deque<int> sorted_deq(sorted_tmp.begin(), sorted_tmp.end());
    clock_t end_deq = clock();

    // Print result
    std::cout << "After:  ";
    for (size_t i = 0; i < sorted_vec.size(); ++i)
        std::cout << sorted_vec[i] << " ";
    std::cout << std::endl;

    double vec_time = (double)(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
    double deq_time = (double)(end_deq - start_deq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of "
              << vec.size()
              << " elements with std::vector : "
              << vec_time << " us" << std::endl;

    std::cout << "Time to process a range of "
              << deq.size()
              << " elements with std::deque  : "
              << deq_time << " us" << std::endl;

   // std::cout << "Comparisons: " << vec_comparisons << std::endl;
}
