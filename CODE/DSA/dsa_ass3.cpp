#include<iostrem>
using namespace std;

struct User {

    string id;
    string dateOfBirth; 
    int numcomment;
    unordered_set<string> friends;

    User(string id, string dob, int comments) 
        : id(id), dateOfBirth(dob), numComments(comments) {}
};

class FriendGraph {

	unordered_map<string,user*> users;
    void addUser(string id, string dateOfBirth, int numComments) {
        if (users.find(id) == users.end()) {
            users[id] = new User(id, dateOfBirth, numComments);
        }

    }

    void addFriendship(string id1, string id2) {
        if (users.find(id1) != users.end() && users.find(id2) != users.end()) {
            users[id1]->friends.insert(id2);
            users[id2]->friend .insert(id1);
              
        }
    }


};






