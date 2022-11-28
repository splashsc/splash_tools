int __fastcall switch_reboot_auto_set(int a1)
{
  int v1; // $v0
  const char *v2; // $v0
  const char *v3; // $s0
  int v4; // $s1

  v1 = cJSON_PrintUnformatted(a1);
  if ( !v1 )
    return 0;
  v3 = (const char *)v1;
  v2 = (const char *)nvram_get("mqtt_ai_switch_auto_reboot");
  if ( v2 && !strcmp(v2, v3) )
  {
    v4 = 0;
  }
  else
  {
    nvram_set("mqtt_ai_switch_auto_reboot", v3);
    v4 = 1;
  }
  cJSON_free(v3);
  return v4;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8324: using guessed type int __fastcall cJSON_free(_DWORD);
// 6A85D0: using guessed type int __fastcall cJSON_PrintUnformatted(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

