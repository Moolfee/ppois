#include <gtest/gtest.h>
#include <ostream>
#include "domain/sorting/MergeSorter/MergeSorter.h"

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& values) {
    stream << "[";
    for (std::size_t index = 0; index < values.size(); index++) {
        stream << values[index];
        if (index + 1 < values.size()) {
            stream << ", ";
        }
    }
    stream << "]";
    return stream;
}

template <typename T>
void expectEqualVectors(const std::vector<T>& actual, const std::vector<T>& expected) {
    EXPECT_EQ(actual.size(), expected.size());
    for (std::size_t index = 0; index < actual.size(); index++) {
        EXPECT_EQ(actual[index], expected[index]);
    }
}

TEST(MergeSorter, SortsIntegersWithDuplicates) {
    std::vector<int> numbers = {5, 1, 1, 3, 2};
    auto sortedNumbers = MergeSorter<int>::sort(numbers);
    expectEqualVectors(sortedNumbers, std::vector<int>{1, 1, 2, 3, 5});
    expectEqualVectors(numbers, std::vector<int>{5, 1, 1, 3, 2});
}

TEST(MergeSorter, KeepsOrderedSequenceStable) {
    std::vector<int> numbers = {1, 2, 3, 4};
    auto sortedNumbers = MergeSorter<int>::sort(numbers);
    expectEqualVectors(numbers, sortedNumbers);
}

TEST(MergeSorter, SortsStringsAlphabetically) {
    std::vector<std::string> words = {"orange", "apple", "banana"};
    auto sortedWords = MergeSorter<std::string>::sort(words);
    expectEqualVectors(sortedWords, std::vector<std::string>{"apple", "banana", "orange"});
}

TEST(MergeSorter, HandlesSingleElement) {
    std::vector<int> singleValue = {42};
    auto sortedSingle = MergeSorter<int>::sort(singleValue);
    expectEqualVectors(sortedSingle, std::vector<int>{42});
}
