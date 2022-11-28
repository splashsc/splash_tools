int __fastcall sdwan_id_init_get(int a1)
{
  int v1; // $v1
  int result; // $v0
  int v3; // $a0
  int v4; // $v0
  int v5; // $s0
  int v6; // $s0
  int v7; // $v0
  int v8; // $a0
  _WORD v9[51200]; // [sp+18h] [-19000h] BYREF

  if ( a1 == 1 )
  {
    v9[0] = 91;
    v5 = shared_get_sdwans_data((char *)v9 + 1, 102399) + 1;
    v6 = v5 + shared_get_sd_vpns_data((char *)v9 + v5, 102400 - v5);
    v7 = v6 + shared_get_sd_wans_data((char *)v9 + v6, 102400 - v6);
    v8 = v7 - 1;
    if ( *((_BYTE *)v9 + v7 - 1) != 44 )
      v8 = v7;
    snprintf((char *)v9 + v8, 102400 - v8, &byte_6445A0);
    dword_67D4E4 = cJSON_Parse(v9);
    result = 0xFFFF;
  }
  else if ( a1 == 2 )
  {
    if ( dword_67D4E4 )
    {
      cJSON_Delete(dword_67D4E4);
      dword_67D4E4 = 0;
    }
    dword_67D4E0 = 0;
    result = 0xFFFF;
  }
  else
  {
    if ( a1 || !dword_67D4E4 )
      goto LABEL_4;
    if ( !dword_67D4E0 || (v3 = *(_DWORD *)dword_67D4E0, (dword_67D4E0 = v3) == 0) )
    {
      v3 = *(_DWORD *)(dword_67D4E4 + 8);
      dword_67D4E0 = v3;
    }
    v4 = cJSON_GetObjectItem(v3, "id");
    if ( v4 )
      v1 = (unsigned __int16)cJSON_GetIntvalue(v4);
    else
LABEL_4:
      v1 = 0xFFFF;
    result = v1;
  }
  return result;
}
// 6445A0: using guessed type char byte_6445A0;
// 67D4E0: using guessed type int dword_67D4E0;
// 67D4E4: using guessed type int dword_67D4E4;
// 6A817C: using guessed type int __fastcall shared_get_sd_vpns_data(_DWORD, _DWORD);
// 6A8314: using guessed type int __fastcall shared_get_sd_wans_data(_DWORD, _DWORD);
// 6A8380: using guessed type int __fastcall shared_get_sdwans_data(_DWORD, _DWORD);
// 6A8744: using guessed type int __fastcall cJSON_GetIntvalue(_DWORD);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

