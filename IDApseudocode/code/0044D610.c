int __fastcall sub_44D610(int a1)
{
  const char **v2; // $v1
  char **v3; // $v0
  char *v4; // $t0
  const char *v5; // $a3
  const char *v6; // $a2
  const char *v7; // $a1
  char *v8; // $v0
  char *v9; // $s3
  unsigned int v10; // $s0
  char *v11; // $a0
  unsigned int v12; // $s4
  unsigned int v13; // $v0
  int v14; // $s0
  unsigned int v15; // $v0
  int v16; // $s0
  unsigned int v17; // $v0
  int v18; // $s0
  unsigned int v19; // $v0
  int v20; // $a2
  char v22[10240]; // [sp+18h] [-282Ch] BYREF
  const char *v23[11]; // [sp+2818h] [-2Ch] BYREF

  memset(v22, 0, sizeof(v22));
  v2 = v23;
  v3 = off_66E300;
  do
  {
    v4 = *v3;
    v5 = v3[1];
    v6 = v3[2];
    v7 = v3[3];
    v3 += 4;
    *v2 = v4;
    v2[1] = v5;
    v2[2] = v6;
    v2[3] = v7;
    v2 += 4;
  }
  while ( v3 != (char **)&off_66E320 );
  *v2 = *v3;
  v8 = httpd_get_parm(a1, "callback");
  v9 = v8;
  if ( v8 )
  {
    v10 = snprintf(v22, 10240, "%s(", v8);
    if ( v10 >= 0x2800 )
      v10 = 10239;
    v11 = &v22[v10];
    v12 = 10240 - v10;
  }
  else
  {
    v12 = 10240;
    v11 = v22;
    v10 = 0;
  }
  v13 = snprintf(v11, v12, (char *)&word_642164);
  if ( v13 >= v12 )
    v13 = 10239 - v10;
  v14 = v13 + v10 + get_wan_nvarms(v23, &v22[v13 + v10], 10240 - (v13 + v10));
  v15 = snprintf(&v22[v14], 10240 - v14, "\"mitool_arr\":");
  if ( v15 >= 10240 - v14 )
    v15 = 10239 - v14;
  v16 = v15 + v14 + miitool_data_buf(&v22[v15 + v14], 10240 - (v15 + v14));
  v17 = snprintf(&v22[v16], 10240 - v16, "}");
  if ( v17 >= 10240 - v16 )
    v17 = 10239 - v16;
  v18 = v17 + v16;
  if ( v9 )
  {
    v19 = snprintf(&v22[v18], 10240 - v18, ")");
    v20 = v19 + v18;
    if ( v19 >= 10240 - v18 )
      v20 = 10239;
  }
  else
  {
    v20 = v18;
  }
  return httpd_cgi_ret(a1, v22, v20, 4);
}
// 642164: using guessed type __int16 word_642164;
// 66E300: using guessed type char *off_66E300[7];
// 66E320: using guessed type void *off_66E320;
// 6A82D0: using guessed type int __fastcall miitool_data_buf(_DWORD, _DWORD);

