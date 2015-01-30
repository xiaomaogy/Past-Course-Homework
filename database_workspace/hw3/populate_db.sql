LOAD DATA
     LOCAL INFILE "data/Users.dat"
     REPLACE INTO TABLE Users
     FIELDS TERMINATED BY '|'
     (User_ID,User_email,User_password);

LOAD DATA
     LOCAL INFILE "data/Following.dat"
     REPLACE INTO TABLE Following
     FIELDS TERMINATED BY '|'
     (Followed_User_ID,Following_User_ID);

LOAD DATA
     LOCAL INFILE "data/Profile.dat"
     REPLACE INTO TABLE Profile
     FIELDS TERMINATED BY '|'
     (User_ID,Real_name,Header_photo,Birthday);

LOAD DATA
     LOCAL INFILE "data/Tweets.dat"
     REPLACE INTO TABLE Tweets
     FIELDS TERMINATED BY '|'
     (Tweet_ID,Content);

LOAD DATA
     LOCAL INFILE "data/Sends.dat"
     REPLACE INTO TABLE Sends
     FIELDS TERMINATED BY '|'
     (User_ID,Tweet_ID);

LOAD DATA
     LOCAL INFILE "data/Retweet.dat"
     REPLACE INTO TABLE Retweet
     FIELDS TERMINATED BY '|'
     (Tweet_ID,User_ID);
     
LOAD DATA
     LOCAL INFILE "data/Hashtag.dat"
     REPLACE INTO TABLE Hashtag
     FIELDS TERMINATED BY '|'
     (Hashtag_name);

LOAD DATA
     LOCAL INFILE "data/HasHashtag.dat"
     REPLACE INTO TABLE HasHashtag
     FIELDS TERMINATED BY '|'
     (Tweet_ID,Hashtag_name);