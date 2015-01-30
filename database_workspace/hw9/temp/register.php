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
$User_ID = $_REQUEST['User_ID'];

$User_email = $_REQUEST['User_email'];

$User_password = $_REQUEST['User_password'];


// Selecting a database
//   Unnecessary in this case because we have already selected 
//   the right database with the connect statement.  
mysqli_select_db($dbcon, $database)
   or die('Could not select database');
print 'Selected database successfully!<br>';

// Listing tables in your database
$query = "INSERT INTO Users VALUES('$User_ID','$User_email','$User_password')";
mysqli_query($dbcon, $query)
  or die('The insertion failed ');

print "The record inserted are:<br>";

print "User_ID:$User_ID<br>";
print "User_email:$User_email<br>";
print "User_password:$User_password<br>";

// Closing connection
mysqli_close($dbcon);
?> 