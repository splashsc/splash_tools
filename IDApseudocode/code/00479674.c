int __fastcall sub_479674(int a1)
{
  char *v2; // $s1
  char *v3; // $s2
  int v4; // $s0
  int v5; // $s2
  _DWORD *v6; // $s0
  int v7; // $s1
  int v8; // $v0
  int v9; // $a0
  char *v10; // $v1
  const char *v11; // $v0
  int v12; // $t0
  int v13; // $a3
  int v14; // $a2
  int v15; // $a1
  char v17[256]; // [sp+18h] [-100h] BYREF

  memset(v17, 0, sizeof(v17));
  v2 = httpd_get_parm(a1, "ip");
  v3 = httpd_get_parm(a1, "opt");
  v4 = httpd_get_json_parm(a1, (int)"list");
  if ( v3 )
    v5 = strcmp(v3, "ban") == 0;
  else
    v5 = 0;
  if ( !v2 || StrToIp(v2) )
  {
    if ( !v4 )
      goto LABEL_11;
    if ( !cJSON_IsArray(v4) )
      goto LABEL_11;
    v6 = *(_DWORD **)(v4 + 8);
    v7 = 0;
    if ( !v6 )
      goto LABEL_11;
    goto LABEL_8;
  }
  v7 = _rzgl_ip_asp((int)v2, v5);
  if ( v4 )
  {
    if ( cJSON_IsArray(v4) )
    {
      v6 = *(_DWORD **)(v4 + 8);
      if ( v6 )
      {
        do
        {
LABEL_8:
          v8 = _rzgl_ip_asp(v6[4], v5);
          v6 = (_DWORD *)*v6;
          v7 += v8;
        }
        while ( v6 );
        goto LABEL_9;
      }
    }
  }
LABEL_9:
  if ( v7 )
  {
    jhl_parm_commit(v9);
    start_rzgl(1);
  }
LABEL_11:
  v10 = v17;
  v11 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v12 = *(_DWORD *)v11;
    v13 = *((_DWORD *)v11 + 1);
    v14 = *((_DWORD *)v11 + 2);
    v15 = *((_DWORD *)v11 + 3);
    v11 += 16;
    *(_DWORD *)v10 = v12;
    *((_DWORD *)v10 + 1) = v13;
    *((_DWORD *)v10 + 2) = v14;
    *((_DWORD *)v10 + 3) = v15;
    v10 += 16;
  }
  while ( v11 != "}" );
  *(_WORD *)v10 = *(_WORD *)v11;
  return httpd_cgi_ret(a1, v17, 33, 4);
}
// 4797C0: variable 'v9' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A862C: using guessed type int __fastcall StrToIp(_DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

