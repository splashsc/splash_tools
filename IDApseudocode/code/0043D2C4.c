int __fastcall sub_43D2C4(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $s1
  int *v5; // $v1
  const char *v6; // $v0
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  int v10; // $a1
  const char *v12; // $s3
  int v13[33]; // [sp+18h] [-84h] BYREF

  v3 = httpd_get_parm(a1, "act");
  v2 = httpd_get_parm(a1, "action_iface");
  if ( v3 )
  {
    v4 = (int)v2;
    if ( v2 )
    {
      if ( !strcmp(v3, "stop") )
      {
        v12 = "stop";
      }
      else
      {
        if ( strcmp(v3, "restart") )
          goto LABEL_5;
        v12 = "restart";
      }
      v13[0] = (int)"wan_conn";
      v13[1] = (int)v12;
      v13[2] = v4;
      v13[3] = (int)"wan_connect_asp";
      v13[4] = 0;
      eval_nowait(v13, 0, 0, 0);
      goto LABEL_5;
    }
  }
LABEL_5:
  v5 = v13;
  v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v7 = *(_DWORD *)v6;
    v8 = *((_DWORD *)v6 + 1);
    v9 = *((_DWORD *)v6 + 2);
    v10 = *((_DWORD *)v6 + 3);
    v6 += 16;
    *v5 = v7;
    v5[1] = v8;
    v5[2] = v9;
    v5[3] = v10;
    v5 += 4;
  }
  while ( v6 != "}" );
  *(_WORD *)v5 = *(_WORD *)v6;
  return httpd_cgi_ret(a1, (char *)v13, 33, 4);
}
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);

