int __fastcall fw_upgrade_timeout(int a1)
{
  int v2; // $s0
  int v3; // $v0
  bool v4; // dc
  int v5; // $v0
  int result; // $v0
  const char *v7; // $v0
  int v8; // $s2
  unsigned int v9; // $v0
  char *v10; // $v0
  int v11; // $a2
  int v12; // $s0
  int v13; // $a1
  int v14; // $a2
  int v15; // $a0
  char v16[1024]; // [sp+18h] [-414h] BYREF
  const char *v17; // [sp+418h] [-14h] BYREF
  void *v18; // [sp+41Ch] [-10h]
  int v19; // [sp+420h] [-Ch]
  int v20; // [sp+424h] [-8h]

  v2 = nvram_get_int("fw_upgrade_state");
  if ( v2 && v2 != 3 || (v3 = *(_DWORD *)(a1 + 205572), v4 = v3 >= 121, v5 = v3 + 1, v4) )
  {
    *(_DWORD *)(a1 + 205552) = httpd_keep_alive_timeout;
    *(_DWORD *)(a1 + 205548) = jiffies_get() + 5000;
    add_timer(a1 + 205540);
    strcpy(v16, "{\"code\":0,\"error\":\"\",\"data\":{");
    switch ( v2 )
    {
      case 0:
        v13 = *(unsigned __int8 *)(a1 + 210102);
        v14 = 0;
        v15 = 20;
        goto LABEL_15;
      case 1:
        v13 = *(unsigned __int8 *)(a1 + 210102);
        v14 = 1;
        v15 = 20;
        goto LABEL_15;
      case 2:
        v7 = (const char *)_GET_LANG_TEXT(22, *(unsigned __int8 *)(a1 + 210102), 572668450);
        goto LABEL_7;
      case 3:
        v7 = (const char *)_GET_LANG_TEXT(23, *(unsigned __int8 *)(a1 + 210102), 572668450);
        goto LABEL_7;
      case 4:
        v10 = httpd_get_parm(a1, "reboot_time");
        v12 = (int)v10;
        if ( v10 && strlen(v10) >= 3 )
        {
          v17 = "time_reboot_del.sh";
          v18 = &unk_649D2C;
          v19 = 0;
          eval(&v17, 0, 0, 0);
          v17 = "time_reboot_add.sh";
          v18 = &unk_649D2C;
          v19 = v12;
          v20 = 0;
          eval(&v17, 0, 0, 0);
        }
        v7 = (const char *)_GET_LANG_TEXT(24, *(unsigned __int8 *)(a1 + 210102), v11);
        goto LABEL_7;
      default:
        v13 = *(unsigned __int8 *)(a1 + 210102);
        v14 = v2;
        v15 = 25;
LABEL_15:
        v7 = (const char *)_GET_LANG_TEXT(v15, v13, v14);
LABEL_7:
        v8 = sprintf(&v16[29], "\"err\":\"%s\"", v7) + 29;
        v9 = snprintf(&v16[v8], 1024 - v8, "}}");
        if ( v9 >= 1024 - v8 )
          v9 = 1023 - v8;
        result = httpd_cgi_ret(a1, v16, v9 + v8, 4);
        break;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 205572) = v5;
    *(_DWORD *)(a1 + 205548) = jiffies_get() + 1000;
    *(_DWORD *)(a1 + 205556) = a1;
    *(_DWORD *)(a1 + 205552) = fw_upgrade_timeout;
    result = add_timer(a1 + 205540);
  }
  return result;
}
// 481904: variable 'v11' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

