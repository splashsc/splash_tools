int __fastcall sub_45E810(int a1)
{
  char *v2; // $a1
  int v3; // $a0

  v2 = httpd_get_parm(a1, "wan_ping");
  if ( v2 )
  {
    nvram_set("wan_ping", v2);
    jhl_parm_commit(v3);
    jhl_setwanxx();
  }
  return wan_ping_data(a1);
}
// 45E870: variable 'v3' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B8: using guessed type int jhl_setwanxx(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

