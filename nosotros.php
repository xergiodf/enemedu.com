<?php 
    include("partials/header.inc"); 
    $include = "nosotros";
    if ( isset($_GET['misvis']) ) {
        $include = "misionvision";
    } else if ( isset($_GET['man']) ) {
        $include = "management";
    }
    include("partials/includes/$include.inc");
    include("partials/footer.inc");
?>