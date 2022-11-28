int __fastcall switch_reboot_auto_runing(_DWORD *a1)
{
  int v2; // $s6
  _DWORD *v3; // $s0
  int v4; // $s3
  char *v5; // $v0
  char *v6; // $fp
  int v7; // $a1
  int v8; // $v0
  const char *v9; // $a3
  unsigned int v10; // $v0
  int v11; // $s3
  unsigned int v13; // $v0
  char v14[4096]; // [sp+18h] [-1108h] BYREF
  char v15[256]; // [sp+1018h] [-108h] BYREF
  unsigned int v16; // [sp+1118h] [-8h]

  memset(v14, 0, sizeof(v14));
  memset(v15, 0, sizeof(v15));
  v2 = switch_reboot_auto_get();
  v3 = *(_DWORD **)(v2 + 8);
  strcpy(v14, "{\"sn\":[");
  if ( v3 )
  {
    v4 = 7;
    do
    {
      while ( 1 )
      {
        strlcpy(v15, v3[4], 256);
        v5 = strchr(v15, 59);
        v6 = v5;
        if ( v5 )
        {
          v7 = a1[6];
          *v5 = 0;
          is_in_wday(v15, v7);
          if ( v8 )
          {
            if ( is_in_time((int)(v6 + 1), a1[2], a1[1]) )
              break;
          }
        }
        v3 = (_DWORD *)*v3;
        if ( !v3 )
          goto LABEL_10;
      }
      v9 = (const char *)v3[8];
      v16 = 4096 - v4;
      v10 = snprintf(&v14[v4], 4096 - v4, "\"%s\",", v9);
      if ( v10 >= v16 )
        v10 = 4095 - v4;
      v3 = (_DWORD *)*v3;
      v4 += v10;
    }
    while ( v3 );
LABEL_10:
    v11 = v4 - 1;
  }
  else
  {
    v11 = 6;
  }
  if ( v14[v11] == 44 )
  {
    v13 = snprintf(&v14[v11], 4096 - v11, "]}");
    if ( v13 >= 4096 - v11 )
      v13 = 4095 - v11;
    ai_unix_cgi_send(0x272Cu, 0xFFFFFFFF, v14, v13 + v11);
  }
  return cJSON_Delete(v2);
}
// 4C909C: variable 'v8' is possibly undefined
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);

