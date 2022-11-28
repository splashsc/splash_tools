int __fastcall get_vpn_nvarms(const char **a1, char *a2, int a3)
{
  int v5; // $s1
  int v6; // $s2
  int v7; // $v0
  const char *v8; // $fp
  int v9; // $s0
  const char **v10; // $s1
  int v11; // $v0
  void **v12; // $v0
  const char *v13; // $s7
  const char *v14; // $v0
  int v15; // $fp
  int v16; // $v0
  char *v17; // $a0
  int v18; // $v0
  char *v19; // $a0
  int v20; // $s3
  int v21; // $v0
  int v23; // $v0
  int v24; // $v0
  int v25; // [sp+28h] [-18h]

  v25 = sq_file_get_max_wan();
  v5 = snprintf(a2, a3, "\"wans\":[ ");
  if ( v5 >= a3 )
    v5 = a3 - 1;
  if ( v25 > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = snprintf(&a2[v5], a3 - v5, "{\"iface\":%d,", v6);
      if ( v7 >= a3 - v5 )
        v7 = a3 - v5 - 1;
      v8 = *a1;
      v9 = v7 + v5;
      if ( *a1 )
      {
        if ( *v8 )
          break;
      }
LABEL_15:
      v17 = &a2[v9];
      if ( v9 > 0 && *(v17 - 1) == 44 )
        v17 = &a2[--v9];
      *v17 = 0;
      v18 = snprintf(v17, a3 - v9, &byte_65078C);
      if ( v18 >= a3 - v9 )
        v18 = a3 - v9 - 1;
      ++v6;
      v5 = v9 + v18;
      if ( v6 == 5 || v25 == v6 )
        goto LABEL_22;
    }
    v10 = a1;
    while ( 1 )
    {
      if ( !strcmp(v8, "vpn_proto") )
      {
        v11 = jhl_vpnget("vpn_new_proto", v6);
        v12 = (void **)nvram_get(v11);
        if ( !v12 )
        {
          v24 = jhl_vpnget("vpn_proto", v6);
          v12 = (void **)nvram_get(v24);
          if ( !v12 )
            v12 = &off_63F984;
        }
      }
      else
      {
        v23 = jhl_vpnget(v8, v6);
        v12 = (void **)jhl_nv_get_def(v23);
        v15 = a3 - v9;
        if ( !v12 )
        {
          v16 = snprintf(&a2[v9], a3 - v9, "\"%s\":\"\",", *v10);
          if ( v16 < v15 )
            goto LABEL_13;
          goto LABEL_30;
        }
      }
      v13 = *v10;
      v14 = (const char *)get_json_data(v12);
      v15 = a3 - v9;
      v16 = snprintf(&a2[v9], a3 - v9, "\"%s\":\"%s\",", v13, v14);
      if ( v16 < a3 - v9 )
        goto LABEL_13;
LABEL_30:
      v16 = v15 - 1;
LABEL_13:
      v8 = *++v10;
      v9 += v16;
      if ( !*v10 || !*v8 )
        goto LABEL_15;
    }
  }
LABEL_22:
  v19 = &a2[v5];
  if ( v5 > 0 && *(v19 - 1) == 44 )
    v19 = &a2[--v5];
  v20 = a3 - v5;
  *v19 = 0;
  v21 = snprintf(v19, v20, "],");
  if ( v21 >= v20 )
    v21 = v20 - 1;
  return v5 + v21;
}
// 63F984: using guessed type void *off_63F984;
// 65078C: using guessed type char byte_65078C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

