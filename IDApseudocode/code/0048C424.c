void __fastcall format_ipsec_net_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 30 )
    snprintf(
      a3,
      a4,
      "{\"name\":\"%s\",\"auto\":\"%s\",\"wans\":\"%s\",\"host_ip\":\"%s\",\"host_mask\":\"%s\",\"ipsec_ip\":\"%s\",\"rem"
      "ot_ip\":\"%s\",\"remot_mask\":\"%s\",\"ike_type\":\"%s\",\"psk_key\":\"%s\",\"host_ip_mask\":\"%s\",\"remot_ip_mas"
      "k\":\"%s\",\"ike_dh_group\":\"%s\",\"ike_encrypt\":\"%s\",\"ike_auth\":\"%s\",\"ike_lifetime\":\"%s\",\"ike_pfs_gr"
      "oup\":\"%s\",\"ipsec_encrypt\":\"%s\",\"ipsec_auth\":\"%s\",\"ipsec_lifetime\":\"%s\",\"ip_compress\":\"%s\",\"ike"
      "_pfs\":\"%s\",\"dpd_time\":\"%s\",\"dpd_latertime\":\"%s\",\"exchange_mode\":\"%s\",\"ping_en\":\"%s\",\"local_ide"
      "nt\":\"%s\",\"local_ident_type\":\"%s\",\"remot_ident\":\"%s\",\"remot_ident_type\":\"%s\"},",
      *a1,
      a1[1],
      a1[2],
      a1[3],
      a1[4],
      a1[5],
      a1[6],
      a1[7],
      a1[8],
      a1[9],
      a1[10],
      a1[11],
      a1[12],
      a1[13],
      a1[14],
      a1[15],
      a1[16],
      a1[17],
      a1[18],
      a1[19],
      a1[20],
      a1[21],
      a1[22],
      a1[23],
      a1[24],
      a1[25],
      a1[26],
      a1[27],
      a1[28],
      a1[29]);
}

