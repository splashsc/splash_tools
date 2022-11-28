int __fastcall get_iface_pppoe_br_data(int a1, char *a2, int a3)
{
  const char *v5; // $v0
  int v7; // $s0
  int v9; // $v0
  _BYTE *v10; // $v0
  int v11; // $v0
  int v12; // $s0
  _BYTE *v13; // $v0
  int v14; // $v0
  int v15; // $v0
  char v16[64]; // [sp+20h] [-50h] BYREF
  int v17[4]; // [sp+60h] [-10h] BYREF

  v5 = (const char *)nvram_get("pppoe_br_more_enable");
  v7 = 0;
  if ( v5 )
  {
    v7 = strcmp(v5, "1");
    if ( v7 )
    {
      v7 = 0;
    }
    else
    {
      v9 = jhl_nvget("wan_pppoebr", a1);
      v10 = (_BYTE *)nvram_get(v9);
      if ( v10 )
      {
        if ( *v10 )
        {
          strlcpy(v16, v10, 64);
          if ( split_string(v16, 124, v17, 2) >= 2 )
          {
            v12 = J_atoi(v17[0]);
            v11 = jhl_nvget("wan_increase", v12);
            v13 = (_BYTE *)nvram_get(v11);
            if ( v13 && *v13 && (strlcpy(v16, v13, 64), split_string(v16, 124, v17, 2) >= 2) )
              v14 = J_atoi(v17[1]);
            else
              v14 = 0;
            v15 = snprintf(a2, a3, ",\"ex_type\":\"br\",\"org_iface\":%d,\"ex_vid\":%d", v12, v14);
            if ( v15 < a3 )
              v7 = v15;
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
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

