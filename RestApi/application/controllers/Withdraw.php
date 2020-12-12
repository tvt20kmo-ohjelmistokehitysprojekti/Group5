<?php 

defined ('BASEPATH') OR exit('No direct script access allowed');

require APPPATH . 'libraries/REST_Controller.php';

 class Withdraw extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Account_model');
    }

    public function index_get() {
        
         // Update the account balance
         $id=$this->input->get('id');
         $amount=$this->input->get('amount');
         $account=$this->input->get('tyyppi');

         $withdraw = $this->Account_model->withdraw_money($id,$amount,$account);
    
         if ($withdraw){
            $message='Money withdrawed';
            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }
        
        else
        {
            $this->response([
                'status' => FALSE,
                'message' => 'Can not withdraw money'
            ], REST_Controller::HTTP_CONFLICT);
        }
    }
}

