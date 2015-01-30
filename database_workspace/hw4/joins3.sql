SELECT DISTINCT User_email 
FROM Following, Users
WHERE Following.Following_User=Users.User_ID

#This query find all the users's email that are following other people


SELECT Hashtag.Hashtag_name, COUNT(Tweet_ID) 
FROM HasHashtag natural join Hashtag 
GROUP BY Hashtag.Hashtag_name

#This query get the num of occurence for each hashtag

SELECT First_Name, User_email
FROM Profile, Users
WHERE Profile.User_ID = Users.User_ID AND First_NAME LIKE "%e%"

#This query find all the email address for all the users that have letter 'e' in their first name


SELECT Tweet_ID, Content, User_ID
FROM Tweets natural join Retweet
WHERE Tweets.Send_User=Retweet.User_ID

#This query find all the Tweets that are retweeted by its author

SELECT DISTINCT Send_User as Author, Content
FROM Tweets natural join Retweet 
WHERE Tweets.Tweet_ID = Retweet.Tweet_ID and Content LIKE "%the%"
#This query find all the people retweet a message that contain word "the"

SELECT CONTENT
FROM Profile natural join Tweets 
WHERE Profile.User_ID = Tweets.Send_User AND AGE>30

#This query find all the tweets that are send by people older than 30