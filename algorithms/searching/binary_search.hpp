#pragma once
#include <vector>

// Checks if the element is present in the array.
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


// ================================================
// SEARCHING ALGORITHMS TO COUNT IN RANGES
// ================================================

// Returns the first position where the element could be inserted in the array while keeping it sorted.
template <typename T>
int lower_bound(const std::vector<T>& arr, T target)
{
    int low{ 0 };
    int high = static_cast<int>(arr.size());

    while (low < high)
    {
        int mid = (low + high) / 2;
        T midValue = arr[mid];

        if (midValue < target)
            low = mid + 1;
        else
            high = mid; // Keep mid because it could be an answer.
    }

    return low; // lower bound position
}

// Returns the last position where the element could be inserted in the array while keeping it sorted.
//template <typename T>
//int upper_bound(const std::vector<T>& arr, T target)
//{
 //   ;
//}