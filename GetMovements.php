<?php
// Database credentials
$host = 'localhost';
$db_user = 'root';
$db_password = '';
$db_name = 'robx24';

// Initialize response variables
$commandStatus = "Command status: Waiting for input...";
$connectionStatus = "Connection status: Not connected";

// Create connection
$conn = mysqli_connect($host, $db_user, $db_password, $db_name);

// Check connection
if (!$conn) {
    $connectionStatus = "Connection status: Failed to connect";
    echo json_encode(['commandStatus' => $commandStatus, 'connectionStatus' => $connectionStatus]);
    exit;
} else {
    $connectionStatus = "Connection status: Connected";
}

// Check if 'command' is present in POST request
if (isset($_GET['command'])) {
    $command = $_GET['command'];
    
    $sql = "INSERT INTO robx24_controlling_system (ID, MOVEMENTS) VALUES ('', '$command')";

    if ($conn->query($sql) === TRUE) {
        $commandStatus = "Command status: New record created successfully";
    } else {
        $commandStatus = "Command status: Error - " . $conn->error;
    }
} else {
    $commandStatus = "Command status: No command provided";
}

// Respond with JSON for AJAX request
header('Content-Type: application/json');
echo json_encode(['commandStatus' => $commandStatus, 'connectionStatus' => $connectionStatus]);
exit;
?>