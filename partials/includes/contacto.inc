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
        $message .= "<tr><td><strong>Enviado:</strong> </td><td>" . date('d/m/Y HH:MM:SS', time()) . "</td></tr>";
        $message .= "</table>";
        $message .= "</body></html>";

        $email_from = trim(stripslashes($_POST['email']));
        $subject = strip_tags($_POST['subject']);
        $email_to = 'contacto@minicubic.com';

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
                <div class="col-sm-5 text-center">
                    <div class="gmap">
                        <iframe frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="https://maps.google.com/maps?f=q&amp;source=s_q&amp;hl=en&amp;geocode=&amp;q=JoomShaper,+Dhaka,+Dhaka+Division,+Bangladesh&amp;aq=0&amp;oq=joomshaper&amp;sll=37.0625,-95.677068&amp;sspn=42.766543,80.332031&amp;ie=UTF8&amp;hq=JoomShaper,&amp;hnear=Dhaka,+Dhaka+Division,+Bangladesh&amp;ll=23.73854,90.385504&amp;spn=0.001515,0.002452&amp;t=m&amp;z=14&amp;iwloc=A&amp;cid=1073661719450182870&amp;output=embed"></iframe>
                    </div>
                </div>

                <div class="col-sm-7 map-content">
                    <ul class="row">
                        <li class="col-sm-6">
                            <address>
                                <h5>Head Office</h5>
                                <p>1537 Flint Street <br>
                                    Tumon, MP 96911</p>
                                <p>Phone:670-898-2847 <br>
                                    Email Address:info@domain.com</p>
                            </address>

                            <address>
                                <h5>Zonal Office</h5>
                                <p>1537 Flint Street <br>
                                    Tumon, MP 96911</p>                                
                                <p>Phone:670-898-2847 <br>
                                    Email Address:info@domain.com</p>
                            </address>
                        </li>


                        <li class="col-sm-6">
                            <address>
                                <h5>Zone#2 Office</h5>
                                <p>1537 Flint Street <br>
                                    Tumon, MP 96911</p>
                                <p>Phone:670-898-2847 <br>
                                    Email Address:info@domain.com</p>
                            </address>

                            <address>
                                <h5>Zone#3 Office</h5>
                                <p>1537 Flint Street <br>
                                    Tumon, MP 96911</p>
                                <p>Phone:670-898-2847 <br>
                                    Email Address:info@domain.com</p>
                            </address>
                        </li>
                    </ul>
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