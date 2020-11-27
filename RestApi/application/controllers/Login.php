<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {
    public function index(){
        $this->load->model('Login_model');
        $idcard=$this->input->get('idkortti');
        $plaintext_pinCode=$this->input->get('tunnusluku');
        $encrypted_pinCode=$this->Login_model->check_login($idcard);

        if(password_verify($plaintext_pinCode, $encrypted_pinCode)){
          $result=true;
        }
        else{
          $result=false;
        }
        echo json_encode($result);
    }
}