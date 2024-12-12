#include "PrimeNumbers.h"

int main()
{
    PrimeNumbers primeNumbers(100000);

    std::vector<int> primes = primeNumbers.getPrimesInRange(1, 200);
    std::cout << "Prime numbers between 1 and 200:\n";
    for(int prime : primes){
        std::cout << prime << " ";
    }
    std::cout << "\n";

    int largestPrime = primeNumbers.getLargestPrimeLessThan(100000);
    std::cout << "Largest prime less than 100,000: " << largestPrime << "\n";
    return 0;
}