#include <iostream>
#include <vector>
#include <cmath>
#include <string>


class PrimeNumbers {
public:
    PrimeNumbers(int maxLimit) {
        // Initialize the sieve for the given max limit
        sieveSize = maxLimit + 1;
        sieve = std::string(sieveSize, 'P'); // Assume all are primes initially
        sieve[0] = sieve[1] = 'C';           // 0 and 1 are not primes

        // Apply the Sieve of Eratosthenes
        for (int i = 2; i * i <= maxLimit; ++i) {
            if (sieve[i] == 'P') {
                for (int j = i * i; j <= maxLimit; j += i) {
                    sieve[j] = 'C'; // Mark multiples of i as composite
                }
            }
        }
    }

    // Get all primes in the range [start, end)
    std::vector<int> getPrimesInRange(int start, int end) const {
        std::vector<int> primes;
        for (int num = std::max(start, 2); num < end; ++num) {
            if (sieve[num] == 'P') {
                primes.push_back(num);
            }
        }
        return primes;
    }

    // Get the largest prime less than the given limit
    int getLargestPrimeLessThan(int limit) const {
        for (int num = limit - 1; num >= 2; --num) {
            if (sieve[num] == 'P') {
                return num;
            }
        }
        return -1; // Return -1 if no primes are found (shouldn't happen)
    }

private:
    int sieveSize;
    std::string sieve; // Holds 'P' for primes and 'C' for composites
};
