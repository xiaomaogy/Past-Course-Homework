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
$query = "SELECT Following_User_ID, firstName,lastName FROM Following, Profile WHERE Followed_User_ID = '$user' and Following_User_ID=User_ID";
$result = mysqli_query($dbcon, $query)
  or die('Query failed: ' . mysqli_error($dbcon));

// Can also check that there is only one tuple in the result
print "<b>$user</b> is followed by: ";



// Printing user attributes in HTML


$tuple = mysqli_fetch_array($result, MYSQL_ASSOC)
  or die("User $user not found!");
while($tuple){
print '<ul>';  
print '<li>User_ID: '.$tuple['Following_User_ID'];
print '<li>First Name:'.$tuple['firstName'];
print '<li>Last Name:'.$tuple['lastName'];
print '</ul>';

$tuple = mysqli_fetch_array($result, MYSQL_ASSOC);
}
// Free result
mysqli_free_result($result);

// Closing connection
mysqli_close($dbcon);
?> 