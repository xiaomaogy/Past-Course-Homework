SET @profileCount = 0;
CALL getProfileCount(@profileCount);
SELECT @profileCount;

# We can see that after calling the getProfileCount procedure the @profileCount variable is recorded with the Profile's tuple count value.

CALL addNewProfile('aa1111','fea','fed','11');

# We can see that after calling the addNewProfile function the new profile tuple is inserted into the Profile table

CALL increaseThisAgeByTenIfLessThanTen(0);

# We can see that after calling the increaseThisAgeByTenIfLessThanTen function, all the people with age 0 has changed to 10 years old.
