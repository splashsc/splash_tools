int __fastcall httpd_formdata_parse(_DWORD *a1, _BYTE *a2, int a3)
{
  int result; // $v0
  int v6; // $a0
  int v7; // $v0
  int v8; // $v0
  _DWORD *v9; // $v1
  int v10; // $a1
  char *v11; // $v1
  int v12; // $v0

  if ( !a3 || (result = a1[8] & 0x8080000) != 0 )
  {
    if ( (a1[8] & 0x8000000) != 0 )
    {
      v6 = a1[12];
      if ( v6 )
      {
        cJSON_Delete(v6);
        a1[12] = 0;
      }
      v7 = cJSON_Parse(a2);
      a1[12] = v7;
      cJSON_NumberToString(v7);
      cJSON_CodeString(a1[12], _httpd_parm_do);
      result = httpd_check_parm_auth_xx((int)a1);
    }
    else
    {
      v8 = a1[13];
      v9 = a1 + 14;
      if ( v8 )
      {
        v8 = 0;
        do
        {
          ++v8;
          if ( !*v9 )
            break;
          ++v9;
        }
        while ( v8 != 127 );
      }
      a1[v8 + 13] = a2;
      if ( a2 && (v10 = (char)*a2, *a2) )
      {
        v11 = a2 + 1;
        while ( v8 != 127 )
        {
          if ( v10 == 38 )
          {
            ++v8;
            *(v11 - 1) = 0;
            a1[v8 + 13] = v11;
            v10 = *v11++;
            if ( !v10 )
              goto LABEL_20;
          }
          else
          {
            if ( !v11 )
              goto LABEL_20;
            v10 = *v11++;
            if ( !v10 )
              goto LABEL_20;
          }
        }
        v12 = 128;
      }
      else
      {
LABEL_20:
        v12 = v8 + 1;
      }
      a1[v12 + 13] = 0;
      result = httpd_check_parm_auth_xx((int)a1);
    }
  }
  return result;
}
// 6A8184: using guessed type int __fastcall cJSON_NumberToString(_DWORD);
// 6A844C: using guessed type int __fastcall cJSON_CodeString(_DWORD, _DWORD);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);

