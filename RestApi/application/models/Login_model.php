<?php

class Login_model extends CI_model
{
  function check_login($idcard){
    $this->db->select('tunnusluku');
    $this->db->from('kortti');
    $this->db->where('idkortti',$idcard);
    return $this->db->get()->row('tunnusluku');
  }

}