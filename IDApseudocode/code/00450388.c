int __fastcall sub_450388(int a1)
{
  time_t v1; // $v0
  const char *v2; // $v0
  const char *v3; // $v0
  size_t v4; // $v0
  const char **v5; // $fp
  int v6; // $s7
  unsigned int v7; // $v0
  size_t v8; // $v0
  const char *v9; // $s1
  int v10; // $v0
  unsigned int v11; // $v0
  int v12; // $s0
  unsigned int v13; // $s2
  char v15[1024]; // [sp+30h] [-650h] BYREF
  char v16[256]; // [sp+430h] [-250h] BYREF
  char v17[128]; // [sp+530h] [-150h] BYREF
  char v18[64]; // [sp+5B0h] [-D0h] BYREF
  char v19[64]; // [sp+5F0h] [-90h] BYREF
  int v20[8]; // [sp+630h] [-50h] BYREF
  int v21[5]; // [sp+650h] [-30h] BYREF
  char *v22; // [sp+664h] [-1Ch] BYREF
  const char *v23; // [sp+668h] [-18h]
  char *v24; // [sp+66Ch] [-14h]
  _BOOL4 v25; // [sp+670h] [-10h]
  char *v26; // [sp+674h] [-Ch]
  const char *v27; // [sp+678h] [-8h]
  char *v28; // [sp+67Ch] [-4h]

  v28 = v19;
  memset(v19, 0, sizeof(v19));
  memset(v18, 0, sizeof(v18));
  v26 = v17;
  memset(v17, 0, sizeof(v17));
  v20[0] = 0;
  v20[1] = 0;
  v20[2] = 0;
  v20[3] = 0;
  v20[4] = 0;
  v20[5] = 0;
  v20[6] = 0;
  v20[7] = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  memset(v16, 0, sizeof(v16));
  v21[0] = 0;
  v21[1] = 0;
  v21[2] = 0;
  v21[3] = 0;
  v21[4] = 0;
  v25 = ai_is_running(1);
  v1 = time(0);
  snprintf(v19, 64, "%u", v1);
  v2 = (const char *)get_sn();
  snprintf(v18, 64, "%s", v2);
  v27 = (const char *)v20;
  v3 = (const char *)get_nonce();
  snprintf((char *)v20, 32, "%s", v3);
  v22 = v19;
  v23 = (const char *)v20;
  v24 = v18;
  params_sort(&v22, 3);
  snprintf(v16, 256, "%s%s%s", v22, v23, v24);
  v4 = strlen(v16);
  SHA1(v16, v4, v21);
  v5 = (const char **)v21;
  v6 = 0;
  do
  {
    v7 = snprintf(&v16[v6], 256 - v6, "%02x", *(unsigned __int8 *)v5);
    v5 = (const char **)((char *)v5 + 1);
    if ( v7 >= 256 - v6 )
      v7 = 255 - v6;
    v6 += v7;
  }
  while ( &v22 != (char **)v5 );
  v8 = strlen(v18);
  v9 = v26;
  base64_encode(v18, v26, v8);
  strcpy(v15, "{\"code\":0,\"error\":\"\",\"data\":{");
  v10 = check_net();
  v11 = snprintf(
          &v15[29],
          995,
          "\"sn\":\"%s\",\"timestamp\":\"%s\",\"nonce\":\"%s\",\"signature\":\"%s\",\"network\":%d,\"ai_en\":%d",
          v9,
          v28,
          v27,
          v16,
          v10,
          v25);
  v12 = v11 + 29;
  if ( v11 >= 0x3E3 )
    v12 = 1023;
  v13 = snprintf(&v15[v12], 1024 - v12, "}}");
  if ( v13 >= 1024 - v12 )
    v13 = 1023 - v12;
  nvram_set("ai_qrcode_nonce_state", "0");
  return httpd_cgi_ret(a1, v15, v13 + v12, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81D8: using guessed type int get_sn(void);
// 6A8364: using guessed type int __fastcall SHA1(_DWORD, _DWORD, _DWORD);
// 6A8474: using guessed type int __fastcall base64_encode(_DWORD, _DWORD, _DWORD);
// 6A87B8: using guessed type int __fastcall params_sort(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

