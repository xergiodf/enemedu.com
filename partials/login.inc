<section ng-app="backoffice">
    <div class="container top-content" ng-controller="loginCtrl">
        <div class="center wow fadeInDown">
            <h2>Bienvenido</h2>
            <p class="lead">Ingresa al backoffice de Enem, o registrate para formar parte de &eacute;ste proyecto.</p>
        </div>
        <div class="row">
            <div class="col-sm-5">
                <div class="form-box">
                    <div class="form-top">
                        <div class="form-top-left">
                            <h3>Ingresar a nuestro backoffice</h3>
                            <p>Ingrese usuario y contrase&ntilde;a para acceder:</p>
                        </div>
                        <div class="form-top-right">
                            <i class="fa fa-lock"></i>
                        </div>
                    </div>
                    <div class="form-bottom">
                        <form role="form" class="login-form" ng-submit="login()">
                            <div class="form-group">
                                <label class="sr-only" for="form-username">Usuario</label>
                                <input type="text" name="w_username" placeholder="Usuario..." class="form-username form-control" id="form-username">
                            </div>
                            <div class="form-group">
                                <label class="sr-only" for="form-password">Contrase&nt&ntilde;a</label>
                                <input type="password" name="w_password" placeholder="Contrase&ntilde;a..." class="form-password form-control" id="form-password">
                            </div>
                            <button type="submit" class="btn btn-primary" ng-disabled="form.$invalid || dataLoading">Ingresar</button>
                        </form>
                    </div>
                </div>
            </div>

            <div class="col-sm-1 middle-border"></div>
            <div class="col-sm-1"></div>

            <div class="col-sm-5">
                <div class="form-box">
                    <div class="form-top">
                        <div class="form-top-left">
                            <h3>Registrate</h3>
                            <p>Segu&iacute; los pasos para formar parte:</p>
                        </div>
                        <div class="form-top-right">
                            <i class="fa fa-pencil"></i>
                        </div>
                    </div>
                    <div class="form-bottom">
                        <h3>¿Todav&iacute;a no sos parte de Enem Business?</h3>
                        <h3>¿Qu&eacute; estas esperando? Registrate haciendo click en el bot&oacute;n</h3>
                        <h3>Recuerda tener el nombre de tu patrocinador a mano</h3>
                        <a class="btn btn-success" href="business.php?registro">Registrarme</a>                        
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>