# cpp-library-app
Create a functioning library - stored parquet files


## Prerequisites:
1. Install Apache Arrow for Parquet
   ```shell
    brew install apache-arrow
    ```
2. 
## Books (Dimension)
 - Schema {id: int, bookTitle: str, author_name: vector , publishing_year: int, publisher, isbn: str}

## Inventory (Fact)
- Each item of a book contained and its status ex. 2 copies of ToKillMockingbird - 1 on loan with custID
  - Schema {id: long long, status: enum (loaned, late, in_stock, ordered, lost, destroyed), book_id: int}

## Loan Policies (Dimension)
- Small table of policies that loans can be on
- Schema {id: int, loan_pol_name: str, loan_pol_days: (-1, 14, 7) etc.
- 
## Loans (Fact)
- running event of when a book was taken out on loan
  - Schema {id: long long, book_id: int, loan_date_start: datetime, loan_date_policy: pol1, loan_due: date (calc'd), member_id: int

## Members (Dimension)
- Schema {id: int, member_forenames: string, member_lastname: str, date_of_birth: date, relationship_with: member_ids (parent/children), 
