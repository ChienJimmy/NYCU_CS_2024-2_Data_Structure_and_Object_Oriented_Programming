#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


class Comment {
    private:
        string id;
        string content;
    public:
        Comment(string id_, string content_): id(id_), content(content_) {}
    
        void print_comment(){
            // TODO
            cout << "] " << id << ": " << content << "\n";
        }
    
        ~Comment(){
            cout << "Comment of " << this->content << " from id " << this->id << " is deleted." << endl;
        }
};

void reply(vector<Comment*> &Replies, string id, string content) {
    // TODO
    Comment* new_comment = new Comment(id, content);
    Replies.push_back(new_comment);
}

void view_comment(vector<Comment*> &Replies, string indexes){
    stringstream String_stream(indexes);
    string token;
    int index;

    while (getline(String_stream, token, ',')) {
        index = stoi(token);
        // TODO
        if (index < 0 || index >= Replies.size()) {
            cout << "Index " << index << " is out of bounds in replies.\n";
        }
        else {
            int i = 0;
            for (auto reply : Replies) {
                if (i == index) {
                    cout << "[" << index;
                    reply->print_comment();
                }
                i++;
            }
        }
        
    }
}

void delete_comment(vector<Comment*> &Replies, int index){
    // TODO
    if (index < 0 || index >= Replies.size()) {
        cout << "Index " << index << " is out of bounds in replies.\n";
    }
    else {
        int i = 0;
        for (auto reply : Replies) {
            if (i == index) {
                delete reply;
                Replies.erase(Replies.begin() + i);
            }
            i++;
        }
    }
}

void delete_all_comment(vector<Comment*> &Replies){
    // TODO
    for (auto reply : Replies) {
        delete reply;
    }
    
}

int main(){
    vector <Comment*> Replies;
    string command, indexes, id, content;
    int index;
    while (true) {
        cin >> command;
        if (command == "reply") {
            cin >> id >> content;
            reply(Replies, id, content);
        } else if (command == "delete") {
            cin >> index;
            delete_comment(Replies, index);
        } else if (command == "print") {
            cin >> indexes;
            view_comment(Replies, indexes);
        } else if (command == "exit") {
            cout << "Deleting all comments..." << endl;
            delete_all_comment(Replies);
            break;
        }
    }
    return 0;
}