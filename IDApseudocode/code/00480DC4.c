int __fastcall sub_480DC4(int a1)
{
  char *v2; // $s3
  char *v3; // $v0
  char *v4; // $s4
  int v5; // $t2
  int v6; // $t1
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  const char *v10; // $s6
  char *v11; // $fp
  int v12; // $v0
  struct tm *v13; // $s5
  unsigned int v14; // $v0
  int v15; // $s1
  unsigned int v16; // $s7
  int v17; // $a2
  int v18; // $v0
  int v19; // $v0
  unsigned int v20; // $v0
  const char *v22; // $v0
  int *v23; // $v1
  int v24; // $t0
  int v25; // $a3
  int v26; // $a2
  int v27; // $a1
  int v28; // $a2
  int v29; // $a1
  __int16 v30; // $a0
  char v31; // $v0
  const char *v32; // $v0
  int v33; // $a1
  int v34; // $a0
  char *v35; // $v0
  const char *v36; // $s4
  char *v37; // $v0
  char *v38; // $v0
  const char *v39; // $a2
  const char *v40; // $v0
  unsigned int v41; // $s1
  unsigned int v42; // $v0
  const char *v43; // $s2
  const char *v44; // $s3
  int v45; // $s4
  const char *v46; // $v0
  char v47[2048]; // [sp+38h] [-1980h] BYREF
  char v48[2048]; // [sp+838h] [-1180h] BYREF
  int v49[256]; // [sp+1038h] [-980h] BYREF
  int v50[6]; // [sp+1438h] [-580h] BYREF
  char v51[4]; // [sp+1450h] [-568h] BYREF
  char v52[256]; // [sp+1838h] [-180h] BYREF
  int v53[12]; // [sp+1938h] [-80h] BYREF
  int v54[8]; // [sp+1968h] [-50h] BYREF
  int v55; // [sp+1988h] [-30h] BYREF
  int v56; // [sp+198Ch] [-2Ch]
  int v57; // [sp+1990h] [-28h]
  int v58; // [sp+1994h] [-24h]
  int v59; // [sp+1998h] [-20h]
  int v60[2]; // [sp+199Ch] [-1Ch] BYREF
  time_t v61; // [sp+19A4h] [-14h] BYREF
  int *v62; // [sp+19A8h] [-10h]
  const char *v63; // [sp+19ACh] [-Ch]
  const char *v64; // [sp+19B0h] [-8h]

  memset(v48, 0, sizeof(v48));
  v60[0] = 0;
  v60[1] = 0;
  v53[0] = 0;
  v53[1] = 0;
  v53[2] = 0;
  v53[3] = 0;
  v53[4] = 0;
  v53[5] = 0;
  v53[6] = 0;
  v53[7] = 0;
  v53[8] = 0;
  v53[9] = 0;
  v53[10] = 0;
  v53[11] = 0;
  v54[0] = 0;
  v54[1] = 0;
  v54[2] = 0;
  v54[3] = 0;
  v54[4] = 0;
  v54[5] = 0;
  v54[6] = 0;
  v54[7] = 0;
  memset(v52, 0, sizeof(v52));
  v2 = httpd_get_parm(a1, "usr");
  v4 = httpd_get_parm(a1, (char *)&off_649194);
  v3 = httpd_get_parm(a1, "callback");
  v5 = *(_DWORD *)(a1 + 205460);
  v6 = *(_DWORD *)(a1 + 205464);
  v7 = *(_DWORD *)(a1 + 205468);
  v8 = *(_DWORD *)(a1 + 205472);
  v9 = *(_DWORD *)(a1 + 205476);
  v62 = v53;
  v55 = v5;
  v56 = v6;
  v57 = v7;
  v58 = v8;
  v59 = v9;
  v10 = v3;
  IpaddrToStr(v53, &v55);
  MacToStr(v54, v60);
  if ( (*(_DWORD *)(a1 + 32) & 0x10000) != 0 )
  {
    v11 = *(char **)(a1 + 205528);
    if ( v11 )
    {
      v12 = strlen(v11);
      web_get_user_agent((unsigned __int8 *)v11, v12, v52, 255);
    }
  }
  time(&v61);
  v13 = localtime(&v61);
  v14 = snprintf(
          v48,
          2048,
          a04d02d02d02d02_0,
          v13->tm_year + 1900,
          v13->tm_mon + 1,
          v13->tm_mday,
          v13->tm_hour,
          v13->tm_min,
          v13->tm_sec,
          v54,
          v62,
          v52);
  if ( v2 )
  {
    v15 = v14;
    if ( v4 )
    {
      if ( v14 >= 0x800 )
        v15 = 2047;
      v16 = snprintf(&v48[v15], 2048 - v15, aSS_14, v2, v4);
      if ( v16 >= 2048 - v15 )
        v16 = 2047 - v15;
      memset(v49, 0, sizeof(v49));
      v63 = (const char *)&v49[4];
      v49[0] = 16;
      v49[3] = 18;
      v49[1] = 1024;
      v49[36] = v55;
      v49[37] = v56;
      v49[38] = v57;
      v49[39] = v58;
      v49[40] = v59;
      strlcpy(&v49[4], v2, 64);
      strlcpy(&v49[20], v4, 64);
      v49[41] = 0;
      LOBYTE(v49[43]) = 0;
      check_client_is_or_not_mobile(a1);
      if ( v18 )
        v49[41] = 1;
      if ( jianhl_order_opt_fun(v49, v49[1], v17) || v49[2] )
      {
        v50[0] = 1701978747;
        v19 = 26;
        v50[1] = 825893492;
        v50[2] = 1936532012;
        v50[3] = 574235239;
        v50[4] = -1278364209;
        v50[5] = -204542540;
        strcpy(v51, "\"}");
      }
      else
      {
        switch ( v49[42] )
        {
          case 1:
          case 2:
            v32 = (const char *)_GET_LANG_TEXT(169, *(unsigned __int8 *)(a1 + 210102), v49[42]);
            goto LABEL_26;
          case 3:
            v32 = (const char *)_GET_LANG_TEXT(170, *(unsigned __int8 *)(a1 + 210102), v49[42]);
            goto LABEL_26;
          case 4:
          case 5:
          case 0xC:
          case 0xE:
            v33 = *(unsigned __int8 *)(a1 + 210102);
            v34 = 171;
            goto LABEL_30;
          case 7:
            v32 = (const char *)_GET_LANG_TEXT(172, *(unsigned __int8 *)(a1 + 210102), v49[42]);
            goto LABEL_26;
          case 8:
            v32 = (const char *)_GET_LANG_TEXT(173, *(unsigned __int8 *)(a1 + 210102), v49[42]);
            goto LABEL_26;
          case 9:
            v32 = (const char *)_GET_LANG_TEXT(174, *(unsigned __int8 *)(a1 + 210102), v49[42]);
            goto LABEL_26;
          case 0xA:
            v32 = (const char *)_GET_LANG_TEXT(175, *(unsigned __int8 *)(a1 + 210102), v49[42]);
            goto LABEL_26;
          case 0xB:
          case 0x11:
            v35 = strstr((const char *)&v49[45], ">>");
            if ( v35 )
            {
              v36 = v35 + 2;
              *v35 = 0;
              v37 = strstr(v35 + 2, ">>");
              if ( v37 )
              {
                v64 = v37 + 2;
                *v37 = 0;
                v38 = strstr(v37 + 2, ">>");
                v39 = v64;
                if ( v38 )
                {
                  *v38 = 0;
                  v40 = v38 + 2;
                }
                else
                {
                  v40 = "";
                }
              }
              else
              {
                v40 = "";
                v39 = "";
              }
            }
            else
            {
              v40 = "";
              v39 = "";
              v36 = "";
            }
            v41 = v16 + v15;
            v42 = snprintf(&v48[v41], 2048 - v41, "\t%s\t%s\t%s\t%s\n", v36, v39, v40, (const char *)&v49[45]);
            if ( v42 >= 2048 - v41 )
              v42 = 2047 - v41;
            auth_write_usblog(v13, v48, v42 + v41);
            v43 = (const char *)nvram_get("rzgl_redirct_en");
            if ( !v43 )
              v43 = "0";
            v44 = (const char *)nvram_get("rzgl_redirct_url");
            if ( !v44 )
              v44 = "";
            v45 = v49[37];
            v46 = (const char *)IpaddrToStr(v62, &v49[36]);
            v19 = sprintf(
                    (char *)v50,
                    "{\"ret\":0,\"u\":\"%s\",\"i\":%u,\"i6\":\"%s\",\"e\":\"%s\",\"l\":\"%s\",\"isto_en\":\"%d\"}",
                    v63,
                    v45,
                    v46,
                    v43,
                    v44,
                    0);
            break;
          case 0xF:
            return webauth_data((_DWORD *)a1);
          case 0x10:
            v32 = (const char *)_GET_LANG_TEXT(176, *(unsigned __int8 *)(a1 + 210102), v49[42]);
            goto LABEL_26;
          default:
            v33 = *(unsigned __int8 *)(a1 + 210102);
            v34 = 177;
LABEL_30:
            v32 = (const char *)_GET_LANG_TEXT(v34, v33, v49[42]);
LABEL_26:
            v19 = sprintf((char *)v50, "{\"ret\":1,\"msg\":\"%s\"}", v32);
            break;
        }
      }
      if ( v10 )
        goto LABEL_17;
      return httpd_cgi_ret(a1, (char *)v50, v19, 4);
    }
  }
  v22 = "{\"ret\":1,\"msg\":\"not user or password err\"}";
  v23 = v50;
  do
  {
    v24 = *(_DWORD *)v22;
    v25 = *((_DWORD *)v22 + 1);
    v26 = *((_DWORD *)v22 + 2);
    v27 = *((_DWORD *)v22 + 3);
    v22 += 16;
    *v23 = v24;
    v23[1] = v25;
    v23[2] = v26;
    v23[3] = v27;
    v23 += 4;
  }
  while ( v22 != "word err\"}" );
  v28 = *(_DWORD *)v22;
  v29 = *((_DWORD *)v22 + 1);
  v30 = *((_WORD *)v22 + 4);
  v31 = v22[10];
  *v23 = v28;
  *((_BYTE *)v23 + 10) = v31;
  v23[1] = v29;
  *((_WORD *)v23 + 4) = v30;
  v19 = 42;
  if ( !v10 )
    return httpd_cgi_ret(a1, (char *)v50, v19, 4);
LABEL_17:
  memset(v47, 0, sizeof(v47));
  v20 = snprintf(v47, 2048, "try{%s(%s);}catch(e){}", v10, (const char *)v50);
  if ( v20 >= 0x800 )
    v20 = 2047;
  return httpd_cgi_ret(a1, v47, v20, 4);
}
// 48115C: variable 'v18' is possibly undefined
// 481170: variable 'v17' is possibly undefined
// 649194: using guessed type char *off_649194;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A835C: using guessed type int __fastcall auth_write_usblog(_DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

