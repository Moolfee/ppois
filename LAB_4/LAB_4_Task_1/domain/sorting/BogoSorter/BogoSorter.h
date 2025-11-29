#pragma once

#include <algorithm>
#include <cstddef>
#include <random>
#include <string>
#include <vector>

// Шаблонная реализация bogosort для небольших наборов данных.
template <typename T>
class BogoSorter {
public:
    // Перемешивает элементы до сортировки либо до исчерпания попыток.
    static std::vector<T> sortRandomly(const std::vector<T>& source, std::size_t maxAttempts = 50000);

private:
    // Проверяет, упорядочен ли текущий набор элементов.
    static bool isOrdered(const std::vector<T>& candidate);
};

template <typename T>
std::vector<T> BogoSorter<T>::sortRandomly(const std::vector<T>& source, std::size_t maxAttempts) {
    if (source.size() <= 1) {
        return source;
    }
    std::vector<T> candidate = source;
    std::mt19937 generator(std::random_device{}());
    std::size_t attemptCount = 0;
    // Цикл случайно перемешивает контейнер и после шага проверяет порядок.
    while (attemptCount < maxAttempts && !isOrdered(candidate)) {
        std::shuffle(candidate.begin(), candidate.end(), generator);
        attemptCount++;
    }
    return candidate;
}

template <typename T>
bool BogoSorter<T>::isOrdered(const std::vector<T>& candidate) {
    if (candidate.empty()) {
        return true;
    }
    for (std::size_t index = 1; index < candidate.size(); index++) {
        if (candidate[index - 1] > candidate[index]) {
            return false;
        }
    }
    return true;
}

// Класс BogoSorter демонстрирует шаблонный bogosort на основе std::shuffle.
// sortRandomly отвечает за перемешивание, isOrdered завершает цикл при успехе.
// Зависит только от стандартной библиотеки и не использует другие классы.
