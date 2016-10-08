<section ng-app="backoffice" ng-controller="registroCtrl">
    <div class="loading" ng-if="dataLoading"></div>
    <div class="container">
        <div class="center wow fadeInDown">        
            <h2>Registrate</h2>
            <p class="lead">Enem. Empresaros de la Nueva Econom&iacute;a Mundial</p>
        </div> 
        <div class="status alert alert-success" style="display: none"></div>
        <form id="registroForm" name="registroForm" class="contact-form" ng-submit="registro()" novalidate="novalidate">
            <div class="row contact-wrap"> 
                <div class="col-sm-6 col-sm-offset-3 wow fadeInDown">
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_patrocinador.$invalid && registroForm.w_patrocinador.$touched }">
                        <label>Patrocinador* </label>
                        <input type="text" name="w_patrocinador" ng-model="reg.w_patrocinador" class="form-control focused" required="required" placeholder="Nombre de usuario del patrocinador" tabindex="1">
                        <span ng-show="registroForm.w_patrocinador.$invalid && registroForm.w_patrocinador.$touched" class="help-block text-danger">Patrocinador es un campo obligatorio.</span>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-sm-6 col-sm-offset-3 wow fadeInDown">
                    <div class="alert alert-info text-center" role="alert" ng-show="patrocinador"><strong>Patrocinador:</strong> {{patrocinador | uppercase}}</div>
                </div>
            </div>
            <div class="row contact-wrap"> 
                <div class="col-sm-4 wow fadeInDown">
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_usuario.$invalid && registroForm.w_usuario.$touched }">
                        <label>Nombre de Usuario *</label>
                        <input type="text" name="w_usuario" ng-model="reg.w_usuario" class="form-control" required="required" placeholder="(Nombre de usuario)" tabindex="3" ng-pattern="usernamePattern" ng-trim="false">
                        <p ng-show="registroForm.w_usuario.$error.required && registroForm.w_usuario.$touched" class="help-block">Nombre de usuario es un campo obligatorio.</p>
                        <p ng-show="registroForm.w_usuario.$error.pattern && registroForm.w_usuario.$touched" class="help-block">Nombre de usuario debe contener letras minusculas. Por lo menos 6.</p>
                    </div>
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_email.$invalid && registroForm.w_email.$touched }">
                        <label>Email *</label>
                        <input type="email" name="w_email" ng-model="reg.w_email" class="form-control" required="required" placeholder="(Email)" tabindex="6">
                        <p ng-show="registroForm.w_email.$error.required && registroForm.w_email.$touched" class="help-block">Email es un campo obligatorio.</p>
                        <p ng-show="registroForm.w_email.$error.email && registroForm.w_email.$touched" class="help-block">Ingrese un email v&aacute;lido (ej. juan@perez.com).</p>
                    </div>    
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_nombre.$invalid && registroForm.w_nombre.$touched }">
                        <label>Nombre *</label>
                        <input type="text" name="w_nombre" ng-model="reg.w_nombre" class="form-control" required="required" placeholder="(Nombre)" tabindex="9">
                        <p ng-show="registroForm.w_nombre.$invalid && registroForm.w_nombre.$touched" class="help-block">Nombre es obligatorio</p>
                    </div>
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_nrodoc.$invalid && registroForm.w_nrodoc.$touched }">
                        <label>Nro. Documento *</label>
                        <input type="text" name="w_nrodoc" ng-model="reg.w_nrodoc" class="form-control" required="required" placeholder="(Nro. Documento)" tabindex="12" ng-pattern="numberPattern">
                        <p ng-show="registroForm.w_nrodoc.$error.required && registroForm.w_nrodoc.$touched" class="help-block">Nro. Documento es un campo obligatorio.</p>
                        <p ng-show="registroForm.w_nrodoc.$error.pattern && registroForm.w_nrodoc.$touched" class="help-block">Ingrese un Nro. de Documento v&aacute;lido (solo n&uacute;meros)</p>
                    </div> 
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_direccion.$invalid && registroForm.w_direccion.$touched }">
                        <label>Dirección *</label>
                        <input type="text" name="w_direccion" ng-model="reg.w_direccion" class="form-control" required="required" placeholder="(Dirección)" tabindex="15">
                        <p ng-show="registroForm.w_direccion.$invalid && registroForm.w_direccion.$touched" class="help-block">Direcci&oacute;n es un campo requerido.</p>
                    </div>
                </div>
                <div class="col-sm-4 wow fadeInDown">
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_password.$invalid && registroForm.w_password.$touched }">
                        <label>Contrase&ntilde;a *</label>
                        <input type="password" name="w_password" ng-model="reg.w_password" class="form-control" required="required" placeholder="(Contraseña)" tabindex="4" ng-pattern="passwordPattern">
                        <p ng-show="registroForm.w_password.$error.required && registroForm.w_password.$touched" class="help-block">La contraseña es obligatoria.</p>
                        <p ng-show="registroForm.w_password.$error.pattern && registroForm.w_password.$touched" class="help-block">Minimo 8 caracteres. Por lo menos 1 letra mayuscula, 1 letra miniscula y 1 n&uacute;mero.</p>
                    </div>
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_email_repeat.$invalid && registroForm.w_email_repeat.$touched }">
                        <label>Confirmar Email * </label>
                        <input type="email" name="w_email_repeat" ng-model="reg.w_email_repeat" data-confirm-email="reg.w_email" class="form-control" required="required" placeholder="(Confirmar Email)" tabindex="7">
                        <p ng-show="registroForm.w_email_repeat.$invalid && registroForm.w_email_repeat.$touched" class="help-block">Las cuentas de email no coinciden.</p>
                    </div>
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_apellido.$invalid && registroForm.w_apellido.$touched }">
                        <label>Apellido *</label>
                        <input type="text" name="w_apellido" ng-model="reg.w_apellido" class="form-control" required="required" placeholder="(Apellido)" tabindex="10">
                        <p ng-show="registroForm.w_apellido.$invalid && registroForm.w_apellido.$touched" class="help-block">Las cuentas de email no coinciden.</p>
                    </div>
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_ruc.$invalid && registroForm.w_ruc.$touched }">
                        <label>RUC</label>
                        <input type="text" name="w_ruc" ng-model="reg.w_ruc" class="form-control" placeholder="(RUC)" tabindex="13" ng-pattern="rucPattern">
                        <p ng-show="registroForm.w_ruc.$error.pattern && registroForm.w_ruc.$touched" class="help-block">El RUC debe contener n&uacute;meros y 1 gui&oacute;n (-).</p>
                    </div> 
                    <div class="form-group">
                        <label>Ciudad </label>
                        <select ng-model="reg.w_ciudad" class="form-control" name="w_ciudad" tabindex="16" >
                            <option ng-repeat="ciudad in ciudadesList" value="{{ciudad.idCiudad}}">
                                {{ciudad.nombre| uppercase}}
                            </option>
                        </select>
                    </div>
                </div>
                <div class="col-sm-4 wow fadeInDown">
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_password_repeat.$invalid && registroForm.w_password_repeat.$touched }">
                        <label>Confirmar Contrase&ntilde;a *</label>
                        <input type="password" name="w_password_repeat" ng-model="reg.w_password_repeat" data-confirm-password="reg.w_password" class="form-control" required="required" placeholder="(Confirmar Contrase&ntilde;a)" tabindex="5">
                        <p ng-show="registroForm.w_password_repeat.$invalid && registroForm.w_password_repeat.$touched" class="help-block">Las contrase&ntilde;as no coinciden.</p>
                    </div>
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_genero.$invalid && registroForm.w_genero.$touched }">
                        <label>G&eacute;nero *</label>
                        <select ng-model="reg.w_genero" class="form-control" name="w_genero" tabindex="8" required="required" required="required">
                            <option ng-repeat="genero in generoList" value="{{genero.id}}">
                                {{genero.descripcion| uppercase}}
                            </option>
                        </select>
                        <p ng-show="registroForm.w_genero.$invalid && registroForm.w_genero.$touched" class="help-block">G&eacute;nero es un campo obligatorio.</p>
                    </div>                        
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_fecnac.$invalid && registroForm.w_fecnac.$touched }">
                        <label>Fecha de Nacimiento *</label>
                        <div class="input-append date">
                            <input type="text" name="w_fecnac" ng-model="reg.w_fecnac" ng-pattern="datePattern" id="w_fecnac" class="form-control" placeholder="dd/mm/aaaa" tabindex="11" required="required" data-date-format="dd/mm/yyyy">
                        </div>
                        <p ng-show="registroForm.w_fecnac.$error.pattern && registroForm.w_fecnac.$touched" class="help-block">Ingrese una fecha de nacimiento v&aacute;lida (01/12/1986).</p>
                    </div> 
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_telef.$invalid && registroForm.w_telef.$touched }">
                        <label>Tel&eacute;fono</label>
                        <input type="text" name="w_telef" ng-model="reg.w_telef" class="form-control" placeholder="(Tel&eacute;fono)" tabindex="14" ng-pattern="numberPattern">
                        <p ng-show="registroForm.w_telef.$error.pattern && registroForm.w_telef.$touched" class="help-block">Ingrese un n&uacute;mero de tel&eacute;fono v&aacute;lido (021123321).</p>
                    </div> 
                    <div class="form-group" ng-class="{ 'has-error' : registroForm.w_celular.$invalid && registroForm.w_celular.$touched }">
                        <label>Celular</label>
                        <input type="text" name="w_celular" ng-model="reg.w_celular" class="form-control" placeholder="(Celular)" tabindex="17" ng-pattern="numberPattern">
                        <p ng-show="registroForm.w_celular.$error.pattern && registroForm.w_celular.$touched" class="help-block">Ingrese un n&uacute;mero de celular v&aacute;lido (0991123321).</p>
                    </div> 
                </div>
            </div><!--/.row-->
            <div class="row">
                <div class="col-sm-8 wow fadeInDown">
                    <div class="alert alert-{{msgClass}} text-center" role="alert" ng-show="msg">{{msg | uppercase}}</div>
                </div>
                <div class="col-sm-4 wow fadeInDown">
                    <div class="form-group">
                        <button type="submit" name="submit" class="btn btn-warning btn-lg" ng-disabled="registroForm.$invalid || dataLoading" tabindex="18">Registrarme</button>
                    </div>
                </div>
            </div>
        </form> 
    </div><!--/.container-->
</section><!--/#contact-page-->