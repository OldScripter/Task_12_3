#include <iostream>
#include <cassert>

float calculateIsoFactor(int* N, int floorCount, int N_reg)
{
    int N_sum = 0;
    for (int i = 0; i < floorCount; i++)
    {
        N_sum += N[i];
    }

    return N_sum * 100 / N_reg;
}

int main() {
    const int FLOORS_COUNT = 5;
    int N_reg;
    int N[FLOORS_COUNT];
    bool badNumberFound;
    do
    {
        badNumberFound = false;
        std::cout << "Enter the number of registered citizens: ";
        std::cin >> N_reg;

        if (N_reg <= 0)
        {
            std::cout << "Number should be greater than zero. Try again.\n";
            std::cout << "-----------Repeat the enter-------------\n\n";
            badNumberFound = true;
        }
        else
        {
            for (int i = 0; i < FLOORS_COUNT; i++)
            {
                std::cout << "Enter the number of citizens on the floor " << i + 1 << ": ";
                std::cin >> N[i];
                if (N[i] < 0)
                {
                    std::cout << "Number for the floor " << i + 1 << " is less than 0. Ni should be >= 0. Try again.\n";
                    std::cout << "-----------Repeat the enter-------------\n\n";
                    badNumberFound = true;
                    break;
                }
            }
        }

    } while (badNumberFound);

    std::cout << "--------------------------\n";
    std::cout << "Calculating the isolation factor.\n";
    std::cout << "Isolation factor is: " << calculateIsoFactor(N, FLOORS_COUNT, N_reg) << "%.\n";
    return 0;
}
