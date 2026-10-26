CREATE TABLE
    books (
              id INT,
              title TEXT,
              author_name TEXT,
              isbn TEXT, -- ISBNs often have leading zeros or are 10 digit with an X at the end.
              pub_year INT CHECK(length(pub_year) = 4 AND pub_year < 3000),
              publisher TEXT,
              misc CHECK(json_valid(misc))
);

INSERT INTO books (id, title, author_name, isbn, pub_year, publisher, misc) VALUES
        (1, 'The Ministry of Pain', 'Dubravka Ugrešić', '9780060825843', 2006, 'Harper Perennial', '{"genre": "Fiction", "country_of_origin": "Croatia", "language": "Croatian", "award_winner": true}'),
        (2, 'A Tomb for Boris Davidovich', 'Danilo Kiš', '9780140054521', 1980, 'Penguin Books', '{"genre": "Historical Fiction", "country_of_origin": "Serbia", "language": "Serbo-Croatian", "pages": 160}'),
        (3, 'The Axion Esti', 'Odysseus Elytis', '9780822953186', 1974, 'University of Pittsburgh Press', '{"genre": "Poetry", "country_of_origin": "Greece", "nobel_prize_year": 1979, "language": "Greek"}'),
        (4, 'Kassandra and the Wolf', 'Margarita Karapanou', '9781623716974', 2024, 'Clockroot Books', '{"genre": "Avant-Garde Fiction", "country_of_origin": "Greece", "language": "Greek", "themes": ["childhood", "surrealism"]}'),
        (5, 'The Return of Philip Latinowicz', 'Miroslav Krleža', '9780810112469', 1995, 'Northwestern University Press', '{"genre": "Modernist Fiction", "country_of_origin": "Croatia", "language": "Croatian", "pages": 232}'),
        (6, 'The Bridge on the Drina', 'Ivo Andrić', '9780226020457', 1977, 'University of Chicago Press', '{"genre": "Historical Fiction", "country_of_origin": "Bosnia and Herzegovina", "nobel_prize_year": 1961, "language": "Serbo-Croatian"}'),
        (7, 'Chronicle in Stone', 'Ismail Kadare', '9781841959085', 2007, 'Canongate Books', '{"genre": "Historical Fiction", "country_of_origin": "Albania", "language": "Albanian", "man_booker_international": 2005}'),
        (8, 'Death and the Dervish', 'Meša Selimović', '9780810112971', 1996, 'Northwestern University Press', '{"genre": "Philosophical Fiction", "country_of_origin": "Bosnia and Herzegovina", "language": "Serbo-Croatian", "pages": 473}'),
        (9, 'Wild Harbour', 'Alek Popov', '9781846590252', 2001, 'Peter Owen Publishers', '{"genre": "Satire", "country_of_origin": "Bulgaria", "language": "Bulgarian", "adapted_to_film": true}'),
        (10, 'The Palace of Dreams', 'Ismail Kadare', '9781628723236', 2014, 'Skyhorse', '{"genre": "Political Allegory", "country_of_origin": "Albania", "language": "Albanian", "banned_initially": true}'),
        (11, 'Zorba the Greek', 'Nikos Kazantzakis', '9780571241705', 2008, 'Faber & Faber', '{"genre": "Philosophical Fiction", "country_of_origin": "Greece", "language": "Greek", "adapted_to_film": true}'),
        (12, 'Dictionary of the Khazars', 'Milorad Pavić', '9780679724612', 1989, 'Vintage', '{"genre": "Lexicon Novel", "country_of_origin": "Serbia", "language": "Serbo-Croatian", "structure": "interactive"}'),
        (13, 'The Museum of Unconditional Surrender', 'Dubravka Ugrešić', '9780140277975', 1998, 'New Directions', '{"genre": "Autobiographical Fiction", "country_of_origin": "Croatia", "language": "Croatian", "themes": ["exile", "memory"]}'),
        (14, 'Garden, Ashes', 'Danilo Kiš', '9780156345484', 1994, 'Harcourt Brace', '{"genre": "Autobiographical Fiction", "country_of_origin": "Serbia", "language": "Serbo-Croatian", "pages": 170}'),
        (15, 'On the Edge of Reason', 'Miroslav Krleža', '9780810112421', 1995, 'Northwestern University Press', '{"genre": "Satire", "country_of_origin": "Croatia", "language": "Croatian", "pages": 182}'),
        (16, 'George Seferis: Collected Poems', 'George Seferis', '9780691014913', 1995, 'Princeton University Press', '{"genre": "Poetry", "country_of_origin": "Greece", "nobel_prize_year": 1963, "language": "Greek"}'),
        (17, 'The Sleepwalker', 'Margarita Karapanou', '9781566568388', 2010, 'Clockroot Books', '{"genre": "Psychological Fiction", "country_of_origin": "Greece", "language": "Greek", "pages": 288}'),
        (18, 'The General of the Dead Army', 'Ismail Kadare', '9781568987613', 2008, 'Clockroot Books', '{"genre": "Historical Fiction", "country_of_origin": "Albania", "language": "Albanian", "pages": 256}'),
        (19, 'The Question of Bruno', 'Aleksandar Hemon', '9780375709289', 2001, 'Vintage', '{"genre": "Short Stories", "country_of_origin": "Bosnia and Herzegovina", "language": "English", "macarthur_fellow": true}'),
        (20, 'Nowhere Man', 'Aleksandar Hemon', '9781400031863', 2003, 'Vintage', '{"genre": "Novel", "country_of_origin": "Bosnia and Herzegovina", "language": "English", "pages": 250}'),
        (21, 'Mission London', 'Alek Popov', '9781846590085', 2004, 'Peter Owen Publishers', '{"genre": "Satire", "country_of_origin": "Bulgaria", "language": "Bulgarian", "adapted_to_film": true}'),
        (22, 'The Physics of Sorrow', 'Georgi Gospodinov', '9781940953090', 2015, 'Open Letter', '{"genre": "Postmodern Fiction", "country_of_origin": "Bulgaria", "language": "Bulgarian"}'),
        (23, 'Time Shelter', 'Georgi Gospodinov', '9781324090953', 2022, 'Liveright', '{"genre": "Speculative Fiction", "country_of_origin": "Bulgaria", "man_booker_international": 2023, "language": "Bulgarian"}'),
        (24, 'The Fortress', 'Meša Selimović', '9780810117136', 1999, 'Northwestern University Press', '{"genre": "Historical Fiction", "country_of_origin": "Bosnia and Herzegovina", "language": "Serbo-Croatian", "pages": 400}'),
        (25, 'The Encyclopedia of the Dead', 'Danilo Kiš', '9780140116854', 1989, 'Penguin Books', '{"genre": "Short Stories", "country_of_origin": "Serbia", "language": "Serbo-Croatian", "pages": 192}'),
        (26, 'Sarajevo Marlboro', 'Miljenko Jergović', '9780972869225', 2003, 'Archipelago Books', '{"genre": "Short Stories", "country_of_origin": "Bosnia and Herzegovina", "language": "Bosnian/Croatian", "pages": 195}'),
        (27, 'Fox', 'Dubravka Ugrešić', '9781940996899', 2018, 'Open Letter', '{"genre": "Literary Fiction", "country_of_origin": "Croatia", "language": "Croatian", "pages": 312}'),
        (28, 'The Days of the Consuls', 'Ivo Andrić', '9780226020464', 2008, 'University of Chicago Press', '{"genre": "Historical Fiction", "country_of_origin": "Bosnia and Herzegovina", "language": "Serbo-Croatian", "pages": 384}'),
        (29, 'Quiet Flows the Una', 'Faruk Šehić', '9781908236494', 2016, 'Istros Books', '{"genre": "Fiction", "country_of_origin": "Bosnia and Herzegovina", "language": "Bosnian", "pages": 180}'),
        (30, 'The Great Transport', 'Vidosav Stevanović', '9780810112445', 1995, 'Northwestern University Press', '{"genre": "Fiction", "country_of_origin": "Serbia", "language": "Serbian", "pages": 280}');