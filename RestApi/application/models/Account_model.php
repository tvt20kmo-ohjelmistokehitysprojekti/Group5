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
        $this->db->query("call nosto($id,$amount)");
        if($this->db->affected_rows()>0) {
            return true;
        } 
        else {
            return false;
        }
    }
}