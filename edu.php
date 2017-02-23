<?php 
    include("partials/header.inc"); 
    $include = "edu";
    if ( isset($_GET['cursos']) ) {
        $include = "cursos";
    } else if ( isset($_GET['eventos']) ) {
        $include = "eventos";
    } else if ( isset($_GET['registro']) ) {
        $include = "newsletter";
    } else if ( isset($_GET['calendario']) ) {
        $include = "calendario";
    } 
    include("partials/includes/$include.inc");
    include("partials/footer.inc");
?>