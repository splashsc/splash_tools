int __fastcall sub_45FA4C(int a1)
{
  const char **v2; // $v1
  char **v3; // $v0
  char *v4; // $t0
  const char *v5; // $a3
  const char *v6; // $a2
  const char *v7; // $a1
  int v8; // $s0
  int v9; // $s0
  unsigned int v10; // $v0
  char v12[1024]; // [sp+18h] [-498h] BYREF
  _DWORD v13[25]; // [sp+418h] [-98h] BYREF
  const char *v14[9]; // [sp+47Ch] [-34h] BYREF
  int v15[4]; // [sp+4A0h] [-10h] BYREF

  memset(v13, 0, sizeof(v13));
  v2 = v14;
  v3 = off_670600;
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
  while ( v3 != (char **)&off_670620 );
  *v2 = *v3;
  v15[0] = 0;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  get_memory(v15);
  strcpy(v12, "{\"code\":0,\"error\":\"\",\"data\":{");
  if ( v15[0] >= 0x10000001u )
  {
    strcpy((char *)v13, "500000");
  }
  else if ( v15[0] >= 0x8000001u )
  {
    strcpy((char *)v13, "400000");
  }
  else if ( v15[0] >= 0x4000001u )
  {
    strcpy((char *)v13, "180000");
  }
  else
  {
    if ( v15[0] < 0x2000001u )
      v13[0] = 808464434;
    else
      v13[0] = 808464437;
    strcpy((char *)&v13[1], "0");
  }
  v8 = sprintf(&v12[29], "\"ct_max_def\":\"%s\",", (const char *)v13) + 29;
  v9 = v8 + get_nvarms(v14, (int)&v12[v8], 1024 - v8) - 1;
  v10 = snprintf(&v12[v9], 1024 - v9, "}}");
  if ( v10 >= 1024 - v9 )
    v10 = 1023 - v9;
  return httpd_cgi_ret(a1, v12, v10 + v9, 4);
}
// 642164: using guessed type __int16 word_642164;
// 670600: using guessed type char *off_670600[7];
// 670620: using guessed type void *off_670620;
// 6A85CC: using guessed type int __fastcall get_memory(_DWORD);

