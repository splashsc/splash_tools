int __fastcall sub_45DBCC(int a1)
{
  char *v2; // $s3
  char *v3; // $s5
  char *v4; // $fp
  char *v5; // $s7
  int v6; // $v0
  char *v7; // $s6
  int v8; // $a0
  char *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  char v16[256]; // [sp+28h] [-1F0h] BYREF
  char v17[200]; // [sp+128h] [-F0h] BYREF
  void **v18; // [sp+1F0h] [-28h] BYREF
  void **v19; // [sp+1F4h] [-24h]
  void **v20; // [sp+1F8h] [-20h]
  char *v21; // [sp+1FCh] [-1Ch]
  char *v22; // [sp+200h] [-18h]
  char *v23; // [sp+204h] [-14h]
  int v24; // [sp+208h] [-10h]
  int v25; // [sp+20Ch] [-Ch]
  char *v26; // [sp+210h] [-8h]
  char *v27; // [sp+214h] [-4h]

  v2 = httpd_get_parm(a1, "arp_defense");
  v3 = httpd_get_parm(a1, "disonline");
  v27 = httpd_get_parm(a1, "notify");
  v4 = httpd_get_parm(a1, "notify_tm");
  v26 = httpd_get_parm(a1, "check");
  v5 = httpd_get_parm(a1, "check_tm");
  v7 = httpd_get_parm(a1, "zn_jb");
  v6 = jhl_nv_get_def("arp_sys");
  strlcpy(v16, v6, 256);
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  split_string(v16, 60, &v18, 6);
  if ( v18 )
  {
    if ( v19 )
      goto LABEL_3;
  }
  else
  {
    v18 = &off_63F984;
    if ( v19 )
    {
LABEL_3:
      if ( v20 )
        goto LABEL_4;
LABEL_29:
      v20 = &off_63F984;
      if ( v21 )
        goto LABEL_5;
      goto LABEL_30;
    }
  }
  v19 = &off_63F984;
  if ( !v20 )
    goto LABEL_29;
LABEL_4:
  if ( v21 )
    goto LABEL_5;
LABEL_30:
  v21 = "200";
LABEL_5:
  if ( !v22 )
    v22 = "10";
  if ( !v23 )
    v23 = "200";
  if ( v27 )
    v19 = (void **)v27;
  if ( v26 )
    v20 = (void **)v26;
  if ( v4 )
    v21 = v4;
  if ( v5 )
    v22 = v5;
  if ( v7 )
    v23 = v7;
  if ( v2 && !strcmp(v2, "disonline") )
  {
    if ( !v3 )
      v3 = "0";
    nvram_set(&unk_646444, v3);
    arp_st_disonline(v3);
  }
  sprintf(v17, "%s<%s<%s<%s<%s<%s", (const char *)v18, (const char *)v19, (const char *)v20, v21, v22, v23);
  nvram_set("arp_sys", v17);
  jhl_parm_commit(v8);
  start_arp_sys();
  v9 = v17;
  v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v11 = *(_DWORD *)v10;
    v12 = *((_DWORD *)v10 + 1);
    v13 = *((_DWORD *)v10 + 2);
    v14 = *((_DWORD *)v10 + 3);
    v10 += 16;
    *(_DWORD *)v9 = v11;
    *((_DWORD *)v9 + 1) = v12;
    *((_DWORD *)v9 + 2) = v13;
    *((_DWORD *)v9 + 3) = v14;
    v9 += 16;
  }
  while ( v10 != "}" );
  *(_WORD *)v9 = *(_WORD *)v10;
  return httpd_cgi_ret(a1, v17, 33, 4);
}
// 45DEA0: variable 'v8' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81EC: using guessed type int start_arp_sys(void);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A88CC: using guessed type int __fastcall arp_st_disonline(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

