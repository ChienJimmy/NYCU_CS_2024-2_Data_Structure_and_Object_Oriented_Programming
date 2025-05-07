#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
using std::string;
constexpr auto npos = string::npos;

class Basic_task{
protected:
    string *name;
    string *category;
    bool *completed;
};

class Task : public Basic_task{
public:
// basic constructors//destructor

    // ordinary constructor
    Task(string* inputname, string* inputcategory, bool* inputcompleted){
        this->name = new string(*inputname);
        this->category = new string(*inputcategory);
        this->completed = new bool(*inputcompleted);
        
    }

    // default constructor with no argument
    Task(){
        this->name = new string("");
        this->category = new string("");
        this->completed = new bool(false);
    }

    // copy constructor
    Task(const Task& input){
        this->name = new string(*input.name);
        this->category = new string(*input.category);
        this->completed = new bool(*input.completed);
    }

    // assignment operator
    Task& operator=(const Task& oldtask){
        if (this != &oldtask) {
            // delete the old memory
            delete this->name;
            delete this->category;
            delete this->completed;
            // copy the new memory
            this->name = new string(*oldtask.name);
            this->category = new string(*oldtask.category);
            this->completed = new bool(*oldtask.completed);
        }
        return *this;
    }

    // destructor
    ~Task(){
        delete name;
        delete category;
        delete completed;
    }

// functions
    // function of showing the task
    void show(){
        if (*completed == 0){
            cout << "name: " << *name << ", category: " << *category << ", Completed: No" << "\n";
        }
        else{
            cout << "name: " << *name << ", category: " << *category << ", Completed: Yes" << "\n";
        }
    }

    // function of modifying the completed status
    bool setcompleted(){
        // if the task is completed, return false
        if (*completed == 1){
            return false;
        }
        delete completed;
        completed = new bool(true);
        return true;
    }

    // function of get the name
    string getname(){
        return *name;
    }

    // function of get the category
    string getcategory(){
        return *category;
    }

    // function of get the completed status
    int getcompleted(){
        return *completed;
    }
};

class Tasklist : public Task{
private:
    vector<Task*> *tasklist;

public:
// basic constructors
    // ordinary constructor
    Tasklist(int* inputmaxsize){
        int *size = new int((*inputmaxsize >= 1) ? *inputmaxsize : 1);
        tasklist = new vector<Task*>(*size);
    }

    // destructor
    ~Tasklist(){
        // delete all the tasks in the tasklist before deleting tasklist
        for (auto* it : *tasklist){
            delete it;
        }
        delete tasklist;
    }

// functions
    // add a task
    void Add(Task* input){
        // add the input task
        tasklist->push_back(input);
        cout << "Task " << tasklist->size() - 1 << " added. Task details: ";
        input->show();
    }

    // view all the tasks
    void View(){
        cout << "Task list:\n";
        int *index = new int(0);
        for (auto* it : *tasklist){
            if (it){
                cout << "Task " << *index << ":\t";
                it->show();
            }
            (*index)++;
        }
        cout << (*index) - 1 << " task(s) found.\n";
    }
    // view the specified tasks
    void View(string* name, string* category, int* completed_status){
        cout << "Task list:\n";
        int *index = new int(0);
        int *total = new int(0);
        for (auto* it : *tasklist) {
            if (it) {
                // check if name, category and completed status follows the filter or left blank
                if ((*name == "" || it->getname() == *name) && (*category == "" || it->getcategory() == *category) && (*completed_status == 2 || it->getcompleted() == *completed_status)) {
                    cout << "Task " << *index << ":\t";
                    it->show();
                    (*total)++;
                }
            }
            (*index)++;
        }
        if (*total == 0){
            cout << "No task matches the filter.\n";
        }
        else{
            cout << *total << " task(s) found with the filter.\n";
        }
    }

    // edit a task
    void Edit(int* index, string* name, string* category, int* completed_int){
        string *targetname = new string();
        string *targetcategory = new string();
        bool *targetcompleted = new bool();
        // check if the name, category and completed status are left blank or should be modified
        if (*name == ""){
            *targetname = tasklist->at(*index)->getname();
            cout << "Automatically reserve the value of name.\n";
        }
        else{
            *targetname = *name;
        }
        if (*category == ""){
            *targetcategory = tasklist->at(*index)->getcategory();
            cout << "Automatically reserve the value of category.\n";
        }
        else{
            *targetcategory = *category;
        }
        if (*completed_int == 2){
            *targetcompleted = tasklist->at(*index)->getcompleted();
            cout << "Automatically reserve the value of completed status.\n";
        }
        else{
            *targetcompleted = (*completed_int == 0)?false:true;
        }
        Task *target = new Task(&(*targetname), &(*targetcategory), &(*targetcompleted));
        cout << "Task " << *index << " edited. Task details: ";
        target->show();
        delete tasklist->at(*index);
        tasklist->at(*index) = target;
    }

    // delete a task
    void Delete(int* index){
        if (*index < 0 || *index >= tasklist->size()) {
            cout << "Invalid index.\n";
            return;
        }
        cout << "Task " << *index << " deleted.\n";
        delete tasklist->at(*index);
        tasklist->erase(tasklist->begin() + *index);
    }

    // mark a task as completed
    void Finish(int* inputindex){
        if (*inputindex < 0 || *inputindex >= tasklist->size()){
            cout << "Invalid index.\n";
            return;
        }
        bool *completed = new bool();
        *completed = tasklist->at(*inputindex)->setcompleted();
        if (*completed == false){
            cout << "Task " << *inputindex << " is already completed.\n";
        }
        else{
            cout << "Task " << *inputindex << " completed.\n";
        }
    }
    
    // function of getting the size of tasklist
    int getsize(){
        return tasklist->size();
    }
};

int main(){
    // create a tasklist, default size is 0
    Tasklist *tasklist = new Tasklist(new int(0));
    while (true){
        string *commandname = new string("");
        cin >> *commandname;
    
        // exit
        if (*commandname == "exit"){
            break;
        }
        
        // add
        if (*commandname == "add"){
            string *name = new string(""), *category = new string("");
            int *completed_int = new int();
            bool *completed = new bool();
            string *input = new string("");
            
            // you can use the following methods to enter the information
            // 1. add -na [name] -ca [category] -co [completed] (you can messed up the order of those flags)
            // 2. add [name] [category] [completed]
            // 3. add [name] [category]
            // 4. add [name] 
            getline(cin, *input);
            // dealing with flags
            if (input->find("-na") != npos || input->find("-ca") != npos || input->find("-co") != npos){
                size_t *pos = new size_t();
                // find the -na flag
                if ((*pos = input->find("-na")) != npos){
                    size_t *end = new size_t(); 
                    *end = input->find(" -", (*pos) + 1);
                    *name = (*input).substr((*pos) + 4, *end - ((*pos) + 4));
                }
                // find the -ca flag
                if ((*pos = input->find("-ca")) != npos){
                    size_t *end = new size_t(); 
                    *end = input->find(" -", (*pos) + 1);
                    *category = (*input).substr((*pos) + 4, *end - ((*pos) + 4));
                }
                // find the -co flag
                if ((*pos = input->find("-co")) != npos){
                    size_t *end = new size_t();
                    *end = input->find(" -", (*pos) + 1);
                    string *completed_str = new string("");
                    *completed_str = input->substr((*pos) + 4, *end - ((*pos) + 4));
                    *completed_int = stoi(*completed_str);
                }
            }
            // no flags are found, using the default declaration
            else{
                // split input by spaces
                istringstream *iss = new istringstream(*input);
                *iss >> *name;
                if (!((*iss) >> (*category))){
                    // default category
                    *category = "";
                    cout << "Automatically set category to blank.\n";
                }
                if (!((*iss) >> (*completed_int))){
                    // default completed status
                    *completed_int = 2;
                }
            }
            if (*completed_int != 0 && *completed_int != 1){
                cout << "Automatically set complete status to completed(1).\n";
            }
            *completed = (*completed_int == 0)?false:true;
            Task* newtask = new Task(&(*name), &(*category), &(*completed));
            tasklist->Add(newtask);
        }

        // view
        else if (*commandname == "view"){
            string *buffer = new string("");
            getline(cin, *buffer);
            if (*buffer != ""){
                if (buffer->find("-na") != npos || buffer->find("-ca") != npos || buffer->find("-co") != npos){
                    size_t *pos = new size_t();
                    string *name = new string(""), *category = new string("");
                    int *completed_status = new int();
                    // find the -na flag
                    if (((*pos) = buffer->find("-na")) != npos){
                        size_t *end = new size_t();
                        *end = buffer->find(" -", (*pos) + 1);
                        *name = buffer->substr((*pos) + 4, (*end) - ((*pos) + 4));
                    }
                    else {
                        *name = "";
                    }
                    // find the -ca flag
                    if (((*pos) = buffer->find("-ca")) != npos){
                        size_t *end = new size_t();
                        *end = buffer->find(" -", (*pos) + 1);
                        *category = buffer->substr((*pos) + 4, (*end) - ((*pos) + 4));
                    }
                    else {
                        *category = "";
                    }
                    // find the -co flag
                    if (((*pos) = buffer->find("-co")) != npos){
                        size_t *end = new size_t();
                        *end = buffer->find(" -", (*pos) + 1);
                        string *completed_str = new string("");
                        *completed_str = buffer->substr((*pos) + 4, (*end) - ((*pos) + 4));
                        *completed_status = stoi(*completed_str);
                    }
                    else{
                        *completed_status = 2;
                    }
                    // filter the tasklist
                    tasklist->View(name, category, completed_status);
                }
            }
            else{
                // view all the tasks
                tasklist->View();
            }
        }

        // edit
        else if (*commandname == "edit"){
            int *taskindex = new int();
            string *name = new string(), *category = new string();
            int *completed_int = new int();
            bool *completed = new bool();
            string *input = new string();
            // task index is necessary
            cin >> *taskindex;
            if (*taskindex < 0 || *taskindex >= tasklist->getsize()){
                cout << "Invalid index.\n";
                continue;
            }

            // you can use the following methods to enter the information
            // 1. edit [index] -na [name] -ca [category] -co [completed] (you can messed up the order of those flags)
            // 2. edit [index] [name] [category] [completed]
            // 3. edit [index] [name] [category]
            // 4. edit [index] [name]
            getline(cin, *input);
            // dealing with flags
            if (input->find("-na") != npos || input->find("-ca") != npos || input->find("-co") != npos){
                size_t *pos = new size_t();
                // find the -na flag
                if (((*pos) = input->find("-na")) != npos){
                    size_t *end = new size_t;
                    *end = input->find(" -", (*pos) + 1);
                    *name = input->substr((*pos) + 4, (*end) - ((*pos) + 4));
                }
                // find the -ca flag
                if ((*pos = input->find("-ca")) != npos){
                    size_t *end = new size_t(); 
                    *end = input->find(" -", (*pos) + 1);
                    *category = (*input).substr((*pos) + 4, *end - ((*pos) + 4));
                }
                // find the -co flag
                if ((*pos = input->find("-co")) != npos){
                    size_t *end = new size_t();
                    *end = input->find(" -", (*pos) + 1);
                    string *completed_str = new string("");
                    *completed_str = input->substr((*pos) + 4, *end - ((*pos) + 4));
                    *completed_int = stoi(*completed_str);
                }
            }
            // no flags are found, using the default declaration
            else{
                // split input by spaces
                istringstream *iss = new istringstream(*input);
                *iss >> *name;
                if (!((*iss) >> *category)){
                    // default category
                    *category = "";
                }
                if (!((*iss) >> *completed_int)){
                    // default completed status
                    *completed_int = 2;
                }
            }
            tasklist->Edit(&(*taskindex), &(*name), &(*category), &(*completed_int));
        }

        // delete
        else if (*commandname == "delete"){
            int *index = new int();
            cin >> *index;
            if (*index < 0 || *index >= tasklist->getsize()){
                cout << "Invalid index.\n";
                continue;
            }
            tasklist->Delete(&(*index));
        }

        // finish
        else if (*commandname == "finish"){
            int *index = new int();
            cin >> *index;
            if (*index < 0 || *index >= tasklist->getsize()){
                cout << "Invalid index.\n";
                continue;
            }
            tasklist->Finish(&(*index));
        }
        
        // Other commands: invalid
        else{
            cout << "Invalid command.\nYour command is: " << *commandname << "\n----------------Simple command manual:----------------\n";
            cout << "add [name] [category] [completed]\nview\nedit [index] [name] [category] [completed]\ndelete [index]\nfinish [index]\nexit\nPlease enter your command again.\n";
            // clear the buffer to prevent an infinite loop
            cin.clear();
            continue;
        }
    }
}