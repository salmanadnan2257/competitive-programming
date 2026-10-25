// --------- Badge ---------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    
    // Reading the graph where each student i points to student p[i]
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; // Adjusting for 0-based indexing
    }

    // To store the result for each student starting
    for (int start = 0; start < n; start++) {
        vector<bool> visited(n, false); // Reset visited for each start
        int current = start;
        
        // Traverse until we hit the first student twice
        while (!visited[current]) {
            visited[current] = true;
            current = p[current];
        }
        
        // Print the student who gets the second hole (1-based indexing)
        cout << current + 1 << " ";
    }

    cout << endl;
    return 0;
}