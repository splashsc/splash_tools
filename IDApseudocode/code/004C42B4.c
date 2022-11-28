int __fastcall sub_4C42B4(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  char *v4; // $s5
  int v5; // $s0
  int v6; // $a0
  int *v7; // $v1
  const char *v8; // $v0
  int v9; // $t0
  int v10; // $a3
  int v11; // $a2
  int v12; // $a1
  unsigned int v13; // $a2
  const char *v15; // $v0
  char v16[256]; // [sp+20h] [-19Ch] BYREF
  int v17[32]; // [sp+120h] [-9Ch] BYREF
  char v18[28]; // [sp+1A0h] [-1Ch] BYREF

  v3 = httpd_get_parm(a1, "n");
  v2 = httpd_get_parm(a1, "en");
  if ( v3 && (v4 = v2, (v5 = mrcl_ips_get_type(v3)) != 0) )
  {
    if ( v5 == 10 && nvram_match_def("drop_foreign_ip", "1") )
      v4 = "1";
    sprintf(v18, "%d", v5);
    sprintf(v16, "mrcl_%d_en", v5);
    v17[0] = (int)"wys";
    v17[1] = (int)"mrcl_en";
    v17[2] = (int)v18;
    v17[3] = (int)v3;
    v17[4] = (int)v4;
    v17[5] = 0;
    eval(v17, 0, 0, 0);
    nvram_set(v16, v4);
    jhl_parm_commit(v6);
    v7 = v17;
    v8 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v9 = *(_DWORD *)v8;
      v10 = *((_DWORD *)v8 + 1);
      v11 = *((_DWORD *)v8 + 2);
      v12 = *((_DWORD *)v8 + 3);
      v8 += 16;
      *v7 = v9;
      v7[1] = v10;
      v7[2] = v11;
      v7[3] = v12;
      v7 += 4;
    }
    while ( v8 != "}" );
    v13 = 33;
    *(_WORD *)v7 = *(_WORD *)v8;
  }
  else
  {
    v15 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
    v13 = snprintf((char *)v17, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v15);
    if ( v13 >= 0x80 )
      v13 = 127;
  }
  return httpd_cgi_ret(a1, (char *)v17, v13, 4);
}
// 4C43F4: variable 'v6' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

