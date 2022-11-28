int __fastcall dns_more_dnstype_item_get_file(_DWORD *a1, size_t a2, const char *a3)
{
  char *v6; // $v0
  char *v7; // $s6
  const char *v8; // $s0
  int v9; // $s2
  signed int v10; // $s4
  char *v11; // $v0
  const char *v12; // $a0
  const char *v13; // $fp
  const char *v15; // [sp+18h] [-18h] BYREF
  const char *v16; // [sp+1Ch] [-14h]
  int v17; // [sp+20h] [-10h]
  int v18; // [sp+24h] [-Ch]
  char *v19; // [sp+28h] [-8h]

  v19 = "1\"";
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  _mem_malloc(0x200000, "dns_more_dnstype_item_get_file", 869);
  if ( v6 )
  {
    v7 = v6;
    memset(a1, 0, a2);
    *a1 = 1313094254;
    *a1 = 1313094254;
    a1[1] = 979840083;
    a1[1] = 979840083;
    a1[2] = -188024373;
    a1[2] = -188024373;
    a1[3] = 1145694679;
    a1[3] = 1145694679;
    *((_BYTE *)a1 + 17) = 10;
    *((_BYTE *)a1 + 16) = 13;
    *((_BYTE *)a1 + 18) = 0;
    jhl_parm_get("dns_more_dnstype_item", v7, 0x200000);
    v8 = v7;
    v9 = 18;
    v10 = a2 - 49;
    while ( 1 )
    {
      if ( !*v8 )
      {
LABEL_11:
        _mem_free(v7);
        return v9;
      }
      v11 = strchr(v8, 60);
      v12 = v8;
      if ( !v11 )
        break;
      *v11 = 0;
      v8 = v11 + 1;
      if ( split_string(v12, 124, &v15, 2) >= 2 )
      {
        if ( a3 )
          goto LABEL_7;
LABEL_14:
        v9 += sprintf((char *)a1 + v9, "{n:%s;g:%s}\r\n", v15, v16);
        goto LABEL_9;
      }
LABEL_10:
      if ( !v8 )
        goto LABEL_11;
    }
    if ( split_string(v8, 124, &v15, 2) < 2 )
      goto LABEL_11;
    v8 = 0;
    if ( !a3 )
      goto LABEL_14;
LABEL_7:
    v13 = v16;
    if ( !strcmp(v16, a3) )
      v9 += sprintf((char *)a1 + v9, "{n:%s;g:%s}\r\n", v15, v13);
LABEL_9:
    if ( v9 >= v10 )
      goto LABEL_11;
    goto LABEL_10;
  }
  return 0;
}
// 494440: variable 'v6' is possibly undefined
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

