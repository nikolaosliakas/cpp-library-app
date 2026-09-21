#include <iostream>
#include <string>
#include <chrono> // handling datetime

struct Author{
    std::string author_forenames;
    std::string author_lastName;};
struct Book {
    // Books object id
    int id;
    // Title
    std::string book_title;
    std::vector<Author> authors;
    u_int8_t year;
    std::string publisher;
    std::string isbn;

};

bool checkISBN13(std::string_view isbn) {
    // Research Modulus10 algo for validation
    // for now - is 17 chars long


    return isbn.size() == 17;
}
enum Status {
    LOANED,
    IN_STOCK,
    LATE,
    ORDERED,
    LOST,
    DESTROYED,
    UNDEFINED
};

struct Inventory {
    // an inventory id
    long long id;
    int book_id;
    Status status;
};

struct LoanPolicies {
    int id;
    // policy 1, standard, extended etc.
    std::string loan_pol_name;
    // number in days -1= undefined, 7, 14, etc.
    int loan_pol_duration;
};
struct Loans {
    long long id;
    int book_id;
    std::tm loan_start_dt;
    std::tm loan_due_dt; // calculated field using loan_pol_id
    int loan_pol_id;
    // staleness of the record
    std::tm refresh_dt;
};

struct Members {
    int id;
    std::string member_forenames;
    std::string member_lastname;
    std::tm date_of_birth;
    // family member id. Child points to Parent, Parent points to child;
    std::vector<int> relation_with;
    std::tm joining_date;

};