int __fastcall sub_48389C(int a1)
{
  char *v2; // $v0
  int v3; // $s2
  int v4; // $s5
  char *v5; // $v0
  char *v6; // $s4
  char *v7; // $v0
  int v8; // $a2
  char *v9; // $s1
  signed int v10; // $s2
  const char *v11; // $v0
  unsigned int v12; // $a2
  FILE *v14; // $v0
  FILE *v15; // $s5
  int v16; // $v0
  int v17; // $a0
  char *v18; // $v1
  const char *v19; // $v0
  int v20; // $t0
  int v21; // $a3
  int v22; // $a2
  int v23; // $a1
  int v24; // $a0
  char v25[1028]; // [sp+20h] [-404h] BYREF

  v3 = a1 + 196608;
  v2 = httpd_get_parm(a1, "time");
  v4 = *(_DWORD *)(v3 + 8756);
  v6 = v2;
  find_file_head(a1, *(const char **)(v3 + 8956));
  if ( v5 )
  {
    v9 = v5;
    v7 = find_file_end(a1, v5, *(_DWORD *)(v3 + 8956) + v4 - (_DWORD)v5);
    v10 = v7 - v9;
    if ( v7 )
    {
      if ( v10 >= 1024 )
      {
        v14 = fopen("/tmp/upgrade/upgrade_file", "w");
        v15 = v14;
        if ( v14 )
        {
          fwrite(v9, 1u, v10, v14);
          fclose(v15);
          v16 = jiffies_get();
          mod_timer(a1 + 205540, v16 + 100000);
          if ( !wayos_file_upgrade("/tmp/upgrade", "upgrade_file") )
          {
            if ( v6 )
              nvram_set("tzk_time", v6);
            nvram_set("tzk_state", "0");
            jhl_parm_commit(v17);
            nvram_set(&unk_649E44, "");
            v18 = v25;
            v19 = "{\"code\":0,\"error\":\"\",\"data\":null}";
            do
            {
              v20 = *(_DWORD *)v19;
              v21 = *((_DWORD *)v19 + 1);
              v22 = *((_DWORD *)v19 + 2);
              v23 = *((_DWORD *)v19 + 3);
              v19 += 16;
              *(_DWORD *)v18 = v20;
              *((_DWORD *)v18 + 1) = v21;
              *((_DWORD *)v18 + 2) = v22;
              *((_DWORD *)v18 + 3) = v23;
              v18 += 16;
            }
            while ( v19 != "}" );
            v12 = 33;
            *(_WORD *)v18 = *(_WORD *)v19;
            return httpd_cgi_ret(a1, v25, v12, 4);
          }
          nvram_set("tzk_state", "1");
          jhl_parm_commit(v24);
        }
      }
    }
    else
    {
      v8 = 572;
      if ( debug_level > 0 )
        printf("%s:%d find_file_end err \n", "upgrade_filter_cgi", 572);
    }
  }
  else
  {
    v8 = 565;
    if ( debug_level > 0 )
      printf("%s:%d find_file_head err  \n", "upgrade_filter_cgi", 565);
  }
  v11 = (const char *)_GET_LANG_TEXT(29, *(unsigned __int8 *)(a1 + 210102), v8);
  v12 = snprintf(v25, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
  if ( v12 >= 0x400 )
    v12 = 1023;
  return httpd_cgi_ret(a1, v25, v12, 4);
}
// 48390C: variable 'v5' is possibly undefined
// 483958: variable 'v8' is possibly undefined
// 483B1C: variable 'v17' is possibly undefined
// 483BFC: variable 'v24' is possibly undefined
// 67D0BC: using guessed type int debug_level;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8598: using guessed type int __fastcall wayos_file_upgrade(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

