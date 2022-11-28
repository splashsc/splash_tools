int __fastcall wan_port_max_speed_get(int a1)
{
  void *v2; // $v0
  void *v3; // $s3
  int v4; // $v0
  int v5; // $s5
  _DWORD *v6; // $fp
  unsigned int v7; // $s4
  int v8; // $v0
  const char *v9; // $s7
  bool v10; // dc
  int v11; // $v0
  int result; // $v0
  int v13; // $s4
  int v14; // $v0
  int v15; // $v0
  int v16; // $v0
  int v17; // $a0
  int v18; // [sp+28h] [-8h]

  _mem_malloc(0x200000, "wan_port_max_speed_get", 108);
  if ( !v2 )
    return 0;
  v3 = v2;
  miitool_data_buf(v2, 0x200000);
  v4 = cJSON_Parse(v3);
  v5 = v4;
  if ( !v4 )
  {
    _mem_free(v3);
    return 0;
  }
  v6 = *(_DWORD **)(v4 + 8);
  v7 = 0;
  if ( v6 )
  {
    while ( 1 )
    {
      v8 = cJSON_GetObjectItem(v6, "n");
      if ( !v8 )
        goto LABEL_8;
      v9 = *(const char **)(v8 + 16);
      if ( !v9 )
        goto LABEL_8;
      v10 = strstr(*(const char **)(v8 + 16), (const char *)&off_645568) == 0;
      v11 = 1;
      if ( !v10 )
        goto LABEL_7;
      if ( !strstr(v9, (const char *)&off_64556C) && !strstr(v9, "2.5GE") )
        break;
      v14 = cJSON_GetObjectItem(v6, "wan");
      if ( !v14 )
        break;
      if ( (*(_DWORD *)(v14 + 20) != 0) == a1 )
      {
LABEL_19:
        v15 = cJSON_GetObjectItem(v6, "link");
        if ( v15 )
        {
          if ( *(_DWORD *)(v15 + 20) )
          {
            v16 = cJSON_GetObjectItem(v6, "state");
            if ( v16 )
            {
              v17 = *(_DWORD *)(v16 + 16);
              v18 = v16;
              if ( v17 )
              {
                if ( v7 < J_atoi(v17) )
                  v7 = J_atoi(*(_DWORD *)(v18 + 16));
              }
            }
          }
        }
      }
LABEL_8:
      v6 = (_DWORD *)*v6;
      if ( !v6 )
        goto LABEL_9;
    }
    v11 = 0;
LABEL_7:
    if ( v11 == a1 )
      goto LABEL_19;
    goto LABEL_8;
  }
LABEL_9:
  _mem_free(v3);
  cJSON_Delete(v5);
  if ( !v7 )
    return 0;
  result = 2;
  if ( v7 != 10 )
  {
    v10 = v7 == 100;
    v13 = v7 ^ 0x3E8;
    if ( v10 )
      result = 4;
    else
      result = 6 - (v13 == 0);
  }
  return result;
}
// 452CD4: variable 'v2' is possibly undefined
// 645568: using guessed type void *off_645568;
// 64556C: using guessed type void *off_64556C;
// 6A82D0: using guessed type int __fastcall miitool_data_buf(_DWORD, _DWORD);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

