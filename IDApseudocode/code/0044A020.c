int __fastcall _wan_group_modify(const char *a1, int a2)
{
  int v4; // $s4
  int v5; // $s0
  int v6; // $s5
  int v7; // $v0
  const char *v8; // $v0
  int v9; // $v0
  int v10; // $v0
  _BYTE *v11; // $v0

  v4 = sq_file_get_max_wan();
  if ( v4 <= 0 )
    return 0;
  v5 = 0;
  v6 = 0;
  do
  {
    v10 = jhl_nvget("wan_ifname", v5);
    v11 = (_BYTE *)nvram_get(v10);
    if ( v11 )
    {
      if ( !*v11 )
        return v6;
    }
    else if ( !asc_4CF9E8[4] )
    {
      return v6;
    }
    v7 = jhl_nvget("wan_group", v5);
    v8 = (const char *)nvram_get(v7);
    if ( v8 && a1 && !strcmp(v8, a1) )
    {
      v9 = jhl_nvget("wan_group", v5);
      nvram_set(v9, a2);
      v6 = 1;
    }
    ++v5;
  }
  while ( v4 != v5 );
  return v6;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

