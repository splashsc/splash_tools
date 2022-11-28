int __fastcall jhl_web_save_json_parm2(int a1, int a2, int a3, int a4)
{
  int v5; // $v0
  int v7; // $s0
  int v8; // $v0
  int v9; // $a1
  bool v10; // dc
  int result; // $v0
  const char *v12; // $s3
  const char *v13; // $v0

  v5 = httpd_get_json_parm(a1, a2);
  if ( !v5 )
    return 0;
  v7 = v5;
  if ( cJSON_IsNumber(v5) )
  {
    v8 = nvram_get_int(a3);
    v9 = *(_DWORD *)(v7 + 20);
    v10 = v8 == v9;
    result = 1;
    if ( !v10 )
    {
      if ( a4 == 1 )
      {
        nvram_set_int(a3, v9);
        result = 1;
      }
      return result;
    }
    return 0;
  }
  v10 = cJSON_IsString(v7) == 0;
  result = 0;
  if ( v10 )
    return result;
  v12 = *(const char **)(v7 + 16);
  if ( !strcmp(v12, "undefined") )
    return 0;
  v13 = (const char *)nvram_get(a3);
  if ( !v13 || (v10 = strcmp(v13, v12) == 0, result = 0, !v10) )
  {
    result = 1;
    if ( a4 == 1 )
    {
      nvram_set(a3, *(_DWORD *)(v7 + 16));
      result = 1;
    }
  }
  return result;
}
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8248: using guessed type int __fastcall cJSON_IsString(_DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A88F0: using guessed type int __fastcall cJSON_IsNumber(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

