int __fastcall ai_read_upgrade_state(int a1, int a2)
{
  int v3; // $v0
  int v5; // $v0
  int v6; // $s0
  int v7; // $v0
  int v8; // $s1
  void *v9; // $a0
  int v10; // $s1

  v3 = f_read_json("/tmp/mqtt_ai_check_upgrade_state");
  if ( !v3 )
    return -1;
  v6 = v3;
  v5 = custom_device_name();
  v7 = cJSON_GetObjectItem(v6, v5);
  if ( v7 )
  {
    v8 = cJSON_PrintUnformatted(v7);
    strlcpy(a1, v8, a2);
    v9 = (void *)v8;
    v10 = 0;
    free(v9);
  }
  else
  {
    v10 = -1;
  }
  cJSON_Delete(v6);
  return v10;
}
// 6A8454: using guessed type int __fastcall f_read_json(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A85D0: using guessed type int __fastcall cJSON_PrintUnformatted(_DWORD);
// 6A86E4: using guessed type int custom_device_name(void);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

