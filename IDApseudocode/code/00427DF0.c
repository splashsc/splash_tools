int __fastcall httpd_cgi_ret(int a1, char *a2, int a3, int a4)
{
  int v4; // $s2
  unsigned int v7; // $v0
  unsigned int v8; // $s5
  unsigned int v9; // $v0
  unsigned int v10; // $s5
  unsigned int v11; // $v0
  unsigned int v12; // $s5
  unsigned int v13; // $v0
  unsigned int v14; // $s5
  char **v15; // $v0
  unsigned int v16; // $v0
  unsigned int v17; // $s5
  unsigned int v18; // $v0
  int v19; // $v1
  unsigned int v20; // $s5
  unsigned int v21; // $s4
  unsigned int v22; // $v0
  signed int v23; // $a0
  signed int v24; // $s4
  char *v25; // $a0
  int v26; // $v0
  int result; // $v0
  signed int v28; // $s2
  char *v29; // $v0
  unsigned int v30; // $v0
  unsigned int v31; // $s5
  unsigned int v32; // $v0
  unsigned int v33; // $s5
  unsigned int v34; // $v0
  unsigned int v35; // $s5
  char **v36; // $v0
  unsigned int v37; // $v0
  int v38; // $s4
  unsigned int v39; // $v0
  int v40; // $v1
  unsigned int v41; // $s4
  unsigned int v42; // $s5
  unsigned int v43; // $v0
  signed int v44; // $a0
  bool v45; // dc
  unsigned int v46; // $v0
  unsigned int v47; // $s5
  unsigned int v48; // $v0
  unsigned int v49; // $s5
  unsigned int v50; // $v0
  unsigned int v51; // $s5
  char **v52; // $v0
  unsigned int v53; // $v0
  int v54; // $s4
  unsigned int v55; // $v0
  int v56; // $v1
  unsigned int v57; // $s4
  unsigned int v58; // $s5
  unsigned int v59; // $v0
  unsigned int v60; // $v0
  unsigned int v61; // $s5
  unsigned int v62; // $v0
  unsigned int v63; // $s5
  unsigned int v64; // $v0
  unsigned int v65; // $s5
  char **v66; // $v0
  unsigned int v67; // $v0
  unsigned int v68; // $s5
  unsigned int v69; // $v0
  int v70; // $v1
  unsigned int v71; // $s5
  unsigned int v72; // $s4
  unsigned int v73; // $v0
  unsigned int v74; // $v0
  unsigned int v75; // $v0
  char v76[1400]; // [sp+18h] [-578h] BYREF

  switch ( a4 )
  {
    case 1:
      *(_BYTE *)(a1 + 41) = 2;
      httpd_send_info(a1, "<head><title>Information</title></head>\n<body><h2> %s </h2></body>\n", (int)a2);
      return 0;
    case 2:
      v28 = strlen(a2);
      if ( v28 >= 102400 )
        v28 = 102399;
      strlcpy(a1 + 564, a2, 102400);
      *(_BYTE *)(a1 + v28 + 564) = 0;
      *(_DWORD *)(a1 + 205364) = v28;
      *(_DWORD *)(a1 + 44) = a1 + 564;
      v29 = strchr((const char *)(a1 + 564), 63);
      if ( v29 )
        *v29 = 0;
      *(_BYTE *)(a1 + 41) = 2;
      httpd_send_file(a1, 0);
      return 0;
    case 4:
      if ( (*(_DWORD *)(a1 + 32) & 2) != 0 )
        v30 = *(_DWORD *)(a1 + 36) | 1;
      else
        v30 = *(_DWORD *)(a1 + 36) & 0xFFFFFFFE;
      *(_DWORD *)(a1 + 36) = v30;
      v31 = snprintf(v76, 1400, "%s", httpd_oktok[0]);
      if ( v31 >= 0x578 )
        v31 = 1399;
      v32 = snprintf(&v76[v31], 1400 - v31, "%s", httpd_servertok[0]);
      if ( v32 >= 1400 - v31 )
        v32 = 1399 - v31;
      v33 = v32 + v31;
      v34 = snprintf(&v76[v33], 1400 - v33, httpd_lengthtok[0], v4);
      if ( v34 >= 1400 - v33 )
        v34 = 1399 - v33;
      v35 = v34 + v33;
      if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
        v36 = httpd_ctalive;
      else
        v36 = httpd_ctclose;
      v37 = snprintf(&v76[v35], 1400 - v35, "%s", *v36);
      v38 = v37 + v35;
      if ( v37 >= 1400 - v35 )
        v38 = 1399;
      if ( (*(_DWORD *)(a1 + 36) & 0x1000) != 0 )
      {
        v74 = snprintf(&v76[v38], 1400 - v38, "Set-Cookie: %s; path=/\r\n", httpd_set_cookie);
        if ( v74 >= 1400 - v38 )
          v74 = 1399 - v38;
        *(_DWORD *)(a1 + 36) &= 0xFFFFEFFF;
        v38 += v74;
        memset(httpd_set_cookie, 0, sizeof(httpd_set_cookie));
      }
      v39 = snprintf(&v76[v38], 1400 - v38, "Pragma: no-cache\r\nCache-Control: no-cache\r\n");
      if ( v39 >= 1400 - v38 )
        v39 = 1399 - v38;
      v40 = *(_DWORD *)(a1 + 36);
      v41 = v39 + v38;
      if ( (v40 & 0x40000) != 0 )
      {
        v42 = 1400 - v41;
        v43 = snprintf(&v76[v41], 1400 - v41, "Content-Type: application/json;charset=utf-8\r\n\r\n");
      }
      else
      {
        v42 = 1400 - v41;
        if ( (v40 & 0x8000) != 0 )
          v43 = snprintf(&v76[v41], v42, "Content-Type: text/html;charset=utf-8\r\n\r\n");
        else
          v43 = snprintf(&v76[v41], v42, "Content-Type: text/html;charset=gb2312\r\n\r\n");
      }
      v44 = v43 + v41;
      if ( v43 >= v42 )
        v44 = 1399;
      v24 = v44 + v4;
      if ( v44 + v4 < 1400 )
        goto LABEL_106;
      goto LABEL_55;
    case 8:
      if ( (*(_DWORD *)(a1 + 32) & 2) != 0 )
        v46 = *(_DWORD *)(a1 + 36) | 1;
      else
        v46 = *(_DWORD *)(a1 + 36) & 0xFFFFFFFE;
      *(_DWORD *)(a1 + 36) = v46;
      v47 = snprintf(v76, 1400, "%s", httpd_oktok[0]);
      if ( v47 >= 0x578 )
        v47 = 1399;
      v48 = snprintf(&v76[v47], 1400 - v47, "%s", httpd_servertok[0]);
      if ( v48 >= 1400 - v47 )
        v48 = 1399 - v47;
      v49 = v48 + v47;
      v50 = snprintf(&v76[v49], 1400 - v49, httpd_lengthtok[0], v4);
      if ( v50 >= 1400 - v49 )
        v50 = 1399 - v49;
      v51 = v50 + v49;
      if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
        v52 = httpd_ctalive;
      else
        v52 = httpd_ctclose;
      v53 = snprintf(&v76[v51], 1400 - v51, "%s", *v52);
      v54 = v53 + v51;
      if ( v53 >= 1400 - v51 )
        v54 = 1399;
      if ( (*(_DWORD *)(a1 + 36) & 0x1000) != 0 )
      {
        v75 = snprintf(&v76[v54], 1400 - v54, "Set-Cookie: %s; path=/\r\n", httpd_set_cookie);
        if ( v75 >= 1400 - v54 )
          v75 = 1399 - v54;
        *(_DWORD *)(a1 + 36) &= 0xFFFFEFFF;
        v54 += v75;
        memset(httpd_set_cookie, 0, sizeof(httpd_set_cookie));
      }
      v55 = snprintf(&v76[v54], 1400 - v54, "Pragma: no-cache\r\nCache-Control: no-cache\r\n");
      if ( v55 >= 1400 - v54 )
        v55 = 1399 - v54;
      v56 = *(_DWORD *)(a1 + 36);
      v57 = v55 + v54;
      if ( (v56 & 0x40000) != 0 )
      {
        v58 = 1400 - v57;
        v59 = snprintf(&v76[v57], 1400 - v57, "Content-Type: application/json;charset=utf-8\r\n\r\n");
      }
      else
      {
        v58 = 1400 - v57;
        if ( (v56 & 0x8000) != 0 )
          v59 = snprintf(&v76[v57], v58, "Content-Type: text/html;charset=utf-8\r\n\r\n");
        else
          v59 = snprintf(&v76[v57], v58, "Content-Type: text/html;charset=gb2312\r\n\r\n");
      }
      v23 = v59 + v57;
      if ( v59 >= v58 )
        v23 = 1399;
      v24 = v23 + v4;
      if ( v23 + v4 < 1400 )
        goto LABEL_123;
      if ( httpd_send_data_alloc(a1, v76, v23) )
        goto LABEL_135;
      v25 = a2;
      if ( *(_DWORD *)(a1 + 205380) )
        goto LABEL_85;
      goto LABEL_26;
    case 16:
      if ( (*(_DWORD *)(a1 + 32) & 2) != 0 )
        v60 = *(_DWORD *)(a1 + 36) | 1;
      else
        v60 = *(_DWORD *)(a1 + 36) & 0xFFFFFFFE;
      *(_DWORD *)(a1 + 36) = v60;
      v61 = snprintf(v76, 1400, "%s", httpd_oktok[0]);
      if ( v61 >= 0x578 )
        v61 = 1399;
      v62 = snprintf(&v76[v61], 1400 - v61, "%s", httpd_servertok[0]);
      if ( v62 >= 1400 - v61 )
        v62 = 1399 - v61;
      v63 = v62 + v61;
      v64 = snprintf(&v76[v63], 1400 - v63, httpd_lengthtok[0], v4);
      if ( v64 >= 1400 - v63 )
        v64 = 1399 - v63;
      v65 = v64 + v63;
      if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
        v66 = httpd_ctalive;
      else
        v66 = httpd_ctclose;
      v67 = snprintf(&v76[v65], 1400 - v65, "%s", *v66);
      if ( v67 >= 1400 - v65 )
        v67 = 1399 - v65;
      v68 = v67 + v65;
      v69 = snprintf(&v76[v68], 1400 - v68, "Pragma: no-cache\r\nCache-Control: no-cache\r\n");
      if ( v69 >= 1400 - v68 )
        v69 = 1399 - v68;
      v70 = *(_DWORD *)(a1 + 36);
      v71 = v69 + v68;
      if ( (v70 & 0x40000) != 0 )
      {
        v72 = 1400 - v71;
        v73 = snprintf(&v76[v71], 1400 - v71, "Content-Type: application/json;charset=utf-8\r\n\r\n");
      }
      else
      {
        v72 = 1400 - v71;
        if ( (v70 & 0x8000) != 0 )
          v73 = snprintf(&v76[v71], v72, "Content-Type: text/html;charset=utf-8\r\n\r\n");
        else
          v73 = snprintf(&v76[v71], v72, "Content-Type: text/html;charset=gb2312\r\n\r\n");
      }
      v44 = v73 + v71;
      if ( v73 >= v72 )
        v44 = 1399;
      v24 = v44 + v4;
      if ( v44 + v4 < 1400 )
      {
LABEL_106:
        memcpy(&v76[v44], a2, v4);
        goto LABEL_107;
      }
LABEL_55:
      v45 = httpd_send_data_alloc(a1, v76, v44) != 0;
      result = -1;
      if ( v45 )
        return result;
      if ( !*(_DWORD *)(a1 + 205380) )
      {
        v26 = httpd_send_data_alloc(a1, a2, v4);
        goto LABEL_58;
      }
LABEL_109:
      httpd_conn_close((int *)a1);
      return -1;
    case 32:
      if ( (*(_DWORD *)(a1 + 32) & 2) != 0 )
        v7 = *(_DWORD *)(a1 + 36) | 1;
      else
        v7 = *(_DWORD *)(a1 + 36) & 0xFFFFFFFE;
      *(_DWORD *)(a1 + 36) = v7;
      v8 = snprintf(v76, 1400, "%s", httpd_oktok[0]);
      if ( v8 >= 0x578 )
        v8 = 1399;
      v9 = snprintf(&v76[v8], 1400 - v8, "%s", httpd_servertok[0]);
      if ( v9 >= 1400 - v8 )
        v9 = 1399 - v8;
      v10 = v9 + v8;
      v11 = snprintf(&v76[v10], 1400 - v10, "Content-Encoding: gzip\r\n");
      if ( v11 >= 1400 - v10 )
        v11 = 1399 - v10;
      v12 = v11 + v10;
      v13 = snprintf(&v76[v12], 1400 - v12, httpd_lengthtok[0], v4);
      if ( v13 >= 1400 - v12 )
        v13 = 1399 - v12;
      v14 = v13 + v12;
      if ( (*(_DWORD *)(a1 + 36) & 1) != 0 )
        v15 = httpd_ctalive;
      else
        v15 = httpd_ctclose;
      v16 = snprintf(&v76[v14], 1400 - v14, "%s", *v15);
      if ( v16 >= 1400 - v14 )
        v16 = 1399 - v14;
      v17 = v16 + v14;
      v18 = snprintf(&v76[v17], 1400 - v17, "Pragma: no-cache\r\nCache-Control: no-cache\r\n");
      if ( v18 >= 1400 - v17 )
        v18 = 1399 - v17;
      v19 = *(_DWORD *)(a1 + 36);
      v20 = v18 + v17;
      if ( (v19 & 0x40000) != 0 )
      {
        v21 = 1400 - v20;
        v22 = snprintf(&v76[v20], 1400 - v20, "Content-Type: application/json;charset=utf-8\r\n\r\n");
      }
      else
      {
        v21 = 1400 - v20;
        if ( (v19 & 0x8000) != 0 )
          v22 = snprintf(&v76[v20], v21, "Content-Type: text/html;charset=utf-8\r\n\r\n");
        else
          v22 = snprintf(&v76[v20], v21, "Content-Type: text/html;charset=gb2312\r\n\r\n");
      }
      v23 = v22 + v20;
      if ( v22 >= v21 )
        v23 = 1399;
      v24 = v23 + v4;
      if ( v23 + v4 < 1400 )
      {
LABEL_123:
        memcpy(&v76[v23], a2, v4);
        _mem_free(a2);
LABEL_107:
        v45 = httpd_send_data_alloc(a1, v76, v24) == 0;
        result = -1;
        if ( v45 )
        {
LABEL_59:
          if ( !*(_DWORD *)(a1 + 205380) )
            httpd_conn_send_finish(a1);
          return 0;
        }
      }
      else
      {
        if ( httpd_send_data_alloc(a1, v76, v23) )
        {
LABEL_135:
          _mem_free(a2);
          return -1;
        }
        v25 = a2;
        if ( *(_DWORD *)(a1 + 205380) )
        {
LABEL_85:
          _mem_free(v25);
          httpd_conn_close((int *)a1);
          return -1;
        }
LABEL_26:
        v26 = httpd_send_data_not_alloc(a1, a2, v4);
LABEL_58:
        v45 = v26 != 0;
        result = -1;
        if ( !v45 )
          goto LABEL_59;
      }
      return result;
    default:
      goto LABEL_109;
  }
}
// 427F4C: variable 'v4' is possibly undefined
// 6676B8: using guessed type char *httpd_lengthtok[22];
// 6676C0: using guessed type char *httpd_ctalive[20];
// 6676C4: using guessed type char *httpd_ctclose[19];
// 6676CC: using guessed type char *httpd_servertok[17];
// 6676D0: using guessed type char *httpd_oktok[16];
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);

