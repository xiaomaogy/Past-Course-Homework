INSERT INTO HasHashtag VALUES ('T12','honey')

INSERT INTO HasHashtag
SELECT 'T14',(SELECT Hashtag_name from Hashtag Where Hashtag_name ='amex')

DELETE FROM HasHashtag 
WHERE Hashtag_name='amex'


UPDATE HasHashtag 
SET Hashtag_name = 'amex'
WHERE Tweet_ID='T3'


