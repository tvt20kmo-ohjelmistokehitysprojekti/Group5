<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 * 
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Account extends REST_Controller {

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
        
        $id = $this->input->get('id');

        if ($id === NULL) {
            $account = $this->Account_model->get_account(NULL);

            if ($account) {
                $this->response($account, REST_Controller::HTTP_OK);
            }
            else {
                $this->response([
                    'status' => FALSE,
                    'message' => 'No account were found'
                ],REST_Controller::HTTP_NOT_FOUND);
            }
        }

        else {
            if ($id <= 0) 
            {
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST);
            }

            $account = $this->Account_model->get_account($id);
            if(!empty($account)) {
                $this->set_response($account, REST_Controller::HTTP_OK);
            }
            else {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'Account could not be found'
                ], REST_Controller::HTTP_NOT_FOUND);
            }
        }
    }
}
