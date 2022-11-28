int dns_url_delall()
{
  void *v0; // $v0
  void *v1; // $s3
  char *v2; // $s0
  int v3; // $v0
  int v4; // $s2
  int v5; // $s1
  int v6; // $s0
  char v8[16384]; // [sp+18h] [-4014h] BYREF
  int v9[5]; // [sp+4018h] [-14h] BYREF

  _mem_malloc(0x200000, "dns_url_delall", 2176);
  if ( !v0 )
    return -1;
  v1 = v0;
  jhl_parm_get("dnsUrl", v0, 0x200000);
  v2 = v8;
  v3 = split_string(v1, 60, v8, 4096);
  v4 = v3 - 1;
  if ( v3 < 2 )
  {
LABEL_7:
    v6 = 0;
  }
  else
  {
    v5 = 0;
    while ( 1 )
    {
      split_string(*(_DWORD *)v2, 58, v9, 2);
      ++v5;
      if ( dns_url_del(v9[0]) )
        break;
      v2 += 4;
      if ( v5 == v4 )
        goto LABEL_7;
    }
    v6 = -1;
  }
  _mem_free(v1);
  return v6;
}
// 469E74: variable 'v0' is possibly undefined
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8884: using guessed type int __fastcall dns_url_del(_DWORD);

