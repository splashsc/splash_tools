int __fastcall usb_upload_do_rcv2(int a1)
{
  char *v2; // $s1
  int v3; // $a2
  char *v4; // $s6
  char *v5; // $v0
  const char *v6; // $s2
  int v7; // $v0
  void *v8; // $a0
  char *v9; // $v0
  int v10; // $a1
  int v11; // $s7
  char *v12; // $fp
  const void *v13; // $s4
  void *v14; // $s7
  int v15; // $v0
  unsigned int v16; // $a2
  int v17; // $fp
  int v18; // $v0
  int v19; // $fp
  const char *v20; // $s1
  int v21; // $v1
  char *v22; // $s7
  _BYTE *v23; // $a1
  _BYTE *v24; // $a0
  FILE *v25; // $a0
  FILE *v26; // $v0
  int v27; // $a2
  int v28; // $a1
  char *v29; // $v0
  int v30; // $v0
  _BYTE *v31; // $a1
  _BYTE *v32; // $a0
  int v33; // $a2
  _DWORD *v34; // $v1
  int v35; // $a1
  int v36; // $v0
  const void *v37; // $a0
  size_t v38; // $s4
  int v39; // $s7
  size_t v40; // $v0
  int v41; // $a0
  int v42; // $a1
  char *v43; // $v0
  FILE *v44; // $a0
  void *v45; // $a0
  int v46; // $s1
  char *v47; // $a0
  int v48; // $a2
  FILE *v49; // $a0
  void *v50; // $a0
  int v51; // $a2
  int v52; // $a1
  char *v53; // $v0
  int v54; // $a1
  const char *v55; // $v0
  unsigned int v56; // $v0
  int result; // $v0
  int v58; // $v0
  const char *v59; // $v0
  int v60; // $v0
  int v61; // $a1
  void *v62; // $s7
  int v63; // $v0
  int v64; // $s7
  int v65; // $v0
  _BYTE *v66; // $a0
  _BYTE *v67; // $v1
  FILE *v68; // $a0
  FILE *v69; // $v0
  int v70; // $v0
  _BYTE *v71; // $a1
  _BYTE *v72; // $a0
  int v73; // $a2
  _DWORD *v74; // $v0
  _DWORD *v75; // $v1
  _DWORD *v76; // $a0
  int v77; // $a1
  int v78; // $a3
  int v79; // $a2
  int v80; // $v1
  int v81; // $v0
  int v82; // $v0
  int v83; // $s4
  bool v84; // dc
  int v85; // $a1
  char *v86; // $v0
  char *v87; // $v0
  int v88; // $v0
  int v89; // $fp
  char v90[512]; // [sp+20h] [-488h] BYREF
  char v91[512]; // [sp+220h] [-288h] BYREF
  char v92[128]; // [sp+420h] [-88h] BYREF
  _DWORD *v93; // [sp+4A0h] [-8h]

  memset(v92, 0, sizeof(v92));
  memset(v90, 0, sizeof(v90));
  v2 = httpd_get_parm(a1, "path");
  v4 = httpd_find_ext_name(*(const char **)(a1 + 44));
  if ( !v2 || (v5 = strstr(v2, "/usb/")) == 0 || (v6 = v5 + 5, v5 == (char *)-5) )
    v6 = "";
  v7 = *(unsigned __int8 *)(a1 + 41);
  if ( !*(_BYTE *)(a1 + 41) )
  {
    v8 = *(void **)(a1 + 209700);
    if ( v8 )
    {
      _mem_free(v8);
      *(_DWORD *)(a1 + 209700) = 0;
    }
    *(_DWORD *)(a1 + 209704) = 0;
    _mem_malloc(102400, "usb_upload_do_rcv2", 2055);
    *(_DWORD *)(a1 + 209700) = v9;
    if ( !v9 )
    {
      v87 = (char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
      strcpy(v92, v87);
      v20 = (const char *)(a1 + 209840);
      goto LABEL_34;
    }
    v10 = *(_DWORD *)(a1 + 205484);
    v11 = *(_DWORD *)(a1 + 205364) - v10;
    *(_DWORD *)(a1 + 209704) = v11;
    if ( v11 <= 0 )
    {
      v12 = v9;
    }
    else
    {
      memcpy(v9, (void *)(a1 + v10 + 564), v11);
      v12 = *(char **)(a1 + 209700);
      v11 = *(_DWORD *)(a1 + 209704);
    }
    v13 = (const void *)(a1 + 209708);
    *(_DWORD *)(a1 + 205560) = usb_upload_do_rcv2;
    memset((void *)(a1 + 209708), 0, 0x80u);
    *(_DWORD *)(a1 + 209836) = 0;
    search_str(v12, v11, "\r\n", 2u);
    v14 = *(void **)(a1 + 209700);
    v16 = v15 - (_DWORD)v14;
    if ( v15 )
    {
      if ( v16 >= 0x7D )
      {
        v17 = 126;
        v16 = 124;
      }
      else
      {
        v17 = v16 + 2;
      }
      *(_BYTE *)(a1 + 209708) = 13;
      *(_BYTE *)(a1 + 209709) = 10;
      memcpy((void *)(a1 + 209710), v14, v16);
      *(_DWORD *)(a1 + 209836) = v17;
    }
    search_str((char *)v14, *(_DWORD *)(a1 + 209704), "filename=", 9u);
    v19 = v18;
    if ( !v18 )
      goto LABEL_86;
    v20 = (const char *)(a1 + 209840);
    memset((void *)(a1 + 209840), 0, 0x80u);
    v21 = *(unsigned __int8 *)(v19 + 10);
    v22 = (char *)(v19 + 10);
    if ( *(_BYTE *)(v19 + 10) )
    {
      v23 = (_BYTE *)(a1 + 209840);
      if ( v21 != 34 )
      {
        v24 = (_BYTE *)(v19 + 10);
        do
        {
          *v23 = v21;
          v21 = (unsigned __int8)*++v24;
          ++v23;
        }
        while ( *v24 && v24 != (_BYTE *)(v19 + 137) && v21 != 34 );
      }
    }
    snprintf(v90, 512, "/tmp/mnt/sda1/%s/%s", v6, (const char *)(a1 + 209840));
    create_dir2(v90);
    v25 = *(FILE **)(a1 + 209696);
    if ( v25 )
    {
      v93 = (_DWORD *)(a1 + 196608);
      fclose(v25);
      v93[3272] = 0;
    }
    v26 = fopen(v90, "wb");
    *(_DWORD *)(a1 + 209696) = v26;
    if ( v26 )
    {
      v28 = *(_DWORD *)(a1 + 209704);
      v29 = &v22[-*(_DWORD *)(a1 + 209700)];
      v93 = (_DWORD *)(a1 + 196608);
      search_str(v22, v28 - (_DWORD)v29, "\r\n\r\n", 4u);
      v31 = (_BYTE *)(v30 + 4);
      if ( v30 )
      {
        v32 = (_BYTE *)v93[3273];
        v33 = v93[3274] - (v31 - v32);
        v93[3274] = v33;
        memmove(v32, v31, v33);
        v34 = v93;
        *(_BYTE *)(v93[3273] + v93[3274]) = 0;
        *(_BYTE *)(a1 + 41) = 8;
        v35 = v34[3274];
LABEL_26:
        search_str(*(char **)(a1 + 209700), v35, v13, *(_DWORD *)(a1 + 209836));
        if ( v36 )
        {
          v37 = *(const void **)(a1 + 209700);
          v38 = v36 - (_DWORD)v37;
          v39 = 1;
          if ( v36 - (int)v37 <= 0 )
            goto LABEL_41;
        }
        else
        {
          v82 = *(_DWORD *)(a1 + 209704);
          v83 = *(_DWORD *)(a1 + 209836);
          v84 = v83 >= v82;
          v38 = v82 - v83;
          if ( v84 )
            goto LABEL_85;
          v37 = *(const void **)(a1 + 209700);
          v39 = 0;
        }
        v40 = fwrite(v37, 1u, v38, *(FILE **)(a1 + 209696));
        v41 = 141;
        if ( v40 != v38 )
        {
          v42 = *(unsigned __int8 *)(a1 + 210102);
LABEL_33:
          v43 = (char *)_GET_LANG_TEXT(v41, v42, v3);
          strcpy(v92, v43);
          v20 = (const char *)(a1 + 209840);
LABEL_34:
          v44 = *(FILE **)(a1 + 209696);
          if ( v44 )
          {
            fclose(v44);
            *(_DWORD *)(a1 + 209696) = 0;
          }
          v45 = *(void **)(a1 + 209700);
          if ( v45 )
          {
            _mem_free(v45);
            *(_DWORD *)(a1 + 209700) = 0;
          }
          *(_DWORD *)(a1 + 209704) = 0;
          snprintf(v90, 512, "/tmp/mnt/sda1/%s/%s", v6, v20);
          v46 = -1;
          unlink(v90);
          httpd_release_caches();
          goto LABEL_46;
        }
        fflush(*(FILE **)(a1 + 209696));
        v47 = *(char **)(a1 + 209700);
        v48 = *(_DWORD *)(a1 + 209704) - v38;
        *(_DWORD *)(a1 + 209704) = v48;
        memmove(v47, &v47[v38], v48);
        *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
        if ( v39 )
        {
LABEL_41:
          v49 = *(FILE **)(a1 + 209696);
          if ( v49 )
          {
            fclose(v49);
            *(_DWORD *)(a1 + 209696) = 0;
          }
          v50 = *(void **)(a1 + 209700);
          v51 = 2337;
          if ( v50 )
          {
            _mem_free(v50);
            *(_DWORD *)(a1 + 209700) = 0;
          }
          v52 = *(unsigned __int8 *)(a1 + 210102);
          *(_DWORD *)(a1 + 209704) = 0;
          v53 = (char *)_GET_LANG_TEXT(182, v52, v51);
          strcpy(v92, v53);
          v46 = 0;
          httpd_release_caches();
LABEL_46:
          sync();
          if ( v4 && !strcmp(v4, (const char *)&off_4CFE60) )
          {
            v54 = *(unsigned __int8 *)(a1 + 210102);
            if ( !v46 )
            {
              v59 = (const char *)_GET_LANG_TEXT(34, v54, v92);
              v56 = snprintf(v91, 512, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v59);
              if ( v56 >= 0x200 )
                v56 = 511;
              return httpd_cgi_ret(a1, v91, v56, 4);
            }
            v55 = (const char *)_GET_LANG_TEXT(33, v54, v92);
            v56 = snprintf(v91, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v55);
            if ( v56 < 0x200 )
              return httpd_cgi_ret(a1, v91, v56, 4);
          }
          else
          {
            v56 = snprintf(
                    v91,
                    512,
                    "<html><head><script type='text/javascript'>function init(){alert('%s');window.parent.location.href='"
                    "/usb/%s';}</script><body onLoad='init();'></body></head></html>",
                    v92,
                    v6);
            if ( v56 < 0x200 )
              return httpd_cgi_ret(a1, v91, v56, 4);
          }
          v56 = 511;
          return httpd_cgi_ret(a1, v91, v56, 4);
        }
LABEL_85:
        v81 = jiffies_get();
        mod_timer(a1 + 205540, v81 + 30000);
        return 0;
      }
LABEL_86:
      *(_BYTE *)(a1 + 41) = 7;
      goto LABEL_85;
    }
    v85 = *(unsigned __int8 *)(a1 + 210102);
LABEL_90:
    v86 = (char *)_GET_LANG_TEXT(139, v85, v27);
    strcpy(v92, v86);
    goto LABEL_34;
  }
  if ( v7 == 7 )
  {
    if ( *(_DWORD *)(a1 + 209984) )
    {
      v60 = https_ssl_read(a1);
      if ( v60 == -2 )
      {
        v61 = *(_DWORD *)(a1 + 209704);
        goto LABEL_67;
      }
    }
    else
    {
      v60 = recv(
              *(_DWORD *)(a1 + 205416),
              (void *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)),
              102400 - *(_DWORD *)(a1 + 209704),
              0);
    }
    if ( v60 <= 0 )
    {
      v42 = *(unsigned __int8 *)(a1 + 210102);
      v41 = 140;
      goto LABEL_33;
    }
    v61 = v60 + *(_DWORD *)(a1 + 209704);
    *(_DWORD *)(a1 + 209704) = v61;
LABEL_67:
    if ( *(_DWORD *)(a1 + 209836) )
    {
      v62 = *(void **)(a1 + 209700);
    }
    else
    {
      search_str(*(char **)(a1 + 209700), v61, "\r\n", 2u);
      v62 = *(void **)(a1 + 209700);
      v89 = v88 - (_DWORD)v62;
      if ( v88 )
      {
        *(_BYTE *)(a1 + 209708) = 13;
        *(_BYTE *)(a1 + 209709) = 10;
        memcpy((void *)(a1 + 209710), v62, v89);
        v61 = *(_DWORD *)(a1 + 209704);
        *(_DWORD *)(a1 + 209836) = v89 + 2;
      }
      else
      {
        v61 = *(_DWORD *)(a1 + 209704);
      }
    }
    search_str((char *)v62, v61, "filename=", 9u);
    v64 = v63;
    if ( v63 )
    {
      v20 = (const char *)(a1 + 209840);
      memset((void *)(a1 + 209840), 0, 0x80u);
      v65 = *(unsigned __int8 *)(v64 + 10);
      if ( *(_BYTE *)(v64 + 10) )
      {
        v66 = (_BYTE *)(a1 + 209840);
        if ( v65 != 34 )
        {
          v67 = (_BYTE *)(v64 + 10);
          do
          {
            *v66 = v65;
            v65 = (unsigned __int8)*++v67;
            ++v66;
          }
          while ( *v67 && (_BYTE *)(v64 + 137) != v67 && v65 != 34 );
        }
      }
      snprintf(v90, 512, "/tmp/mnt/sda1/%s/%s", v6, (const char *)(a1 + 209840));
      create_dir2(v90);
      v68 = *(FILE **)(a1 + 209696);
      if ( v68 )
      {
        fclose(v68);
        *(_DWORD *)(a1 + 209696) = 0;
      }
      v69 = fopen(v90, "wb");
      *(_DWORD *)(a1 + 209696) = v69;
      if ( !v69 )
      {
        v85 = *(unsigned __int8 *)(a1 + 210102);
        goto LABEL_90;
      }
      search_str((char *)(v64 + 10), *(_DWORD *)(a1 + 209704) - (v64 + 10 - *(_DWORD *)(a1 + 209700)), "\r\n\r\n", 4u);
      v71 = (_BYTE *)(v70 + 4);
      if ( v70 )
      {
        v72 = *(_BYTE **)(a1 + 209700);
        v73 = *(_DWORD *)(a1 + 209704) - (v71 - v72);
        *(_DWORD *)(a1 + 209704) = v73;
        memmove(v72, v71, v73);
        *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
        *(_BYTE *)(a1 + 41) = 8;
        v35 = *(_DWORD *)(a1 + 209704);
        v13 = (const void *)(a1 + 209708);
        goto LABEL_26;
      }
    }
    if ( *(_DWORD *)(a1 + 209704) == 102400 )
    {
      v74 = *(_DWORD **)(a1 + 209700);
      v75 = v74 + 12800;
      v76 = v74 + 25600;
      do
      {
        v77 = v75[3];
        v78 = v75[1];
        v79 = v75[2];
        *v74 = *v75;
        v74[1] = v78;
        v74[2] = v79;
        v75 += 4;
        v74[3] = v77;
        v74 += 4;
      }
      while ( v75 != v76 );
      v80 = *(_DWORD *)(a1 + 209700) + 0x10000;
      *(_DWORD *)(a1 + 209704) = 51200;
      *(_BYTE *)(v80 - 14336) = 0;
    }
    goto LABEL_85;
  }
  if ( v7 != 8 )
  {
    v42 = *(unsigned __int8 *)(a1 + 210102);
    v41 = 13;
    goto LABEL_33;
  }
  if ( *(_DWORD *)(a1 + 209984) )
  {
    v58 = https_ssl_read(a1);
    if ( v58 == -2 )
    {
      v35 = *(_DWORD *)(a1 + 209704);
      v13 = (const void *)(a1 + 209708);
      goto LABEL_26;
    }
    if ( v58 >= 0 )
    {
      if ( v58 )
      {
LABEL_60:
        v35 = v58 + *(_DWORD *)(a1 + 209704);
        *(_DWORD *)(a1 + 209704) = v35;
        v13 = (const void *)(a1 + 209708);
        goto LABEL_26;
      }
LABEL_94:
      v42 = *(unsigned __int8 *)(a1 + 210102);
      v41 = 140;
      goto LABEL_33;
    }
  }
  else
  {
    v58 = recv(
            *(_DWORD *)(a1 + 205416),
            (void *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)),
            102400 - *(_DWORD *)(a1 + 209704),
            0);
    if ( v58 )
    {
      if ( v58 > 0 )
        goto LABEL_60;
      goto LABEL_94;
    }
  }
  result = 0;
  if ( !*(_BYTE *)(a1 + 210101) )
    goto LABEL_94;
  return result;
}
// 4B1FE0: variable 'v9' is possibly undefined
// 4B207C: variable 'v15' is possibly undefined
// 4B20F0: variable 'v18' is possibly undefined
// 4B222C: variable 'v30' is possibly undefined
// 4B229C: variable 'v36' is possibly undefined
// 4B2310: variable 'v3' is possibly undefined
// 4B24D4: variable 'v51' is possibly undefined
// 4B2784: variable 'v63' is possibly undefined
// 4B28B4: variable 'v70' is possibly undefined
// 4B2A10: variable 'v27' is possibly undefined
// 4B2AE0: variable 'v88' is possibly undefined
// 4CFE60: using guessed type void *off_4CFE60;
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8584: using guessed type int __fastcall create_dir2(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

