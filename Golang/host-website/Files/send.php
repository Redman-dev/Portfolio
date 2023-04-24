<?php

    $field1 = $_POST['field1'];
    $field2 = $_POST['field2'];
    $field3 = $_POST['field3'];

    $errors = 0;
    $errorMessage = "";

    if ($field1 == "") { $errors = 1; $errorMessage = "field 1 required"; }
    if ($field2 == "") { $errors = 2; $errorMessage = "field 2 required"; }
    if ($field3 == "") { $errors = 3; $errorMessage = "field 3 required"; }
    if (!filter_var( $field1, FILTER_VALIDATE_EMAIL)) { $errors = 4; $errorMessage = "Invalid Email address"; }
    if ($errors != 0) {
        echo "errors detected: $errorMessage";
    } else {
        echo "OK";
    }

?>