int __fastcall sub_43D854(int a1)
{
  int v2; // $a0
  const char *v3; // $v0
  char *v4; // $v1
  int v5; // $t1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  char v10[256]; // [sp+18h] [-100h] BYREF

  if ( set_nvrams(a1, base_network_nvarms_dns, 1) )
  {
    dns_srv_start();
    jhl_parm_commit(v2);
  }
  v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v4 = v10;
  do
  {
    v5 = *(_DWORD *)v3;
    v6 = *((_DWORD *)v3 + 1);
    v7 = *((_DWORD *)v3 + 2);
    v8 = *((_DWORD *)v3 + 3);
    v3 += 16;
    *(_DWORD *)v4 = v5;
    *((_DWORD *)v4 + 1) = v6;
    *((_DWORD *)v4 + 2) = v7;
    *((_DWORD *)v4 + 3) = v8;
    v4 += 16;
  }
  while ( v3 != "}" );
  *(_WORD *)v4 = *(_WORD *)v3;
  return httpd_cgi_ret(a1, v10, 33, 4);
}
// 43D8B0: variable 'v2' is possibly undefined
// 66E2E0: using guessed type char *base_network_nvarms_dns[4];
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8300: using guessed type int dns_srv_start(void);

