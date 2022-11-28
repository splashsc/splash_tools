int __fastcall sub_45FCC4(int a1)
{
  int v2; // $a0
  char *v3; // $v1
  const char *v4; // $v0
  int v5; // $t0
  int v6; // $a3
  int v7; // $a2
  int v8; // $a1
  unsigned int v9; // $a2
  char *v11; // $v0
  char v12[516]; // [sp+20h] [-204h] BYREF

  if ( save_variables(a1, 0) )
  {
    if ( save_variables(a1, 1) )
      jhl_parm_commit(v2);
    exec_service("ctnf-restart");
    v3 = v12;
    v4 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v5 = *(_DWORD *)v4;
      v6 = *((_DWORD *)v4 + 1);
      v7 = *((_DWORD *)v4 + 2);
      v8 = *((_DWORD *)v4 + 3);
      v4 += 16;
      *(_DWORD *)v3 = v5;
      *((_DWORD *)v3 + 1) = v6;
      *((_DWORD *)v3 + 2) = v7;
      *((_DWORD *)v3 + 3) = v8;
      v3 += 16;
    }
    while ( v4 != "}" );
    v9 = 33;
    *(_WORD *)v3 = *(_WORD *)v4;
  }
  else
  {
    v11 = resmsg_get();
    v9 = snprintf(v12, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
    if ( v9 >= 0x200 )
      v9 = 511;
  }
  return httpd_cgi_ret(a1, v12, v9, 4);
}
// 45FDB0: variable 'v2' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);

