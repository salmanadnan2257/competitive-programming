// --------- Unforgivable Curse (Easy Version) ---------

#include <bits/stdc++.h>

using namespace std;

#define size_of_vector(v) static_cast<int>(v.size())
#define all_elements(v) v.begin(), v.end()
#define emplace_back_element emplace_back

void exhaustive_search(int length, int step, string initial_str, string target_str) {
    set<string> visited_states;
    queue<string> state_queue;
    state_queue.push(initial_str);
    visited_states.insert(initial_str);

    auto try_swap = [&](string& str, int idx1, int idx2) {
        if (idx1 >= 0 && idx1 < idx2 && idx2 < length) {
            swap(str[idx1], str[idx2]);
            if (!visited_states.count(str)) {
                visited_states.insert(str);
                state_queue.push(str);
            }
            swap(str[idx1], str[idx2]);
        }
    };

    while (!state_queue.empty()) {
        initial_str = state_queue.front();
        state_queue.pop();
        for (int i = 0; i < length; ++i) {
            try_swap(initial_str, i, i + step);
            try_swap(initial_str, i, i + step + 1);
            try_swap(initial_str, i - step, i);
            try_swap(initial_str, i - step - 1, i);
        }
    }
    cout << (visited_states.count(target_str) ? "Yes" : "No") << '\n';
}

void solve_problem() {
    int length, step;
    cin >> length >> step;
    string initial_str, target_str;
    cin >> initial_str >> target_str;

    if (length <= 5) {
        exhaustive_search(length, step, initial_str, target_str);
        return;
    }
    map<char, int> char_count;
    for (char c : initial_str) {
        char_count[c]++;
    }

    for (char c : target_str) {
        char_count[c]--;
    }

    bool is_possible = true;
    for (auto [character, count] : char_count) {
        is_possible &= (count == 0);
    }
    cout << (is_possible ? "Yes" : "No") << '\n';
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve_problem();
    }
}
