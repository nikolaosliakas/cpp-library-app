#include <iostream>
#include <memory>

// Arrow & Parquet headers
#include "arrow/api.h"
#include "arrow/util/type_fwd.h"
#include "parquet/arrow/writer.h"

void writeParquetExample() {
    // 1. Create an Arrow Schema
    auto schema = arrow::schema({
        arrow::field("id", arrow::int64()),
        arrow::field("title", arrow::utf8())
    });

    // 2. Build Arrow Arrays (Sample Data)
    arrow::Int64Builder id_builder;
    arrow::StringBuilder title_builder;

    PARQUET_ASSIGN_OR_THROW(auto id_array, id_builder.Finish());

    // 3. Create Table
    std::shared_ptr<arrow::Table> table = arrow::Table::Make(schema, {id_array});

    // 4. Write Table to Parquet File
    std::shared_ptr<arrow::io::FileOutputStream> outfile;
    PARQUET_ASSIGN_OR_THROW(outfile, arrow::io::FileOutputStream::Open("output.parquet"));

    // Write using parquet::arrow::WriteTable
    PARQUET_THROW_NOT_OK(
        parquet::arrow::WriteTable(*table, arrow::default_memory_pool(), outfile, table->num_rows())
    );

    std::cout << "Successfully wrote output.parquet" << std::endl;
}