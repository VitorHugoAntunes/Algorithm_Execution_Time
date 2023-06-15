#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

std::vector<double> list2;

void bubbleSort(std::vector<double> &array)
{
    int arraySize = array.size();

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < (arraySize - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 100; i++)
    {
        list2.push_back(static_cast<double>(rand()) / RAND_MAX * 10);
    }

    std::cout << "Array inicial:" << std::endl;
    for (const auto &element : list2)
    {
        std::cout << element << " ";
    }
    std::cout << "\n"
              << std::endl;

    const int numIterations = 100;
    double totalElapsedTime = 0.0;

    for (int i = 0; i < numIterations; i++)
    {
        auto start = std::chrono::steady_clock::now();

        bubbleSort(list2);

        auto end = std::chrono::steady_clock::now();
        double elapsedTime = std::chrono::duration<double>(end - start).count();
        totalElapsedTime += elapsedTime;
    }

    double averageTime = totalElapsedTime / numIterations;

    std::cout << "Array ordenado pelo Bubble Sort:" << std::endl;
    for (const auto &element : list2)
    {
        std::cout << element << " ";
    }
    std::cout << "\n"
              << std::endl;

    std::cout << "Tempo de execucao medio: " << std::fixed << std::setprecision(10) << averageTime << " segundos" << std::endl;

    return 0;
}
