CREATE TABLE Users(
       User_ID varchar(50) PRIMARY KEY,
       User_email varchar(50),
       User_password varchar(50)
);

CREATE TABLE Following(
       Followed_User_ID  varchar(50) ,
       Following_User_ID varchar(50)
);

CREATE TABLE Profile(
       User_ID varchar(50) PRIMARY KEY,
       Real_name varchar(50),
       Birthday varchar(50)
);

CREATE TABLE Tweets(
       Tweet_ID varchar(50) PRIMARY KEY,
       Content varchar(50)
);

CREATE TABLE Sends(
       User_ID varchar(50) PRIMARY KEY,
       Tweet_ID varchar(50)
);

CREATE TABLE Retweet(
       Tweet_ID varchar(50) PRIMARY KEY,
       User_ID varchar(50)
);

CREATE TABLE Hashtag(
       Hashtag_name varchar(50) PRIMARY KEY
);

CREATE TABLE HasHashtag(
       Tweet_ID varchar(50) PRIMARY KEY,
       Hashtag_name varchar(50)
);
