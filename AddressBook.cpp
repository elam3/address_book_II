/**
 *  Edison Lam, CS110B, Professor Deepa Mahalingam
 *  Address Book II
 *
 *  Implement the Address Book using linked lists.
 *  
 * The person struct is dynamically allocated just like we do for nodes in the
 * linked list material we covered in class. In this assignment user must be
 * able to do the following operations :
 *  Add a person in the address book
 *  Update a person in the address book
 *  Delete a person in the address book
 *  Search for a person in the address book
 */
#include <cassert> //assert
#include <cstdlib> //srand, rand
#include <ctime> //time
#include <iomanip> //setw
#include <string>
#include <iostream>
using namespace std;
#include <limits> //numeric_limits<int>::max()





struct Person {
    string firstname;
    string lastname;
    string phone;
    string address;
    struct Person* next;
};





void displayMenu();
    /**
     * Postcondition: a textual representation of the Menu screen is
     *  displayed on stdout.
     */





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





struct Person * addPerson(struct Person *head, struct Person *source);
    /**
     * Precondition: head is a Person LinkedList,
     *  and source is a Person node to be added to the end of head.
     * Postcondition: source is added to the end of head.
     * Returns: a pointer to the head Person node of the provided linkedlist
     */





void updatePerson(struct Person *head, struct Person *target, struct Person *other);
    /**
     * Precondition:
     *  - head is the first node of a Person linkedlist,
     *  - target is the a matching record to search for in head,
     *  - and other contains the new data to be inserted to the original
     *  entry in the linked list. Empty strings in other will be ignored.
     * Postcondition: the matching person to target within the linkedlist
     *  trailing head will be updated with information provided by other.
     */





struct Person * deletePerson(struct Person *head, string query);
    /**
     * Precondition: head is a Person linkedlist, and query is a string
     *  containing search terms to identify a Person object.
     * Postcondition: the first Person object with a match on query will be
     *  removed from the linkedlist.
     * Return: the head node of the linkedlist
     */





struct Person* searchPerson(struct Person *head, string query);
    /**
     * Precondition: head is a pointer to a Person LinkedList,
     *  and query is a string containing search terms to identify a Person object.
     * Return: a Person linkedlist of Person objects that contain matches with the query string,
     *  if there are no matches, a Person pointer pointing to null is returned.
     */





int compare(struct Person *src, struct Person *other);
    /**
     * Precondition: src and other are well-define Person objects
     * Postcondition: src and other are compared by lastname, firstname, phone, then address.
     * Return: a negative integer if src is smaller than other,
     *  a positive integer if greater,
     *  or a 0 if they are equal.
     */





struct Person * sort(struct Person *head);
    /**
     * Precondition: head is a Person linkedlist
     * Postcondition: the linkedlist will be sorted in ascending order based on lastname, firstname, phone, then address.
     * Return: returns the head node of the sorted linkedlist
     */





string toString(struct Person *person);
    /**
     * Preconditon: person is null, or properly initialized.
     * Return: an empty string if person is NULL,
     *  otherwise return a string representation of a Person object.
     */





void printAddressBook(struct Person *head, const string title);
    /**
     * Precondition: head is NULL, or a linkedlist of Person objects.
     * Postcondition: print a textual representation of the address book to stdout.
     */





struct Person* destroyPersonLinkedList(struct Person *head);
    /**
     * Precondition: head is a pointer to a linkedlist of Person objects
     * Postcondition: all Person nodes of the linkedlist AddressBook will be deallocated from the heap.
     * Returns: the head node, which should be a NULL.
     */





string getRandFirstName();
    /**
     * Helper function to randomly generate a first name.
     * Return: a randomly chosen first name from a list of 50.
     */





string getRandLastName();
    /**
     * Helper function to randomly generate a last name.
     * Return: a randomly chosen last name from a list of 50.
     */





string getRandPhone();
    /**
     * Helper function to randomly generate a phone number.
     * Return: a random string containing a phone number with the
     *  format "(###) ###-####".
     */





string getRandAddress();
    /**
     * Helper function to randomly generate a street address.
     * Return: a randomly chosen street address from a list of 50.
     */





struct Person * addPerson(struct Person *head, string _firstname, string _lastname, string _phone, string _address ) {
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





struct Person * addPerson(struct Person *head, struct Person *source) {
    return addPerson(head, source->firstname, source->lastname, source->phone, source->address);
}





string toString(struct Person *person) {
    return ( (person == NULL) ? "" :
            person->lastname + ", "
            + person->firstname + ". "
            + person->phone + ". "
            + person->address + "."
        );
}





void printAddressBook(struct Person *head, const string title) {
    cout << "==============================================\n"
        << "\t\t" << title << "\n"
        << "==============================================\n";
    if (head == NULL) 
        cout << "\t(Empty)\n";
    else {
        struct Person *current = head;
        int index = 0;
        while (current != NULL) {
            cout << setw(4) << ++index << ": "
                << toString(current) << endl;
            current = current->next;
        }
    }
    cout << "==============================================\n"
        << endl;
}





void updatePerson(struct Person *head, struct Person *target, struct Person *other) {
    struct Person *current = head;
    while (current != NULL) {
        if (compare(current, target) == 0) {
            if (other->firstname != "")
                current->firstname = other->firstname;
            if (other->lastname != "")
                current->lastname = other->lastname;
            if (other->phone != "")
                current->phone = other->phone;
            if (other->address != "")
                current->address = other->address;
        }
        current = current->next;
    }
}





struct Person * deletePerson(struct Person *head, string query) {
    if (head != NULL) {
        string person_str = toString(head);
        if (person_str.find(query) != string::npos) {
            head = head->next;
        } else {
            struct Person *current = head;
            while (current->next != NULL) {
                person_str = toString(current->next);
                if (person_str.find(query) != string::npos) {
                    current->next = current->next->next;
                    break;
                }
                current = current->next;
            }
        }
    }
    return head;
}





struct Person* searchPerson(struct Person *head, string query) {
    struct Person *results = NULL;
    if (head != NULL && query.length() != 0) {
        struct Person *current = head;
        while (current != NULL) {
            string person_str = toString(current);
            if (person_str.find(query) != string::npos)
                results = addPerson(results, current);
            current = current->next;
        }
        return results;
    }
    return results;
}





int compare(struct Person *src, struct Person *other) {
    //Primary Sort: By Last Name
    if (src->lastname < other->lastname)
        return -1;
    else if (src->lastname > other->lastname)
        return 1;
    else {
        //assert (src->lastname == other->lastname);
        //Secondary Sort: By First Name
        if (src->firstname < other->firstname)
            return -1;
        else if (src->firstname > other->firstname)
            return 1;
        else {
            //assert (src->firstname == other->firstname);
            //Tertiary Sort: By Phone Number
            if (src->phone < other->phone)
                return -1;
            else if (src->phone > other->phone)
                return 1;
            else {
                //assert (src->phone == other->phone);
                //Quarternary Sort: By Address
                if (src->address < other->address)
                    return -1;
                else if (src->address > other->address)
                    return 1;
                else {
                    //assert (src->address == other->address);
                    return 0;
                }
            } 
        }
    }
}





struct Person * sort(struct Person *head) {
    if (head == NULL || head->next == NULL)
        return head; //Ignore empty list, or singletons.
    else {
        //There are at least 2 nodes.
        struct Person *current = head,
                      *next,
                      *prev;
        int len = 0;
        while (current != NULL) {
            len++;
            current = current->next;
        }
        //Bubble Sort
        for (int i = 0; i < len; i++) {
            prev = head;
            current = head->next;
            next = head->next->next;
            //If the first two nodes need to swap, head needs to be updated.
            if (compare(prev, current) > 0) {
                head = current;
                current->next = prev;
                prev->next = next;
                //Re-align the pointers
                prev = head;
                current = head->next;
                next = head->next->next;
            }
            while (next != NULL) {
                if (compare(current, next) > 0) {
                    struct Person *tmp = next->next;
                    prev->next = next;
                    next->next = current;
                    current->next = tmp;
                    //Re-aligni pointers
                    current = prev->next;
                    next = prev->next->next;
                }
                prev = prev->next;
                current = current->next;
                next = next->next;
            }
        }
    }
    return head;
}





struct Person* destroyPersonLinkedList(struct Person *head) {
    if (head != NULL) {
        struct Person *current = head;
        while (head != NULL) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    return head;
}





string getRandFirstName() {
    int randomIndex = rand()%50;
    string firstNames[50] = {
        "Lakenya",
        "Anita",
        "Sherita",
        "Ezra",
        "Margeret",
        "Rosena",
        "Meridith",
        "Taren",
        "Velma",
        "Audra",
        "Shara",
        "Madison",
        "Bonny",
        "Helen",
        "Farah",
        "Danita",
        "Noel",
        "Marisha",
        "Tatum",
        "Catrice",
        "Laree",
        "Sanjuana",
        "Fidel",
        "Sang",
        "Teressa",
        "Maris",
        "Breanne",
        "Lady",
        "Elia",
        "Kelle",
        "Brandie",
        "Christy",
        "Kathlyn",
        "Fiona",
        "Eula",
        "Magnolia",
        "Jerrie",
        "Luci",
        "Pearline",
        "Giuseppina",
        "Michal",
        "Chase",
        "Jamie",
        "Rozella",
        "Arlinda",
        "Karena",
        "Jeanetta",
        "Aurelio",
        "Tonda",
        "Crista"
    };
    return firstNames[randomIndex];
}





string getRandLastName() {
    int randomIndex = rand()%50;
    string lastNames[50] = {
        "English",
        "Hall",
        "Levine",
        "Bright",
        "Mcdaniel",
        "Nash",
        "Day",
        "Bullock",
        "Robles",
        "Norman",
        "Tate",
        "Byrd",
        "Chavez",
        "Graham",
        "Donovan",
        "Holmes",
        "Fisher",
        "Briggs",
        "Ware",
        "Clark",
        "Williams",
        "Fleming",
        "Charles",
        "Myers",
        "Baldwin",
        "Doyle",
        "Mcclain",
        "Orr",
        "Floyd",
        "Whitehead",
        "Melendez",
        "Callahan",
        "Mathis",
        "Randall",
        "Collier",
        "Valentine",
        "Friedman",
        "Jacobs",
        "Castaneda",
        "Howe",
        "Gallegos",
        "Reid",
        "Riley",
        "Washington",
        "Hendrix",
        "Mcmahon",
        "Pollard",
        "Gregory",
        "Goodwin",
        "Everett"
    };
    return lastNames[randomIndex];
}





string getRandPhone() {
    return "(" + to_string(rand()%900+100) + ") " + to_string(rand()%900+100) + "-" + to_string(rand()%10000+1000);
}





string getRandAddress() {
    int randomIndex = rand()%50;
    string address[50] = {
        "8684 Olive St. Floral Park, NY 11001",
        "28 Creek Ave. Milton, MA 02186",
        "773 Westminster St. Corona, NY 11368",
        "167 S. Andover Ave. Youngstown, OH 44512",
        "7658 North Hillcrest Lane everly, MA 01915",
        "96 Glenwood Ave. Norwalk, CT 06851",
        "9508 Kingston Drive evern, MD 21144",
        "552 Sunbeam Rd. Parkville, MD 21234",
        "5 Livingston Street est New York, NJ 07093",
        "6 High Ridge St. Greer, SC 29650",
        "868 W. Surrey Ave. Horn Lake, MS 38637",
        "999 Ann Drive arpentersville, IL 60110",
        "7218 Arrowhead Street ummelstown, PA 17036",
        "7300 South Lakeview Street outhfield, MI 48076",
        "85 Creek Rd. Bridgewater, NJ 08807",
        "40 Hickory Court verett, MA 02149",
        "97 John Street hevy Chase, MD 20815",
        "9013 Kingston Ave. Wilkes Barre, PA 18702",
        "7744 Catherine Ave. Fort Lauderdale, FL 33308",
        "9280 Evergreen St. Villa Rica, GA 30180",
        "884 Canterbury Street airfax, VA 22030",
        "9714 Edgewater Rd. Silver Spring, MD 20901",
        "9598 Ashley Rd. Newark, NJ 07103",
        "234 Trout Drive ake Charles, LA 70605",
        "523 Manor Station Drive indsor, CT 06095",
        "9016 Vine St. Richmond, VA 23223",
        "8889 Rockledge St. Glen Ellyn, IL 60137",
        "46 East Glenlake Ave. Collierville, TN 38017",
        "5 S. Sherwood Rd. Toms River, NJ 08753",
        "263 2nd Dr. Anaheim, CA 92806",
        "8049 South Prairie St. Santa Clara, CA 95050",
        "1 Atlantic St. Superior, WI 54880",
        "9 Mayfield St. North Haven, CT 06473",
        "875 Smith Street enatchee, WA 98801",
        "686 Wood St. Hobart, IN 46342",
        "836 South Jefferson St. New Lenox, IL 60451",
        "472 Brown St. Cherry Hill, NJ 08003",
        "64 Inverness St. Oklahoma City, OK 73112",
        "5 Canal Ave. Kalamazoo, MI 49009",
        "758 Cherry Dr. Norcross, GA 30092",
        "7473 Hilltop Lane rankfort, KY 40601",
        "454 Livingston St. Appleton, WI 54911",
        "328C Glen Ridge Dr. Ypsilanti, MI 48197",
        "64 E. High Noon Dr. Woodhaven, NY 11421",
        "768 Courtland St. Oakland, CA 94603",
        "8427 W. Lakeshore St. Apex, NC 27502",
        "8473 Union Ave. Clermont, FL 34711",
        "424 Mayfield Street umberland, RI 02864",
        "65 W. Stonybrook Ave. Tualatin, OR 97062",
        "895 Cedar Drive ort Orange, FL 32127"
    };
    return address[randomIndex];
}





void displayMenu() {
    cout << "==============================================\n"
        << "\t\t Menu \n"
        << "==============================================\n"
        << "  0. Print AddressBook\n"
        << "  1. Add a new contact\n"
        << "  2. Update an existing contact\n"
        << "  3. Delete a contact\n"
        << "  4. List all added contacts in sorted order\n"
        << "  5. Search for a given contact\n"
        << "  6. Quit\n"
        << "==============================================\n"
        << endl;
}





int main() {
    srand (time(NULL));

    const string ADDRESS_BOOK = "Address Book";
    const string SEARCH_RESULTS = "Search Results";
    struct Person *AddressBook = NULL;
    struct Person *searchResults = NULL;
    struct Person *p = NULL;
    int index;
    string searchTerms;

    int menuInput;
    bool isQuit = false,
         isUnexpectedInput = false;
    do {
        displayMenu();
        cout << "What would you like to do? ";
        cin >> menuInput;
        if (cin.fail())
            isUnexpectedInput = true;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        if (isUnexpectedInput) {
            cout << "Opps. Please choose from the menu number.\n";
            isUnexpectedInput = false;
        } else if (menuInput < 0 || menuInput > 6) {
            cout << "The number you entered, " << menuInput
                << " is out of range. Please try again.\n";
        } else {
            cout << "You entered: " << menuInput << endl << endl;
            switch(menuInput) {
                case 0: //Print AddressBook
                    printAddressBook(AddressBook, ADDRESS_BOOK);
                    break;
                case 1: //Add a new contact
                    AddressBook = addPerson(AddressBook, getRandFirstName(), getRandLastName(), getRandPhone(), getRandAddress());
                    break;
                case 2: //Update an existing contact
                    break;
                case 3: //Delete a contact
                    break;
                case 4: //List all added contacts in sorted order
                    break;
                case 5: //Search for a given contact
                    break;
                case 6: //Quit
                    isQuit = true;
                    cout << "Thank you for using AddressBook. Good bye!\n\n";
                    break;
            }
        }
    } while (!isQuit);

/*
    cout << "Search (Case-Sensitive): ";
    getline(cin, searchTerms);
    cout << "Searching for: " << searchTerms << endl;
    searchResults = searchPerson(AddressBook, searchTerms);
    printAddressBook(searchResults, SEARCH_RESULTS);
    if (searchResults == NULL && searchTerms.find(" ") != string::npos)
        cout << "No results were found. Try narrowing the search. e.g. Just one word.\n";
    searchResults = destroyPersonLinkedList(searchResults);

    AddressBook = sort(AddressBook);
    printAddressBook(AddressBook, ADDRESS_BOOK);

    cout << "Which entry would you like to delete? ";
    getline(cin, searchTerms);
    AddressBook = deletePerson(AddressBook, searchTerms);
    printAddressBook(AddressBook, ADDRESS_BOOK);

    cout << "Who's entry would you like to update? ";
    getline(cin, searchTerms);
    cout << "You entered: " << searchTerms << endl;
    searchResults = searchPerson(AddressBook, searchTerms);
    printAddressBook(searchResults, SEARCH_RESULTS);
    if (searchResults != NULL) {
        struct Person *target = searchResults;
        if (searchResults->next != NULL) {
            //More than one matches
            cout << "Which INDEX NUMBER matches the person you would like to update? ";
            cin >> index;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            for (int i = 0; i < index-1; i++)
                target = target->next;
        }
        cout << "The following entry will be updated: \n"
            << "\t" << toString(target) << endl;
        tmp_person = new Person;
        // The following sequences feels so DRY :(
        // But I don't know how to simplify it.
        // Thought of using an array to hold string literals with the
        // name of each field. But it doesn't help with pointer
        // references tmp_person->FIELD_NAME;
        cout << "First name (Press ENTER to skip): ";
        getline(cin, tmp_person->firstname);
        if (tmp_person->firstname != "")
            cout << "You entered: '" << tmp-person->firstname << "'\n";
        else
            cout << "Skipping; First name will not be updated.\n";
        //
        cout << "Last name (Press ENTER to skip): ";
        getline(cin, tmp_person->lastname);
        if (tmp_person->lastname != "")
            cout << "You entered: '" << tmp_person->lastname << "'\n";
        else
            cout << "Skipping; Last name will not be updated.\n";
        //
        cout << "Phone Number (Press ENTER to skip): ";
        getline(cin, tmp_person->phone);
        if (tmp_person->phone != "")
            cout << "You entered: '" << tmp_person->phone<< "'\n";
        else
            cout << "Skipping; Phone number will not be updated.\n";
        //
        cout << "Address (Press ENTER to skip): ";
        getline(cin, tmp_person->address);
        if (tmp_person->address != "")
            cout << "You entered: " << tmp_person->address<< "'\n";
        else
            cout << "Skipping; Address field will not be updated.\n";
        //
        updatePerson(AddressBook, target, tmp_person);
        delete tmp_person;
        tmp_person = NULL;
        searchResults = destroyPersonLinkedList(searchResults);
        printAddressBook(AddressBook, ADDRESS_BOOK);
    } else {
        cout << "No matching records to update.\n";
    }
*/

    //Memory cleanup.
    AddressBook = destroyPersonLinkedList(AddressBook);

    return 0;
}





