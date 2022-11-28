int __fastcall sub_4ACA0C(int a1)
{
  int v1; // $v0
  int v2; // $fp
  char *v3; // $s2
  int v4; // $s1
  int v5; // $s3
  int v6; // $v0
  const char *v7; // $v0
  char *v8; // $s4
  char *v9; // $v0
  char *v10; // $s0
  int v11; // $v0
  int v12; // $s5
  char *v13; // $v1
  int v14; // $v0
  unsigned int v15; // $v0
  char *v16; // $v1
  char *v17; // $a0
  struct tm *v18; // $v0
  const char *v19; // $v0
  char *v20; // $v0
  int v21; // $a0
  int v22; // $v0
  char *v23; // $a0
  int v24; // $v0
  int v25; // $s3
  int v26; // $v0
  int v27; // $s3
  int v28; // $v0
  int v29; // $a2
  struct tm *v31; // $v0
  const char *v32; // $v0
  char *v33; // $v0
  const char *v34; // $v0
  unsigned int v35; // $v0
  char v36[1024]; // [sp+48h] [-1448h] BYREF
  __int16 v37[512]; // [sp+448h] [-1048h] BYREF
  __int16 v38; // [sp+848h] [-C48h] BYREF
  char v39[1024]; // [sp+C48h] [-848h] BYREF
  char v40[256]; // [sp+1048h] [-448h] BYREF
  char v41[256]; // [sp+1148h] [-348h] BYREF
  struct stat v42; // [sp+1248h] [-248h] BYREF
  char v43[128]; // [sp+12E8h] [-1A8h] BYREF
  char v44[64]; // [sp+1368h] [-128h] BYREF
  char v45[64]; // [sp+13A8h] [-E8h] BYREF
  char *nptr; // [sp+13E8h] [-A8h] BYREF
  char *v47; // [sp+13ECh] [-A4h]
  int v48; // [sp+13F0h] [-A0h]
  char *src; // [sp+13F4h] [-9Ch]
  int v50; // [sp+13F8h] [-98h]
  int v51; // [sp+13FCh] [-94h]
  int v52; // [sp+1400h] [-90h]
  int v53; // [sp+1404h] [-8Ch]
  int v54; // [sp+1408h] [-88h]
  int v55[8]; // [sp+1414h] [-7Ch] BYREF
  char v56[32]; // [sp+1434h] [-5Ch] BYREF
  unsigned int v57; // [sp+1454h] [-3Ch] BYREF
  char *v58; // [sp+1458h] [-38h] BYREF
  char *v59; // [sp+1460h] [-30h]
  char *v60; // [sp+1464h] [-2Ch]
  char *dest; // [sp+1468h] [-28h]
  char *v62; // [sp+146Ch] [-24h]
  char *str; // [sp+1470h] [-20h]
  char *s; // [sp+1474h] [-1Ch]
  char *format; // [sp+1478h] [-18h]
  char *v66; // [sp+147Ch] [-14h]
  char *v67; // [sp+1480h] [-10h]
  char *v68; // [sp+1484h] [-Ch]
  const char *v69; // [sp+1488h] [-8h]
  char *v70; // [sp+148Ch] [-4h]

  s = v45;
  memset(v45, 0, sizeof(v45));
  memset(v36, 0, sizeof(v36));
  v2 = sq_file_get_max_wan();
  _mem_malloc(0x200000, "base_ddns_data", 361);
  v3 = (char *)v1;
  if ( !v1 )
  {
    v34 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    str = (char *)v37;
    v35 = snprintf((char *)v37, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v34);
    if ( v35 >= 0x100 )
      v35 = 255;
    return httpd_cgi_ret(a1, str, v35, 4);
  }
  qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\",\"data\":{\"all", 33);
  qmemcpy((void *)v1, "{\"code\":0,\"error", 16);
  *(_DWORD *)(v1 + 24) = 975331700;
  *(_BYTE *)(v1 + 32) = 108;
  *(_DWORD *)(v1 + 33) = &unk_5B3A22;
  *(_DWORD *)(v1 + 33) = &unk_5B3A22;
  if ( v2 <= 0 )
  {
    v22 = 35;
    v21 = 36;
    v5 = 36;
    goto LABEL_38;
  }
  v4 = 0;
  v59 = "1\"";
  v5 = 36;
  v69 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
  v66 = "1\"";
  v62 = "oray";
  format = (char *)&unk_64D734;
  v67 = "{\"wans\":%d,\"id\":%d,\"serv\":\"%s\",\"user\":\"%s\",\"host\":\"%s\",\"wild\":\"%s\",\"mx\":\"%s\",\"bmx\":\"%"
        "s\",\"cust\":\"%s\",\"ip\":\"%s\",\"msg\":\"%s\",\"state\":\"%s\",\"type\":\"%s\"},";
  do
  {
    v6 = jhl_nvget(v59 - 10548, v4);
    v7 = (const char *)nvram_get(v6);
    if ( !v7 )
      v7 = v69 - 1556;
    v8 = v39;
    if ( *v7 )
    {
      strlcpy(v39, v7, 1024);
      v68 = "1\"";
      while ( 1 )
      {
        while ( 1 )
        {
          if ( !*v8 )
            goto LABEL_4;
          v9 = strchr(v8, 60);
          v10 = v9;
          if ( v9 )
            break;
          if ( split_string(v8, 124, &nptr, 9) != 9 )
          {
            ++v4;
            goto LABEL_5;
          }
LABEL_16:
          v12 = atoi(nptr);
          if ( !strcmp(v47, v62) )
          {
            sprintf(v56, "orayddnsx%d_%d", v4, v12);
            sprintf(s, "/var/lib/mdu/domainfile%d_%d.url", v4, v12);
            sprintf(v44, "/var/lib/mdu/orayusertype%d_%d", v4, v12);
          }
          else
          {
            sprintf(v56, "ddnsx%d_%d", v4, v12);
          }
          sprintf(v43, format, v56);
          v60 = v40;
          v38 = 32;
          v37[0] = 32;
          f_read_string(v43, v40, 256);
          dest = (char *)&v38;
          str = (char *)v37;
          if ( v40[0] )
          {
            if ( stat(v43, &v42) || v42.st_ctim.tv_sec < 0x5FEDF581u )
            {
              v20 = (char *)get_json_data(v60);
              strcpy(dest, v20);
            }
            else
            {
              v31 = localtime(&v42.st_ctim.tv_sec);
              v70 = v41;
              strftime(v41, 0x100u, "%F %H:%M:%S ", v31);
              v32 = (const char *)get_json_data(v60);
              sprintf(dest, "%s %s", v70, v32);
            }
          }
          sprintf(v43, v66 - 10400, v56);
          f_read_string(v43, v60, 256);
          if ( v40[0] )
          {
            v15 = strtoul(v60, &v58, 10);
            v16 = v58;
            v57 = v15;
            v17 = ++v58;
            if ( *v16 == 44 )
            {
              if ( v15 < 0x5FEDF581 )
              {
                v33 = (char *)get_json_data(v17);
                strcpy(str, v33);
              }
              else
              {
                v18 = localtime((const time_t *)&v57);
                strftime(v41, 0x100u, v68 - 10376, v18);
                v19 = (const char *)get_json_data(v58);
                sprintf(str, "%s %s", v41, v19);
              }
            }
          }
          memset(v36, 0, sizeof(v36));
          v55[0] = 0;
          v60 = v47;
          v55[1] = 0;
          v55[2] = 0;
          v55[3] = 0;
          v55[4] = 0;
          v55[5] = 0;
          v55[6] = 0;
          v55[7] = 0;
          if ( !strcmp(v47, v62) )
          {
            f_read_string(s, v36, 1024);
            f_read_string(v44, v55, 32);
            v13 = v47;
          }
          else
          {
            strcpy(v36, src);
            v13 = v60;
          }
          v60 = (char *)0x200000;
          v14 = snprintf(&v3[v5], 0x200000 - v5, v67, v4, v12, v13, v48, v36, v50, v51, v52, v53, v54, dest, str, v55);
          v8 = v10;
          if ( v14 >= 0x200000 - v5 )
            v14 = (int)&v60[-v5 - 1];
          v5 += v14;
          if ( !v10 )
          {
            ++v4;
            goto LABEL_5;
          }
        }
        *v9 = 0;
        v11 = split_string(v8, 124, &nptr, 9);
        v8 = v10 + 1;
        if ( v11 == 9 )
        {
          ++v10;
          goto LABEL_16;
        }
        if ( v10 == (char *)-1 )
        {
          ++v4;
          goto LABEL_5;
        }
      }
    }
LABEL_4:
    ++v4;
LABEL_5:
    ;
  }
  while ( v2 != v4 );
  v21 = v5;
  if ( v5 > 0 )
  {
    v22 = v5 - 1;
LABEL_38:
    if ( v3[v22] == 44 )
      v21 = --v5;
  }
  v23 = &v3[v21];
  *v23 = 0;
  v24 = snprintf(v23, 0x200000 - v5, (char *)&dword_6463E0);
  if ( v24 >= 0x200000 - v5 )
    v24 = 0x1FFFFF - v5;
  v25 = v5 + v24 + get_wans_data(&v3[v5 + v24], 0x200000 - (v5 + v24));
  v26 = snprintf(&v3[v25], 0x200000 - v25, ",\"ddns_show\":\"%d\",\"dnspod\":\"%d\"", 0, 1);
  if ( v26 >= 0x200000 - v25 )
    v26 = 0x1FFFFF - v25;
  v27 = v26 + v25;
  v28 = snprintf(&v3[v27], 0x200000 - v27, "}}");
  if ( v28 >= 0x200000 - v27 )
    v29 = 0x1FFFFF - v27;
  else
    v29 = v28;
  return httpd_cgi_ret(a1, v3, v29 + v27, 8);
}
// 4ACAC4: variable 'v1' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6463E0: using guessed type int dword_6463E0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83D4: using guessed type int __fastcall f_read_string(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

