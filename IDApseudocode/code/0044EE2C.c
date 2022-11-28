bool __fastcall ai_is_running(int a1)
{
  _BOOL4 result; // $v0
  const char *v3; // $v0
  bool v4; // dc

  if ( !f_exists(&dword_641714) )
    return 0;
  v3 = (const char *)nvram_get("mqtt_ai_enable");
  if ( !v3 )
    return 0;
  v4 = strcmp(v3, "1") != 0;
  result = 0;
  if ( !v4 )
  {
    if ( a1 )
      result = nvram_get_int("wys_mqtt_ai_online") != 0;
    else
      result = 1;
  }
  return result;
}
// 641714: using guessed type int dword_641714;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);

