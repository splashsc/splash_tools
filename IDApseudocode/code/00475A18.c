int __fastcall sub_475A18(int a1)
{
  char *v1; // $v0
  const char *v3; // $v0
  const char *v4; // $s1
  int v5; // $s1
  char *v6; // $s2
  const char *v7; // $v0
  char *v8; // $s2
  const char *v9; // $v0
  char *v10; // $s2
  const char *v11; // $v0
  char *v12; // $s2
  const char *v13; // $v0
  int v14; // $s2
  char *v15; // $s3
  const char *v16; // $v0
  char *v17; // $s3
  const char *v18; // $v0
  char *v19; // $s3
  const char *v20; // $v0
  char *v21; // $s3
  const char *v22; // $v0
  char *v23; // $s3
  const char *v24; // $v0
  int v25; // $a0
  char *v26; // $s3
  const char *v27; // $v0
  int v28; // $a0
  const char **v29; // $v1
  const char *v30; // $v0
  const char *v31; // $t0
  const char *v32; // $a3
  const char *v33; // $a2
  const char *v34; // $a1
  const char *v36; // $v0
  const char *v37; // [sp+18h] [-100h] BYREF
  const char *v38; // [sp+1Ch] [-FCh]
  char *v39; // [sp+20h] [-F8h]
  char *v40; // [sp+24h] [-F4h]
  char *v41; // [sp+28h] [-F0h]
  int v42; // [sp+2Ch] [-ECh]

  v1 = httpd_get_parm(a1, "en");
  if ( !v1 || (v4 = v1, (v3 = (const char *)nvram_get("rd_en")) != 0) && !strcmp(v3, v4) )
  {
    v5 = 0;
  }
  else
  {
    nvram_set("rd_en", v4);
    v5 = 1;
  }
  v6 = httpd_get_parm(a1, "auth");
  if ( v6 )
  {
    v7 = (const char *)nvram_get("rd_auth");
    if ( !v7 || strcmp(v7, v6) )
    {
      nvram_set("rd_auth", v6);
      ++v5;
    }
  }
  v8 = httpd_get_parm(a1, "acct");
  if ( v8 )
  {
    v9 = (const char *)nvram_get("rd_acct");
    if ( !v9 || strcmp(v9, v8) )
    {
      nvram_set("rd_acct", v8);
      ++v5;
    }
  }
  v10 = httpd_get_parm(a1, "key");
  if ( v10 )
  {
    v11 = (const char *)nvram_get("rd_key");
    if ( !v11 || strcmp(v11, v10) )
    {
      nvram_set("rd_key", v10);
      ++v5;
    }
  }
  v12 = httpd_get_parm(a1, "ip");
  if ( !v12 || (v13 = (const char *)nvram_get("rd_ip")) != 0 && !strcmp(v13, v12) )
  {
    v14 = 0;
  }
  else
  {
    nvram_set("rd_ip", v12);
    v14 = 1;
  }
  v15 = httpd_get_parm(a1, "dev");
  if ( v15 )
  {
    v16 = (const char *)nvram_get("rd_dev");
    if ( !v16 || strcmp(v16, v15) )
    {
      nvram_set("rd_dev", v15);
      ++v14;
    }
  }
  v17 = httpd_get_parm(a1, "id");
  if ( v17 )
  {
    v18 = (const char *)nvram_get("rd_id");
    if ( !v18 || strcmp(v18, v17) )
    {
      nvram_set("rd_id", v17);
      ++v5;
    }
  }
  v19 = httpd_get_parm(a1, (char *)&off_6489D8);
  if ( v19 )
  {
    v20 = (const char *)nvram_get("rd_coa");
    if ( !v20 || strcmp(v20, v19) )
    {
      nvram_set("rd_coa", v19);
      ++v5;
    }
  }
  v21 = httpd_get_parm(a1, "get_user");
  if ( v21 )
  {
    v22 = (const char *)nvram_get("rd_get_user");
    if ( !v22 || strcmp(v22, v21) )
    {
      nvram_set("rd_get_user", v21);
      ++v14;
    }
  }
  v23 = httpd_get_parm(a1, "auth_mode");
  if ( v23 )
  {
    v24 = (const char *)nvram_get(&unk_647E00);
    if ( !v24 || strcmp(v24, v23) )
    {
      nvram_set(&unk_647E00, v23);
      ++v14;
    }
  }
  v26 = httpd_get_parm(a1, "list");
  if ( !v26 || (v27 = (const char *)nvram_get("rd_list")) != 0 && !strcmp(v27, v26) )
  {
    if ( v5 )
    {
      jhl_parm_commit(v25);
      if ( !v14 )
        goto LABEL_45;
    }
    else
    {
      if ( !v14 )
        goto LABEL_46;
      jhl_parm_commit(v25);
    }
LABEL_52:
    v36 = (const char *)nvram_get("rd_en");
    if ( v36 && !strcmp(v36, "1") )
    {
      v38 = "radiusset";
      v37 = "wys";
      v39 = "2";
      v40 = (char *)jhl_nv_get_def("rd_get_user");
      v41 = (char *)jhl_nv_get_def(&unk_647E00);
      v42 = 0;
      eval(&v37, 0, 0, 0);
      if ( !v5 )
        goto LABEL_46;
    }
    else
    {
      v37 = "wys";
      v38 = "radiusset";
      v39 = "0";
      v40 = (char *)jhl_nv_get_def("rd_get_user");
      v41 = "0";
      v42 = 0;
      eval(&v37, 0, 0, 0);
      if ( !v5 )
        goto LABEL_46;
    }
    goto LABEL_45;
  }
  nvram_set("rd_list", v26);
  ++v5;
  jhl_parm_commit(v28);
  if ( v14 )
    goto LABEL_52;
LABEL_45:
  jhl_setwanxx();
  v38 = "user";
  v39 = "rd_down_all";
  v37 = "wys";
  v40 = "all";
  v41 = 0;
  eval(&v37, 0, 0, 0);
  sleep(1u);
  radius_server_start();
LABEL_46:
  v29 = &v37;
  v30 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v31 = *(const char **)v30;
    v32 = (const char *)*((_DWORD *)v30 + 1);
    v33 = (const char *)*((_DWORD *)v30 + 2);
    v34 = (const char *)*((_DWORD *)v30 + 3);
    v30 += 16;
    *v29 = v31;
    v29[1] = v32;
    v29[2] = v33;
    v29[3] = v34;
    v29 += 4;
  }
  while ( v30 != "}" );
  *(_WORD *)v29 = *(_WORD *)v30;
  return httpd_cgi_ret(a1, (char *)&v37, 33, 4);
}
// 475F48: variable 'v28' is possibly undefined
// 47608C: variable 'v25' is possibly undefined
// 6489D8: using guessed type void *off_6489D8;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82B8: using guessed type int jhl_setwanxx(void);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8814: using guessed type int radius_server_start(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

