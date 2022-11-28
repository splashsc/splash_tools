int __fastcall lan_webset(int a1)
{
  char **v1; // $v0
  char **v3; // $v1
  char *v4; // $t0
  char *v5; // $a3
  char *v6; // $a2
  char *v7; // $a1
  int v8; // $s1
  int v9; // $s1
  int v10; // $s1
  int v11; // $s2
  int v12; // $s1
  int result; // $v0
  char *v14[14]; // [sp+18h] [-38h] BYREF

  v1 = off_66D260;
  v3 = v14;
  do
  {
    v4 = *v1;
    v5 = v1[1];
    v6 = v1[2];
    v7 = v1[3];
    v1 += 4;
    *v3 = v4;
    v3[1] = v5;
    v3[2] = v6;
    v3[3] = v7;
    v3 += 4;
  }
  while ( v1 != (char **)&off_66D290 );
  *v3 = *v1;
  v8 = jhl_web_save_parm(a1, "dnsMaxtm", 1);
  v9 = v8 | jhl_web_save_parm(a1, "dnsMintm", 1);
  v10 = v9 | jhl_web_save_parm(a1, "dnsEn", 1);
  if ( v10 | jhl_web_save_parm(a1, "dnsShowct", 1) )
  {
    v11 = 1;
    dns_srv_start();
  }
  else
  {
    v11 = 0;
  }
  if ( jhl_web_save_parm(a1, "duolanlist", 0) || jhl_web_save_parm(a1, "duolan_enble", 0) )
  {
    v11 = 1;
    duolan_undo();
    jhl_web_save_parm(a1, "duolanlist", 1);
    jhl_web_save_parm(a1, "duolan_enble", 1);
    duolan_do(0);
  }
  v12 = jhl_web_save_parm(a1, "lan_ipaddr", 1);
  if ( v12 | jhl_web_save_parm(a1, "lan_netmask", 1) )
  {
    jhl_web_save_parms(a1, v14, 1);
    lanip_change();
    start_dhcp_server();
    start_rzgl(0);
    start_arp_sys();
    exec_service("ac_server-restart");
    goto LABEL_10;
  }
  if ( jhl_web_save_parms(a1, v14, 1) )
  {
    start_dhcp_server();
    goto LABEL_10;
  }
  result = v11;
  if ( v11 )
  {
LABEL_10:
    jhl_start_firewall();
    result = 1;
  }
  return result;
}
// 66D260: using guessed type char *off_66D260[11];
// 66D290: using guessed type void *off_66D290;
// 6A81EC: using guessed type int start_arp_sys(void);
// 6A8300: using guessed type int dns_srv_start(void);
// 6A8398: using guessed type int duolan_undo(void);
// 6A83CC: using guessed type int __fastcall duolan_do(_DWORD);
// 6A84B8: using guessed type int start_dhcp_server(void);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A86D0: using guessed type int lanip_change(void);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

