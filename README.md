# cpp-library-app
A library management system.

## Architecture

### Presentation
CLI based interface
### Logic
Actions that are expressed as programs. This is where the design of how the library functions is placed.
### Storage
Receives requests for data and responds to those requests.
Separates the physical type of data (SQLite, CSV, Parquet etc.) from the logic layer requesting data.

Current type: SQLite



## Setup

1. Create database with initial objects (you will need sqlite installed):
```bash
# create and populate books table
sqlite ~/src/storage/data/library_system.db < books_init.sql
```

## Log

1. 20261026 - Before this date, architecture was envisioning many libraries that would need to share a database. As such they would request and get a logical clock tick and send the request to a database object. That object would process requests maintaining order and preventing WR,RW and WW failures (ex. Waiting for requests )



