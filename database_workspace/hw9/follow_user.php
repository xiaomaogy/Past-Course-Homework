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
$Followed_User_ID = $_REQUEST['Followed_User_ID'];

$Following_User_ID = $_REQUEST['Following_User_ID'];



// Selecting a database
//   Unnecessary in this case because we have already selected 
//   the right database with the connect statement.  
mysqli_select_db($dbcon, $database)
   or die('Could not select database');
print 'Selected database successfully!<br>';

// Listing tables in your database
$query = "INSERT INTO Following VALUES('$Followed_User_ID','$Following_User_ID')";
mysqli_query($dbcon, $query)
  or die('The insertion failed ');

print "The record inserted are:<br>";

print "Followed_User_ID:$Followed_User_ID<br>";
print "Following_User_ID:$Following_User_ID<br>";

// Closing connection
mysqli_close($dbcon);
?> 