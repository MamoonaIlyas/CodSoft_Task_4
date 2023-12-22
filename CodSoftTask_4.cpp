// CODSOFT TASK 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Todo {
public:
    int id;
    string task;
    bool completed;

    Todo(int _id, const string& _task) : id(_id), task(_task), completed(false) {}

    void print() const {
        cout << "\n\tID: " << id;
        cout << "\n\tTask: " << task;
        cout << "\n\tStatus: " << (completed ? "Completed" : "Incomplete") << endl;
    }
};

class TodoList {
private:
    vector<Todo> todos;
    int nextId;

public:
    TodoList() : nextId(1) {}

    void addTask(const string& task) {
        todos.push_back(Todo(nextId++, task));
        cout << "\n\t*******Task added successfully*******" << endl;
    }

    void viewTasks() const {
        cout << "\n\t*******Your current Tasks in the list********";
        for (const auto& todo : todos) {
            todo.print();
        }
    }

    void markTaskAsCompleted(int taskId) {
        for (auto& todo : todos) {
            if (todo.id == taskId) {
                todo.completed = true;
                cout << "\n\t*******Task marked as completed*******" << endl;
                return;
            }
        }
        cout << "\n\t*******Task not found*******" << endl;
    }

    void removeTask(int taskId) {
        auto it = remove_if(todos.begin(), todos.end(), [taskId](const Todo& todo) {
            return todo.id == taskId;
            });

        if (it != todos.end()) {
            todos.erase(it, todos.end());
            cout << "\n\t*******Task removed successfully*******" << endl;
        }
        else {
            cout << "\n\t*******Task not found*******" << endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        cout << "\t\t*******CODSOFT COMPANY TO-DO LIST*******"<<endl;
        cout << "\n\t1. Add Task";
        cout << "\n\t2. View Tasks";
        cout << "\n\t3. Mark Task as Completed";
        cout << "\n\t4. Remove Task";
        cout << "\n\t5. Exit\n";

        int choice;
        cout << "\n\tEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string task;
            cout << "\n\tEnter new task: ";
            cin.ignore();
            cin >> task;
            todoList.addTask(task);
            system("pause");
            system("cls");
            break;
        }
        case 2:
            todoList.viewTasks();
            system("pause");
            system("cls");
            break;
        case 3: {
            int taskId;
            cout << "\n\tEnter task ID to mark as completed: ";
            cin >> taskId;
            todoList.markTaskAsCompleted(taskId);
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int taskId;
            cout << "\n\tEnter task ID to remove: ";
            cin >> taskId;
            todoList.removeTask(taskId);
            system("pause");
            system("cls");
            break;
        }
        case 5:
       
            cout << "\n\tExiting the TODO List application" << endl;
            system("pause");
            system("cls");
            return 0;
      
        default:
            cout << "\n\tInvalid choice. Please enter a valid option." << endl;
        }
    }
    
    return 0;
}