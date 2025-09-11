#include "searching/binary_search.hpp"
#include <vector>
#include <cassert>
#include <iostream>

int main()
{
    std::cout << "Test 1..." << std::endl;
    assert(binary_search({1,2,3,4,5,6,7}, 4) != -1);

    std::cout << "Test 2..." << std::endl;
    assert(binary_search({1,2,3,4,5,6,7}, 1) != -1);

    std::cout << "Test 3..." << std::endl;
    assert(binary_search({1,2,3,4,5,6,7}, 7) != -1);

    std::cout << "Test 4..." << std::endl;
    assert(binary_search({1,2,3,4,5,6,7}, 1000) == -1);

    std::cout << "Test 5..." << std::endl;
    assert(binary_search({1,2,3,4,5,6,7}, 0) == -1);

    std::cout << "Test 6..." << std::endl;
    assert(binary_search({1,2,3,4,5,6,7,20,45}, 25) == -1);

    std::cout << "Test 7..." << std::endl;
    assert(binary_search({1}, 1) != -1);

    std::cout << "Test 8..." << std::endl;
    assert(binary_search({1}, 2) == -1);

    std::cout << "Test 9..." << std::endl;
    assert(binary_search({1, 2}, 2) != -1);

    std::cout << "Test 10..." << std::endl;
    assert(binary_search({1, 2}, 3) == -1);

    std::cout << "Test 11..." << std::endl;
    assert(binary_search({}, 2) == -1);

    std::cout << "works!" << '\n';
}   