int __fastcall sub_470BEC(int a1)
{
  char *v2; // $v0
  char *v3; // $s2
  char *v4; // $s3
  _BOOL4 v5; // $s4
  unsigned int v6; // $a2
  unsigned int v7; // $a0
  unsigned int v8; // $v1
  int v9; // $a2
  int v10; // $a1
  char *v11; // $a2
  int v12; // $a0
  const char *v13; // $v0
  int v14; // $a2
  int v16; // $a2
  int v17; // $v0
  int v18; // $a2
  int v19; // $v0
  const char *v20; // $v0
  _BOOL4 v21; // $v1
  int v22; // $v0
  int v23; // $v0
  char v24[2048]; // [sp+50h] [-125Ch] BYREF
  __int16 v25[512]; // [sp+850h] [-A5Ch] BYREF
  _QWORD v26[128]; // [sp+C50h] [-65Ch] BYREF
  __int16 v27[256]; // [sp+1050h] [-25Ch] BYREF
  char v28[64]; // [sp+1250h] [-5Ch] BYREF
  unsigned int v29; // [sp+1290h] [-1Ch] BYREF
  __int64 v30; // [sp+1294h] [-18h]
  __int64 v31; // [sp+129Ch] [-10h]

  v3 = httpd_get_parm(a1, "i");
  v2 = httpd_get_parm(a1, "u");
  if ( !v2 || !v3 )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = "not user or ipaddr";
    v12 = 12;
    goto LABEL_17;
  }
  v29 = 0;
  v30 = 0LL;
  v31 = 0LL;
  v4 = v2;
  if ( strchr(v3, 46) || strchr(v3, 58) )
    StrToIpaddr(v3, &v29);
  else
    LODWORD(v30) = J_atoi(v3);
  if ( !nvram_match_def("jf_en", "1") || (v5 = 1, !sq_file_get_state_new("wys_jf")) )
    v5 = nvram_match_def("billing_en", "1") != 0;
  memset(v26, 0, sizeof(v26));
  v26[0] = 0x40000000010LL;
  HIDWORD(v26[1]) = 22;
  v26[13] = v30;
  v26[14] = v31;
  v6 = *(_DWORD *)(a1 + 205468);
  v7 = *(_DWORD *)(a1 + 205472);
  v8 = *(_DWORD *)(a1 + 205476);
  v26[10] = *(_QWORD *)(a1 + 205460);
  v26[11] = __PAIR64__(v7, v6);
  v26[12] = __PAIR64__(v29, v8);
  strlcpy(&v26[2], v4, 64);
  if ( jianhl_order_opt_fun(v26, HIDWORD(v26[0]), v9) )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = "";
    v12 = 3;
    goto LABEL_17;
  }
  if ( LODWORD(v26[1]) )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    if ( LODWORD(v26[1]) >= 0x33 || (v11 = (char *)jhlret_err_str[LODWORD(v26[1])]) == 0 )
      v11 = "not find err!";
    v12 = 3;
    goto LABEL_17;
  }
  if ( LODWORD(v26[20]) != 17 )
  {
    sprintf((char *)v25, "%d", LODWORD(v26[20]));
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = (char *)v25;
    v12 = 3;
LABEL_17:
    v13 = (const char *)_GET_LANG_TEXT(v12, v10, v11);
    v14 = sprintf(v24, "{\"ret\":1,\"msg\":\"%s\"}", v13);
    return httpd_cgi_ret(a1, v24, v14, 4);
  }
  jhl_parm_get("rzglLx", v27, 512);
  if ( !LOBYTE(v27[0]) )
    v27[0] = 32;
  if ( HIDWORD(v26[19]) == 2 )
  {
    jhl_parm_get("rzglMsg", v25, 1024);
    if ( LOBYTE(v25[0]) )
      goto LABEL_27;
  }
  else if ( HIDWORD(v26[19]) == 1 )
  {
    v23 = _GET_LANG_TEXT(75, *(unsigned __int8 *)(a1 + 210102), v16);
    strlcpy(v25, v23, 1024);
    goto LABEL_27;
  }
  v25[0] = 32;
LABEL_27:
  v17 = _GET_LANG_TEXT(81, *(unsigned __int8 *)(a1 + 210102), v16);
  strlcpy(v28, v17, 64);
  check_client_is_or_not_mobile(a1);
  if ( v19 )
  {
    v22 = _GET_LANG_TEXT(82, *(unsigned __int8 *)(a1 + 210102), v18);
    strlcpy(v28, v22, 64);
  }
  v20 = (const char *)nvram_get("web_exit");
  if ( !v20 )
    v20 = "0";
  v21 = 1;
  if ( !v5 )
    v21 = LOBYTE(v26[21]) == 0;
  v14 = sprintf(
          v24,
          "{\"tm\":%u,\"up\":%u,\"down\":%u,\"zup\":%llu,\"zdown\":%llu,\"dtm\":%u,\"state\":%d,\"msg\":\"%s\",\"lx\":\"%"
          "s\",\"exit\":\"%s\",\"client_type\":\"%s\",\"dis_mod_pwd\":\"%d\",\"dis_contact_admin\":\"%d\",\"callAdmin\":\"1\"}",
          LODWORD(v26[15]),
          HIDWORD(v26[15]),
          LODWORD(v26[16]),
          v26[17],
          v26[18],
          LODWORD(v26[19]),
          HIDWORD(v26[20]),
          (const char *)v25,
          (const char *)v27,
          v20,
          v28,
          v21,
          0);
  return httpd_cgi_ret(a1, v24, v14, 4);
}
// 470DB4: variable 'v9' is possibly undefined
// 470FA4: variable 'v16' is possibly undefined
// 470FE4: variable 'v19' is possibly undefined
// 4710C0: variable 'v18' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8284: using guessed type int __fastcall StrToIpaddr(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8848: using guessed type int __fastcall sq_file_get_state_new(_DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

