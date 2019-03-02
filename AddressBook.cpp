#include <iostream>
using namespace std;

struct Person {
    string firstname;
    string lastname;
    string phone;
    string address;
    struct Person* next;
};

int main() {
    return 0;
}
