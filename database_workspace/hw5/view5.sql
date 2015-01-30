CREATE VIEW Tweet_by_who AS
SELECT First_Name, Last_Name, Content
FROM Profile JOIN Tweets
ON Profile.User_ID = Tweets.Send_User

# This creates a view that shows the author of every tweets

CREATE VIEW Retweet_by_who AS
SELECT Content, First_Name, Last_Name
FROM Profile,Tweets,Retweet
WHERE Profile.User_ID = Retweet.User_ID AND Retweet.Tweet_ID = Tweets.Tweet_ID
ORDER BY CONTENT

# This creates a view that shows who is retweeting what tweet.

SELECT First_Name,Last_Name,CONTENT
FROM Tweet_by_who
WHERE CONTENT LIKE '%#%'

# This finds the tweet that contain the # and the author's first and last name.

SELECT CONTENT
FROM Tweet_by_who
WHERE First_Name = 'ebby'

# This finds the tweet content that is send by ebby

SELECT CONTENT, COUNT(First_Name)
FROM Retweet_by_who
GROUP BY CONTENT

# This finds for each tweet how many different users with distinct first name are retweeting

SELECT CONTENT
FROM Retweet_by_who
WHERE First_Name = 'ebby'

# This finds all the contents that is retweeted by ebby.