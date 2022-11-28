int __fastcall sub_491124(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  int v4; // $s4
  char *v5; // $v1
  const char *v6; // $v0
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  int v10; // $a1
  const char *v12; // $s3
  char v13[512]; // [sp+18h] [-218h] BYREF
  int v14[6]; // [sp+218h] [-18h] BYREF

  memset(v13, 0, sizeof(v13));
  v3 = httpd_get_parm(a1, "act");
  v2 = httpd_get_parm(a1, "action_iface");
  if ( v3 )
  {
    v4 = (int)v2;
    if ( !strcmp(v3, "stop") )
    {
      v12 = "stop";
    }
    else
    {
      if ( strcmp(v3, "restart") )
        goto LABEL_4;
      v12 = "restart";
    }
    v14[0] = (int)"vpn_conn";
    v14[1] = (int)v12;
    v14[2] = v4;
    v14[3] = (int)"vpn_connect_asp";
    v14[4] = 0;
    eval_nowait(v14, 0, 0, 0);
  }
LABEL_4:
  v5 = v13;
  v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v7 = *(_DWORD *)v6;
    v8 = *((_DWORD *)v6 + 1);
    v9 = *((_DWORD *)v6 + 2);
    v10 = *((_DWORD *)v6 + 3);
    v6 += 16;
    *(_DWORD *)v5 = v7;
    *((_DWORD *)v5 + 1) = v8;
    *((_DWORD *)v5 + 2) = v9;
    *((_DWORD *)v5 + 3) = v10;
    v5 += 16;
  }
  while ( v6 != "}" );
  *(_WORD *)v5 = *(_WORD *)v6;
  return httpd_cgi_ret(a1, v13, 33, 4);
}
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);

