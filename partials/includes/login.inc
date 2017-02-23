<section ng-controller="loginCtrl" id="services">
    <div class="loading" ng-show="dataLoading"></div>
    <div class="container top-content" >
        <div class="center wow fadeInDown">
            <h2>Bienvenido</h2>
            <p class="lead">Ingresa al backoffice de Enem, o registrate para formar parte de &eacute;ste proyecto.</p>
        </div>
        <div class="row">
            <div class="col-sm-5">
                <div class="alert alert-danger text-center" role="alert" ng-show="error">{{error| uppercase}}</div>
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
                        <form role="form" class="login-form" ng-submit="login()" id="loginForm" name="loginForm">
                            <div class="form-group">
                                <label class="sr-only" for="form-username">Usuario</label>
                                <input type="text" name="w_username" ng-model="w_username" placeholder="Usuario..." class="form-username form-control" id="form-username">
                            </div>
                            <div class="form-group">
                                <label class="sr-only" for="form-password">Contrase&nt&ntilde;a</label>
                                <input type="password" name="w_password" ng-model="w_password" placeholder="Contrase&ntilde;a..." class="form-password form-control" id="form-password">
                            </div>
                            <div class="form-group">
                                <input type="hidden" ng-model="f_tokenEmail" value="<?php echo $_GET['tokenEmail'] ?>"/>
                                <button type="submit" class="btn btn-primary" ng-disabled="form.$invalid || dataLoading">Ingresar</button>
                                <a class="btn btn-primary" data-toggle="modal" data-target="#forgot" role="button">Olvide mi Contrase&ntilde;a</a>
                            </div>
                        </form>
                    </div>
                    <div class="modal fade" id="forgot" role="dialog">
                        <div class="modal-dialog">
                            <div class="modal-content">
                                <div class="modal-header">
                                    <a type="button" class="close" data-dismiss="modal">&times;</a>
                                    <h4 class="modal-title">Olvide mi Contrase&ntilde;a</h4>
                                </div>
                                <div class="modal-body">
                                    <div class="alert alert-danger text-center" role="alert" ng-show="error">{{error| uppercase}}</div>
                                    <form class="form-horizontal" ng-submit="forgotPassword()" if="forgotForm" name="forgotForm">
                                        <div class="form-group">
                                            <label class="col-md-4 control-label" for="textinput">Correo electronico</label>  
                                            <div class="col-md-8">
                                                <input id="textinput" name="w_email" ng-model="w_email" type="email" class="form-control input-lg">
                                                <p ng-show="forgotForm.w_email.$invalid && forgotForm.w_email.$touched" class="help-block">El email debe ser valido y es obligatorio.</p>
                                            </div>
                                        </div>
                                        <div class="form-group">     
                                            <label class="col-md-4 control-label" for="enviarMail"></label>
                                            <div class="col-md-4">
                                                <button id="enviarMail" name="enviarMail" class="btn btn-primary" ng-disabled="forgotForm.$invalid || loading">Solicitar Cambio de Contrase&ntilde;a</button>
                                            </div>
                                        </div>
                                    </form>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="modal fade" id="cambioPass" role="dialog">
                        <div class="modal-dialog">
                            <div class="modal-content">
                                <div class="modal-header">
                                    <a type="button" class="close" data-dismiss="modal">&times;</a>
                                    <h4 class="modal-title">Cambio de Contrase&ntilde;a</h4>
                                </div>
                                <div class="modal-body">
                                    <div class="alert alert-danger text-center" role="alert" ng-show="error">{{error| uppercase}}</div>
                                    <form class="form-horizontal" ng-submit="changePassword()" id="changePassForm" name="changePassForm">
                                        <div class="form-group">
                                            <label class="col-md-4 control-label" for="w_password">Contraseña</label>  
                                            <div class="col-md-6">
                                                <input id="w_password" name="w_password" ng-model="w_password" type="password" placeholder="" class="form-control input-md" required="required"ng-pattern="passwordPattern" />
                                                <p ng-show="changePassForm.w_password.$error.required && changePassForm.w_password.$touched" class="help-block">La contraseña es obligatoria.</p>
                                                <p ng-show="changePassForm.w_password.$error.pattern && changePassForm.w_password.$touched" class="help-block">Minimo 8 caracteres. Por lo menos 1 letra mayuscula, 1 letra miniscula y 1 n&uacute;mero.</p>
                                            </div>
                                        </div>
                                        <div class="form-group">
                                            <label class="col-md-4 control-label" for="w_confirmpass">Confirmar Contraseña</label>  
                                            <div class="col-md-6">
                                                <input id="w_confirmpass" name="w_confirmpass" ng-model="w_confirmpass" type="password" data-confirm-password="w_password" class="form-control input-md" required="required">
                                                <p ng-show="changePassForm.w_confirmpass.$invalid && changePassForm.w_confirmpass.$touched" class="help-block">Las contrase&ntilde;as no coinciden.</p>
                                            </div>
                                        </div>
                                        <div class="form-group">
                                            <input type="hidden" name="w_tokenCambioPass" ng-model = "w_tokenCambioPass" value="<?php echo $_GET['tokenCambioPass']; ?>" />
                                            <label class="col-md-4 control-label" for="submitChangePass"></label>
                                            <div class="col-md-4">
                                                <button id="submitChangePass" name="submitChangePass" class="btn btn-primary" ng-disabled="changePassForm.$invalid || dataLoading">Cambiar Contraseña</button>
                                            </div>
                                        </div>
                                    </form>
                                </div>
                            </div>
                        </div>
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