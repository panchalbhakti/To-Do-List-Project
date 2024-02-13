#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task{
	string description;
	bool completed;
	
	Task(string desc): description(desc), completed(false){}
};

void addTask(vector<Task>& todoList, const string& description){
	todoList.push_back(Task(description));
	cout << "Task added : "<< description <<endl;
}

void completeTask(vector<Task>& todoList, int index){
	if(index >= 0 && index < todoList.size()){
		todoList[index].completed = true;
		cout << "Task completed : "<< todoList[index].description << endl;
	}
	else{
		cout << "Invalid task index." <<endl;
	}
}

void displaytodoList(const vector<Task>& todoList){
	cout << "To-Do List : "<<endl;
	for(int i=0; i<todoList.size(); ++i){
		cout << "[" << (todoList[i].completed ? "X" : " ") << "]" << i+i << ". "<< todoList[i].description<<endl;
	}
}

int main(){
	vector<Task> todoList;
	
	int choice;
	do{
		cout << "\nMenu : \n";
		cout << "1. Add Task\n";
		cout << "2. Complete Task\n";
		cout << "3. Display To-Do List\n";
		cout << "4. Exit\n";
		cout << "enter your choice : ";
		cin >> choice;
		
		switch(choice){
			case 1: {
				string description;
				cout << "Enter task description";
				cin.ignore();
				getline(cin, description);
				addTask(todoList, description);
				break;
			}
			case 2 : {
				int index;
				cout << "Enter task index to mark as completed : ";
				cin >> index;
				completeTask(todoList, index - 1);
				break;
			}
			case 3:{
				displaytodoList(todoList);
				break;
		    }
		    case 4: {
		    	cout << "Existing..."<<endl;
				break;
			}
			default: 
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	while (choice != 4);
	return 0;
	}
