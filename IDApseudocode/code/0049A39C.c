int __fastcall get_wans_pppoebr_data(char *a1, int a2)
{
  int v4; // $s3
  int v5; // $s1
  int v6; // $s0
  int v7; // $v0
  const char *v8; // $fp
  int v9; // $v0
  const char *v10; // $v0
  int v11; // $v0
  _BYTE *v12; // $v0
  int v13; // $v0
  _BYTE *v14; // $v0
  int v15; // $v0
  char *v16; // $v0
  int v18; // [sp+14h] [-84h]
  char v19[64]; // [sp+28h] [-70h] BYREF
  int v20; // [sp+68h] [-30h] BYREF
  int v21; // [sp+6Ch] [-2Ch]
  const char *v22; // [sp+78h] [-20h]
  const char *v23; // [sp+7Ch] [-1Ch]
  const char *v24; // [sp+80h] [-18h]
  char *v25; // [sp+84h] [-14h]
  int v26; // [sp+88h] [-10h]
  int *v27; // [sp+8Ch] [-Ch]
  int v28; // [sp+90h] [-8h]

  v4 = sq_file_get_max_wan();
  v5 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v5 >= a2 )
    v5 = a2 - 1;
  if ( v4 > 0 && v5 < a2 - 99 )
  {
    v22 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
    v6 = 0;
    v23 = "wan_pppoebr";
    v24 = "wan_increase";
    v25 = "1\"";
    do
    {
      v7 = jhl_nvget("wan_ifname", v6);
      v8 = (const char *)nvram_get(v7);
      if ( !v8 )
        v8 = v22 - 1556;
      if ( !*v8 )
        break;
      v9 = jhl_nvget("wan_down", v6);
      v10 = (const char *)nvram_get(v9);
      if ( v10 && !strcmp(v10, "1")
        || jhl_iface_link_up_check(v8, v6)
        || (v11 = jhl_nvget(v23, v6), (v12 = (_BYTE *)nvram_get(v11)) == 0)
        || !*v12
        || (strlcpy(v19, v12, 64), v27 = &v20, split_string(v19, 124, &v20, 2) < 2) )
      {
        if ( v4 == ++v6 )
          break;
      }
      else
      {
        v26 = J_atoi(v20);
        v28 = J_atoi(v21);
        v13 = jhl_nvget(v24, v26);
        v14 = (_BYTE *)nvram_get(v13);
        if ( v14 && *v14 && (strlcpy(v19, v14, 64), split_string(v19, 124, v27, 2) >= 2) )
          v18 = J_atoi(v21);
        else
          v18 = 0;
        v15 = snprintf(&a1[v5], a2 - v5, v25 - 15772, v6, v26, v18, v28);
        if ( v15 >= a2 - v5 )
          v15 = a2 - v5 - 1;
        ++v6;
        v5 += v15;
        if ( v4 == v6 )
          break;
      }
    }
    while ( v5 < a2 - 99 );
  }
  v16 = &a1[v5];
  if ( v5 > 0 && *(v16 - 1) == 44 )
    v16 = &a1[--v5];
  *(_WORD *)v16 = 93;
  return v5 + 1;
}
// 642A04: using guessed type __int16 word_642A04;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

