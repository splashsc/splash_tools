int __fastcall sub_447AD4(int a1)
{
  int v1; // $a0
  const char *v3; // $v0
  char *v4; // $v1
  int v5; // $t1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int v10; // $t1
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  char v14[504]; // [sp+18h] [-1F8h] BYREF

  if ( _lan_vlan_asp(a1) )
  {
    jhl_parm_commit(v1);
    v4 = v14;
    v3 = "{\"code\":4,\"error\":\"\",\"data\":null}";
    do
    {
      v10 = *(_DWORD *)v3;
      v11 = *((_DWORD *)v3 + 1);
      v12 = *((_DWORD *)v3 + 2);
      v13 = *((_DWORD *)v3 + 3);
      v3 += 16;
      *(_DWORD *)v4 = v10;
      *((_DWORD *)v4 + 1) = v11;
      *((_DWORD *)v4 + 2) = v12;
      *((_DWORD *)v4 + 3) = v13;
      v4 += 16;
    }
    while ( v3 != "}" );
  }
  else
  {
    v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v4 = v14;
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
  }
  *(_WORD *)v4 = *(_WORD *)v3;
  return httpd_cgi_ret(a1, v14, 33, 4);
}
// 447B7C: variable 'v1' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);

