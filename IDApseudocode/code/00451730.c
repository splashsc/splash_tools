int __fastcall speed_test_info_get(char *a1, int a2)
{
  unsigned int v4; // $v0
  int v5; // $s6
  char *v6; // $s1
  int v7; // $v0
  int v8; // $v1
  char *v9; // $s2
  int result; // $v0

  nvram_get_int("speed_test_upload");
  nvram_get_int("speed_test_download");
  v4 = nvram_get_int("speed_test_state") - 1;
  v5 = -1;
  if ( v4 < 5 )
    v5 = dword_6454D0[v4];
  v6 = (char *)nvram_get("speed_test_isp");
  if ( !v6 )
    v6 = "";
  v7 = nvram_get("speed_test_server");
  v9 = (char *)v7;
  if ( !v7 )
    v9 = "";
  result = snprintf(a1, a2, aCode0MsgOkData, "router", v6, v9, v7, v8, v7, v8, v5);
  if ( result >= a2 )
    result = a2 - 1;
  return result;
}
// 451904: variable 'v8' is possibly undefined
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

