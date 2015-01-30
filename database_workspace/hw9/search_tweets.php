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
$seg = $_REQUEST['seg'];

// Get the attributes of the user with the given username

$query = "SELECT Content FROM Tweets WHERE CONTENT LIKE \"%$seg%\" ";
$result = mysqli_query($dbcon, $query)
  or die('Query failed: ' . mysqli_error($dbcon));

// Can also check that there is only one tuple in the result
print "<b>$seg</b> has the following result: ";



// Printing user attributes in HTML


$tuple = mysqli_fetch_array($result, MYSQL_ASSOC)
  or die("Content $seg not found!");
while($tuple){
print '<ul>';  
print '<li>'.$tuple['Content'];
print '</ul>';

$tuple = mysqli_fetch_array($result, MYSQL_ASSOC);
}
// Free result
mysqli_free_result($result);

// Closing connection
mysqli_close($dbcon);
?> 