int __fastcall usb_upload_do_rcv(int a1)
{
  char *v2; // $v0
  int v3; // $a2
  int v4; // $v1
  const char *v5; // $s5
  void *v6; // $a0
  int v7; // $v0
  FILE *v8; // $a0
  FILE *v9; // $v0
  int v10; // $a2
  int v11; // $a1
  int v12; // $s7
  const void *v13; // $s6
  char *v14; // $a0
  void *v15; // $s7
  int v16; // $v0
  unsigned int v17; // $a2
  int v18; // $s2
  int v19; // $v0
  int v20; // $v0
  _BYTE *v21; // $a1
  _BYTE *v22; // $a0
  int v23; // $a2
  int v24; // $a1
  int v25; // $v0
  const void *v26; // $a0
  size_t v27; // $s2
  int v28; // $s7
  size_t v29; // $v0
  int v30; // $a0
  int v31; // $a1
  char *v32; // $v0
  FILE *v33; // $a0
  void *v34; // $a0
  const char *v35; // $a3
  char *v36; // $a0
  int v37; // $a2
  FILE *v38; // $a0
  void *v39; // $a0
  int v40; // $a2
  char *v41; // $v0
  unsigned int v42; // $v0
  int result; // $v0
  int v44; // $s2
  ssize_t v45; // $v0
  int v46; // $v0
  int v47; // $a1
  void *v48; // $s7
  int v49; // $v0
  int v50; // $v0
  _BYTE *v51; // $a1
  _BYTE *v52; // $a0
  int v53; // $a2
  int v54; // $v0
  int v55; // $v0
  int v56; // $s2
  bool v57; // dc
  _DWORD *v58; // $v0
  _DWORD *v59; // $v1
  _DWORD *v60; // $a0
  int v61; // $a1
  int v62; // $a3
  int v63; // $a2
  int v64; // $v1
  char *v65; // $v0
  int v66; // $v0
  int v67; // $fp
  char v68[512]; // [sp+20h] [-680h] BYREF
  char v69[512]; // [sp+220h] [-480h] BYREF
  int v70[128]; // [sp+420h] [-280h] BYREF
  char v71[128]; // [sp+620h] [-80h] BYREF

  memset(v71, 0, sizeof(v71));
  memset(v69, 0, sizeof(v69));
  memset(v68, 0, sizeof(v68));
  v2 = httpd_get_parm(a1, "filename");
  v4 = *(unsigned __int8 *)(a1 + 41);
  v5 = v2;
  if ( *(_BYTE *)(a1 + 41) )
  {
    if ( v4 != 7 )
    {
      if ( v4 != 8 )
      {
        v31 = *(unsigned __int8 *)(a1 + 210102);
        v30 = 13;
        goto LABEL_21;
      }
      v44 = a1 + 196608;
      if ( !*(_DWORD *)(a1 + 209984) )
      {
        v45 = recv(
                *(_DWORD *)(a1 + 205416),
                (void *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)),
                102400 - *(_DWORD *)(a1 + 209704),
                0);
        if ( v45 )
        {
          if ( v45 > 0 )
          {
LABEL_59:
            v24 = v45 + *(_DWORD *)(a1 + 209704);
            *(_DWORD *)(a1 + 209704) = v24;
            v13 = (const void *)(a1 + 209708);
            goto LABEL_17;
          }
        }
        else
        {
          result = 0;
          if ( *(_BYTE *)(a1 + 210101) )
            return result;
        }
        v31 = *(unsigned __int8 *)(a1 + 210102);
        v30 = 140;
        goto LABEL_21;
      }
      v45 = https_ssl_read(a1);
      if ( v45 == -2 )
      {
        v24 = *(_DWORD *)(a1 + 209704);
        v13 = (const void *)(a1 + 209708);
        goto LABEL_17;
      }
      if ( v45 >= 0 )
      {
        if ( !v45 )
          goto LABEL_23;
        goto LABEL_59;
      }
      result = 0;
      if ( *(_BYTE *)(a1 + 210101) )
        return result;
LABEL_72:
      v31 = *(unsigned __int8 *)(v44 + 13494);
      v30 = 140;
      goto LABEL_21;
    }
    v44 = a1 + 196608;
    if ( *(_DWORD *)(a1 + 209984) )
    {
      v46 = https_ssl_read(a1);
      if ( v46 == -2 )
      {
        v47 = *(_DWORD *)(a1 + 209704);
        goto LABEL_52;
      }
      if ( !v46 )
        goto LABEL_23;
      if ( v46 < 0 )
        goto LABEL_72;
    }
    else
    {
      v46 = recv(
              *(_DWORD *)(a1 + 205416),
              (void *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)),
              102400 - *(_DWORD *)(a1 + 209704),
              0);
      if ( v46 < 0 )
        goto LABEL_72;
      if ( !v46 )
        goto LABEL_23;
    }
    v47 = v46 + *(_DWORD *)(a1 + 209704);
    *(_DWORD *)(a1 + 209704) = v47;
LABEL_52:
    if ( *(_DWORD *)(a1 + 209836) )
    {
      v48 = *(void **)(a1 + 209700);
    }
    else
    {
      search_str(*(char **)(a1 + 209700), v47, "\r\n", 2u);
      v48 = *(void **)(a1 + 209700);
      v67 = v66 - (_DWORD)v48;
      if ( v66 )
      {
        *(_BYTE *)(a1 + 209708) = 13;
        *(_BYTE *)(a1 + 209709) = 10;
        memcpy((void *)(a1 + 209710), v48, v67);
        v47 = *(_DWORD *)(a1 + 209704);
        *(_DWORD *)(a1 + 209836) = v67 + 2;
      }
      else
      {
        v47 = *(_DWORD *)(a1 + 209704);
      }
    }
    search_str((char *)v48, v47, "filename=", 9u);
    if ( !v49
      || (search_str((char *)(v49 + 9), *(_DWORD *)(a1 + 209704) - (v49 + 9 - *(_DWORD *)(a1 + 209700)), "\r\n\r\n", 4u),
          v51 = (_BYTE *)(v50 + 4),
          !v50) )
    {
      if ( *(_DWORD *)(a1 + 209704) == 102400 )
      {
        v58 = *(_DWORD **)(a1 + 209700);
        v59 = v58 + 12800;
        v60 = v58 + 25600;
        do
        {
          v61 = v59[3];
          v62 = v59[1];
          v63 = v59[2];
          *v58 = *v59;
          v58[1] = v62;
          v58[2] = v63;
          v59 += 4;
          v58[3] = v61;
          v58 += 4;
        }
        while ( v59 != v60 );
        v64 = *(_DWORD *)(a1 + 209700) + 0x10000;
        *(_DWORD *)(a1 + 209704) = 51200;
        *(_BYTE *)(v64 - 14336) = 0;
      }
      goto LABEL_61;
    }
    v52 = *(_BYTE **)(a1 + 209700);
    v53 = *(_DWORD *)(a1 + 209704) - (v51 - v52);
    *(_DWORD *)(a1 + 209704) = v53;
    memmove(v52, v51, v53);
    *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
    *(_BYTE *)(a1 + 41) = 8;
    v24 = *(_DWORD *)(a1 + 209704);
    v13 = (const void *)(a1 + 209708);
    goto LABEL_17;
  }
  v6 = *(void **)(a1 + 209700);
  if ( v6 )
  {
    _mem_free(v6);
    *(_DWORD *)(a1 + 209700) = 0;
  }
  *(_DWORD *)(a1 + 209704) = 0;
  _mem_malloc(102400, "usb_upload_do_rcv", 1568);
  *(_DWORD *)(a1 + 209700) = v7;
  if ( !v7 )
  {
    v32 = (char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    goto LABEL_22;
  }
  snprintf(v69, 512, "/tmp/mnt/sda1/upload/%s", v5);
  snprintf(v68, 512, "/tmp/mnt/sda1/tmp/%s", v5);
  create_dir2(v69);
  create_dir2(v68);
  v8 = *(FILE **)(a1 + 209696);
  if ( v8 )
  {
    fclose(v8);
    *(_DWORD *)(a1 + 209696) = 0;
  }
  v9 = fopen(v68, "wb");
  *(_DWORD *)(a1 + 209696) = v9;
  if ( !v9 )
  {
    v65 = (char *)_GET_LANG_TEXT(181, *(unsigned __int8 *)(a1 + 210102), v10);
    strcpy(v71, v65);
    goto LABEL_23;
  }
  v11 = *(_DWORD *)(a1 + 205484);
  v12 = *(_DWORD *)(a1 + 205364) - v11;
  *(_DWORD *)(a1 + 209704) = v12;
  if ( v12 > 0 )
  {
    memcpy(*(void **)(a1 + 209700), (void *)(a1 + v11 + 564), v12);
    v12 = *(_DWORD *)(a1 + 209704);
  }
  v13 = (const void *)(a1 + 209708);
  *(_DWORD *)(a1 + 205560) = usb_upload_do_rcv;
  memset((void *)(a1 + 209708), 0, 0x80u);
  v14 = *(char **)(a1 + 209700);
  *(_DWORD *)(a1 + 209836) = 0;
  search_str(v14, v12, "\r\n", 2u);
  v15 = *(void **)(a1 + 209700);
  v17 = v16 - (_DWORD)v15;
  if ( v16 )
  {
    v18 = 126;
    if ( v17 >= 0x7D )
      v17 = 124;
    else
      v18 = v17 + 2;
    *(_BYTE *)(a1 + 209708) = 13;
    *(_BYTE *)(a1 + 209709) = 10;
    memcpy((void *)(a1 + 209710), v15, v17);
    *(_DWORD *)(a1 + 209836) = v18;
  }
  search_str((char *)v15, *(_DWORD *)(a1 + 209704), "filename=", 9u);
  if ( !v19
    || (search_str((char *)(v19 + 9), *(_DWORD *)(a1 + 209704) - (v19 + 9 - *(_DWORD *)(a1 + 209700)), "\r\n\r\n", 4u),
        v21 = (_BYTE *)(v20 + 4),
        !v20) )
  {
    *(_BYTE *)(a1 + 41) = 7;
    goto LABEL_61;
  }
  v22 = *(_BYTE **)(a1 + 209700);
  v23 = *(_DWORD *)(a1 + 209704) - (v21 - v22);
  *(_DWORD *)(a1 + 209704) = v23;
  memmove(v22, v21, v23);
  *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
  *(_BYTE *)(a1 + 41) = 8;
  v24 = *(_DWORD *)(a1 + 209704);
LABEL_17:
  search_str(*(char **)(a1 + 209700), v24, v13, *(_DWORD *)(a1 + 209836));
  if ( v25 )
  {
    v26 = *(const void **)(a1 + 209700);
    v27 = v25 - (_DWORD)v26;
    v28 = 1;
    if ( v25 - (int)v26 <= 0 )
    {
LABEL_32:
      v38 = *(FILE **)(a1 + 209696);
      if ( v38 )
      {
        fclose(v38);
        *(_DWORD *)(a1 + 209696) = 0;
      }
      v39 = *(void **)(a1 + 209700);
      if ( v39 )
      {
        _mem_free(v39);
        *(_DWORD *)(a1 + 209700) = 0;
      }
      *(_DWORD *)(a1 + 209704) = 0;
      snprintf(v69, 512, "/tmp/mnt/sda1/upload/%s", v5);
      snprintf(v68, 512, "/tmp/mnt/sda1/tmp/%s", v5);
      v70[0] = (int)&unk_4D17B4;
      v70[1] = (int)"-f";
      v70[2] = (int)v68;
      v70[3] = (int)v69;
      v70[4] = 0;
      eval(v70, 0, 0, 0);
      v41 = (char *)_GET_LANG_TEXT(182, *(unsigned __int8 *)(a1 + 210102), v40);
      strcpy(v71, v41);
      httpd_release_caches();
      v35 = "true";
      goto LABEL_37;
    }
  }
  else
  {
    v55 = *(_DWORD *)(a1 + 209704);
    v56 = *(_DWORD *)(a1 + 209836);
    v57 = v56 >= v55;
    v27 = v55 - v56;
    if ( v57 )
      goto LABEL_61;
    v26 = *(const void **)(a1 + 209700);
    v28 = 0;
  }
  v29 = fwrite(v26, 1u, v27, *(FILE **)(a1 + 209696));
  v30 = 141;
  if ( v29 == v27 )
  {
    fflush(*(FILE **)(a1 + 209696));
    v36 = *(char **)(a1 + 209700);
    v37 = *(_DWORD *)(a1 + 209704) - v27;
    *(_DWORD *)(a1 + 209704) = v37;
    memmove(v36, &v36[v27], v37);
    *(_BYTE *)(*(_DWORD *)(a1 + 209700) + *(_DWORD *)(a1 + 209704)) = 0;
    if ( v28 )
      goto LABEL_32;
LABEL_61:
    v54 = jiffies_get();
    mod_timer(a1 + 205540, v54 + 30000);
    return 0;
  }
  v31 = *(unsigned __int8 *)(a1 + 210102);
LABEL_21:
  v32 = (char *)_GET_LANG_TEXT(v30, v31, v3);
LABEL_22:
  strcpy(v71, v32);
LABEL_23:
  v33 = *(FILE **)(a1 + 209696);
  if ( v33 )
  {
    fclose(v33);
    *(_DWORD *)(a1 + 209696) = 0;
  }
  v34 = *(void **)(a1 + 209700);
  if ( v34 )
  {
    _mem_free(v34);
    *(_DWORD *)(a1 + 209700) = 0;
  }
  *(_DWORD *)(a1 + 209704) = 0;
  snprintf(v68, 512, "/tmp/mnt/sda1/tmp/%s", v5);
  unlink(v68);
  httpd_release_caches();
  v35 = "false";
LABEL_37:
  v42 = snprintf((char *)v70, 512, "{\"success\":%s,\"message\":\"%s\"}", v35, v71);
  if ( v42 >= 0x200 )
    v42 = 511;
  return httpd_cgi_ret(a1, (char *)v70, v42, 4);
}
// 4B10EC: variable 'v7' is possibly undefined
// 4B1240: variable 'v16' is possibly undefined
// 4B12B0: variable 'v19' is possibly undefined
// 4B12E4: variable 'v20' is possibly undefined
// 4B1344: variable 'v25' is possibly undefined
// 4B1394: variable 'v3' is possibly undefined
// 4B15FC: variable 'v40' is possibly undefined
// 4B17C4: variable 'v49' is possibly undefined
// 4B1800: variable 'v50' is possibly undefined
// 4B19D0: variable 'v10' is possibly undefined
// 4B1A64: variable 'v66' is possibly undefined
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8584: using guessed type int __fastcall create_dir2(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

