#pragma once
#include <vector>

// Returns the index of the target in the array or -1 if is not found. 
template <typename T>
int binary_search(const std::vector<T>& arr, T target)
{
    if (arr.empty()) return -1;

    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high)
    {
        // #1 Decision: The middle point
        int mid = (low + high) / 2;
        T midValue = arr[mid];

        // #2 Decision: The comparison
        if (midValue == target)
        {
            return mid;
        }

        // #3 Decision: The discard.
        if (midValue > target)
        {
            // Target is to the left.
            high = mid - 1;
        }
        else
        {
            // Target is to the right.
            low = mid + 1;
        }
    }

    return -1;
}