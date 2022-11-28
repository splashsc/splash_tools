int __fastcall switch_reboot_auto_asp(int a1)
{
  int v2; // $v0
  int v3; // $s0
  _DWORD *v4; // $s0
  int i; // $s3
  int v6; // $s2
  _BYTE *v7; // $s1
  int v8; // $v0
  void (*v9)(void); // $t9
  char *v10; // $v1
  const char *v11; // $v0
  int v12; // $t1
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  char v17[1024]; // [sp+18h] [-400h] BYREF

  v3 = httpd_get_json_parm(a1, (int)"list");
  v2 = switch_reboot_auto_get();
  v4 = *(_DWORD **)(v3 + 8);
  for ( i = v2; v4; v4 = (_DWORD *)*v4 )
  {
    v6 = GetJSONItemValueAsString(v4, "sn");
    v7 = (_BYTE *)GetJSONItemValueAsString(v4, "time");
    v8 = cJSON_GetObjectItem(i, v6);
    v9 = (void (*)(void))&cJSON_SetValuestring;
    if ( *v7 )
    {
      if ( !v8 )
      {
        cJSON_AddStringToObject(i, v6, v7);
        continue;
      }
    }
    else
    {
      v9 = (void (*)(void))&cJSON_DetachItemFromObject;
      if ( !v8 )
        continue;
    }
    v9();
  }
  if ( switch_reboot_auto_set(i) )
    nvram_commit();
  cJSON_Delete(i);
  v10 = v17;
  v11 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v12 = *(_DWORD *)v11;
    v13 = *((_DWORD *)v11 + 1);
    v14 = *((_DWORD *)v11 + 2);
    v15 = *((_DWORD *)v11 + 3);
    v11 += 16;
    *(_DWORD *)v10 = v12;
    *((_DWORD *)v10 + 1) = v13;
    *((_DWORD *)v10 + 2) = v14;
    *((_DWORD *)v10 + 3) = v15;
    v10 += 16;
  }
  while ( v11 != "}" );
  *(_WORD *)v10 = *(_WORD *)v11;
  return httpd_cgi_ret(a1, v17, 33, 4);
}
// 6A83A8: using guessed type int __fastcall cJSON_AddStringToObject(_DWORD, _DWORD, _DWORD);
// 6A87C4: using guessed type int nvram_commit(void);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A887C: using guessed type int __fastcall GetJSONItemValueAsString(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

