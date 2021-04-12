<?php

    $field01 = $_POST['field01'];
    $field02 = $_POST['field02'];
    $field03 = $_POST['field03'];
    $field04 = $_POST['field04'];
    $field05 = $_POST['field05'];
    $field06 = $_POST['field06'];
    $field07 = $_POST['field07'];
    $field08 = $_POST['field08'];
    $field09 = $_POST['field09'];
    $field10 = $_POST['field10'];
    $field11 = $_POST['field11'];

    $errors = 0;
    $errorMessage = "";

    if ($field01 == "") { $errors = 1; $errorMessage = "field 1 required"; }
    if ($field02 == "") { $errors = 2; $errorMessage = "field 2 required"; }
    if ($field03 == "") { $errors = 3; $errorMessage = "field 3 required"; }
    if ($field04 == "") { $errors = 4; $errorMessage = "field 4 required"; }
    if ($field07 == "") { $errors = 7; $errorMessage = "field 7 required"; }
    if ($field08 == "") { $errors = 8; $errorMessage = "field 8 required"; }
    if ($field09 == "") { $errors = 9; $errorMessage = "field 9 required"; }
    if ($field10 == "") { $errors = 10; $errorMessage = "field 10 required"; }
    if ($field11 == "") { $errors = 11; $errorMessage = "field 11 required"; }
    if (strlen($field10) < 6) { $errors = 12; $errorMessage = "Password is not 6+ characters"; }
    if (strlen($field11) < 6) { $errors = 13; $errorMessage = "Confirm Password is not 6+ characters"; }
    if (!filter_var( $field09, FILTER_VALIDATE_EMAIL)) { $errors = 14; $errorMessage = "Invalid Email address"; }
    if ($field10 != $field11) {$errors = 50;$errorMessage = "Passwords must match";}
    if ($errors != 0) {
        echo "errors detected: $errorMessage";
    } else {
        echo "OK";
    }

?>