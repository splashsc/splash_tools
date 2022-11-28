int __fastcall httpd_do_recv(int a1)
{
  int v1; // $v0
  int v3; // $v0
  int *v4; // $v0
  int *v5; // $s5
  int v6; // $s7
  int v7; // $s6
  int (__fastcall *v8)(int); // $s3
  unsigned int v9; // $a0
  int v10; // $v0
  int v11; // $s6
  unsigned int v12; // $s0
  unsigned int v13; // $v1
  int (__fastcall *v14)(int); // $t9
  int v15; // $s3
  int v17; // $s4
  int v18; // $s0
  int v19; // $a2
  int v20; // $s0
  int v21; // $v0
  int v22; // $v0
  int v23; // $v0
  _BYTE *v24; // $v1
  const char *v25; // $s2
  int v26; // $s0
  int v27; // $a2
  int v28; // $s0
  char *v29; // $v0
  bool v30; // dc
  char *v31; // $v0
  int v32; // $v0
  int v33; // $v0
  _BYTE *v34; // $s0
  int v35; // $v0
  int v36; // $v0
  const char *v37; // $s4
  int v38; // $v1
  int v39; // $a1
  unsigned int v40; // $a0
  unsigned int v41; // $v1
  int v42; // $v0
  int v43; // $v0
  int v44; // $v0
  char *v45; // $a0
  _BYTE *v46; // $a1
  int v47; // $v0
  _BYTE *v48; // $s0
  _BYTE *v49; // $s0
  const char *v51; // $s0
  int v52; // $v0
  const char *v53; // $s0
  int v54; // $v0
  int v55; // $v1
  int v56; // $a2
  size_t v57; // $a2
  int v58; // $v0
  int v59; // $v0
  _BYTE *v60; // $a0
  char v61[4]; // [sp+18h] [-24h] BYREF
  unsigned int v62; // [sp+1Ch] [-20h]
  int v63[5]; // [sp+28h] [-14h] BYREF

  v1 = *(unsigned __int8 *)(a1 + 41);
  v63[0] = 0;
  switch ( v1 )
  {
    case 0:
      if ( *(_DWORD *)(a1 + 209984) )
      {
        v25 = (const char *)(a1 + 564);
        v26 = https_ssl_read(a1);
        v27 = 0;
        if ( v26 == -2 )
        {
          v26 = 0;
          goto LABEL_38;
        }
      }
      else
      {
        v25 = (const char *)(a1 + 564);
        v26 = recv(
                *(_DWORD *)(a1 + 205416),
                (void *)(a1 + 564 + *(_DWORD *)(a1 + 205364)),
                102399 - *(_DWORD *)(a1 + 205364),
                0);
      }
      v27 = v26;
      if ( v26 <= 0 )
        goto LABEL_34;
LABEL_38:
      memcpy((void *)(a1 + 102964 + *(_DWORD *)(a1 + 205364)), (void *)&v25[*(_DWORD *)(a1 + 205364)], v27);
      v28 = v26 + *(_DWORD *)(a1 + 205364);
      *(_DWORD *)(a1 + 205364) = v28;
      *(_BYTE *)(a1 + v28 + 564) = 0;
      *(_BYTE *)(a1 + v28 + 102964) = 0;
      v29 = strstr(v25, "\r\n\r\n");
      v30 = v29 == 0;
      v31 = v29 + 4;
      if ( v30 )
        goto LABEL_28;
      v32 = v31 - v25;
      *(_DWORD *)(a1 + 205484) = v32;
      *(_BYTE *)(a1 + v32 + 563) = 0;
      if ( !memcmp(v25, "GET ", 4u) )
      {
        *(_BYTE *)(a1 + 40) = 1;
        *(_BYTE *)(a1 + 43) = 0;
        return httpd_dowith_get(a1);
      }
      v15 = memcmp(v25, "POST ", 5u);
      if ( v15 )
        goto LABEL_34;
      v33 = *(char *)(a1 + 569);
      *(_BYTE *)(a1 + 40) = 2;
      *(_BYTE *)(a1 + 43) = 0;
      *(_DWORD *)(a1 + 44) = a1 + 569;
      if ( v33 == 32 )
      {
        v34 = (_BYTE *)(a1 + 569);
        goto LABEL_48;
      }
      v34 = (_BYTE *)(a1 + 569);
      if ( v33 == 63 )
      {
LABEL_67:
        *v34 = 0;
        v45 = *(char **)(a1 + 44);
        v63[2] = (int)(v34 + 1);
        unescape(v45);
        v46 = v34 + 1;
        *(_DWORD *)(a1 + 52) = 0;
        if ( v34 == (_BYTE *)-1 )
        {
          v34 = 0;
        }
        else
        {
          v47 = v34[1] & 0xDF;
          v48 = v34 + 1;
          if ( v47 )
          {
            v49 = v46 + 1;
            while ( *v49++ & 0xDF )
              ;
            v48 = v49 - 1;
          }
          *v48 = 0;
          httpd_formdata_parse((_DWORD *)a1, v46, 0);
          v34 = v48 + 1;
        }
      }
      else
      {
        if ( v33 )
        {
          while ( 1 )
          {
            v35 = (char)*++v34;
            if ( v35 == 32 )
              break;
            if ( v35 == 63 )
              goto LABEL_67;
            if ( !*v34 )
              goto LABEL_73;
          }
LABEL_48:
          *v34++ = 0;
          unescape(*(char **)(a1 + 44));
          *(_DWORD *)(a1 + 52) = 0;
          goto LABEL_49;
        }
LABEL_73:
        unescape((char *)(a1 + 569));
        *(_DWORD *)(a1 + 52) = 0;
      }
LABEL_49:
      httpd_do_wwwparm((_DWORD *)a1, v34);
      if ( !httpd_proxy_check(a1, v63) )
        goto LABEL_50;
      if ( !httpd_proxy_is_self(a1) )
      {
        if ( v63[0] && httdp_proxy_check_user(a1) )
          v15 = 0;
        else
          v15 = httpd_proxy_cgi(a1);
        return v15;
      }
      v51 = *(const char **)(a1 + 44);
      if ( !strncmp(v51, "/ap/", 4u) )
      {
        v51 += 3;
        *(_DWORD *)(a1 + 44) = v51;
      }
      v52 = strncmp(v51, "/rt/", 4u);
      v53 = v51 + 3;
      if ( !v52 )
        *(_DWORD *)(a1 + 44) = v53;
LABEL_50:
      if ( (*(_DWORD *)(a1 + 32) & 0x80) == 0 )
      {
        if ( debug_level > 0 )
          printf("%s:%d post not  Content-Length\n ", "httpd_do_recv", 4449);
        goto LABEL_34;
      }
      v36 = *(_DWORD *)(a1 + 44);
      v37 = (const char *)(v36 + 1);
      if ( *(_BYTE *)(v36 + 1) )
      {
        v3 = get_name_hash((unsigned __int8 *)(v36 + 1));
        v4 = httpd_find_ext_cgi(v37, v3);
        v5 = v4;
        if ( v4 )
        {
          v6 = *(_DWORD *)(a1 + 205364);
          v7 = *(_DWORD *)(a1 + 205484);
          if ( httpd_check_user(a1, v4[4]) )
            return v15;
          v8 = (int (__fastcall *)(int))v5[6];
          *(_DWORD *)(a1 + 205560) = v8;
          if ( !strcmp(v37, "upload_manage/upload.htm")
            || !strcmp(v37, "upload_manage/upload2.htm")
            || !strcmp(v37, aUsbUpload2)
            || !strcmp(v37, "auth_upload.cgi") )
          {
            if ( !v8 )
              goto LABEL_34;
            return v8(a1);
          }
          *(_DWORD *)(a1 + 205568) = (*(_DWORD *)(a1 + 205496) & 0xFFFFFC00) + 1025;
          if ( !strcmp(v37, "upfile.cgi") )
          {
            upgrade_prepare();
            get_memory(v61);
            v9 = *(_DWORD *)(a1 + 205568);
            if ( v62 < v9 )
            {
              upgrade_after(v9);
              if ( debug_level > 0 )
                printf("%s:%d mem_malloc %d false \n ", "httpd_do_recv", 4535, *(_DWORD *)(a1 + 205568));
              goto LABEL_34;
            }
          }
          else
          {
            get_memory(v61);
            v9 = *(_DWORD *)(a1 + 205568);
            if ( v62 < v9 )
            {
              if ( debug_level > 0 )
                printf("%s:%d mem_malloc %d false \n ", "httpd_do_recv", 4544, *(_DWORD *)(a1 + 205568));
              nvram_set("jhttpd_no_mem", "1");
              goto LABEL_34;
            }
          }
          _mem_malloc(v9, "httpd_do_recv", 4550);
          *(_DWORD *)(a1 + 205564) = v10;
          if ( !v10 )
          {
            if ( debug_level > 0 )
              printf("%s:%d mem_malloc %d false \n ", "httpd_do_recv", 4553, *(_DWORD *)(a1 + 205568));
            goto LABEL_34;
          }
          if ( strcmp(v37, "login.cgi") && strcmp(v37, "log_in.cgi") )
            nvram_set("jhttpd_no_mem", "0");
          v11 = v6 - v7;
          if ( v11 > 0 )
          {
            memcpy(*(void **)(a1 + 205564), (void *)(a1 + *(_DWORD *)(a1 + 205484) + 564), v11);
            v12 = v11;
            *(_BYTE *)(*(_DWORD *)(a1 + 205564) + v11) = 0;
          }
          else
          {
            v12 = v11;
          }
          *(_BYTE *)(a1 + 41) = 6;
          if ( *(_DWORD *)(a1 + 205364) != 102400 )
          {
            *(_DWORD *)(a1 + 205364) = v11;
LABEL_18:
            v13 = *(_DWORD *)(a1 + 205496);
            if ( v12 >= v13 )
            {
              if ( v13 )
                httpd_formdata_parse((_DWORD *)a1, &v25[*(_DWORD *)(a1 + 205484)], 1);
              goto LABEL_21;
            }
            v54 = jiffies_get();
            mod_timer(a1 + 205540, v54 + 15000);
            return 0;
          }
          v55 = *(_DWORD *)(a1 + 209984);
          v56 = *(_DWORD *)(a1 + 205568) - 1;
          *(_DWORD *)(a1 + 205364) = v11;
          v57 = v56 - v11;
          if ( v55 )
          {
            v58 = https_ssl_read(a1);
            if ( v58 == -2 )
            {
              v58 = 0;
LABEL_98:
              v59 = v58 + *(_DWORD *)(a1 + 205364);
              v60 = (_BYTE *)(*(_DWORD *)(a1 + 205564) + v59);
              *(_DWORD *)(a1 + 205364) = v59;
              *v60 = 0;
              v12 = *(_DWORD *)(a1 + 205364);
              goto LABEL_18;
            }
          }
          else
          {
            v58 = recv(*(_DWORD *)(a1 + 205416), (void *)(*(_DWORD *)(a1 + 205564) + v11), v57, 0);
          }
          if ( v58 <= 0 )
            goto LABEL_34;
          goto LABEL_98;
        }
      }
      v38 = *(_DWORD *)(a1 + 205364);
      if ( v38 == 102400 )
      {
        if ( debug_level > 0 )
          printf("%s:%d len == HTTPD_CONN_DATA_LEN \n ", "httpd_do_recv", 4634);
        goto LABEL_34;
      }
      v39 = *(_DWORD *)(a1 + 205484);
      v40 = *(_DWORD *)(a1 + 205496);
      v41 = v38 - v39;
      if ( 102400 - v39 < v40 )
      {
        if ( debug_level > 0 )
          printf("%s:%d post Content-Length too big \n ", "httpd_do_recv", 4640);
        goto LABEL_34;
      }
      if ( v41 >= v40 )
      {
        v43 = jiffies_get();
        mod_timer(a1 + 205540, v43 + 5000);
        return httpd_dowith_post(a1);
      }
      *(_BYTE *)(a1 + 41) = 1;
      v42 = jiffies_get();
      mod_timer(a1 + 205540, v42 + 15000);
      return v15;
    case 1:
      if ( *(_DWORD *)(a1 + 209984) )
      {
        v17 = a1 + 564;
        v18 = https_ssl_read(a1);
        v19 = 0;
        if ( v18 == -2 )
        {
          v18 = 0;
          goto LABEL_27;
        }
      }
      else
      {
        v17 = a1 + 564;
        v18 = recv(
                *(_DWORD *)(a1 + 205416),
                (void *)(a1 + 564 + *(_DWORD *)(a1 + 205364)),
                102399 - *(_DWORD *)(a1 + 205364),
                0);
      }
      v19 = v18;
      if ( v18 <= 0 )
        goto LABEL_34;
LABEL_27:
      memcpy((void *)(a1 + 102964 + *(_DWORD *)(a1 + 205364)), (void *)(v17 + *(_DWORD *)(a1 + 205364)), v19);
      v20 = v18 + *(_DWORD *)(a1 + 205364);
      *(_DWORD *)(a1 + 205364) = v20;
      *(_BYTE *)(a1 + v20 + 564) = 0;
      *(_BYTE *)(a1 + v20 + 102964) = 0;
      if ( (unsigned int)(v20 - *(_DWORD *)(a1 + 205484)) >= *(_DWORD *)(a1 + 205496) )
        return httpd_dowith_post(a1);
LABEL_28:
      v21 = jiffies_get();
      mod_timer(a1 + 205540, v21 + 2000);
      return 0;
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
LABEL_21:
      v14 = *(int (__fastcall **)(int))(a1 + 205560);
      if ( !v14 )
        goto LABEL_34;
      return v14(a1);
    case 6:
      if ( *(_DWORD *)(a1 + 209984) )
      {
        v22 = https_ssl_read(a1);
        if ( v22 == -2 )
        {
          v22 = 0;
          goto LABEL_32;
        }
      }
      else
      {
        v22 = recv(
                *(_DWORD *)(a1 + 205416),
                (void *)(*(_DWORD *)(a1 + 205564) + *(_DWORD *)(a1 + 205364)),
                *(_DWORD *)(a1 + 205568) - 1 - *(_DWORD *)(a1 + 205364),
                0);
      }
      if ( v22 <= 0 )
      {
LABEL_34:
        httpd_conn_close((int *)a1);
        return -1;
      }
LABEL_32:
      v23 = v22 + *(_DWORD *)(a1 + 205364);
      v24 = (_BYTE *)(*(_DWORD *)(a1 + 205564) + v23);
      *(_DWORD *)(a1 + 205364) = v23;
      *v24 = 0;
      if ( *(_DWORD *)(a1 + 205364) >= *(_DWORD *)(a1 + 205496) )
      {
        httpd_formdata_parse((_DWORD *)a1, *(_BYTE **)(a1 + 205564), 1);
        v14 = *(int (__fastcall **)(int))(a1 + 205560);
        if ( v14 )
          return v14(a1);
        goto LABEL_34;
      }
      v15 = 0;
      v44 = jiffies_get();
      mod_timer(a1 + 205540, v44 + 20000);
      return v15;
    default:
      goto LABEL_34;
  }
}
// 42ADD4: variable 'v10' is possibly undefined
// 67D0BC: using guessed type int debug_level;
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A837C: using guessed type int __fastcall upgrade_after(_DWORD);
// 6A85CC: using guessed type int __fastcall get_memory(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8894: using guessed type int upgrade_prepare(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

