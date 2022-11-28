int __fastcall httpd_check_parm_auth_xx(int a1)
{
  char *v2; // $s0
  char *v3; // $s1
  size_t v4; // $v0
  int *v5; // $s0
  int result; // $v0
  const char **v7; // $s2
  char *v8; // $v0
  int v9; // $v0
  int v10; // $a0
  size_t v11; // $v0
  int v12; // $s2
  int v13; // $s0
  unsigned __int8 v14; // $v0
  int v15; // $a0
  unsigned __int8 v16; // $s0
  const char *v17; // $s0
  bool v18; // dc
  char v19[256]; // [sp+20h] [-2C0h] BYREF
  char v20[128]; // [sp+120h] [-1C0h] BYREF
  char v21[128]; // [sp+1A0h] [-140h] BYREF
  char v22[128]; // [sp+220h] [-C0h] BYREF
  const char *v23; // [sp+2A0h] [-40h] BYREF
  int v24; // [sp+2A4h] [-3Ch]
  const char *v25; // [sp+2A8h] [-38h]
  const char *v26; // [sp+2ACh] [-34h]
  int v27; // [sp+2B0h] [-30h]
  int v28; // [sp+2B4h] [-2Ch]
  int v29; // [sp+2B8h] [-28h]
  int v30[6]; // [sp+2BCh] [-24h] BYREF
  int v31; // [sp+2D4h] [-Ch] BYREF
  char v32[4]; // [sp+2D8h] [-8h] BYREF
  char *v33; // [sp+2DCh] [-4h]

  v2 = httpd_get_parm(a1, "wt_wys_token");
  if ( v2 || (result = (int)httpd_get_parm(a1, "_wtoken"), (v2 = (char *)result) != 0) )
  {
    memset(v19, 0, sizeof(v19));
    memset(v22, 0, sizeof(v22));
    v30[0] = 0;
    v30[1] = 0;
    v30[2] = 0;
    v30[3] = 0;
    v30[4] = 0;
    v30[5] = 0;
    v31 = 0;
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    memset(v21, 0, sizeof(v21));
    v3 = v20;
    memset(v20, 0, sizeof(v20));
    v4 = strlen(v2);
    base64_decode(v2, v19, v4);
    v5 = v30;
    result = split_string(v19, 38, v30, 6) < 4;
    v7 = &v23;
    if ( !result )
    {
      do
      {
        split_string(*v5, 61, v32, 2);
        v8 = v33;
        ++v5;
        if ( !v33 )
          v8 = "";
        *v7++ = v8;
      }
      while ( &v31 != v5 );
      v9 = StrToIp(v27);
      v10 = v28;
      *(_DWORD *)(a1 + 205452) = v9;
      *(_WORD *)(a1 + 205448) = J_atoi(v10);
      sq_file_get_ssid_en(v22, 128);
      if ( !strcmp(v22, "no-ssid") )
        memset(v22, 0, sizeof(v22));
      sprintf(v21, "%s%s%s", v22, v25, v26);
      v11 = strlen(v21);
      getMD5Str(v21, v11, v20);
      v12 = v24;
LABEL_9:
      ++v12;
      while ( 1 )
      {
        result = *(unsigned __int8 *)(v12 - 1);
        v13 = (unsigned __int8)*v3++;
        if ( !*(_BYTE *)(v12 - 1) )
          break;
        if ( !*(v3 - 1) )
          return result;
        if ( result == v13 )
          goto LABEL_9;
        v14 = tolower(*(unsigned __int8 *)(v12 - 1));
        v15 = v13;
        v16 = v14;
        result = (unsigned __int8)tolower(v15);
        ++v12;
        if ( v16 != result )
          return result;
      }
      if ( !*(v3 - 1) )
      {
        v17 = v23;
        if ( !strcmp(v23, "vue") )
        {
          result = 1;
          *(_BYTE *)(a1 + 210100) = 1;
        }
        else
        {
          v18 = strcmp(v17, "wys_ai") != 0;
          result = 196608;
          if ( !v18 )
          {
            result = 2;
            *(_BYTE *)(a1 + 210100) = 2;
          }
        }
      }
    }
  }
  return result;
}
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A862C: using guessed type int __fastcall StrToIp(_DWORD);
// 6A8660: using guessed type int __fastcall getMD5Str(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8800: using guessed type int __fastcall sq_file_get_ssid_en(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

