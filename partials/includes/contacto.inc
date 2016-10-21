<?php
    if (isset($_POST['submit'])) {
        
        $header = 'From: ' . trim(stripslashes($_POST['email'])) . " \r\n";
        $header .= "X-Mailer: PHP/" . phpversion() . " \r\n";
        $header .= "Mime-Version: 1.0 \r\n";
        $header .= "Content-Type: text/html; charset=ISO-8859-1 \r\n";

        $message = '<html><body>';
        $message .= '<h1>Contacto enemedu.com</h1>';
        $message .= '<table rules="all" style="border-color: #666;" cellpadding="10">';
        $message .= "<tr style='background: #FF5200;'><td><strong>Nombre:</strong> </td><td>" . strip_tags($_POST['name']) . "</td></tr>";
        $message .= "<tr><td><strong>Tel&eacute;fono:</strong> </td><td>" . strip_tags($_POST['tel']) . "</td></tr>";
        $message .= "<tr><td><strong>Email:</strong> </td><td>" . strip_tags($_POST['email']) . "</td></tr>";
        $message .= "<tr><td><strong>Asunto:</strong> </td><td>" . strip_tags($_POST['subject']) . "</td></tr>";
        $message .= "<tr><td><strong>Empresa:</strong> </td><td>" . strip_tags($_POST['empresa'])  . "</td></tr>";
        $message .= "<tr><td><strong>Mensaje:</strong> </td><td>" . strip_tags($_POST['message'])  . "</td></tr>";
        $message .= "<tr><td><strong>Enviado:</strong> </td><td>" . date('d/m/Y H:i:s', time()) . "</td></tr>";
        $message .= "</table>";
        $message .= "</body></html>";

        $email_from = trim(stripslashes($_POST['email']));
        $subject = strip_tags($_POST['subject']);
        $email_to = 'info@enemedu.com';

        $body = $message;

        mail($email_to, $subject, $body, $header);

        echo "<script type='text/javascript'>
            alert('Gracias por contactarnos. En breve le responderemos.');
            history.back ();
        </script>";
    }
?>
<section id="services">
    <div class="center">                
        <h2>¿Donde encontrarnos?</h2>
    </div>
    <div class="gmap-area">
        <div class="container">
            <div class="row">
                <div class="col-sm-4 text-center">
                    <div class="gmap">
                        <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3605.6696578917167!2d-57.506244884987474!3d-25.348863783825895!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x0%3A0x0!2zMjXCsDIwJzU1LjkiUyA1N8KwMzAnMTQuNiJX!5e0!3m2!1ses!2s!4v1476716642646" width="600" height="450" frameborder="0" style="border:0" allowfullscreen></iframe>
                    </div>
                </div>

                <div class="col-sm-4 map-content">
                    <ul class="row">
                        <li class="col-sm-12">
                            <address>
                                <h5>Enem Business</h5>
                                <p>Doctor Gaspar Rodriguez de Francia casi Manuel Ortiz Guerrero Nº 72<br>
                                     Barrio Maria Auxiliadora, San Lorenzo, Paraguay</p>
                                <p>Tel&eacute;fono: 0972 197 397 <br>
                                    Email: info@enemedu.com</p>
                            </address>

                            <address>
                                <h5>Enem Edu</h5>
                                <p>36 proyectada y avenida japon Nº 1878 <br>
                                    Barrio Republicano, Asunción, Paraguay</p>                                
                                <p>Tel&eacute;fono: 0984 563 212 <br>
                                    Email: info@enemedu.com</p>
                            </address>
                        </li>
                    </ul>
                </div>
                
                <div class="col-sm-4 text-center">
                    <div class="gmap">
                        <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3606.496618624174!2d-57.64319038498793!3d-25.321111283838682!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x0%3A0x0!2zMjXCsDE5JzE2LjAiUyA1N8KwMzgnMjcuNiJX!5e0!3m2!1ses!2s!4v1476717694613" width="600" height="450" frameborder="0" style="border:0" allowfullscreen></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <br /><br /><br /><br />
    <div class="container">
        <div class="center">        
            <h2>Dejanos un mensaje</h2>
        </div> 
        <div class="row contact-wrap">             
            <form id="main-contact-form" class="contact-form" name="contact-form" method="post" action="contacto.php">
                <div class="col-sm-5 col-sm-offset-1">
                    <div class="form-group">
                        <label>Nombre *</label>
                        <input type="text" name="name" class="form-control" required="required">
                    </div>
                    <div class="form-group">
                        <label>Email *</label>
                        <input type="email" name="email" class="form-control" required="required">
                    </div>
                    <div class="form-group">
                        <label>Telefono</label>
                        <input type="number" name="tel" class="form-control">
                    </div>
                    <div class="form-group">
                        <label>Empresa</label>
                        <input type="text" name="empresa" class="form-control">
                    </div>                        
                </div>
                <div class="col-sm-5">
                    <div class="form-group">
                        <label>Asunto *</label>
                        <input type="text" name="subject" class="form-control" required="required">
                    </div>
                    <div class="form-group">
                        <label>Mensaje *</label>
                        <textarea name="message" id="message" required="required" class="form-control" rows="8"></textarea>
                    </div>                        
                    <div class="form-group">
                        <button type="submit" name="submit" class="btn btn-primary btn-lg" required="required">Enviar Mensaje</button>
                    </div>
                </div>
            </form> 
        </div>
    </div>
</section>