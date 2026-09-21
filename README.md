# cpp-library-app
Create a functioning library - stored parquet files

## Books (Dimension)
- 
  - Schema {id: int, book_name: , author_name, publishing_year, publisher, isbn}

## Inventory (Fact)
- Each item of a book contained and its status ex. 2 copies of ToKillMockingbird - 1 on loan with custID
  - Schema {id: long long, status: enum (loaned, in_stock, ordered, lost, destroyed), book_id: int}

