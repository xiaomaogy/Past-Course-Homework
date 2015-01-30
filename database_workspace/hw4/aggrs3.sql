SELECT Following_User as User_Name,COUNT(Followed_User) as Num_of_Following
FROM Following
GROUP BY Following_User

#find the number of users each user is following


SELECT Followed_User as User_Name,COUNT(Following_User) as Num_Followed
FROM Following
GROUP BY Followed_User
#find the number of users that are following this user.

SELECT AVG(AGE)
FROM Profile
#get the average age of all the users


SELECT MAX(AGE), First_NAME, Last_NAme, Content
FROM Profile, Tweets
#get the tweet content that are send by the oldest user


SELECT CONTENT
FROM (
SELECT Tweet_ID,COUNT(Retweet_ID) as Retweet_COUNT
FROM Retweet
GROUP BY Tweet_ID
) AS p1, Tweets
WHERE p1.Retweet_COUNT>1 and p1.Tweet_ID = Tweets.Tweet_ID
#get the content that are retweeted more than once

SELECT First_Name, Last_Name, Age,COUNT(Retweet_ID)
FROM Retweet right join Profile on Retweet.User_ID = Profile.User_ID
GROUP BY Profile.User_ID
HAVING Age>20
#get the number of retweets by any people older than 20 years old