SELECT User_email
FROM Users natural join Following
WHERE Following_ID='iu73';

SELECT Real_name
FROM Profile
WHERE Birthday LIKE '%2%';

SELECT Header_photo,Birthday
FROM Profile
WHERE Header_photo LIKE '%.com%';

SELECT Content,User_ID
FROM Tweets NATURAL JOIN Retweet
WHERE User_ID LIKE '%9%';

SELECT CONTENT,Hashtag_name
FROM Tweets NATURAL JOIN HasHashtag
WHERE Hashtag_name = 'amex';

SELECT Tweet_ID
FROM Sends;
WHERE User_ID LIKE '%12%';