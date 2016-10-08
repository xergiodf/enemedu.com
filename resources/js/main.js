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

    // portfolio filter
    $(window).load(function () {
        'use strict';
        var $portfolio_selectors = $('.portfolio-filter >li>a');
        var $portfolio = $('.portfolio-items');
        $portfolio.isotope({
            itemSelector: '.portfolio-item',
            layoutMode: 'fitRows'
        });

        $portfolio_selectors.on('click', function () {
            $portfolio_selectors.removeClass('active');
            $(this).addClass('active');
            var selector = $(this).attr('data-filter');
            $portfolio.isotope({filter: selector});
            return false;
        });
    });

    //goto top
    $('.gototop').click(function (event) {
        event.preventDefault();
        $('html, body').animate({
            scrollTop: $("body").offset().top
        }, 500);
    });

    //Pretty Photo
    $("a[rel^='prettyPhoto']").prettyPhoto({
        social_tools: false
    });

    $('#w_fecnac').datepicker();
});
var backend = "http://45.79.159.123:8080/enem-services/servicios";
angular.module('backoffice', [])
        .directive('confirmPassword', function () {

            var linkFn = function (scope, element, attributes, ngModel) {
                ngModel.$validators.confirmPassword = function (modelValue) {
                    return modelValue == scope.password;
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
                    return modelValue == scope.email;
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
            }
            ;
        })
        .controller('registroCtrl',
                ['$scope', '$http',
                    function ($scope, $http) {
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
                        $scope.patrocinador = "Fulano de tal";

                        $scope.ciudadesList;
                        $http.get(backend + '/ciudadrest/lista')
                                .then(
                                        function success(response) {
                                            console.log(response);
                                            $scope.ciudadesList = response.data.data;
                                        },
                                        function error(response) {
                                            console.log(response);
                                        }
                                );

                        // Registro
                        $scope.registro = function () {
                            $scope.dataLoading = true;
                            $http.post(backend + '/usuariosrest/registrar', {
                                nombres: $scope.reg.w_nombre,
                                apellidos: $scope.reg.w_apellido,
                                nroDocumento: $scope.reg.w_nrodoc,
                                fechaNacimiento: $scope.reg.w_fecnac,
                                email: $scope.reg.w_email,
                                direccion: $scope.reg.w_direccion,
                                celular: $scope.reg.w_celular,
                                telefono: $scope.reg.w_telef,
                                ruc: $scope.reg.w_ruc,
                                sponsorUsername: $scope.reg.w_patrocinador,
                                username: $scope.reg.w_usuario,
                                password: $scope.reg.w_password,
                                idCiudad: $scope.reg.w_ciudad,
                                genero: $scope.reg.w_genero
                            })
                                    .then(
                                            function success(response) {
                                                $scope.dataLoading = false;
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
                                            },
                                            function error(response) {
                                                console.log(response);
                                                $scope.msg = "Ocurri&oacute; un error en la comunicaci&oacute;n con el servidor.";
                                                $scope.msgClass = "danger";
                                            }
                                    );
                        };
                    }]
                )

        .controller('loginCtrl',
                ['$scope', '$http',
                    function ($scope, $http) {
                        $scope.login = function () {
                            $scope.dataLoading = true;
                            $http.post(backend + '/usuariosrest/login', {
                                username: $scope.w_username,
                                password: $scope.w_password
                            })
                                    .then(
                                            function success(response) {
                                                console.log(response);
                                            },
                                            function error(response) {
                                                console.log(response);
                                            }
                                    );
                        }
                        ;
                    }])
        .controller('adminCtrl',
                ['$scope', '$http',
                    function ($scope, $http) {

                        $scope.usuariosList;
                        $http.get(backend + '/usuariosrest/listanoactivos')
                                .then(
                                        function success(response) {
                                            console.log(response);
                                            $scope.usuariosList = response.data.data;
                                            $scope.dataLoading = false;
                                        },
                                        function error(response) {
                                            console.log(response);
                                            $scope.dataLoading = false;
                                        }
                                );
                    }]);
