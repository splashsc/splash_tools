char *__fastcall httpd_get_parm(int a1, char *a2)
{
  char *v2; // $v0
  int v3; // $t0
  int v4; // $a2
  char *v5; // $v1
  int v6; // $a3
  char *v7; // $v0
  char *v8; // $s0
  int v9; // $v0
  int v10; // $s0
  char *result; // $v0

  v2 = *(char **)(a1 + 52);
  v3 = a1 + 56;
  if ( v2 )
  {
    while ( 1 )
    {
      v4 = *v2;
      v5 = a2;
      v6 = *a2;
      if ( v6 == v4 )
      {
        v7 = v2 + 1;
        do
        {
          ++v5;
          v4 = *v7;
          v6 = *v5;
          ++v7;
        }
        while ( v4 == v6 );
        v2 = v7 - 1;
      }
      if ( !v6 )
      {
        v8 = v2 + 1;
        if ( v4 == 61 )
          break;
      }
      v3 += 4;
      v2 = *(char **)(v3 - 4);
      if ( !v2 )
        goto LABEL_9;
    }
    _httpd_parm_do(v2 + 1);
    result = v8;
  }
  else
  {
LABEL_9:
    v9 = httpd_get_json_parm(a1, (int)a2);
    v10 = v9;
    if ( v9 && cJSON_IsString(v9) )
      result = *(char **)(v10 + 16);
    else
      result = 0;
  }
  return result;
}
// 6A8248: using guessed type int __fastcall cJSON_IsString(_DWORD);

