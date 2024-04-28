/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:46:02 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/28 19:33:14 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pair::Pair(int min, int max) {
	if (min <= max) {
		this->min = min;
		this->max = max;
	} else {
		this->min = max;
		this->max = min;
	}
}

Pair::Pair(const Pair &src) {
	*this = src;
}

Pair::~Pair() {
}

Pair	&Pair::operator=(const Pair &rhs) {
	if (this != &rhs) {
		min = rhs.min;
		max = rhs.max;
	}
	return *this;
}

bool	Pair::operator==(const Pair &other) {
	return min == other.min && max == other.max;
}

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs) {
	(void) rhs;
	return *this;
}

std::vector<int>	PmergeMe::parse(int ac, char **av) {
	std::vector<int>	numbers;

	for (int i = 1; i < ac; i++) {
		char		*left;
		long long	n = strtoll(av[i], &left, 10);
		if (errno == ERANGE || *left != '\0'
			|| n < -2147483647-1 || n > 2147483647) {
			std::cout << "Error: Invalid number: " << av[i] << std::endl;
			return std::vector<int>();
		}
		numbers.push_back(n);
	}

	if (numbers.size() <= 0)
		std::cout << "Error: No numbers provided" << std::endl;

	return numbers;
}

/**
 * @brief Sort a list of integers using the Ford-Johnson algorithm.
 * 
 * @note See wikipedia : @ref https://en.wikipedia.org/wiki/Ford%E2%80%93Johnson_algorithm
*/
template <typename Container, typename PairContainer>
Container	PmergeMe::sort(Container &list, PairContainer ppairs) {
	if (list.size() <= 1)
		return list;

	PairContainer	pairs;
	Container		maximums;
	Container		sorted;

	/*
	 * 1. Create pairs of elements and store the maximum of each pair.
	 */
	for (typename Container::iterator it = list.begin(); it + 1 < list.end(); it += 2) {
		Pair	pair(*it, *(it + 1));
		pairs.push_back(pair);
		maximums.push_back(pair.max);
	}

	/*
	 * 2. Sort the maximums RECURSIVELY and start to fill the sorted list.
	 */
	maximums = sort(maximums, ppairs);
	sorted = maximums;

	/*
	 * 3. Add the `min` of the first pair to the front of the sorted list.
	 * 
	 * `maximums` has been sorted, the first element is the lowest.
	 * `Pair::min` is the lower than `Pair::max`.
	 * So the `min` associated with `maximums[0]` is the lowest of all.
	 */
	sorted.insert(sorted.begin(), findPairFromMax(pairs, maximums[0]).min);
	pairs.erase(pairs.begin() + posOf(pairs, findPairFromMax(pairs, maximums[0])));

	/*
	 * 4. Loop through the remaining pairs
	 *     and insert the `min` at the right place in `sorted`.
	 * 
	 * Only the `min` because the `max` are already in `sorted`.
	 */
	int	loopCount = 0;
	int	maxOffset = 1;
	while (pairs.size() > 0)
	{
		/*
		 * Get the chunk size for the current iteration.
		 * 
		 * The numbers will be added in chunks of `chunkSize` elements.
		 * Ex: For [3, 1, 4, 2, 0, 5, 8, 6, 7, 9],
		 * We will insert [3, 1], next [4, 2], next [2, 0, 5, 8, 6, 7, 9]
		 *                 (2)           (2)                  (6)
		 * Following the MODIFIED-Jacobsthal sequence (see below).
		 * 
		 * Because this part uses a merge sort (binary insertion), it's
		 *  optimal to insert elements in chunks of size following the
		 *  `2^k - 1`'s rule (see below).
		 */
		size_t	chunkSize = jacobsthal(loopCount++);

		if (chunkSize > pairs.size())
			chunkSize = pairs.size();

		int	chunkSizeBackup = chunkSize;

		/*
		 * But we need to insert the elements in reverse order.
		 * 
		 * Ex: For [3, 1, 4, 2, 0, 5, 8, 6, 7, 9],
		 * 		Step 1: [3, 1] -> Insert 1, then 3
		 * 		Step 2: [4, 2] -> Insert 2, then 4
		 * 		Step 3: [2, 0, 5, 8, 6, 7, 9] -> Insert 9, then 7, then 6, ...
		 * 
		 * `maximums` is immutable, so we need to keep track of the current index.
		 * We will insert the elements at `maxIndex` in `maximums`
		 *  and decrement `maxIndex` until `maxIndex - chunkSize` is reached.
		 */
		int	maxIndex = maxOffset + chunkSize - 1;
		while (chunkSize--) {
			int		elem = maximums[maxIndex--]; // Get the "key" to the pair to insert
			Pair	pair = findPairFromMax(pairs, elem);
			int		rightBoundIndex = posOf(sorted, elem);

			// Find the right place to insert the `min` in `sorted` (binary insertion)
			int		insertionIndex = binarySearch(sorted, pair.min, 0, rightBoundIndex);

			sorted.insert(sorted.begin() + insertionIndex, pair.min);
			pairs.erase(pairs.begin() + posOf(pairs, pair));
		}
		/*
		 * Update the offset to keep track of the current index in `maximums`.
		 *  (`maximums` is immutable, while `pairs` is emptied as we go through the loop)
		 */
		maxOffset += chunkSizeBackup;
	}

	/*
	 * 5. If the original list had an odd number of elements, insert the last one.
	 */
	if (list.size() % 2 == 1) {
		int	odd = list[list.size() - 1];
		int	insertionIndex = binarySearch(sorted, odd, 0, sorted.size() - 1);
		sorted.insert(sorted.begin() + insertionIndex, odd);
	}

	return sorted;
}

template <typename PairContainer>
Pair	PmergeMe::findPairFromMax(PairContainer &pairs, int max) {
	for (typename PairContainer::iterator it = pairs.begin(); it < pairs.end(); it++) {
		if (it->max == max)
			return *it;
	}
	return Pair(-2147483647-1, 2147483647);
}

/**
 * @brief Return the nth MODIFIED-Jacobsthal number.
 * 
 * @note The original Jacobsthal sequence starts with `0` and `1`.
 * @note The MODIFIED-Jacobsthal sequence starts with `2` and `2`.
 * @note This way, the sequence follows the rule:
 * @note `∃k∈ℕ ∋ J(n) + J(n + 1) = 2^k - 1, ∀n∈ℕ` !
 * @note ---
 * @note First numbers of the original sequence are:
 * 		`0` `1` `1` `3` `5` `11` `21` `43` `85` `171` `341` `683` `1365` `2731`
 * 		`5461` `10923` `21845` `43691` `87381` `174763` `349525`
 * @note First numbers of the MODIFIED sequence are:
 * 		`2` `2` `6` `10` `22` `42` `86` `170` `342` `682` `1366` `2730` `5462`
 * 		`10922` `21846` `43690` `87380` `174762` `349526` `699050`
 * @note ---
 * @note See wikipedia : @ref https://en.wikipedia.org/wiki/Jacobsthal_number
 */
size_t	PmergeMe::jacobsthal(int n) {
	if (n == 0)
		return 2;
	if (n == 1)
		return 2;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

template <typename Container>
int	PmergeMe::binarySearch(Container &list, int target, int left, int right) {
	if (left > right)
		return 0;

	int	mid = (left + right) / 2;

	if (left == right)
		return target < list[left] ? left : left + 1;
	if (target < list[mid])
		return binarySearch(list, target, left, mid);
	return binarySearch(list, target, mid + 1, right);
}

template <typename T, typename S>
int	posOf(S &container, T elem) {
	for (size_t i = 0; i < container.size(); i++) {
		if (container[i] == elem)
			return i;
	}
	return -1;
}

// --- Explicit instantiation (to avoid linking errors) ---
template std::vector<int>	PmergeMe::sort<std::vector<int>, std::vector<Pair> >(std::vector<int> &, std::vector<Pair>);
template std::deque<int>	PmergeMe::sort<std::deque<int>, std::deque<Pair> >(std::deque<int> &, std::deque<Pair>);
