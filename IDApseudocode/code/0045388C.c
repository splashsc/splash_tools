int auto_diagnosis_timer_fun()
{
  int v0; // $v0
  int v1; // $s1
  int v2; // $v0
  int v4; // $v0
  int v5; // $v0

  v0 = nvram_get_int("vue_health_checking");
  v1 = v0;
  if ( v0 )
  {
    if ( v0 >= 15 || nvram_get_int("vue_health_score") >= 100 )
    {
      nvram_set("vue_health_checking", "0");
      v2 = jiffies_get();
      return mod_timer(&gl_auto_diagnosis_timer, v2 + 3600000);
    }
    v4 = get_diagnosis_result();
    cJSON_Delete(v4);
    nvram_set_int("vue_health_checking", v1 + 1);
  }
  else
  {
    nvram_set("vue_health_checking", "1");
    start_diagnosis();
  }
  v5 = jiffies_get();
  return mod_timer(&gl_auto_diagnosis_timer, v5 + 1000);
}
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

