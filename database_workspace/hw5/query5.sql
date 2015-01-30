SELECT Profile.User_ID
FROM Tweets RIGHT JOIN Profile
ON Tweets.Send_User = Profile.User_ID
WHERE Tweet_ID is NULL

# This query finds the user that didn't send a tweet

SELECT DISTINCT Profile.User_ID
FROM Tweets INNER JOIN Profile
ON Tweets.Send_User = Profile.User_ID

# This query finds the user that has send a tweet

SELECT AVG(Age)
FROM Tweets RIGHT JOIN Profile
ON Tweets.Send_User = Profile.User_ID
WHERE Tweet_ID is NULL

# This query finds the average age of the user that didn't send a tweet


SELECT DISTINCT f1.firstName, f1.lastName
FROM Profile f1, Following, Profile f2
WHERE f1.User_ID = Followed_User_ID AND f2.User_ID = Following_User_ID AND f2.firstName = 'ais'

# This query finds the firstname and lastname of the user following ais.

SELECT DISTINCT f1.firstName, f1.lastName
FROM Profile f1, Following, Profile f2
WHERE f1.User_ID = Followed_User_ID AND f2.User_ID = Following_User_ID AND f2.firstName = 'ais'

# This query finds the firstname and lastname of the user following ais.

SELECT DISTINCT f2.firstName, f2.lastName
FROM Profile f1, Following, Profile f2
WHERE f1.User_ID = Followed_User_ID AND f2.User_ID = Following_User_ID AND f1.firstName = 'ais'

# This query finds the firstname and lastname of the user followed by ais.

SELECT User_email, COUNT(Tweet_ID)
FROM Retweet LEFT OUTER JOIN Users Using (User_ID)
GROUP BY User_email

# This query finds the user emails and their respective Retweet numbers


SELECT Hashtag_name, COUNT(Tweet_ID)
FROM Tweets RIGHT JOIN HasHashtag 
USING(Tweet_ID)
GROUP BY Hashtag_name
# This query finds the using times of each hashtags

SELECT MIN(Age)
FROM Profile Natural JOIN Users
WHERE User_email LIKE '%gmail%'

# This query finds the minimum user age among people that use gmail

SELECT AVG(Age)
FROM Profile Natural JOIN Users
WHERE User_email LIKE '%y%'

# This query finds the average user age among people that use email containing letter y.

