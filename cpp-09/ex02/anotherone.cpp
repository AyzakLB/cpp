#include <iostream>
#include <vector>
#include <utility>   // for std::pair
#include <algorithm> // for std::reverse and std::find

// ----------------------------------------------------------
// Helper: binary search to find correct insertion position
// ----------------------------------------------------------
int binarySearchInsertPosition(const std::vector<int> &sorted, int value)
{
    int left = 0;
    int right = (int)sorted.size();

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// ----------------------------------------------------------
// Main recursive Ford–Johnson (Merge-Insertion) sort
// ----------------------------------------------------------
std::vector<int> mergeInsertionSort(const std::vector<int> &X)
{
    int n = (int)X.size();
    if (n <= 1)
        return X;

    // --- Step 1: Pair up elements ---
    std::vector< std::pair<int, int> > pairs;
    int leftover = 0;
    bool hasLeftover = false;

    for (int i = 0; i + 1 < n; i += 2)
        pairs.push_back(std::make_pair(X[i], X[i + 1]));

    if (n % 2 != 0)
    {
        leftover = X[n - 1];
        hasLeftover = true;
    }

    // --- Step 2: Compare within pairs ---
    std::vector<int> larger;
    std::vector<int> smaller;
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first > it->second)
        {
            larger.push_back(it->first);
            smaller.push_back(it->second);
        }
        else
        {
            larger.push_back(it->second);
            smaller.push_back(it->first);
        }
    }

    // --- Step 3: Recursively sort the larger elements ---
    std::vector<int> S = mergeInsertionSort(larger);

    // --- Step 4: Insert partner of smallest element ---
    int smallest = S[0];
    int partner = 0;
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first == smallest || it->second == smallest)
        {
            partner = (it->first == smallest) ? it->second : it->first;
            break;
        }
    }
    S.insert(S.begin(), partner);

    // --- Step 5: Prepare remaining uninserted elements ---
    std::vector<int> remaining;
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first == smallest || it->second == smallest)
            continue;
        int smallerVal = (it->first < it->second) ? it->first : it->second;
        remaining.push_back(smallerVal);
    }
    if (hasLeftover)
        remaining.push_back(leftover);

    // --- Step 6: Determine insertion order ---
    std::reverse(remaining.begin(), remaining.end());

    // --- Step 7: Insert each remaining element using binary search ---
    for (std::vector<int>::iterator rit = remaining.begin(); rit != remaining.end(); ++rit)
    {
        int y = *rit;
        int paired_with = -1;

        for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first == y || it->second == y)
            {
                paired_with = (it->first == y) ? it->second : it->first;
                break;
            }
        }

        int pos;
        if (paired_with != -1)
        {
            std::vector<int>::iterator it_find = std::find(S.begin(), S.end(), paired_with);
            int idx_limit = (it_find != S.end()) ? (int)std::distance(S.begin(), it_find) : (int)S.size();
            std::vector<int> sub(S.begin(), S.begin() + idx_limit);
            pos = binarySearchInsertPosition(sub, y);
        }
        else
        {
            pos = binarySearchInsertPosition(S, y);
        }

        S.insert(S.begin() + pos, y);
    }

    return S;
}

// ----------------------------------------------------------
// Utility: print vector
// ----------------------------------------------------------
void printVector(const std::vector<int> &v)
{
    std::cout << "[ ";
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
}

// ----------------------------------------------------------
// Example usage
// ----------------------------------------------------------
int main()
{
    int arr[] = {7, 3, 1, 4, 9, 2, 8};
    std::vector<int> X(arr, arr + sizeof(arr) / sizeof(int));

    std::cout << "Original array: ";
    printVector(X);

    std::vector<int> sorted = mergeInsertionSort(X);

    std::cout << "Sorted array:   ";
    printVector(sorted);

    return 0;
}
