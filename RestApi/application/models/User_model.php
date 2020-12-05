<?php
/**
 *
 */
class User_model extends CI_model
{
  function get_user($id){
    $this->db->select('*');
    $this->db->from('kortti');
    if($id !== NULL) {
      $this->db->where('idkortti',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_user($add_data){
    $this->db->insert('kortti',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id();
    }
    else {
      return FALSE;
    }
  }
  function update_user($id, $update_data){
    $this->db->where('idkortti',$id);
    $this->db->update('kortti',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function delete_user($id){
    $this->db->where('idkortti',$id);
    $this->db->delete('kortti');
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function check_login($username){
    $this->db->select('tunnusluku');
    $this->db->from('kortti');
    $this->db->where('idkortti',$username);
    return $this->db->get()->row('tunnusluku');
  }

}