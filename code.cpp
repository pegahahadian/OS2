#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_PROCESSES = 5;
const int NUM_RESOURCES = 3;

bool isSafe(vector<int>& available, vector<vector<int>>& max_need, vector<vector<int>>& allocation, vector<bool>& finished) {
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        if (!finished[i]) {
            bool canExecute = true;
            for (int j = 0; j < NUM_RESOURCES; ++j) {
                if (max_need[i][j] - allocation[i][j] > available[j]) {
                    canExecute = false;
                    break;
                }
            }

            if (canExecute) {
                // Execute process i
                for (int j = 0; j < NUM_RESOURCES; ++j) {
                    available[j] += allocation[i][j];
                }

                finished[i] = true;

                // Recursively check for the next processes
                if (isSafe(available, max_need, allocation, finished)) {
                    return true;
                }

                // Backtrack
                finished[i] = false;
                for (int j = 0; j < NUM_RESOURCES; ++j) {
                    available[j] -= allocation[i][j];
                }
            }
        }
    }

    // No safe sequence found
    return false;
}

int main() {
    ifstream inputFile("input.txt");

    vector<vector<int>> allocation(NUM_PROCESSES, vector<int>(NUM_RESOURCES));
    vector<vector<int>> max_need(NUM_PROCESSES, vector<int>(NUM_RESOURCES));
    vector<int> available(NUM_RESOURCES);
    vector<bool> finished(NUM_PROCESSES, false);

    // Read input data from file
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        for (int j = 0; j < NUM_RESOURCES; ++j) {
            inputFile >> allocation[i][j];
        }
        for (int j = 0; j < NUM_RESOURCES; ++j) {
            inputFile >> max_need[i][j];
        }
        for (int j = 0; j < NUM_RESOURCES; ++j) {
            inputFile >> available[j];
        }
    }

    // Check if the system is in a safe state
    if (isSafe(available, max_need, allocation, finished)) {
        cout << "The system is in a safe state.\n";
        cout << "Safe Sequence: ";
        for (int i = 0; i < NUM_PROCESSES; ++i) {
            cout << "P" << find(finished.begin(), finished.end(), false) - finished.begin();
            finished[find(finished.begin(), finished.end(), false) - finished.begin()] = true;
            if (i != NUM_PROCESSES - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "The system is not in a safe state.\n";
    }

    inputFile.close();
    return 0;
}
