#include <iostream>
#include <string>

using namespace std;

class Task {
public:
    string desc;
    bool done;
};

Task* tasks = nullptr;
int taskCount = 0;

void add(const string& desc) {
    Task* newTasks = new Task[taskCount + 1];
    for (int i = 0; i < taskCount; ++i)
        newTasks[i] = tasks[i];
    newTasks[taskCount].desc = desc;
    newTasks[taskCount].done = false;
    delete[] tasks;
    tasks = newTasks;
    taskCount++;
}

void view() {
    cout << "Tasks:" << endl << endl;
    for (int i = 0; i < taskCount; ++i)
        cout << i + 1 << ". " << tasks[i].desc << " - " << (tasks[i].done ? "Completed" : "Pending") << endl;
    cout << endl;
}

void remove(int index) {
    if (index >= 0 && index < taskCount) {
        Task* newTasks = new Task[taskCount - 1];
        int idx = 0;
        for (int i = 0; i < taskCount; ++i)
            if (i != index)
                newTasks[idx++] = tasks[i];
        delete[] tasks;
        tasks = newTasks;
        taskCount--;
        cout << "Task deleted successfully." << endl;
    }
    else
        cout << "Invalid task index." << endl;
}

void mark(int index) {
    if (index >= 0 && index < taskCount) {
        tasks[index].done = true;
        cout << "Task marked as completed." << endl;
    }
    else
        cout << "Invalid task index." << endl;
}

int main() {
    for (;;) {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Mark Task as Completed" << endl;
        cout << "5. Exit" << endl << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string desc;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, desc);
            add(desc);
            cout << "Task added successfully." << endl;
            break;
        }
        case 2:
            view();
            break;
        case 3: {
            int index;
            cout << "Enter task number to delete: ";
            cin >> index;
            remove(index - 1);
            break;
        }
        case 4: {
            int index;
            cout << "Enter task number to mark as completed: ";
            cin >> index;
            mark(index - 1);
            break;
        }
        case 5:
            delete[] tasks;
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}
