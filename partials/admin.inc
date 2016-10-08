<section id="blog" class="container" ng-app="backoffice">
    <div class="center wow fadeInDown">
        <h2>Admin</h2>
        <p class="lead">Bienvenido a la Administración de Enem Business</p>
    </div>

    <div class="blog" ng-controller="adminCtrl">
        <div class="row">
            <div class="col-md-12">
                <div class="widget search">
                    <form role="form">
                        <input type="text" class="form-control search_box" autocomplete="off" placeholder="Buscar usuarios">
                    </form>
                </div><!--/.search-->

                <div class="widget categories">
                    <h3>Usuarios Sin Activar</h3>
                    <div class="row">
                        <div class="col-sm-12">
                            <div class="single_comments" ng-repeat="usuario in usuariosList">
                                <img src="resources/images/blog/avatar3.png" alt=""/>
                                <br/>
                                <p><strong>{{ usuario.username }}</strong></p>
                                <div class="entry-meta small muted">
                                    <span><a href="#">Activar</a></span> | <span><a href="#">Eliminar</a></span>
                                </div>
                            </div>
                        </div>
                    </div>                     
                </div><!--/.recent comments-->
            </div>  
        </div><!--/.row-->
    </div>
</section><!--/#blog-->