#include <iostream>
#include <sstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <string>
#include <chrono>
#include <fstream>
#include <nlohmann/json.hpp>

void selectionSort(std::vector<std::double_t> &array)
{
    bool swapped;

    int arraySize = array.size();

    for (int i = 0; i < arraySize; i++)
    {
        swapped = false;
        int min = i;
        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            std::swap(array[i], array[min]);
            swapped = true;
        }

        if (!swapped)
            break;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 100.0);

    std::ifstream file1("../../data/data.json");
    if (!file1)
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }
    else
    {
        std::cout << "Arquivo encontrado com sucesso." << std::endl;
    }

    std::ifstream file2("../../data/text.json");
    if (!file2)
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }
    else
    {
        std::cout << "Arquivo encontrado com sucesso." << std::endl;
    }

    nlohmann::json jsonData1;
    nlohmann::json jsonData2;

    file1 >> jsonData1;
    file2 >> jsonData2;

    std::vector<std::string> wordsArray = jsonData1;
    std::vector<std::string> textArray = jsonData2;

    std::vector<double> list2(20000);
    for (auto &element : list2)
    {
        element = dis(gen);
    }

    std::cout << "Array inicial:" << std::endl;
    for (const auto &element : list2)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
    std::cout << "-----------------------------------------";
    std::cout << "-----------------------------------------"
              << std::endl;

    const int numIterations = 10;
    double totalElapsedTime = 0.0;

    for (int i = 0; i < numIterations; i++)
    {
        auto start = std::chrono::steady_clock::now();

        selectionSort(list2);

        auto end = std::chrono::steady_clock::now();
        double elapsedTime = std::chrono::duration<double>(end - start).count();
        totalElapsedTime += elapsedTime;
    }

    double averageTime = totalElapsedTime / numIterations;

    std::cout << "Array ordenado pelo SelectionSort Sort:" << std::endl;
    for (const auto &element : list2)
    {
        std::cout << element << " ";
    }
    std::cout << "\n"
              << std::endl;

    std::cout << "Tempo de execucao medio: " << std::fixed << std::setprecision(6) << averageTime << " segundos" << std::endl;

    return 0;
}
