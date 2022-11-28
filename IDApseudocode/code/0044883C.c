int __fastcall sub_44883C(int a1)
{
  char *v1; // $v0
  int v3; // $a0
  const char *v4; // $v0
  char *v5; // $v1
  int v6; // $t1
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  char v11[1024]; // [sp+18h] [-400h] BYREF

  v1 = httpd_get_parm(a1, "vlan_name");
  if ( v1 && !set_vlan_name_data((int)v1) )
    jhl_parm_commit(v3);
  v4 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v5 = v11;
  do
  {
    v6 = *(_DWORD *)v4;
    v7 = *((_DWORD *)v4 + 1);
    v8 = *((_DWORD *)v4 + 2);
    v9 = *((_DWORD *)v4 + 3);
    v4 += 16;
    *(_DWORD *)v5 = v6;
    *((_DWORD *)v5 + 1) = v7;
    *((_DWORD *)v5 + 2) = v8;
    *((_DWORD *)v5 + 3) = v9;
    v5 += 16;
  }
  while ( v4 != "}" );
  *(_WORD *)v5 = *(_WORD *)v4;
  return httpd_cgi_ret(a1, v11, 33, 4);
}
// 448908: variable 'v3' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);

