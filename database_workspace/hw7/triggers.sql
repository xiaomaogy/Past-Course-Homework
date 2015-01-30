DELIMITER |
CREATE TRIGGER AgeIsPositive
BEFORE INSERT ON Profile
FOR EACH ROW
BEGIN
	IF(NEW.Age < 0) THEN
		SET NEW.User_ID = NULL;
	END IF;
END;|
DELIMITER ;

# Trigger 1
# This trigger makes all the person's age added to profile table not smaller than 0

# SET ProfileNumAdded to the number of tuples in the Profile table

DELIMITER |
CREATE TRIGGER ProfileNumAdded
BEFORE INSERT ON Profile
FOR EACH ROW 
BEGIN
	SET @ProfileAdded = @ProfileAdded +1;
END;|
DELIMITER ;

# Trigger 2
# This trigger keep track of the number of rows added to profile table


DELIMITER |
CREATE TRIGGER UpdateHashTag
AFTER INSERT ON HasHashtag
FOR EACH ROW
BEGIN
	INSERT IGNORE INTO Hashtag
		VALUES (NEW.Hashtag_name);
END; |
DELIMITER ;

# Trigger 3
# This trigger automatically insert a Hashtag into the Hashtag table after we insert a new hashtag in the Hashashtag table

