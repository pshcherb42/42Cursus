
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cerrno>
#include <cstdlib>

// Stores a winning/losing pair from the initial comparison step.
// large = winner (bigger), small = loser (smaller).
// Keeping them together lets us recover the correct upper bound
// for each small element even after the large values are recursively sorted.
struct Pair
{
    int large;
    int small;
};

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();
		static int comparisons;

	    // ------------------------------------------------------------------ //
	    //  Comparison wrapper — counts every comparison made                  //
	    // ------------------------------------------------------------------ //
	    static bool comp(int a, int b);

	    // ------------------------------------------------------------------ //
	    //  Returns true when the input is already sorted (used as guard)      //
	    // ------------------------------------------------------------------ //
	    static bool already_sorted(const std::vector<int>& v);

	    // ------------------------------------------------------------------ //
	    //  Jacobsthal sequence up to n:  1, 3, 5, 11, 21, …                  //
	    // ------------------------------------------------------------------ //
	    static std::vector<size_t> jacobsthal(size_t n);

	    // ------------------------------------------------------------------ //
	    //  Binary-insert value into c before end_it.                          //
	    //  Only elements in [c.begin(), end_it) are searched.                 //
	    //  The key invariant: value < *end_it is already KNOWN by the         //
	    //  caller (it is the paired large element), so end_it is an           //
	    //  EXCLUSIVE upper bound — never pass end_it = position_of_a + 1.    //
	    // ------------------------------------------------------------------ //
	    template<typename Container>
	    static void binary_insert(Container& c, int value, typename Container::iterator end_it) {
			typename Container::iterator left  = c.begin();
			typename Container::iterator right = end_it;
			while (left < right)
			{
		    	typename Container::iterator mid = left + (right - left) / 2;
		    	if (comp(value, *mid))
		        	right = mid;
		    	else
		        	left  = mid + 1;
			}
			c.insert(left, value);
	    }

	    // ------------------------------------------------------------------ //
	    //  Re-order a vector of Pairs so that their .large values appear in   //
	    //  the same order as sorted_larges.  No comparisons — pure bookkeeping//
	    // ------------------------------------------------------------------ //
	    static std::vector<Pair> reorder_pairs(const std::vector<Pair>&  pairs, const std::vector<int>&   sorted_larges);
		// ------------------------------------------------------------------ //
		//  Core Ford-Johnson sort — works on std::vector<int>.                //
		//  The deque path converts to vector, sorts, then converts back.      //
		// ------------------------------------------------------------------ //
	    static std::vector<int> ford_johnson(std::vector<int> input);

public:

    static void run(char **argv);
};

#endif
