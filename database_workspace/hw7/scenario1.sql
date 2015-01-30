INSERT INTO Profile 
VALUES ('aa3734','fea','aeae',-1);

# Trigger 1 prevents this insertion to happen because the age is -1.

INSERT INTO Profile 
VALUES ('aa3734','fea','aeae',3);

# Trigger 1 allow this insertion to happen because the age is 3, which is positive


SELECT @ProfileAdded;

INSERT INTO Profile 
VALUES ('aa4356','feafea','aeeae',5);

SELECT @ProfileAdded;

# Trigger 2 has increased @ProfileAdded by 1 after insert another tuple to the table


SELECT @ProfileAdded;

INSERT INTO Profile 
VALUES ('aa3222','feafea','aeeae',5);

SELECT @ProfileAdded;

# Trigger 2 hasn't increased since there is no tuple being inserted.



INSERT INTO HasHashtag VALUES ('fe789432','abc');

# Trigger 3 has automatically put a tuple into the Hashtag table after inserting on Hashashtag table


INSERT INTO HasHashtag VALUES ('fe439432','ach');

# Trigger 3 has not put a new hashtag into the Hashtag table.