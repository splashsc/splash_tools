int __fastcall sub_45D93C(int a1)
{
  int v2; // $v0
  void **v3; // $s5
  void **v4; // $s0
  const char *v5; // $s2
  const char *v6; // $s3
  const char *v7; // $s4
  const char *v8; // $v0
  int v9; // $s2
  unsigned int v10; // $v0
  char v12[1024]; // [sp+28h] [-524h] BYREF
  char v13[256]; // [sp+428h] [-124h] BYREF
  void **v14; // [sp+528h] [-24h] BYREF
  void **v15; // [sp+52Ch] [-20h]
  void **v16; // [sp+530h] [-1Ch]
  char *v17; // [sp+534h] [-18h]
  char *v18; // [sp+538h] [-14h]
  char *v19; // [sp+53Ch] [-10h]
  int v20; // [sp+540h] [-Ch]
  int v21; // [sp+544h] [-8h]

  v2 = jhl_nv_get_def("arp_sys");
  strlcpy(v13, v2, 256);
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  split_string(v13, 60, &v14, 6);
  if ( v14 )
  {
    v3 = v15;
    if ( v15 )
      goto LABEL_3;
  }
  else
  {
    v3 = v15;
    v14 = &off_63F984;
    if ( v15 )
    {
LABEL_3:
      v4 = v16;
      if ( v16 )
        goto LABEL_4;
      goto LABEL_14;
    }
  }
  v4 = v16;
  v3 = &off_63F984;
  v15 = &off_63F984;
  if ( v16 )
  {
LABEL_4:
    v5 = v17;
    if ( v17 )
      goto LABEL_5;
    goto LABEL_15;
  }
LABEL_14:
  v5 = v17;
  v4 = &off_63F984;
  v16 = &off_63F984;
  if ( v17 )
  {
LABEL_5:
    v6 = v18;
    if ( v18 )
      goto LABEL_6;
LABEL_16:
    v7 = v19;
    v6 = "0";
    v18 = "0";
    if ( v19 )
      goto LABEL_7;
    goto LABEL_17;
  }
LABEL_15:
  v6 = v18;
  v5 = "0";
  v17 = "0";
  if ( !v18 )
    goto LABEL_16;
LABEL_6:
  v7 = v19;
  if ( v19 )
    goto LABEL_7;
LABEL_17:
  v7 = "200";
  v19 = "200";
LABEL_7:
  strcpy(v12, "{\"code\":0,\"error\":\"\",\"data\":{");
  v8 = (const char *)nvram_get(&unk_646444);
  if ( !v8 )
    v8 = "";
  v9 = sprintf(
         &v12[29],
         "\"notify\":\"%s\",\"check\":\"%s\",\"notify_tm\":%s,\"check_tm\":%s,\"zn_jb\":%s,\"disonline\":%s",
         (const char *)v3,
         (const char *)v4,
         v5,
         v6,
         v7,
         v8)
     + 29;
  v10 = snprintf(&v12[v9], 1024 - v9, "}}");
  if ( v10 >= 1024 - v9 )
    v10 = 1023 - v9;
  return httpd_cgi_ret(a1, v12, v10 + v9, 4);
}
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

