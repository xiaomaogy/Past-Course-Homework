DELIMITER |
CREATE PROCEDURE getProfileCount(OUT count INT)
BEGIN
	SELECT COUNT(*) into count FROM Profile;
END; |
DELIMITER |

# This procedure get the tuple count of the Profile table

DELIMITER |
CREATE PROCEDURE addNewProfile(
	IN User_ID VARCHAR(50), 
	IN firstName VARCHAR(50), 
	IN lastName VARCHAR(50), 
	IN Age INT)
BEGIN
	INSERT INTO Profile
	VALUES(User_ID,firstName,lastName,Age);
END; |
DELIMITER |

# This procedure insert a new tuple into the Profile table

DELIMITER |
CREATE PROCEDURE increaseThisAgeByTenIfLessThanTen(IN changeAge INT)
BEGIN
	DECLARE a_User_ID VARCHAR(50);
	DECLARE a_Age VARCHAR(50);
	DECLARE flag INT DEFAULT 0;
	DECLARE profileIncreased CURSOR FOR
		SELECT User_ID, Age
		FROM Profile
		WHERE Age = changeAge;
	DECLARE CONTINUE HANDLER
		FOR NOT FOUND
		SET flag = 1;
	OPEN profileIncreased;
	
	REPEAT 
		FETCH profileIncreased INTO a_User_ID, a_Age;
		IF a_Age < 10 THEN
			UPDATE Profile SET Age = a_Age+10
			WHERE a_User_ID = User_ID;
		END IF;
	UNTIL flag = 1
	END REPEAT;
	CLOSE profileIncreased;
	END; |
DELIMITER ;

# This procedure increase all the people's input age by 10 if they are younger than 10 years old. 






