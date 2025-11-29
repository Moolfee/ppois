#pragma once

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

// Шаблон сортировки слиянием для контейнеров std::vector.
template <typename T>
class MergeSorter {
public:
    // Возвращает отсортированную копию исходного вектора.
    // Для результата используется классическое рекурсивное слияние.
    static std::vector<T> sort(const std::vector<T>& source);

private:
    // Делит диапазон пополам и собирает результат через рекурсию.
    static void splitAndMerge(std::vector<T>& working,
                              std::vector<T>& buffer,
                              std::size_t leftIndex,
                              std::size_t rightIndex);
    // Сливает два отсортированных подотрезка в буфер и переносит результат.
    static void performMerge(std::vector<T>& working,
                             std::vector<T>& buffer,
                             std::size_t leftIndex,
                             std::size_t midIndex,
                             std::size_t rightIndex);
};

template <typename T>
std::vector<T> MergeSorter<T>::sort(const std::vector<T>& source) {
    if (source.size() <= 1) {
        return source;
    }
    std::vector<T> working = source;
    std::vector<T> buffer(source.size());
    // Рекурсия дробит диапазон на половины, пока размер не станет единичным.
    splitAndMerge(working, buffer, 0, working.size());
    return working;
}

template <typename T>
void MergeSorter<T>::splitAndMerge(std::vector<T>& working,
                                   std::vector<T>& buffer,
                                   std::size_t leftIndex,
                                   std::size_t rightIndex) {
    const std::size_t length = rightIndex - leftIndex;
    if (length <= 1) {
        return;
    }
    const std::size_t midIndex = leftIndex + length / 2;
    splitAndMerge(working, buffer, leftIndex, midIndex);
    splitAndMerge(working, buffer, midIndex, rightIndex);
    performMerge(working, buffer, leftIndex, midIndex, rightIndex);
}

template <typename T>
void MergeSorter<T>::performMerge(std::vector<T>& working,
                                  std::vector<T>& buffer,
                                  std::size_t leftIndex,
                                  std::size_t midIndex,
                                  std::size_t rightIndex) {
    std::size_t leftCursor = leftIndex;
    std::size_t rightCursor = midIndex;
    std::size_t bufferCursor = leftIndex;
    // Слияние выбирает минимальный элемент из двух упорядоченных частей.
    while (leftCursor < midIndex && rightCursor < rightIndex) {
        if (working[leftCursor] <= working[rightCursor]) {
            buffer[bufferCursor] = working[leftCursor];
            leftCursor++;
        } else {
            buffer[bufferCursor] = working[rightCursor];
            rightCursor++;
        }
        bufferCursor++;
    }
    const std::size_t leftTail = midIndex - leftCursor;
    const std::size_t rightTail = rightIndex - rightCursor;
    if (leftTail > 0) {
        std::copy_n(working.begin() + static_cast<std::ptrdiff_t>(leftCursor),
                    static_cast<std::ptrdiff_t>(leftTail),
                    buffer.begin() + static_cast<std::ptrdiff_t>(bufferCursor));
        bufferCursor += leftTail;
    }
    if (rightTail > 0) {
        std::copy_n(working.begin() + static_cast<std::ptrdiff_t>(rightCursor),
                    static_cast<std::ptrdiff_t>(rightTail),
                    buffer.begin() + static_cast<std::ptrdiff_t>(bufferCursor));
    }
    // Копирование буфера возвращает отсортированный диапазон.
    std::copy(buffer.begin() + static_cast<std::ptrdiff_t>(leftIndex),
              buffer.begin() + static_cast<std::ptrdiff_t>(rightIndex),
              working.begin() + static_cast<std::ptrdiff_t>(leftIndex));
}

// Класс MergeSorter выполняет рекурсивное слияние для сравнимых типов.
// Шаги: sort стартует, splitAndMerge делит, performMerge объединяет.
// Использует только стандартную библиотеку, без сторонних классов.
