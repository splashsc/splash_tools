int __fastcall httpd_get_json_parm(int a1, int a2)
{
  int v2; // $a0
  int result; // $v0

  v2 = *(_DWORD *)(a1 + 48);
  if ( v2 )
    result = cJSON_GetObjectItem(v2, a2);
  else
    result = 0;
  return result;
}
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

