int __fastcall get_wans_increase_data(char *a1, int a2)
{
  int v3; // $s3
  int v4; // $s1
  int v5; // $s0
  int v6; // $v0
  const char *v7; // $fp
  int v8; // $v0
  const char *v9; // $v0
  int v10; // $v0
  _BYTE *v11; // $v0
  int v12; // $fp
  int v13; // $v0
  char *v14; // $v0
  char v16[64]; // [sp+20h] [-60h] BYREF
  int v17[4]; // [sp+60h] [-20h] BYREF
  const char *v18; // [sp+70h] [-10h]
  const char *v19; // [sp+74h] [-Ch]
  char *format; // [sp+78h] [-8h]

  v3 = sq_file_get_max_wan();
  v4 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v4 >= a2 )
    v4 = a2 - 1;
  if ( v3 > 0 && v4 < a2 - 99 )
  {
    v18 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
    v5 = 0;
    v19 = "wan_increase";
    format = "{\"iface\":%d,\"org_iface\":%s,\"vid\":%s},";
    do
    {
      v6 = jhl_nvget("wan_ifname", v5);
      v7 = (const char *)nvram_get(v6);
      if ( !v7 )
        v7 = v18 - 1556;
      if ( !*v7 )
        break;
      v8 = jhl_nvget("wan_down", v5);
      v9 = (const char *)nvram_get(v8);
      if ( v9 && !strcmp(v9, "1")
        || jhl_iface_link_up_check(v7, v5)
        || (v10 = jhl_nvget(v19, v5), (v11 = (_BYTE *)nvram_get(v10)) == 0)
        || !*v11
        || (strlcpy(v16, v11, 64), v12 = a2 - v4, split_string(v16, 124, v17, 2) < 2) )
      {
        if ( v3 == ++v5 )
          break;
      }
      else
      {
        v13 = snprintf(&a1[v4], a2 - v4, format, v5, v17[0], v17[1]);
        if ( v13 >= v12 )
          v13 = v12 - 1;
        ++v5;
        v4 += v13;
        if ( v3 == v5 )
          break;
      }
    }
    while ( v4 < a2 - 99 );
  }
  v14 = &a1[v4];
  if ( v4 > 0 && *(v14 - 1) == 44 )
    v14 = &a1[--v4];
  *(_WORD *)v14 = 93;
  return v4 + 1;
}
// 642A04: using guessed type __int16 word_642A04;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

