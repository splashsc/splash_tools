int __fastcall dns_more_member_get_file(char *a1, size_t a2)
{
  char *v4; // $v0
  char *v5; // $s6
  const char *v6; // $v0
  int v7; // $v0
  char *v8; // $v1
  _DWORD *v9; // $a0
  int v10; // $a1
  int v11; // $a2
  int v12; // $a1
  signed int v13; // $s2
  const char *v14; // $s0
  signed int v15; // $s5
  char *v16; // $v0
  const char *v17; // $s1
  const char *v19; // [sp+18h] [-10h] BYREF
  const char *v20; // [sp+1Ch] [-Ch]
  int v21; // [sp+20h] [-8h]
  int v22; // [sp+24h] [-4h]

  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  _mem_malloc(0x200000, "dns_more_member_get_file", 719);
  if ( !v4 )
    return 0;
  v5 = v4;
  memset(a1, 0, a2);
  v6 = (const char *)nvram_get("dns_more_dnstype");
  if ( !v6 )
    v6 = "";
  v7 = sprintf(a1, "gids:%s\r\n", v6);
  v8 = &a1[v7];
  v9 = &unk_64BA34;
  do
  {
    v10 = v9[1];
    *(_DWORD *)v8 = *v9;
    *((_DWORD *)v8 + 1) = v10;
    v11 = v9[2];
    *((_DWORD *)v8 + 1) = v10;
    *((_DWORD *)v8 + 2) = v11;
    v12 = v9[3];
    *((_DWORD *)v8 + 2) = v11;
    *((_DWORD *)v8 + 3) = v12;
    v9 += 4;
    *((_DWORD *)v8 + 3) = v12;
    v8 += 16;
  }
  while ( v9 != (_DWORD *)&unk_64BA54 );
  *v8 = *(_BYTE *)v9;
  v13 = v7 + 32;
  jhl_parm_get("dns_more_dnstype_item", v5, 0x200000);
  v14 = v5;
  v15 = a2 - 49;
  while ( *v14 )
  {
    v16 = strchr(v14, 60);
    v17 = v16 + 1;
    if ( !v16 )
    {
      if ( split_string(v14, 124, &v19, 2) >= 2 )
        v13 += sprintf(&a1[v13], "{n:%s;g:%s}\r\n", v19, v20);
      break;
    }
    *v16 = 0;
    if ( split_string(v14, 124, &v19, 2) < 2 || (v13 += sprintf(&a1[v13], "{n:%s;g:%s}\r\n", v19, v20), v13 < v15) )
    {
      v14 = v17;
      if ( v17 )
        continue;
    }
    break;
  }
  _mem_free(v5);
  return v13;
}
// 493E34: variable 'v4' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

