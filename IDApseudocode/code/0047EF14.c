int __fastcall auth_html_upload_do_rcv(int a1)
{
  int v2; // $a2
  int v3; // $v0
  void *v4; // $a0
  char *v5; // $v0
  int v6; // $a1
  int v7; // $s5
  char *v8; // $s6
  const void *v9; // $s2
  void *v10; // $s5
  int v11; // $v0
  unsigned int v12; // $a2
  int v13; // $s6
  int v14; // $v0
  int v15; // $s6
  int v16; // $v1
  _BYTE *v17; // $a0
  _BYTE *v18; // $a1
  FILE *v19; // $a0
  FILE *v20; // $v0
  int v21; // $s0
  int v22; // $v0
  _BYTE *v23; // $a1
  _BYTE *v24; // $a0
  int v25; // $a2
  int v26; // $a1
  int v27; // $v0
  const void *v28; // $a0
  size_t v29; // $s0
  int v30; // $s4
  size_t v31; // $v0
  int v32; // $a0
  int v33; // $a1
  const char *v34; // $v0
  unsigned int v35; // $s0
  FILE *v36; // $a0
  void *v37; // $a0
  char *v38; // $a0
  int v39; // $a2
  FILE *v40; // $a0
  void *v41; // $a0
  int v42; // $a2
  int v43; // $a1
  const char *v44; // $v0
  int result; // $v0
  int v46; // $v0
  int v47; // $v0
  int v48; // $a1
  void *v49; // $s5
  int v50; // $v0
  int v51; // $s5
  int v52; // $v0
  _BYTE *v53; // $a0
  _BYTE *v54; // $v1
  FILE *v55; // $a0
  FILE *v56; // $v0
  int v57; // $v0
  _BYTE *v58; // $a1
  _BYTE *v59; // $a0
  int v60; // $a2
  _DWORD *v61; // $v0
  _DWORD *v62; // $v1
  _DWORD *v63; // $a0
  int v64; // $a1
  int v65; // $a3
  int v66; // $a2
  int v67; // $v1
  int v68; // $v0
  int v69; // $v0
  int v70; // $s0
  bool v71; // dc
  int v72; // $v0
  int v73; // $s6
  char v74[512]; // [sp+20h] [-280h] BYREF
  char v75[128]; // [sp+220h] [-80h] BYREF

  memset(v75, 0, sizeof(v75));
  memset(v74, 0, sizeof(v74));
  v3 = *(unsigned __int8 *)(a1 + 41);
  if ( !*(_BYTE *)(a1 + 41) )
  {
    v4 = *(void **)(a1 + 209700);
    if ( v4 )
    {
      _mem_free(v4);
      *(_DWORD *)(a1 + 209700) = 0;
    }
    *(_DWORD *)(a1 + 209704) = 0;
    _mem_malloc(102400, "auth_html_upload_do_rcv", 5575);
    *(_DWORD *)(a1 + 209700) = v5;
    if ( !v5 )
    {
      v34 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
      goto LABEL_31;
    }
    v6 = *(_DWORD *)(a1 + 205484);
    v7 = *(_DWORD *)(a1 + 205364) - v6;
    *(_DWORD *)(a1 + 209704) = v7;
    if ( v7 <= 0 )
    {
      v8 = v5;
    }
    else
    {
      memcpy(v5, (void *)(a1 + v6 + 564), v7);
      v8 = *(char **)(a1 + 209700);
      v7 = *(_DWORD *)(a1 + 209704);
    }
    v9 = (const void *)(a1 + 209708);
    *(_DWORD *)(a1 + 205560) = auth_html_upload_do_rcv;
    memset((void *)(a1 + 209708), 0, 0x80u);
    *(_DWORD *)(a1 + 209836) = 0;
    search_str(v8, v7, "\r\n", 2u);
    v10 = *(void **)(a1 + 209700);
    v12 = v11 - (_DWORD)v10;
    if ( v11 )
    {
      if ( v12 >= 0x7D )
      {
        v13 = 126;
        v12 = 124;
      }
      else
      {
        v13 = v12 + 2;
      }
      *(_BYTE *)(a1 + 209708) = 13;
      *(_BYTE *)(a1 + 209709) = 10;
      memcpy((void *)(a1 + 209710), v10, v12);
      *(_DWORD *)(a1 + 209836) = v13;
    }
    search_str((char *)v10, *(_DWORD *)(a1 + 209704), "filename=", 9u);
    v15 = v14;
    if ( !v14 )
      goto LABEL_79;
    memset((void *)(a1 + 209840), 0, 0x80u);
    v16 = *(unsigned __int8 *)(v15 + 10);
    if ( *(_BYTE *)(v15 + 10) )
    {
      v17 = (_BYTE *)(a1 + 209840);
      if ( v16 != 34 )
      {
        v18 = (_BYTE *)(v15 + 10);
        do
        {
          *v17 = v16;
          v16 = (unsigned __int8)*++v18;
          ++v17;
        }
        while ( *v18 && v18 != (_BYTE *)(v15 + 137) && v16 != 34 );
      }
    }
    strcpy(v74, "/tmp/auth_html_tmp/auth.tar.gz");
    create_dir2(v74);
    v19 = *(FILE **)(a1 + 209696);
    if ( v19 )
    {
      fclose(v19);
      *(_DWORD *)(a1 + 209696) = 0;
    }
    v20 = fopen(v74, "wb");
    v21 = a1 + 196608;
    *(_DWORD *)(a1 + 209696) = v20;
    if ( v20 )
    {
      search_str((char *)(v15 + 10), *(_DWORD *)(a1 + 209704) - (v15 + 10 - *(_DWORD *)(a1 + 209700)), "\r\n\r\n", 4u);
      v23 = (_BYTE *)(v22 + 4);
      if ( v22 )
      {
        v24 = *(_BYTE **)(a1 + 209700);
        v25 = *(_DWORD *)(a1 + 209704) - (v23 - v24);
        *(_DWORD *)(a1 + 209704) = v25;
        memmove(v24, v23, v25);
        *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
        *(_BYTE *)(a1 + 41) = 8;
        v26 = *(_DWORD *)(a1 + 209704);
LABEL_23:
        search_str(*(char **)(a1 + 209700), v26, v9, *(_DWORD *)(a1 + 209836));
        if ( v27 )
        {
          v28 = *(const void **)(a1 + 209700);
          v29 = v27 - (_DWORD)v28;
          v30 = 1;
          if ( v27 - (int)v28 <= 0 )
            goto LABEL_39;
        }
        else
        {
          v69 = *(_DWORD *)(a1 + 209704);
          v70 = *(_DWORD *)(a1 + 209836);
          v71 = v70 >= v69;
          v29 = v69 - v70;
          if ( v71 )
            goto LABEL_78;
          v28 = *(const void **)(a1 + 209700);
          v30 = 0;
        }
        v31 = fwrite(v28, 1u, v29, *(FILE **)(a1 + 209696));
        v32 = 141;
        if ( v31 != v29 )
        {
          v33 = *(unsigned __int8 *)(a1 + 210102);
LABEL_30:
          v34 = (const char *)_GET_LANG_TEXT(v32, v33, v2);
LABEL_31:
          v35 = snprintf(v75, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v34);
          if ( v35 >= 0x80 )
            v35 = 127;
          v36 = *(FILE **)(a1 + 209696);
          if ( v36 )
          {
            fclose(v36);
            *(_DWORD *)(a1 + 209696) = 0;
          }
          v37 = *(void **)(a1 + 209700);
          if ( v37 )
          {
            _mem_free(v37);
            *(_DWORD *)(a1 + 209700) = 0;
          }
          *(_DWORD *)(a1 + 209704) = 0;
LABEL_47:
          system("rm -rf /tmp/auth_html_tmp");
          httpd_release_caches();
          sync();
          return httpd_cgi_ret(a1, v75, v35, 4);
        }
        fflush(*(FILE **)(a1 + 209696));
        v38 = *(char **)(a1 + 209700);
        v39 = *(_DWORD *)(a1 + 209704) - v29;
        *(_DWORD *)(a1 + 209704) = v39;
        memmove(v38, &v38[v29], v39);
        *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
        if ( v30 )
        {
LABEL_39:
          v40 = *(FILE **)(a1 + 209696);
          if ( v40 )
          {
            fclose(v40);
            *(_DWORD *)(a1 + 209696) = 0;
          }
          v41 = *(void **)(a1 + 209700);
          v42 = 5856;
          if ( v41 )
          {
            _mem_free(v41);
            *(_DWORD *)(a1 + 209700) = 0;
          }
          v43 = *(unsigned __int8 *)(a1 + 210102);
          *(_DWORD *)(a1 + 209704) = 0;
          v44 = (const char *)_GET_LANG_TEXT(34, v43, v42);
          v35 = snprintf(v75, 128, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v44);
          if ( v35 >= 0x80 )
            v35 = 127;
          system("rm -rf /tmp/auth_html");
          system("mkdir -p /tmp/auth_html");
          system("tar -zxf /tmp/auth_html_tmp/auth.tar.gz -C /tmp/auth_html");
          if ( check_usb_state() )
          {
            system("mkdir -p /tmp/mnt/sda1/auth_html/");
            system("mv -f /tmp/auth_html_tmp/auth.tar.gz /tmp/mnt/sda1/auth_html/auth.tar.gz");
          }
          goto LABEL_47;
        }
LABEL_78:
        v68 = jiffies_get();
        mod_timer(a1 + 205540, v68 + 30000);
        return 0;
      }
LABEL_79:
      *(_BYTE *)(a1 + 41) = 7;
      goto LABEL_78;
    }
LABEL_80:
    v33 = *(unsigned __int8 *)(v21 + 13494);
    v32 = 139;
    goto LABEL_30;
  }
  if ( v3 == 7 )
  {
    if ( *(_DWORD *)(a1 + 209984) )
    {
      v47 = https_ssl_read(a1);
      if ( v47 == -2 )
      {
        v48 = *(_DWORD *)(a1 + 209704);
        goto LABEL_60;
      }
    }
    else
    {
      v47 = recv(
              *(_DWORD *)(a1 + 205416),
              (void *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)),
              102400 - *(_DWORD *)(a1 + 209704),
              0);
    }
    if ( v47 <= 0 )
    {
      v33 = *(unsigned __int8 *)(a1 + 210102);
      v32 = 140;
      goto LABEL_30;
    }
    v48 = v47 + *(_DWORD *)(a1 + 209704);
    *(_DWORD *)(a1 + 209704) = v48;
LABEL_60:
    if ( *(_DWORD *)(a1 + 209836) )
    {
      v49 = *(void **)(a1 + 209700);
    }
    else
    {
      search_str(*(char **)(a1 + 209700), v48, "\r\n", 2u);
      v49 = *(void **)(a1 + 209700);
      v73 = v72 - (_DWORD)v49;
      if ( v72 )
      {
        *(_BYTE *)(a1 + 209708) = 13;
        *(_BYTE *)(a1 + 209709) = 10;
        memcpy((void *)(a1 + 209710), v49, v73);
        v48 = *(_DWORD *)(a1 + 209704);
        *(_DWORD *)(a1 + 209836) = v73 + 2;
      }
      else
      {
        v48 = *(_DWORD *)(a1 + 209704);
      }
    }
    search_str((char *)v49, v48, "filename=", 9u);
    v51 = v50;
    if ( v50 )
    {
      memset((void *)(a1 + 209840), 0, 0x80u);
      v52 = *(unsigned __int8 *)(v51 + 10);
      if ( *(_BYTE *)(v51 + 10) )
      {
        v53 = (_BYTE *)(a1 + 209840);
        if ( v52 != 34 )
        {
          v54 = (_BYTE *)(v51 + 10);
          do
          {
            *v53 = v52;
            v52 = (unsigned __int8)*++v54;
            ++v53;
          }
          while ( *v54 && (_BYTE *)(v51 + 137) != v54 && v52 != 34 );
        }
      }
      strcpy(v74, "/tmp/auth_html_tmp/auth.tar.gz");
      create_dir2(v74);
      v55 = *(FILE **)(a1 + 209696);
      if ( v55 )
      {
        fclose(v55);
        *(_DWORD *)(a1 + 209696) = 0;
      }
      v56 = fopen(v74, "wb");
      v21 = a1 + 196608;
      *(_DWORD *)(a1 + 209696) = v56;
      if ( !v56 )
        goto LABEL_80;
      search_str((char *)(v51 + 10), *(_DWORD *)(a1 + 209704) - (v51 + 10 - *(_DWORD *)(a1 + 209700)), "\r\n\r\n", 4u);
      v58 = (_BYTE *)(v57 + 4);
      if ( v57 )
      {
        v59 = *(_BYTE **)(a1 + 209700);
        v60 = *(_DWORD *)(a1 + 209704) - (v58 - v59);
        *(_DWORD *)(a1 + 209704) = v60;
        memmove(v59, v58, v60);
        *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
        *(_BYTE *)(a1 + 41) = 8;
        v26 = *(_DWORD *)(a1 + 209704);
        v9 = (const void *)(a1 + 209708);
        goto LABEL_23;
      }
    }
    if ( *(_DWORD *)(a1 + 209704) == 102400 )
    {
      v61 = *(_DWORD **)(a1 + 209700);
      v62 = v61 + 12800;
      v63 = v61 + 25600;
      do
      {
        v64 = v62[3];
        v65 = v62[1];
        v66 = v62[2];
        *v61 = *v62;
        v61[1] = v65;
        v61[2] = v66;
        v62 += 4;
        v61[3] = v64;
        v61 += 4;
      }
      while ( v62 != v63 );
      v67 = *(_DWORD *)(a1 + 209700) + 0x10000;
      *(_DWORD *)(a1 + 209704) = 51200;
      *(_BYTE *)(v67 - 14336) = 0;
    }
    goto LABEL_78;
  }
  if ( v3 != 8 )
  {
    v33 = *(unsigned __int8 *)(a1 + 210102);
    v32 = 13;
    goto LABEL_30;
  }
  if ( *(_DWORD *)(a1 + 209984) )
  {
    v46 = https_ssl_read(a1);
    if ( v46 == -2 )
    {
      v26 = *(_DWORD *)(a1 + 209704);
      v9 = (const void *)(a1 + 209708);
      goto LABEL_23;
    }
    if ( v46 >= 0 )
    {
      if ( v46 )
      {
LABEL_55:
        v26 = v46 + *(_DWORD *)(a1 + 209704);
        *(_DWORD *)(a1 + 209704) = v26;
        v9 = (const void *)(a1 + 209708);
        goto LABEL_23;
      }
LABEL_86:
      v33 = *(unsigned __int8 *)(a1 + 210102);
      v32 = 140;
      goto LABEL_30;
    }
  }
  else
  {
    v46 = recv(
            *(_DWORD *)(a1 + 205416),
            (void *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)),
            102400 - *(_DWORD *)(a1 + 209704),
            0);
    if ( v46 )
    {
      if ( v46 > 0 )
        goto LABEL_55;
      goto LABEL_86;
    }
  }
  result = 0;
  if ( !*(_BYTE *)(a1 + 210101) )
    goto LABEL_86;
  return result;
}
// 47EFEC: variable 'v5' is possibly undefined
// 47F088: variable 'v11' is possibly undefined
// 47F0FC: variable 'v14' is possibly undefined
// 47F254: variable 'v22' is possibly undefined
// 47F2B4: variable 'v27' is possibly undefined
// 47F328: variable 'v2' is possibly undefined
// 47F4AC: variable 'v42' is possibly undefined
// 47F6F4: variable 'v50' is possibly undefined
// 47F850: variable 'v57' is possibly undefined
// 47FA74: variable 'v72' is possibly undefined
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8584: using guessed type int __fastcall create_dir2(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A88E0: using guessed type int check_usb_state(void);

