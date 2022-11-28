int __fastcall get_iface_increase_data(int a1, char *a2, int a3)
{
  const char *v5; // $v0
  int v7; // $s0
  int v9; // $v0
  _BYTE *v10; // $v0
  int v11; // $v0
  char v12[64]; // [sp+20h] [-54h] BYREF
  const char *v13[5]; // [sp+60h] [-14h] BYREF

  v5 = (const char *)nvram_get("increase_wan");
  v7 = 0;
  if ( v5 )
  {
    v7 = strcmp(v5, "enable");
    if ( v7 )
    {
      v7 = 0;
    }
    else
    {
      v9 = jhl_nvget("wan_increase", a1);
      v10 = (_BYTE *)nvram_get(v9);
      if ( v10 )
      {
        if ( *v10 )
        {
          strlcpy(v12, v10, 64);
          if ( split_string(v12, 124, v13, 2) >= 2 )
          {
            v11 = snprintf(a2, a3, ",\"ex_type\":\"ex\",\"org_iface\":%s,\"ex_vid\":%s", v13[0], v13[1]);
            if ( v11 < a3 )
              v7 = v11;
            else
              v7 = a3 - 1;
          }
        }
      }
    }
  }
  return v7;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

