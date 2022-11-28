int __fastcall sub_4486B8(int a1)
{
  int v1; // $v0
  int v3; // $a0
  _BOOL4 v4; // $s1
  const char *v5; // $v0
  char *v6; // $v1
  int v7; // $t1
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  int v12; // $t1
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  char v16[260]; // [sp+18h] [-104h] BYREF

  v1 = httpd_get_json_parm(a1, (int)"vlan_name");
  if ( v1 )
  {
    v4 = set_vlan_name_data(*(_DWORD *)(v1 + 16)) == 0;
    if ( !(v4 | wan_webset_json(a1)) )
      goto LABEL_3;
  }
  else
  {
    v4 = 0;
    if ( !wan_webset_json(a1) )
      goto LABEL_3;
  }
  jhl_parm_commit(v3);
  if ( !v4 )
  {
LABEL_3:
    v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v6 = v16;
    do
    {
      v7 = *(_DWORD *)v5;
      v8 = *((_DWORD *)v5 + 1);
      v9 = *((_DWORD *)v5 + 2);
      v10 = *((_DWORD *)v5 + 3);
      v5 += 16;
      *(_DWORD *)v6 = v7;
      *((_DWORD *)v6 + 1) = v8;
      *((_DWORD *)v6 + 2) = v9;
      *((_DWORD *)v6 + 3) = v10;
      v6 += 16;
    }
    while ( v5 != "}" );
    goto LABEL_5;
  }
  jhl_gl_net_restart_timer(1000);
  v6 = v16;
  v5 = "{\"code\":4,\"error\":\"\",\"data\":null}";
  do
  {
    v12 = *(_DWORD *)v5;
    v13 = *((_DWORD *)v5 + 1);
    v14 = *((_DWORD *)v5 + 2);
    v15 = *((_DWORD *)v5 + 3);
    v5 += 16;
    *(_DWORD *)v6 = v12;
    *((_DWORD *)v6 + 1) = v13;
    *((_DWORD *)v6 + 2) = v14;
    *((_DWORD *)v6 + 3) = v15;
    v6 += 16;
  }
  while ( v5 != "}" );
LABEL_5:
  *(_WORD *)v6 = *(_WORD *)v5;
  return httpd_cgi_ret(a1, v16, 33, 4);
}
// 4487CC: variable 'v3' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);

