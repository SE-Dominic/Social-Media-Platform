#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Post {
private:
    string title;
    string post_description;
    vector<string> comments;
    unsigned likes = 0;
    //add image to gui after complete
public:
    Post();
    Post(string t, string p_description);
};

class Account {
private:
    string username;
    string password;
    string occupation;
    string description;
    vector<Account>followers;
    vector<Account>following;
    stack<Account> requests;
    vector<Post> posts;
public:
    Account() {
        this->username = "N/A";
        this->password = "N/A";
        this->occupation = "N/A";
        this->description = "N/A";
        this->followers = {};
        this->following = {};
        this->requests = {};
    }
    Account(string un, string pw, string occ, string des);

    string getUsername() {
        return this->username;
    }
    string getPassword() {
        return this->password;
    }
    string getOccupation() {
        return this->occupation;
    }
    string getDescription() {
        return this->description;
    }
    void setUsername(string username_) {
        this->username = username_;
    } 
    void setPassword(string password_) {
        this->password = password_;
    }
    void setOccupation(string occupation_) {
        this->occupation = occupation_;
    }
    void setDescription(string description_) {
        this->description = description_;
    }

    void printAccountInfo();
    void addFollower(Account& account_follower);
    void removeFollower(string key); //search by username
    void printFollowerList();

    void addToFollowing(Account& account_followed);
    void removeFromFollowing(string account_username);
    void printFollowing();

    void addPost(string post_title, string post_description);
    void removePost(int idx);
    void printAllPosts();
};
void Account::addFollower(Account& account_follower) {
    this->followers.push_back(account_follower);
}
 

//search by username
void Account::removeFollower(string key) {
    for (int i = 0; i < this->followers.size(); i++) {
        if (this->followers.at(i).username == key) {
            followers.erase(followers.begin() + i); //remove elements from vector
        }
    }
}
void Account::printFollowerList() {
    for (int i = 0; i < followers.size(); i++) {
        cout << i + 1 << ". " << endl << this->followers.at(i).username << endl;
    }
    for (int a = 0; a < 20; a++) {
        cout << "-";
    }
    cout << endl;
}

void Account::addToFollowing(Account& account_followed) {
    this->following.push_back(account_followed);
}
void Account::removeFromFollowing(string account_username) {
    for (int i = 0; i < this->following.size(); i++) {
        if (this->following.at(i).username == account_username) {
            this->following.erase(following.begin() + i);
        }
    }
}
void Account::printFollowing() {
    for (int i = 0; i < this->following.size(); i++) {
        cout << this->following.at(i).username << endl;
    }
}
void Account::printAccountInfo() {
    cout << "Username: " << this->username << endl;
    cout << "Password: " << this->password << endl;
    cout << "Occupation: " << this->occupation << endl;
    cout << "Description: \n" << this->description << endl;
    for (int z = 0; z < 15; z++) {
        cout << " - "; 
    }
    cout << endl;
}
/*

    void addPost(string post_title, string post_description);
    void removePost(int idx);
    void printAllPosts();
*/
#endif
