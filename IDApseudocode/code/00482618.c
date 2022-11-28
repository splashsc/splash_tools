int __fastcall sub_482618(int a1)
{
  char *v2; // $s0
  char *v3; // $s1
  int v4; // $v0
  int v5; // $v0
  int v6; // $a2
  int v7; // $s0
  int v8; // $s1
  char *v9; // $v0
  unsigned int v10; // $v0
  unsigned int v11; // $s0
  unsigned int v12; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  const char *v16; // [sp+10h] [-22Ch]
  const char *v17; // [sp+10h] [-22Ch]
  char v18[512]; // [sp+20h] [-21Ch] BYREF
  const char *v19; // [sp+220h] [-1Ch] BYREF
  const char *v20; // [sp+224h] [-18h]
  char *v21; // [sp+228h] [-14h]
  char *v22; // [sp+22Ch] [-10h]
  int v23; // [sp+230h] [-Ch]

  v2 = httpd_get_parm(a1, "path");
  v3 = httpd_get_parm(a1, "type");
  strcpy(v18, "{\"code\":0,\"error\":\"\",\"data\":{");
  if ( v2 )
  {
    v4 = jiffies_get();
    mod_timer(a1 + 205540, v4 + 200000);
    if ( v3 && !strcmp(v3, "1") )
    {
      v19 = "wys";
      v20 = "version_upgrade";
      v21 = v2;
      v22 = "1";
      v23 = 0;
      eval(&v19, 0, 0, 0);
    }
    else
    {
      v19 = "wys";
      v20 = "version_upgrade";
      v21 = v2;
      v22 = "0";
      v23 = 0;
      eval(&v19, 0, 0, 0);
    }
    v5 = nvram_get("version_upgrade_state");
    v7 = J_atoi(v5);
    if ( v7 )
    {
      v8 = *(unsigned __int8 *)(a1 + 210102);
      v9 = (char *)nvram_get("version_upgrade_msg");
      if ( !v9 )
        v9 = "";
      v16 = (const char *)_GET_LANG_TEXT(19, v8, v9);
      v10 = snprintf(&v18[29], 483, "\"ret\":%d,\"msg\":\"%s\"", v7, v16);
    }
    else
    {
      v17 = (const char *)_GET_LANG_TEXT(18, *(unsigned __int8 *)(a1 + 210102), v6);
      v10 = snprintf(&v18[29], 483, "\"ret\":%d,\"msg\":\"%s\"", 0, v17);
    }
    if ( v10 < 0x1E3 )
      goto LABEL_10;
    goto LABEL_15;
  }
  v14 = (const char *)_GET_LANG_TEXT(17, *(unsigned __int8 *)(a1 + 210102), 1919906418);
  v15 = snprintf(&v18[29], 483, "\"ret\":1,\"msg\":\"%s\"", v14);
  v11 = v15 + 29;
  if ( v15 >= 0x1E3 )
  {
LABEL_15:
    v10 = 482;
LABEL_10:
    v11 = v10 + 29;
  }
  v12 = snprintf(&v18[v11], 512 - v11, "}}");
  if ( v12 >= 512 - v11 )
    v12 = 511 - v11;
  return httpd_cgi_ret(a1, v18, v12 + v11, 4);
}
// 4828EC: variable 'v6' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

