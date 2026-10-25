// --------- Counting Divisors ---------

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

// Optimized function to count the number of divisors
int countDivisors(ll n) {
    if (n == 1) return 1;  // Special case: 1 has only one divisor

    int totalDivisors = 1;
    int count = 0;

    // Count factor of 2
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    totalDivisors *= (count + 1);

    // Check odd numbers from 3 to sqrt(n)
    for (ll i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        totalDivisors *= (count + 1);
    }

    // If n is still greater than 1, it must be prime
    if (n > 1) {
        totalDivisors *= 2;
    }

    return totalDivisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        ll number;
        cin >> number;
        cout << countDivisors(number) << "\n";
    }

    return 0;
}
