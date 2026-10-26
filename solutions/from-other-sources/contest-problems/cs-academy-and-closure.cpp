// CS Academy - AND Closure - 2

#include <bits/stdc++.h>
using namespace std;

// Assuming similar macros or direct for loops
// #define rep(i,a,b) for (long long i = a; i < b; ++i)
// #define per(i,a,b) for (long long i = a; i >= b; --i)

void solve_with_OR() {
    const int MAX_VAL = 1000000; // Max possible value in input
    int MAX_BITS = 0;
    if (MAX_VAL > 0) {
        MAX_BITS = std::floor(std::log2(MAX_VAL)) + 1; // 20 for 10^6
    }
    
    // Ensure MAX_BITS is at least 1 even for MAX_VAL = 0
    if (MAX_BITS == 0 && MAX_VAL > 0) MAX_BITS = 1;
    if (MAX_BITS < 1) MAX_BITS = 1; // Minimum for 0 to 1

    const int ALL_ONES_MASK = (1 << MAX_BITS) - 1; // e.g., 2^20 - 1

    std::vector<int> dp(ALL_ONES_MASK + 1, 0); // Initialize with 0

    int N;
    std::cin >> N;

    // Use a boolean array to mark input numbers directly
    std::vector<bool> is_input_num(ALL_ONES_MASK + 1, false);
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        is_input_num[x] = true;
    }

    // Initialize dp states based on input numbers
    // dp[mask] = OR { (~x) & ALL_ONES_MASK | for all x in input s.t. (x & mask) == mask }
    for (int mask = 0; mask <= ALL_ONES_MASK; ++mask) {
        if (is_input_num[mask]) {
            dp[mask] = (~mask) & ALL_ONES_MASK;
        }
    }

    // DP Transitions (SOS DP for supermasks with OR)
    // Iterate through each bit position
    for (int b = 0; b < MAX_BITS; ++b) {
        // Iterate through masks from largest to smallest
        // This order is crucial for propagating from supermask to submask
        for (int mask = ALL_ONES_MASK; mask >= 0; --mask) {
            if ((mask >> b) & 1) { // If bit 'b' is set in 'mask'
                // Propagate information from 'mask' to its submask (mask with bit 'b' unset)
                // The submask 'mask ^ (1 << b)' will receive OR'd info from 'mask'
                dp[mask ^ (1 << b)] |= dp[mask];
            }
        }
    }

    int distinct_results_count = 0;
    // The problem states the empty subset yields 0.
    // It's safer to add 0 to a set and then add other valid results.
    std::set<int> results_set;
    results_set.insert(0); // Account for empty subset

    // Check for valid results
    for (int mask = 0; mask <= ALL_ONES_MASK; ++mask) {
        if (dp[mask] == ((~mask) & ALL_ONES_MASK)) {
            results_set.insert(mask);
        }
    }

    std::cout << results_set.size() - 1 << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve_with_OR();
    return 0;
}