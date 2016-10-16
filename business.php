<?php include("partials/header.inc"); ?>
<?php 
    $include = "business";
    if ( isset($_GET['login']) ) {
        $include = "login";
    } else if ( isset($_GET['registro']) ) {
        $include = "registro";
    }
    include("partials/includes/$include.inc"); ?>
<?php include("partials/footer.inc"); ?>