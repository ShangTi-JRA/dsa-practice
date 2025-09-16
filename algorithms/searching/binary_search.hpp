#pragma once
#include <vector>

// ===============================
// STANDARD BINARY SEARCH
// ===============================

// Checks if the element is present in the array.
// Returns the index if found, -1 otherwise.
template <typename T>
int binary_search(const std::vector<T>& arr, T target)
{
    if (arr.empty()) return -1;

    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        T mid_value = arr[mid];

        if (mid_value == target)
        {
            return mid;
        }

        if (mid_value > target)
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
// BOUNDS SEARCH
// ================================================

// Returns the first index where target could be inserted
// while keeping the array sorted.
template <typename T>
int lower_bound(const std::vector<T>& arr, T target)
{
    int low{ 0 };
    int high = static_cast<int>(arr.size());

    while (low < high)
    {
        int mid = (low + high) / 2;
        T mid_value = arr[mid];

        if (mid_value < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid; // Keep mid because it could be an answer.
        }
    }

    return low; // Could be low or high.
}

// Returns the first index where an element > target could be inserted
// (i.e. the position *after* the last target).
template <typename T>
int upper_bound(const std::vector<T>& arr, T target)
{
    int low = 0;
    int high = static_cast<int>(arr.size());

    while (low < high)
    {
        int mid = (low + high) / 2;
        T mid_value = arr[mid];
        
        if (mid_value <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return high; // or low (they are equal here).
}

// ================================================
// RANGE COUNTING HELPERS
// ================================================

// Counts how many times `target` occurs in `arr`.
template <typename T>
int count_occurrences(const std::vector<T>& arr, T target)
{
    return upper_bound(arr, target) - lower_bound(arr, target);
}

// Counts how many elements fall within the closed interval [L, R].
template <typename T>
int count_in_range(const std::vector<T>& arr, T L, T R)
{
    return upper_bound(arr, R) - lower_bound(arr, L);
}
