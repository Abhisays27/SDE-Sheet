#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        vector<bool> isPrime(n+1, true);

        // 0 and 1 are not prime numbers
        isPrime[0] = false;
        isPrime[1] = false;

        // Sieve of Eratosthenes algorithm
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) { // Corrected: access the element using square brackets
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false; // Corrected: should be isPrime[j], not isPrime[i]
                }
            }
        }

        // Count the prime numbers
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) cnt++;
        }

        return cnt;
    }
};
