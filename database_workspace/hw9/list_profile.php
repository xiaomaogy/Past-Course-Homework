<?php

// Connection parameters 
$host = 'mpcs53001.cs.uchicago.edu';
$username = 'yg79';
$password = '881222';
$database = $username.'DB';

// Attempting to connect
$dbcon = mysqli_connect($host, $username, $password, $database)
   or die('Could not connect: ' . mysqli_connect_error());
print 'Connected successfully!<br>';

// Getting the input parameter (user):
$user = $_REQUEST['user'];

// Get the attributes of the user with the given username
$query = "SELECT * FROM Profile WHERE User_ID = '$user'";
$result = mysqli_query($dbcon, $query)
  or die('Query failed: ' . mysqli_error($dbcon));

// Can also check that there is only one tuple in the result
$tuple = mysqli_fetch_array($result, MYSQL_ASSOC)
  or die("User $user not found!");

print "Here is <b>$user</b>'s Profile";

// Printing user attributes in HTML
print '<ul>';  
print '<li> User_ID: '.$tuple['User_ID'];
print '<li> First Name: '.$tuple['firstName'];
print '<li> Last Name: '.$tuple['lastName'];
print '<li> Age: '.$tuple['Age'];
print '</ul>';

// Free result
mysqli_free_result($result);

// Closing connection
mysqli_close($dbcon);
?> 