#include <iostream>
using namespace std;





struct Person {
    string firstname;
    string lastname;
    string phone;
    string address;
    struct Person* next;
};





struct Person * addPerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address );
    /* Precondition:
     *  head: Is the head node of a linked list.
     *      Contains NULL if empty.
     *  _firstname: is the first name of the new person to be added
     *  _lastname: is the last name of the new person to be added
     *  _phone: is the phone number of the new person to be added
     *  _address: is the address of the new person to be added
     *  All provided arguments are assumed to be non-null.
     *
     * Postcondition:
     *  A new Person node is appended to the end of head linked list.
     *  The new person node is pointing to NULL as next.
     *
     * Return:
     *  Returns the head node of the linked list.
     */





int main() {
    struct Person *AddressBook = NULL;
    AddressBook = addPerson(AddressBook, "Bob", "Doe", "(415) 123-4567", "123 Fake St.");
    cout << AddressBook->firstname << endl;
    AddressBook = addPerson(AddressBook, "Bob", "Doe", "(415) 123-4567", "123 Fake St.");
    cout << AddressBook->next->lastname << endl;

    return 0;
}





struct Person * addPerson(struct Person *head,
        string _firstname,
        string _lastname,
        string _phone,
        string _address ) {
    if (head == NULL) {
        struct Person *person = new Person;
        person->firstname = _firstname;
        person->lastname = _lastname;
        person->phone = _phone;
        person->address = _address;
        person->next = NULL;
        return person;
    } else {
        struct Person *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new Person;
        curr = curr->next;
        curr->firstname = _firstname;
        curr->lastname = _lastname;
        curr->phone = _phone;
        curr->address = _address;
        curr->next = NULL;
        return head;
    }
}
