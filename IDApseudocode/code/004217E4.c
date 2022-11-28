int __fastcall httpd_check_aitoken(int a1)
{
  char *v2; // $v0
  unsigned int v3; // $s3
  size_t v4; // $v0
  const char *v5; // $s0
  int v6; // $v0
  int v7; // $v0
  int v8; // $s1
  int v9; // $v0
  int v10; // $s2
  size_t v11; // $v0
  const time_t *v12; // $a0
  struct tm *v13; // $v0
  size_t v14; // $s2
  char *v15; // $v0
  int v16; // $s0
  char v18[2048]; // [sp+20h] [-C08h] BYREF
  char v19[1024]; // [sp+820h] [-408h] BYREF
  int v20; // [sp+C20h] [-8h]
  int v21; // [sp+C24h] [-4h] BYREF

  memset(v18, 0, sizeof(v18));
  memset(v19, 0, sizeof(v19));
  v3 = time(0);
  v2 = httpd_get_parm(a1, "aitoken");
  if ( !v2 )
    return -1;
  v5 = v2;
  v4 = strlen(v2);
  v6 = base64_decode(v5, v19, v4);
  ai_aes_cbc_decrypt(v19, v6, v18);
  v7 = cJSON_Parse(v18);
  v8 = v7;
  if ( !v7 )
    return -1;
  v9 = cJSON_GetObjectItem(v7, "expire_at");
  v10 = v9;
  if ( !v9 || v3 >= *(_DWORD *)(v9 + 20) )
    goto LABEL_11;
  v21 = 0;
  v20 = 0;
  if ( gl_httpd_high_admin_en )
  {
    if ( httpd_cgi_user_check(gl_httpd_high_admin, gl_httpd_high_adminpwd, &v21) > 0 )
      goto LABEL_7;
LABEL_11:
    v16 = -1;
    goto LABEL_8;
  }
  if ( httpd_cgi_user_check(gl_httpd_admin, gl_httpd_adminpwd, &v21) <= 0 )
    goto LABEL_11;
LABEL_7:
  v11 = strlen(httpd_set_cookie);
  v12 = (const time_t *)(v10 + 20);
  v14 = v11;
  v13 = gmtime(v12);
  v15 = asctime(v13);
  snprintf(&httpd_set_cookie[v14], 256 - v14, ",vue_aitoken=%s;expires=%s", v5, v15);
  v16 = 0;
  *(_DWORD *)(a1 + 36) |= 0x1000u;
LABEL_8:
  cJSON_Delete(v8);
  return v16;
}
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8670: using guessed type int __fastcall ai_aes_cbc_decrypt(_DWORD, _DWORD, _DWORD);
// 6A8780: using guessed type int __fastcall cJSON_Parse(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

