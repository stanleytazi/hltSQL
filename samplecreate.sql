
CREATE TABLE Book (
bookId int PRIMARY KEY,
title varchar(30),
pages int,
authorId int,
editorial varchar(30)
);
CREATE TABLE Author (
authorId int PRIMARY KEY,
name varchar(30),
nationality varchar(30)
);