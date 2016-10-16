jQuery(function ($) {
    'use strict',
            //#main-slider
            $(function () {
                $('#main-slider.carousel').carousel({
                    interval: 50
                });
            });


    // accordian
    $('.accordion-toggle').on('click', function () {
        $(this).closest('.panel-group').children().each(function () {
            $(this).find('>.panel-heading').removeClass('active');
        });

        $(this).closest('.panel-heading').toggleClass('active');
    });

    //Initiat WOW JS
    new WOW().init();

    //goto top
    $('.gototop').click(function (event) {
        event.preventDefault();
        $('html, body').animate({
            scrollTop: $("body").offset().top
        }, 500);
    });

    $('#w_fecnac').datepicker();

    if (window.location.pathname === '/business.php' &&
            window.location.search.startsWith('?login&tokenCambioPass=')) {
        $('#cambioPass').modal('toggle');
    }
});
var backend = "http://45.79.159.123:8080/enem-services/servicios";
angular.module('enem', [
    'ui.router',
    'ngCookies'
])
        .config(['$stateProvider', '$urlRouterProvider',
            function ($stateProvider) {
                $stateProvider
                        .state("usuarios", {
                            url: "/usuarios",
                            templateUrl: "partials/adm-usuarios.html",
                            controller: "usuariosCtrl",
                            data: {
                                authRequired: true,
                                adminRequired: true
                            }
                        })
                        .state("inicio", {
                            url: "/inicio",
                            templateUrl: "partials/adm-inicio.html",
                            controller: "inicioCtrl",
                            data: {
                                authRequired: true
                            }
                        })
                        .state("password", {
                            url: "/password",
                            templateUrl: "partials/adm-password.html",
                            controller: "passwordCtrl",
                            data: {
                                authRequired: true
                            }
                        })
                        .state("network", {
                            url: "/network",
                            templateUrl: "partials/adm-network.html",
                            controller: "networkCtrl",
                            data: {
                                authRequired: true
                            }
                        });
            }])
        .run(['$rootScope', '$transitions', '$state', '$cookies', '$http', 'AuthService',
            function ($rootScope, $transitions, $state, $cookies, $http, AuthService) {

                // keep user logged in after page refresh
                $rootScope.loggedUser = $cookies.getObject('loggedUser') || {};
                $http.defaults.headers.common['Authorization'] = 'Bearer ' + $rootScope.loggedUser.token;

                $transitions.onBefore({
                    to: function (state) {
                        return state.data != null && state.data.authRequired === true;
                    }
                }, function () {
                    if (!AuthService.isAuthenticated()) {
                        return window.location.href = "business.php?login";
                    }
                });

                $transitions.onBefore({
                    to: function (state) {
                        return state.data != null && state.data.adminRequired === true;
                    }
                }, function () {
                    if (!AuthService.isAdmin()) {
                        return $state.go('inicio');
                    }
                });

                $transitions.onStart({}, function () {
                    $rootScope.dataLoading = true;
                });

                $transitions.onFinish({}, function () {
                    $rootScope.dataLoading = false;
                });

            }])
        .directive('input', function ($parse) {
            return {
                restrict: 'E',
                require: '?ngModel',
                link: function (scope, element, attrs) {
                    if (attrs.ngModel && attrs.value) {
                        $parse(attrs.ngModel).assign(scope, attrs.value);
                    }
                }
            };
        })
        .directive('confirmPassword', function () {
            var linkFn = function (scope, element, attributes, ngModel) {
                ngModel.$validators.confirmPassword = function (modelValue) {
                    return modelValue === scope.password;
                };

                scope.$watch("password", function () {
                    ngModel.$validate();
                });
            };

            return {
                require: "ngModel",
                scope: {
                    password: "=confirmPassword"
                },
                link: linkFn
            }
            ;
        })
        .directive('confirmEmail', function () {
            var linkFn = function (scope, element, attributes, ngModel) {
                ngModel.$validators.confirmEmail = function (modelValue) {
                    return modelValue === scope.email;
                };

                scope.$watch("email", function () {
                    ngModel.$validate();
                });
            };

            return {
                require: "ngModel",
                scope: {
                    email: "=confirmEmail"
                },
                link: linkFn
            };
        })
        .factory('AuthService',
                ['$http', '$cookies', '$rootScope',
                    function ($http, $cookies, $rootScope) {
                        var service = {};

                        service.authenticate = function (username, password, callback) {

                            $http.post(backend + '/usuariosrest/login', {usuario: username, password: password})
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                alert("Ocurrió un error al loguearse");
                                                console.log(response);
                                            }
                                    );
                        };

                        service.setCredentials = function (response) {
                            $rootScope.loggedUser = response.data.data;

                            $http.defaults.headers.common['Authorization'] = 'Bearer ' + $rootScope.loggedUser.token;
                            $cookies.put('loggedUser', JSON.stringify($rootScope.loggedUser));
                        };

                        service.isAuthenticated = function () {
                            return !($cookies.get('loggedUser') === undefined);
                        };

                        service.isAdmin = function () {
                            return ($cookies.getObject('loggedUser').admin === true);
                        };

                        service.clearCredentials = function () {

                            $rootScope.loggedUser = undefined;
                            $cookies.remove('loggedUser');
                            $http.defaults.headers.common.Authorization = 'Bearer ';
                        };

                        service.changePasswordOlvidada = function (tokenCambioPass, newPassword, callback) {
                            $http.post(backend + '/usuariosrest/cambioContrasenhaOlvidada', {tokenCambioPass: tokenCambioPass, newPassword: newPassword})
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                console.log(response);
                                                callback(response);
                                            }
                                    );
                        };
                        service.changePassword = function (oldPassword, newPassword, callback) {
                            $http.post(backend + '/usuariosrest/cambiarContrasenha', {password: oldPassword, newPassword: newPassword})
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                console.log(response);
                                                callback(response);
                                            }
                                    );
                        };

                        service.confirmarEmail = function (username, tokenEmail, callback) {
                            $http.get(backend + '/usuariosrest/confirmarEmailUsuario/' + username + "/" + tokenEmail)
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                console.log(response);
                                                callback(response);
                                            }
                                    );
                        };

                        service.forgotPassword = function (email, callback) {
                            $http.post(backend + '/usuariosrest/solicitarCambioContrasenha', {email: email})
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                console.log(response);
                                                callback(response);
                                            }
                                    );
                        };

                        service.registro = function (reg, callback) {
                            $http.post(backend + '/usuariosrest/registrar', {
                                nombres: reg.w_nombre,
                                apellidos: reg.w_apellido,
                                nroDocumento: reg.w_nrodoc,
                                fechaNacimiento: reg.w_fecnac,
                                email: reg.w_email,
                                direccion: reg.w_direccion,
                                celular: reg.w_celular,
                                telefono: reg.w_telef,
                                ruc: reg.w_ruc,
                                sponsorUsername: reg.w_patrocinador,
                                username: reg.w_usuario,
                                password: reg.w_password,
                                idCiudad: reg.w_ciudad,
                                genero: reg.w_genero
                            })
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                callback(response);
                                            }
                                    );
                        };

                        service.listCiudades = function (callback) {
                            $http.get(backend + '/ciudadrest/lista')
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                console.log(response);
                                                callback(response);
                                            }
                                    );
                        };

                        return service;
                    }])
        .factory('UsuarioService',
                ['$http', '$rootScope',
                    function ($http, $rootScope) {
                        var service = {};

                        service.listaUsuarios = function (callback) {

                            $http.get(backend + '/usuariosrest/lista')
                                    .then(
                                            function success(response) {
                                                callback(response.data.data);
                                            },
                                            function error(response) {
                                            }
                                    );
                        };

                        service.getDatoPersonaUsuario = function (username, callback) {
                            $http.post(backend + '/usuariosrest/datospatrocinador', {usuario: username})
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                callback(response);
                                            }
                                    );
                        };

                        service.cambiarEstadoUsuario = function (callback) {
                            $http.get(backend + '/usuariosrest/cambiarEstadoUsuario/' + userId)
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                callback(response);
                                            }
                                    );
                        };
                        
                        service.cambiarDireccionUsuario = function(callback) {
                            $http.get(backend + '/usuariosrest/cambiarDireccionRed')
                                    .then(
                                            function success(response) {
                                                callback(response);
                                            },
                                            function error(response) {
                                                callback(response);
                                            }
                                    );
                        }

                        return service;
                    }])
        .controller('inicioCtrl', ['$scope',
            function ($scope) {


            }])
        .controller('passwordCtrl', ['$scope', 'AuthService',
            function ($scope, AuthService) {
                $scope.passwordPattern = /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/;

                $scope.changePassword = function () {
                    $scope.dataLoading = true;
                    AuthService.changePassword($scope.w_oldPassword, $scope.w_newPassword, function (response) {
                        $scope.dataLoading = false;
                        if (response.status !== 200) {
                            console.log(response);
                        } else {
                            if (response.data.codigo !== 200) {
                                $scope.msg = response.data.mensaje;
                                $scope.msgClass = "danger";
                            } else {
                                $scope.w_oldPassword = "";
                                $scope.w_newPassword = "";
                                $scope.w_confirmpass = "";
                                $scope.changePassForm.$setPristine();
                                $scope.changePassForm.$setUntouched();

                                $scope.msg = response.data.mensaje;
                                $scope.msgClass = "success";
                            }
                        }
                    })
                };
            }])
        .controller('registroCtrl',
                ['$scope', 'AuthService', 'UsuarioService',
                    function ($scope, AuthService, UsuarioService) {
                        $scope.dataLoading = false;

                        $scope.datePattern = /^((\d{4})-(\d{2})-(\d{2})|(\d{2})\/(\d{2})\/(\d{4}))$/;
                        $scope.usernamePattern = /^[a-z]{6,}$/;
                        $scope.numberPattern = /^\d+$/;
                        $scope.rucPattern = /^(?=.*[\-])(?=.*\d)[0-9\-]+$/;
                        $scope.passwordPattern = /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/;

                        $scope.generoList = [{
                                id: "M",
                                descripcion: "Masculino"
                            }, {
                                id: "F",
                                descripcion: "Femenino"
                            }];

                        $scope.reg = {};
                        $scope.patrocinador;

                        $scope.ciudadesList = {};
                        AuthService.listCiudades(function (response) {
                            $scope.ciudadesList = response.data.data;
                        });

                        // Registro
                        $scope.registro = function () {
                            $scope.dataLoading = true;
                            AuthService.registro($scope.reg, function (response) {
                                $scope.dataLoading = false;
                                if (response.status !== 200) {
                                    console.log(response);
                                    $scope.msg = "Ocurrió un error en la comunicacion con el servidor.";
                                    $scope.msgClass = "danger";
                                } else {
                                    if (response.data.codigo !== 200) {
                                        $scope.msg = response.data.mensaje;
                                        $scope.msgClass = "danger";
                                    } else {
                                        $scope.msg = "Usuario agregado correctamente";
                                        $scope.msgClass = "success";
                                        $scope.reg = {};
                                        $scope.registroForm.$setPristine();
                                        $scope.registroForm.$setUntouched();
                                    }
                                }
                            });
                        };

                        $scope.datos = function (form) {
                            if (form.w_patrocinador.$valid) {
                                UsuarioService.getDatoPersonaUsuario($scope.reg.w_patrocinador, function (response) {
                                    if (response.status !== 200) {
                                        console.log(response);
                                    } else {
                                        if (response.data.codigo === 200) {
                                            $scope.patrocinador = response.data.data;
                                        }
                                    }
                                });
                            }
                        };
                    }]
                )

        .controller('loginCtrl',
                ['$scope', '$rootScope', 'AuthService',
                    function ($scope, $rootScope, AuthService) {

                        // reset login status
                        AuthService.clearCredentials();

                        $scope.passwordPattern = /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/;

                        var authenticate = function () {
                            $scope.dataLoading = true;
                            AuthService.authenticate($scope.w_username, $scope.w_password, function (response) {
                                if (response.data.codigo === 200) {
                                    AuthService.setCredentials(response);
                                    window.location.href = "admin.php#/inicio";
                                } else {
                                    $scope.error = response.data.mensaje;
                                    $scope.dataLoading = false;
                                }
                            });
                        };

                        $scope.login = function () {
                            $scope.dataLoading = true;

                            if ($scope.tokenEmail !== "") {
                                AuthService.confirmarEmail($scope.w_username, $scope.f_tokenEmail, function (response) {
                                    $scope.dataLoading = false;
                                    if (response.status !== 200) {
                                        console.log(response);
                                        $scope.error = "Ocurrió un error en la comunicaciónn con el servidor.";
                                    } else {
                                        if (response.data.codigo !== 200 && response.data.codigo !== 306) {
                                            $scope.error = response.data.mensaje;
                                        } else {
                                            // El usuario confirmó su email correctamente.
                                            authenticate();
                                        }
                                    }
                                });
                            } else {
                                authenticate();
                            }
                        };

                        $scope.forgotPassword = function () {
                            $scope.dataLoading = true;
                            AuthService.forgotPassword($scope.w_email, function (response) {
                                $scope.dataLoading = false;
                                if (response.status !== 200) {
                                    console.log(response);
                                } else {
                                    if (response.data.codigo !== 200) {
                                        $scope.error = response.data.mensaje;
                                    } else {
                                        $scope.w_email = "";
                                        $scope.forgotForm.$setPristine();
                                        $scope.forgotForm.$setUntouched();
                                        $('#forgot').modal('toggle');
                                        alert(response.data.mensaje);
                                    }
                                }
                            });
                        };

                        $scope.changePassword = function () {
                            $scope.dataLoading = true;
                            AuthService.changePasswordOlvidada($scope.w_tokenCambioPass, $scope.w_password, function (response) {
                                $scope.dataLoading = false;
                                if (response.status !== 200) {
                                    console.log(response);
                                } else {
                                    if (response.data.codigo !== 200) {
                                        console.log(response);
                                    } else {
                                        $scope.w_tokenCambioPass = "";
                                        $scope.w_password = "";
                                        $scope.w_confirmpass = "";
                                        $scope.changePassForm.$setPristine();
                                        $scope.changePassForm.$setUntouched();
                                        $('#cambioPass').modal('toggle');
                                        alert(response.data.mensaje);
                                    }
                                }
                            })
                        };
                    }]
                )
        .controller('usuariosCtrl',
                ['$scope', '$rootScope', '$http', 'UsuarioService',
                    function ($scope, $rootScope, $http, UsuarioService) {

                        UsuarioService.listaUsuarios(function (response) {
                            $scope.usuariosList = response;
                        });

                        $scope.changeUser = function (userId) {
                            $scope.dataLoading = true;
                            UsuarioService.cambiarEstadoUsuario(userId, function (response) {
                                $scope.dataLoading = false;
                                if (response.status !== 200) {
                                    console.log(response);
                                    $scope.error = "Ocurrió un error en la comunicaciónn con el servidor.";
                                } else {
                                    if (response.data.codigo !== 200) {
                                        $scope.msg = response.data.mensaje;
                                        $scope.msgClass = "danger";
                                    } else {
                                        $scope.msg = response.data.mensaje;
                                        $scope.msgClass = "success";
                                    }
                                }

                                UsuarioService.listaUsuarios(function (response) {
                                    $scope.usuariosList = response;
                                });
                            });
                        };
                    }]
                )
        .controller('networkCtrl',
                ['$rootScope', '$scope', 'UsuarioService',
                    function ($rootScope, $scope, UsuarioService) {
                        
                        $scope.direccion = $rootScope.loggedUser.direccion;
                        
                        $scope.cambiarDireccion = function() {
                            $scope.dataLoading = true;
                            UsuarioService.cambiarDireccionUsuario(function (response) {
                                $scope.dataLoading = false;
                                if (response.status !== 200) {
                                    console.log(response);
                                    $scope.error = "Ocurrió un error en la comunicaciónn con el servidor.";
                                } else {
                                    if (response.data.codigo !== 200) {
                                        $scope.msg = response.data.mensaje;
                                        $scope.msgClass = "danger";
                                    } else {
                                        $scope.msg = response.data.mensaje;
                                        $scope.msgClass = "success";
                                        $scope.direccion = response.data.data.direccion;
                                        $rootScope.loggedUser.direccion = $scope.direccion;
                                    }
                                }
                            });
                        };
                        
                        var treeData = [
                            {
                                "name": $rootScope.loggedUser.nombreCompleto,
                                "parent": "null",
                                "children": [
                                    {
                                        "name": "Level 2: A",
                                        "parent": "Top Level",
                                        "children": [
                                            {
                                                "name": "Son of A",
                                                "parent": "Level 2: A"
                                            },
                                            {
                                                "name": "Daughter of A",
                                                "parent": "Level 2: A"
                                            }
                                        ]
                                    },
                                    {
                                        "name": "Level 2: B",
                                        "parent": "Top Level"
                                    }
                                ]
                            }
                        ];
                        // ************** Generate the tree diagram  *****************
                        var margin = {top: 20, right: 120, bottom: 20, left: 120},
                        width = 960 - margin.right - margin.left,
                                height = 500 - margin.top - margin.bottom;

                        var i = 0;

                        var tree = d3.layout.tree()
                                .size([height, width]);

                        var diagonal = d3.svg.diagonal()
                                .projection(function (d) {
                                    return [d.y, d.x];
                                });

                        var svg = d3.select("#treeCanvas").append("svg")
                                .attr("width", width + margin.right + margin.left)
                                .attr("height", height + margin.top + margin.bottom)
                                .append("g")
                                .attr("transform", "translate(" + margin.left + "," + margin.top + ")");

                        root = treeData[0];

                        update(root);

                        function update(source) {

                            // Compute the new tree layout.
                            var nodes = tree.nodes(root).reverse(),
                                    links = tree.links(nodes);

                            // Normalize for fixed-depth.
                            nodes.forEach(function (d) {
                                d.y = d.depth * 180;
                            });

                            // Declare the nodesâ€¦
                            var node = svg.selectAll("g.node")
                                    .data(nodes, function (d) {
                                        return d.id || (d.id = ++i);
                                    });

                            // Enter the nodes.
                            var nodeEnter = node.enter().append("g")
                                    .attr("class", "node")
                                    .attr("transform", function (d) {
                                        return "translate(" + d.y + "," + d.x + ")";
                                    });

                            nodeEnter.append("circle")
                                    .attr("r", 10)
                                    .style("fill", "#fff");

                            nodeEnter.append("text")
                                    .attr("x", function (d) {
                                        return d.children || d._children ? -13 : 13;
                                    })
                                    .attr("dy", ".35em")
                                    .attr("text-anchor", function (d) {
                                        return d.children || d._children ? "end" : "start";
                                    })
                                    .text(function (d) {
                                        return d.name;
                                    })
                                    .style("fill-opacity", 1);

                            // Declare the linksâ€¦
                            var link = svg.selectAll("path.link")
                                    .data(links, function (d) {
                                        return d.target.id;
                                    });

                            // Enter the links.
                            link.enter().insert("path", "g")
                                    .attr("class", "link")
                                    .attr("d", diagonal);

                        }
                    }]
                );
