int __fastcall sub_453A04(int a1)
{
  int v2; // $s3
  const char *v3; // $v0
  char *v4; // $s1
  unsigned int v5; // $s0
  int v6; // $v0
  int v7; // $s0
  unsigned int v8; // $s1
  unsigned int v9; // $v0
  char v11[2052]; // [sp+18h] [-804h] BYREF

  v2 = get_diagnosis_result();
  strcpy(v11, "{\"code\":0,\"error\":\"\",\"data\":");
  if ( v2 )
  {
    v3 = (const char *)cJSON_PrintUnformatted(v2);
    v4 = (char *)v3;
    if ( v3 )
    {
      v5 = snprintf(&v11[28], 2020, "%s", v3);
      free(v4);
      v6 = v5;
      if ( v5 >= 0x7E4 )
        v6 = 2019;
      v7 = v6 + 28;
      v8 = 2048 - (v6 + 28);
    }
    else
    {
      v8 = 2020;
      v7 = 28;
    }
    cJSON_Delete(v2);
  }
  else
  {
    v8 = 2020;
    v7 = 28;
  }
  v9 = snprintf(&v11[v7], v8, "}");
  if ( v9 >= v8 )
    v9 = 2047 - v7;
  return httpd_cgi_ret(a1, v11, v9 + v7, 4);
}
// 6A85D0: using guessed type int __fastcall cJSON_PrintUnformatted(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);

