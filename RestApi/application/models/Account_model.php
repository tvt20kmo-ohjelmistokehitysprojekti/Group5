<?php

class Account_model extends CI_Model
{
    function get_account($id) {
        $this->db->select('*');
        $this->db->from('tili');
        if ($id !== NULL) {
            $this->db->where('idtili',$id);
        }
        return $this->db->get()->result_array();
    }

    function get_transaction($id) {
        $this->db->select('*');
        $this->db->from('tilitapahtuma');
        if ($id !== NULL) {
            $this->db->where('idtili',$id);
        }
        return $this->db->get()->result_array();
    }

    function withdraw_money($id, $amount) {
        if ($id !== NULL) {
            $this->db->call("nosto($id,$amount)");
        }
        return $this->db->get()->result_array();
    }

}