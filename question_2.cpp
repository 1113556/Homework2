//蔡宗修



#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Define a structure to hold tasks and their priorities
struct Task {
    string name;
    int priority;

    // Overload the comparison operator for max heap
    bool operator<(const Task &other) const {
        return priority < other.priority;
    }
};

int main() {
    int N;
    cin >> N; // Read number of operations

    // Priority queue to serve as a max heap
    priority_queue<Task> taskQueue;

    // Process operations
    for (int i = 0; i < N; ++i) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            string taskName;
            int priority;
            cin >> taskName >> priority;
            taskQueue.push({taskName, priority});
        } else if (operation == "GET") {
            if (!taskQueue.empty()) {
                Task highestPriorityTask = taskQueue.top();
                taskQueue.pop();
                cout << highestPriorityTask.name << endl; // Print the task with highest priority
            } else {
                cout << "No tasks available" << endl;
            }
        }
    }

    // Display remaining tasks
    vector<Task> remainingTasks;
    while (!taskQueue.empty()) {
        remainingTasks.push_back(taskQueue.top());
        taskQueue.pop();
    }

    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].name << "', " << remainingTasks[i].priority << ")";
        if (i != remainingTasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

