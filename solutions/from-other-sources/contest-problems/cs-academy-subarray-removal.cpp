// CS Academy - Subarray Removal - 2

#include <bits/stdc++.h>
using namespace std;

const long long NEG_INF = -400000000000000LL; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> ms_end(N);
    vector<long long> ms_overall_left(N);
    
    ms_end[0] = A[0];
    ms_overall_left[0] = A[0];

    for (int k = 1; k < N; ++k) {
        ms_end[k] = max(A[k], A[k] + ms_end[k-1]);
        ms_overall_left[k] = max(ms_overall_left[k-1], ms_end[k]);
    }

    vector<long long> ms_start(N);
    vector<long long> ms_overall_right(N);

    ms_start[N-1] = A[N-1];
    ms_overall_right[N-1] = A[N-1];

    for (int k = N - 2; k >= 0; --k) {
        ms_start[k] = max(A[k], A[k] + ms_start[k+1]);
        ms_overall_right[k] = max(ms_overall_right[k+1], ms_start[k]);
    }

    vector<long long> suff_max_start_val(N);
    suff_max_start_val[N-1] = ms_start[N-1];
    for (int k = N - 2; k >= 0; --k) {
        suff_max_start_val[k] = max(ms_start[k], suff_max_start_val[k+1]);
    }

    long long overall_max_sum = NEG_INF;

    for (int j = 0; j < N - 1; ++j) {
        overall_max_sum = max(overall_max_sum, ms_overall_right[j+1]);
    }

    for (int i = 1; i < N; ++i) {
        overall_max_sum = max(overall_max_sum, ms_overall_left[i-1]);
    }

    for (int x = 0; x < N - 2; ++x) {
        overall_max_sum = max(overall_max_sum, ms_end[x] + suff_max_start_val[x+2]);
    }
    
    cout << overall_max_sum << endl;

    return 0;
}