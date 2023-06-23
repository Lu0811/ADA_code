#include <iostream>
#include <algorithm>

bool compareTasks(const int tasks[][2], int task1, int task2) {
    return tasks[task1][1] < tasks[task2][1];
}

void scheduleTasks(const int tasks[][2], int numTasks) {
    int* schedule = new int[numTasks];
    schedule[0] = 0;
    int scheduledCount = 1;

    for (int i = 1; i < numTasks; i++) {
        if (tasks[i][0] >= tasks[schedule[scheduledCount - 1]][1]) {
            schedule[scheduledCount] = i;
            scheduledCount++;
        }
    }

    std::cout << "Scheduled tasks:\n";
    for (int i = 0; i < scheduledCount; i++) {
        std::cout << "Start: " << tasks[schedule[i]][0] << ", End: " << tasks[schedule[i]][1] << std::endl;
    }

    delete[] schedule;
}

int main() {
    const int tasks[][2] = {
        {1, 3},
        {2, 5},
        {4, 7},
        {6, 9},
        {8, 10}
    };
    int numTasks = sizeof(tasks) / sizeof(tasks[0]);

    scheduleTasks(tasks, numTasks);

    return 0;
}
