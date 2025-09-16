#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "searching/binary_search.hpp"
#include "doctest.h"
#include <vector>

// =======================================
// BINARY SEARCH TEST CASES
// =======================================

TEST_CASE("binary_search basic cases") {
    std::vector<int> arr{1, 3, 5, 7, 9};

    CHECK(binary_search(arr, 1) == 0);
    CHECK(binary_search(arr, 5) == 2);
    CHECK(binary_search(arr, 9) == 4);
}

TEST_CASE("binary_search not found cases") {
    std::vector<int> arr{1, 3, 5, 7, 9};

    CHECK(binary_search(arr, 0) == -1);
    CHECK(binary_search(arr, 2) == -1);
    CHECK(binary_search(arr, 10) == -1);
}

TEST_CASE("binary_search empty array") {
    std::vector<int> arr{};
    CHECK(binary_search(arr, 5) == -1);
}

TEST_CASE("binary_search with duplicates") {
    std::vector<int> arr{1, 3, 3, 3, 5};

    int idx = binary_search(arr, 3);
    CHECK(idx >= 1);
    CHECK(idx <= 3); // any valid index is fine
}

// =======================================
// LOWER BOUND TEST CASES
// =======================================

TEST_CASE("lower_bound basic cases") {
    std::vector<int> arr{1, 3, 5, 7, 9};

    CHECK(lower_bound(arr, 1) == 0); // exact match
    CHECK(lower_bound(arr, 2) == 1); // first greater is 3
    CHECK(lower_bound(arr, 5) == 2); // exact match
    CHECK(lower_bound(arr, 8) == 4); // first greater is 9
    CHECK(lower_bound(arr, 10) == 5); // past-the-end
}

TEST_CASE("lower_bound empty array") {
    std::vector<int> arr{};
    CHECK(lower_bound(arr, 5) == 0);
}

TEST_CASE("lower_bound with duplicates") {
    std::vector<int> arr{1, 3, 3, 3, 5};

    CHECK(lower_bound(arr, 3) == 1); // first occurrence
    CHECK(lower_bound(arr, 4) == 4); // position of 5
}

TEST_CASE("lower_bound all smaller") {
    std::vector<int> arr{1, 2, 3};
    CHECK(lower_bound(arr, 0) == 0); // would insert at beginning
}

TEST_CASE("lower_bound all greater") {
    std::vector<int> arr{10, 20, 30};
    CHECK(lower_bound(arr, 40) == 3); // insert at end
}

// =======================================
// UPPER BOUND TEST CASES
// =======================================

TEST_CASE("upper_bound basic cases") {
    std::vector<int> arr{1, 3, 5, 7, 9};

    CHECK(upper_bound(arr, 1) == 1); // next greater is 3 at index 1
    CHECK(upper_bound(arr, 3) == 2); // next greater is 5
    CHECK(upper_bound(arr, 5) == 3); // next greater is 7
    CHECK(upper_bound(arr, 7) == 4); // next greater is 9
    CHECK(upper_bound(arr, 9) == 5); // past-the-end
}

TEST_CASE("upper_bound value smaller than all elements") {
    std::vector<int> arr{10, 20, 30};
    CHECK(upper_bound(arr, 5) == 0); // insert before first element
}

TEST_CASE("upper_bound value larger than all elements") {
    std::vector<int> arr{10, 20, 30};
    CHECK(upper_bound(arr, 30) == 3); // past-the-end
    CHECK(upper_bound(arr, 40) == 3); // past-the-end
}

TEST_CASE("upper_bound empty array") {
    std::vector<int> arr{};
    CHECK(upper_bound(arr, 100) == 0);
}

TEST_CASE("upper_bound with duplicates") {
    std::vector<int> arr{1, 3, 3, 3, 5};

    CHECK(upper_bound(arr, 3) == 4); // next greater is 5 at index 4
    CHECK(upper_bound(arr, 5) == 5); // past-the-end
    CHECK(upper_bound(arr, 1) == 1); // next greater is 3 at index 1
}

// ================================================
// RANGE COUNTING HELPERS
// ================================================

TEST_CASE("count_occurrences works correctly") {
    std::vector<int> arr = {1, 3, 3, 3, 5, 6, 6, 8};

    CHECK(count_occurrences(arr, 1) == 1);   // single element
    CHECK(count_occurrences(arr, 3) == 3);   // multiple occurrences
    CHECK(count_occurrences(arr, 6) == 2);   // multiple occurrences
    CHECK(count_occurrences(arr, 8) == 1);   // last element
    CHECK(count_occurrences(arr, 7) == 0);   // not in array
    CHECK(count_occurrences(arr, 0) == 0);   // smaller than all
    CHECK(count_occurrences(arr, 10) == 0);  // larger than all
    CHECK(count_occurrences(std::vector<int>{}, 5) == 0); // empty array
}

TEST_CASE("count_in_range works correctly") {
    std::vector<int> arr = {1, 3, 3, 3, 5, 6, 6, 8};

    CHECK(count_in_range(arr, 3, 6) == 6);   // {3,3,3,5,6,6}
    CHECK(count_in_range(arr, 1, 8) == 8);   // whole array
    CHECK(count_in_range(arr, 2, 4) == 3);   // only the 3's
    CHECK(count_in_range(arr, 5, 5) == 1);   // single exact match
    CHECK(count_in_range(arr, 7, 9) == 1);   // only {8}
    CHECK(count_in_range(arr, 9, 12) == 0);  // outside right
    CHECK(count_in_range(arr, -5, 0) == 0);  // outside left
    CHECK(count_in_range(std::vector<int>{}, 0, 10) == 0); // empty array
}