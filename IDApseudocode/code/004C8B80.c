int switch_reboot_auto_get()
{
  int v0; // $v0
  int v1; // $v0
  int v2; // $s0
  bool v3; // dc
  int result; // $v0

  v0 = jhl_nv_get_def("mqtt_ai_switch_auto_reboot");
  v1 = cJSON_Parse(v0);
  v2 = v1;
  if ( !v1 || (v3 = cJSON_IsObject(v1) != 0, result = v2, !v3) )
  {
    cJSON_Delete(v2);
    result = cJSON_CreateObject();
  }
  return result;
}
// 6A822C: using guessed type int __fastcall cJSON_IsObject(_DWORD);
// 6A8258: using guessed type int cJSON_CreateObject(void);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);

