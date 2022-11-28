int __fastcall sub_4856BC(int a1)
{
  char *v2; // $s3
  char *v3; // $v0
  char *v4; // $s2
  int v5; // $s4
  char *v6; // $v0
  const char *v7; // $s5
  char *v8; // $v0
  char *v9; // $fp
  int v10; // $s1
  int v11; // $a2
  int v12; // $a1
  int v13; // $a0
  int v14; // $v0
  void *v15; // $fp
  unsigned int v16; // $s4
  void *v17; // $a0
  uint32_t v19; // $a0
  signed int v20; // $s5
  unsigned __int8 *v21; // $s4
  char *v22; // $s6
  int v23; // $s7
  int v24; // $v0
  int v25; // $a0
  const char *v26; // $v0
  uint32_t v27; // $a0
  void *v28; // $v0
  uint32_t v29; // $a0
  uint32_t v30; // $v0
  int v31; // $a0
  int v32; // $s7
  const char *v33; // $v0
  int *v34; // $t1
  int i; // $t0
  unsigned int v36; // $a0
  int v37; // $a1
  char *v38; // $a1
  unsigned int v39; // $a0
  int v40; // $v0
  const char *v41; // $v0
  int v42; // $a2
  const char *v43; // $v0
  int v44; // $a1
  void *v45; // $v0
  signed int v46; // $s1
  int v47; // $a1
  int v48; // $t0
  int v49; // $v0
  int v50; // $v0
  int v51; // $t0
  int v52; // $v0
  ssize_t (__fastcall *v53)(char *, int, int, int, unsigned int, char *); // $t9
  int v54; // $v0
  int v55; // $t0
  int v56; // $v0
  int v57; // $a2
  int v58; // $v0
  unsigned int v59; // $s2
  void *v60; // $a0
  int v61; // $a0
  int v62; // $a2
  int v63; // $v0
  ssize_t v64; // $v0
  char v65[2048]; // [sp+28h] [-10B8h] BYREF
  int v66[257]; // [sp+828h] [-8B8h] BYREF
  char v67[1024]; // [sp+C2Ch] [-4B4h] BYREF
  char v68[128]; // [sp+102Ch] [-B4h] BYREF
  int v69[3]; // [sp+10ACh] [-34h] BYREF
  void *v70; // [sp+10B8h] [-28h]
  int v71; // [sp+10BCh] [-24h]
  int v72; // [sp+10C0h] [-20h]
  char *v73; // [sp+10C4h] [-1Ch]
  char *v74; // [sp+10C8h] [-18h]
  char *v75; // [sp+10CCh] [-14h]
  char *v76; // [sp+10D0h] [-10h]
  int v77; // [sp+10D4h] [-Ch]
  int v78; // [sp+10D8h] [-8h]

  strcpy(v68, "Error reading file");
  memset(&v68[19], 0, 0x6Du);
  v69[0] = 0;
  v69[1] = 0;
  v2 = httpd_get_parm(a1, "filename");
  v4 = httpd_get_parm(a1, "type");
  v3 = httpd_get_parm(a1, "md5");
  v5 = *(_DWORD *)(a1 + 205364);
  v7 = v3;
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( !v6 )
  {
    if ( debug_level > 0 )
    {
      printf("%s:%d %s:%d find_file_head err \n", "upfile_cgi", 1673);
LABEL_27:
      v15 = 0;
      v16 = 0;
      goto LABEL_10;
    }
LABEL_44:
    v15 = 0;
    v16 = 0;
    goto LABEL_10;
  }
  v9 = v6;
  v8 = find_file_end(a1, v6, *(_DWORD *)(a1 + 205564) + v5 - (_DWORD)v6);
  if ( !v8 )
  {
    if ( debug_level > 0 )
    {
      printf("%s:%d %s:%d find_file_end err \n", "upfile_cgi", 1680);
      goto LABEL_27;
    }
    goto LABEL_44;
  }
  v10 = v8 - v9;
  if ( v7 )
  {
    memset(v65, 0, 0x40u);
    getMD5Str(v9, v10, v65);
    if ( strcasecmp(v65, v7) )
    {
      if ( debug_level > 0 )
        printf("%s:%d %s:%d md5 error %s/%s \n", "upfile_cgi", 1691, "upfile_cgi", 1691, v7, v65);
      v12 = *(unsigned __int8 *)(a1 + 210102);
      v13 = 128;
      goto LABEL_8;
    }
  }
  if ( *v9 == 86 && v9[1] == 69 && v9[2] == 82 && v9[3] == 50 )
  {
    v27 = *((_DWORD *)v9 + 12);
    v72 = *((_DWORD *)v9 + 10);
    v20 = htonl(v27);
    v28 = (void *)htonl(*((_DWORD *)v9 + 14));
    v29 = *((_DWORD *)v9 + 15);
    v70 = v28;
    v30 = htonl(v29);
    v31 = (unsigned __int8)v9[75];
    v22 = v9 + 76;
    v21 = (unsigned __int8 *)(v9 + 36);
    v71 = v30;
    if ( v31 != 50 && !find_old_sq_exist(1) )
    {
      v14 = _GET_LANG_TEXT(50, *(unsigned __int8 *)(a1 + 210102), 1);
      goto LABEL_9;
    }
    v32 = (unsigned __int8)v9[73];
    v33 = (const char *)nvram_get("flash_enc_new");
    if ( v33 && !strcmp(v33, "1") && v32 != 1 )
    {
      v14 = _GET_LANG_TEXT(50, *(unsigned __int8 *)(a1 + 210102), 2);
      goto LABEL_9;
    }
    v23 = 76;
  }
  else
  {
    v70 = (void *)*((_DWORD *)v9 + 5);
    v19 = *((_DWORD *)v9 + 6);
    v72 = *((_DWORD *)v9 + 1);
    v20 = *((_DWORD *)v9 + 3);
    v21 = (unsigned __int8 *)v9;
    v22 = v9 + 40;
    v71 = htonl(v19);
    v23 = 40;
  }
  v24 = *v21;
  if ( v24 == 117 )
  {
    if ( v21[1] == 98 && v21[2] == 111 && v21[3] == 116 )
    {
      v72 = 123;
      goto LABEL_49;
    }
  }
  else if ( v24 == 97 && v21[1] == 114 && v21[2] == 116 && v21[3] == 49 )
  {
    v72 = 124;
    goto LABEL_49;
  }
  get_upfile_version_flag(v69);
  if ( __PAIR64__(v21[1], *v21) != __PAIR64__(BYTE1(v69[0]), LOBYTE(v69[0]))
    || __PAIR64__(v21[3], v21[2]) != __PAIR64__(HIBYTE(v69[0]), BYTE2(v69[0])) )
  {
    v14 = _GET_LANG_TEXT(42, *(unsigned __int8 *)(a1 + 210102), "1");
    goto LABEL_9;
  }
  if ( v72 != jhl_hardversion_get() )
  {
    v14 = _GET_LANG_TEXT(42, *(unsigned __int8 *)(a1 + 210102), "2");
    goto LABEL_9;
  }
  if ( v10 < 0x100000 )
  {
    v14 = _GET_LANG_TEXT(42, *(unsigned __int8 *)(a1 + 210102), "3");
    goto LABEL_9;
  }
  v72 = 0;
LABEL_49:
  if ( (char *)v70 + v20 + v23 != (void *)v10 )
  {
    v14 = _GET_LANG_TEXT(42, *(unsigned __int8 *)(a1 + 210102), "4");
    goto LABEL_9;
  }
  memset(v66, 0, sizeof(v66));
  v34 = &v66[256];
  for ( i = 255; i != -1; --i )
  {
    v36 = i;
    v37 = 8;
    do
    {
      while ( (v36 & 1) != 0 )
      {
        --v37;
        v36 = (v36 >> 1) ^ 0xEDB88320;
        if ( !v37 )
          goto LABEL_62;
      }
      --v37;
      v36 >>= 1;
    }
    while ( v37 );
LABEL_62:
    *v34-- = v36;
  }
  if ( v20 <= 0 )
  {
    v39 = 0;
  }
  else
  {
    v38 = v22;
    v39 = 0;
    do
    {
      v40 = *(_DWORD *)&v65[4 * (unsigned __int8)(*v38++ ^ v39) + 2052];
      v39 = (v39 >> 8) ^ v40;
    }
    while ( &v22[v20] != v38 );
    v66[0] = v39;
  }
  if ( v71 != v39 )
  {
    v14 = _GET_LANG_TEXT(42, *(unsigned __int8 *)(a1 + 210102), &unk_4D15F8);
    goto LABEL_9;
  }
  v73 = "a";
  v41 = (const char *)nvram_get("fw_upgrade_state");
  if ( v41 )
  {
    v70 = "a";
    if ( !strcmp(v41, "4") )
    {
      v12 = *(unsigned __int8 *)(a1 + 210102);
      v13 = 21;
LABEL_8:
      v14 = _GET_LANG_TEXT(v13, v12, v11);
LABEL_9:
      strlcpy(v68, v14, 128);
      v15 = 0;
      v16 = 0;
      goto LABEL_10;
    }
  }
  else
  {
    v70 = "a";
  }
  v76 = "a";
  unregister_signal();
  exec_service("jhttpd_check-stop");
  v43 = (const char *)_GET_LANG_TEXT(22, *(unsigned __int8 *)(a1 + 210102), v42);
  v16 = snprintf(v67, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v43);
  if ( v16 >= 0x400 )
    v16 = 1023;
  if ( !v72 )
  {
    v71 = (int)v65;
    memset(v65, 0, 0x40u);
    get_md5_str(v9, v10, v65);
    nvram_set("self_trx_md5", v71);
    nvram_set("ai_upgrade_flag", "1");
    nvram_commit();
  }
  nvram_set(v73 + 20068, (char *)v70 + 16640);
  if ( !v4 || J_atoi(v4) )
    prepare_upgrade();
  v74 = "1\"";
  _mem_malloc(0x10000, "upfile_cgi", 1914);
  v15 = v45;
  if ( v72 == 123 )
  {
    v64 = flash_Uboot_write(v22, v44, 0, 0, v20, v68);
  }
  else
  {
    if ( v72 != 124 )
    {
      if ( flash_Kernel_write(v22, v44, 0, 0, v20) != -2 )
      {
        v46 = v20;
        sync();
        sleep(1u);
        if ( v20 >= 65537 )
          v46 = 0x10000;
        if ( !v15 )
        {
LABEL_103:
          if ( !v72 )
            flash_erase_mtd("modules", 0, 0);
          goto LABEL_105;
        }
LABEL_85:
        if ( v46 > 0 )
        {
          v77 = 65537;
          v48 = 0;
          v71 = 0;
          v70 = v22;
          v75 = v68;
          while ( 1 )
          {
            v49 = v72;
            if ( v72 != 123 )
              goto LABEL_88;
            while ( 2 )
            {
              v78 = v48;
              flash_Uboot_read(v15, v47, v48, v71, v46);
              v52 = memcmp(v15, v70, v46);
              v51 = v78;
              if ( v52 )
              {
                v53 = flash_Uboot_write;
                goto LABEL_94;
              }
LABEL_90:
              v48 = v51 + v46;
              v46 = v20 - v48;
              if ( v20 - v48 < v77 )
              {
                if ( v46 <= 0 )
                  goto LABEL_103;
                v71 = v48 >> 31;
                v70 = &v22[v48];
              }
              else
              {
                v71 = v48 >> 31;
                v70 = &v22[v48];
                v49 = v72;
                v46 = 0x10000;
                if ( v72 == 123 )
                  continue;
LABEL_88:
                if ( v49 != 124 )
                {
                  v78 = v48;
                  flash_Kernel_read(v15, v47, v48, v71, v46);
                  v50 = memcmp(v15, v70, v46);
                  v51 = v78;
                  if ( v50 )
                  {
                    flash_Kernel_write((char *)v70, v47, v78, v71, v46);
                    v55 = v78;
                    goto LABEL_95;
                  }
                  goto LABEL_90;
                }
                v78 = v48;
                flash_art_read(v15, v47, v48, v71, v46);
                v56 = memcmp(v15, v70, v46);
                v51 = v78;
                if ( !v56 )
                  goto LABEL_90;
                v53 = flash_art_write;
LABEL_94:
                v78 = v51;
                v54 = v53((char *)v70, v47, v51, v71, v46, v75);
                v55 = v78;
                if ( v54 == -1 )
                  goto LABEL_121;
LABEL_95:
                v78 = v55;
                sync();
                v48 = v78;
              }
              break;
            }
          }
        }
        goto LABEL_103;
      }
      nvram_set(v73 + 20068, "0");
      v63 = _GET_LANG_TEXT(41, *(unsigned __int8 *)(a1 + 210102), v62);
      strlcpy(v68, v63, 128);
LABEL_10:
      v17 = *(void **)(a1 + 205564);
      if ( v17 )
      {
        _mem_free(v17);
        *(_DWORD *)(a1 + 205564) = 0;
      }
      if ( v68[0] )
      {
        register_signal();
        exec_service("jhttpd_check-start");
        upgrade_after(v25);
        if ( !v15 )
        {
LABEL_15:
          if ( v68[0] )
          {
            v26 = (const char *)_GET_LANG_TEXT(19, *(unsigned __int8 *)(a1 + 210102), v68);
            v16 = snprintf(v67, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v26);
            if ( v16 >= 0x400 )
              v16 = 1023;
          }
          return httpd_cgi_ret(a1, v67, v16, 4);
        }
      }
      else if ( !v15 )
      {
        return httpd_cgi_ret(a1, v67, v16, 4);
      }
      _mem_free(v15);
      goto LABEL_15;
    }
    v64 = flash_art_write(v22, v44, 0, 0, v20, v68);
  }
  if ( v64 == -1 )
  {
LABEL_121:
    nvram_set(v73 + 20068, "0");
    goto LABEL_10;
  }
  v46 = v20;
  sync();
  sleep(1u);
  if ( v20 >= 65537 )
    v46 = 0x10000;
  if ( v15 )
    goto LABEL_85;
LABEL_105:
  nvram_set(v73 + 20068, "0");
  v68[0] = 0;
  if ( !v4 || J_atoi(v4) )
  {
    jhl_gl_reboot_timer(2000);
    goto LABEL_10;
  }
  v58 = _GET_LANG_TEXT(18, *(unsigned __int8 *)(a1 + 210102), v57);
  v59 = snprintf(v65, 2048, v76 + 20316, v58);
  if ( v59 >= 0x800 )
    v59 = 2047;
  if ( v2 )
    nvram_set("upgrade_version_name", v2);
  v60 = *(void **)(a1 + 205564);
  if ( v60 )
  {
    _mem_free(v60);
    *(_DWORD *)(a1 + 205564) = 0;
  }
  if ( v15 )
    _mem_free(v15);
  register_signal();
  exec_service("jhttpd_check-start");
  upgrade_after(v61);
  return httpd_cgi_ret(a1, v65, v59, 4);
}
// 4857CC: variable 'v6' is possibly undefined
// 4858B4: variable 'v11' is possibly undefined
// 485AFC: variable 'v25' is possibly undefined
// 485F70: variable 'v42' is possibly undefined
// 486030: variable 'v45' is possibly undefined
// 486064: variable 'v44' is possibly undefined
// 486118: variable 'v47' is possibly undefined
// 48633C: variable 'v57' is possibly undefined
// 486434: variable 'v61' is possibly undefined
// 486504: variable 'v62' is possibly undefined
// 67D0BC: using guessed type int debug_level;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81C0: using guessed type int prepare_upgrade(void);
// 6A82C8: using guessed type int __fastcall get_upfile_version_flag(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A837C: using guessed type int __fastcall upgrade_after(_DWORD);
// 6A8394: using guessed type int jhl_hardversion_get(void);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8520: using guessed type int __fastcall get_md5_str(_DWORD, _DWORD, _DWORD);
// 6A8660: using guessed type int __fastcall getMD5Str(_DWORD, _DWORD, _DWORD);
// 6A87B4: using guessed type int __fastcall find_old_sq_exist(_DWORD);
// 6A87C4: using guessed type int nvram_commit(void);
// 6A883C: using guessed type int __fastcall flash_erase_mtd(_DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

