<!DOCTYPE html>
<html lang="es" ng-app="enem">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta name="description" content="">
        <meta name="author" content="">
        <title>ENEM | Despertando Sue&ntilde;os</title>

        <!-- core CSS -->
        <link href="resources/css/bootstrap.min.css" rel="stylesheet">
        <link href="resources/css/font-awesome.min.css" rel="stylesheet">
        <link href="resources/css/animate.min.css" rel="stylesheet">
        <link href="resources/css/prettyPhoto.css" rel="stylesheet">
        <link href="resources/css/main.css?<?php echo(rand()); ?>" rel="stylesheet">
        <link href="resources/css/responsive.css" rel="stylesheet">
        <link href="resources/css/datepicker.css" rel="stylesheet">
        <!--[if lt IE 9]>
        <script src="js/html5shiv.js"></script>
        <script src="js/respond.min.js"></script>
        <![endif]-->       
        <link rel="shortcut icon" href="favicon.ico">
    </head><!--/head-->

    <body class="homepage">
        <div id="container">
            <div id="content">
                <header id="header">
                    <nav class="navbar navbar-inverse" role="banner">
                        <div class="container">
                            <div class="navbar-header">
                                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                                    <span class="sr-only">Toggle navigation</span>
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                    <span class="icon-bar"></span>
                                </button>
                                <a class="navbar-brand" href="index.php"><img src="resources/images/enem/logo-web.png" alt="logo"></a>
                            </div>

                            <div class="collapse navbar-collapse navbar-right">
                                <ul class="nav navbar-nav">
                                    <li><a href="index.php">Inicio</a></li>
                                    <li class="dropdown">
                                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Nosotros <i class="fa fa-angle-down"></i></a>
                                        <ul class="dropdown-menu">
                                            <li><a href="nosotros.php">Conocenos</a></li>
                                            <li><a href="nosotros.php?misvis">Misi&oacute;n / Visi&oacute;n</a></li>
                                            <li><a href="nosotros.php?man">Management</a></li>
                                        </ul>
                                    </li>
                                    <li class="dropdown">
                                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">Enem Edu <i class="fa fa-angle-down"></i></a>
                                        <ul class="dropdown-menu">
                                            <li><a href="edu.php">¿Qu&eacute; es Enem Edu?</a></li>
                                            <li><a href="edu.php?cursos">Cursos</a></li>
                                            <li><a href="edu.php?eventos">Eventos</a></li>
                                            <li><a href="edu.php?registro">Registro</a></li>
                                            <li><a href="edu.php?calendario">Calendario</a></li>
                                        </ul>
                                    </li>
                                    <li class="dropdown">
                                        <a href="business.html" class="dropdown-toggle" data-toggle="dropdown">Enem Business <i class="fa fa-angle-down"></i></a>
                                        <ul class="dropdown-menu">
                                            <li><a href="business.php?login">Login</a></li>
                                            <li><a href="business.php?registro">Registrate</a></li>
                                            <li><a href="business.php">Conoc&eacute; ENEM giftCard</a></li>
                                        </ul>
                                    </li>
                                    <li><a href="contacto.php">Contacto</a></li>
                                    <li class="dropdown">
                                        <a href="admin.php" class="dropdown-toggle" data-toggle="dropdown" ng-show="loggedUser">Back Office</a>
                                        <ul class="dropdown-menu">
                                            <li><a href="admin.php#/inicio">Inicio</a></li>
                                            <li><a href="admin.php#/pagos">Formas de Pago</a></li>
                                            <li><a href="admin.php#/network">Network</a></li>
                                            <li><a href="admin.php#/password">Cambio de Contrase&ntilde;a</a></li>
                                            <li ng-show="loggedUser.admin"><a href="admin.php#/usuarios">Activar Usuarios Nuevos</a></li>
                                            <li><a href="business.php?login">Cerrar Sesi&oacute;n</a></li>
                                        </ul>
                                    </li>
                                </ul>
                            </div>
                        </div><!--/.container-->
                    </nav><!--/nav-->
                </header><!--/header-->