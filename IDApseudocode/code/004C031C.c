int __fastcall sub_4C031C(int a1)
{
  char **v1; // $v0
  const char **v3; // $v1
  char *v4; // $t0
  const char *v5; // $a3
  const char *v6; // $a2
  const char *v7; // $a1
  char *v8; // $a0
  const char *v9; // $v0
  char *v10; // $v0
  char *v11; // $s0
  int v12; // $v0
  int v13; // $s3
  char *v14; // $s1
  const char *v15; // $v0
  int v16; // $s3
  int *v17; // $v0
  int v18; // $v1
  int v19; // $a0
  int v20; // $v1
  char v21; // $a1
  char v22; // $v0
  const char *v23; // $v0
  bool v24; // dc
  char *v25; // $v0
  int *v26; // $v1
  int v27; // $a0
  int v28; // $a1
  int v29; // $a0
  int v30; // $v1
  const char *v31; // $v0
  int v32; // $s1
  char *v33; // $v0
  int *v34; // $v1
  int v35; // $a0
  int v36; // $a1
  int v37; // $a0
  char v38; // $v1
  const char *v39; // $v0
  int v40; // $s1
  char *v41; // $v0
  int *v42; // $v1
  int v43; // $a0
  int v44; // $a1
  int v45; // $a0
  char v46; // $v1
  const char *v47; // $v0
  int v48; // $s1
  char *v49; // $v0
  int *v50; // $v1
  int v51; // $a1
  int v52; // $a0
  int v53; // $a1
  int v54; // $a0
  char v55; // $v1
  const char *v56; // $v0
  int v57; // $s1
  char *v58; // $v0
  int *v59; // $v1
  int v60; // $a0
  int v61; // $a1
  int v62; // $a0
  char v63; // $v1
  int v64; // $s1
  int v65; // $a2
  int result; // $v0
  const char *v67; // $v0
  unsigned int v68; // $v0
  char v69[256]; // [sp+20h] [-12Ch] BYREF
  const char *v70[11]; // [sp+120h] [-2Ch] BYREF

  v1 = off_678AF0;
  v3 = v70;
  do
  {
    v4 = *v1;
    v5 = v1[1];
    v6 = v1[2];
    v7 = v1[3];
    v1 += 4;
    *v3 = v4;
    v3[1] = v5;
    v3[2] = v6;
    v3[3] = v7;
    v3 += 4;
  }
  while ( v1 != (char **)&off_678B10 );
  v8 = *v1;
  v9 = v1[1];
  *v3 = v8;
  v3[1] = v9;
  _mem_malloc(5000, "mr_clips_data", 1192);
  v11 = v10;
  if ( v10 )
  {
    strcpy(v10, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v10, "{\"code\":0,\"error", 16);
    v12 = get_nvarms(v70, (int)(v10 + 29), 4971);
    v13 = v12 + 29;
    v14 = &v11[v12 + 29];
    if ( v12 + 29 > 0 && *(v14 - 1) == 44 )
    {
      v13 = v12 + 28;
      v14 = &v11[v12 + 28];
    }
    *v14 = 0;
    v15 = (const char *)nvram_get("mrcl_dianxin");
    if ( v15 && *v15 && strlen(v15) >= 5 )
    {
      v16 = v13 + 18;
      v17 = &dword_64FFDC;
    }
    else
    {
      v16 = v13 + 18;
      v17 = &dword_64FFF0;
    }
    *(_DWORD *)v14 = 1768170028;
    v18 = v17[1];
    *(_DWORD *)v14 = 1768170028;
    *((_DWORD *)v14 + 1) = v18;
    v19 = v17[2];
    *((_DWORD *)v14 + 1) = v18;
    *((_DWORD *)v14 + 2) = v19;
    v20 = v17[3];
    *((_DWORD *)v14 + 2) = v19;
    LOBYTE(v19) = *((_BYTE *)v17 + 17);
    *((_DWORD *)v14 + 3) = v20;
    v21 = *((_BYTE *)v17 + 16);
    v14[17] = v19;
    v22 = *((_BYTE *)v17 + 18);
    v14[16] = v21;
    v14[18] = v22;
    v23 = (const char *)nvram_get("mrcl_wangtong");
    if ( v23 && *v23 && (v24 = strlen(v23) >= 5, v25 = &v11[v16], v24) )
    {
      v26 = &dword_650014;
    }
    else
    {
      v25 = &v11[v16];
      v26 = &dword_650028;
    }
    *(_DWORD *)v25 = 1635197484;
    v27 = v26[1];
    *(_DWORD *)v25 = 1635197484;
    *((_DWORD *)v25 + 1) = v27;
    v28 = v26[2];
    *((_DWORD *)v25 + 1) = v27;
    *((_DWORD *)v25 + 2) = v28;
    v29 = v26[3];
    *((_DWORD *)v25 + 2) = v28;
    *((_DWORD *)v25 + 3) = v29;
    v30 = v26[4];
    *((_DWORD *)v25 + 3) = v29;
    *((_DWORD *)v25 + 4) = v30;
    v31 = (const char *)nvram_get("mrcl_yidong");
    v32 = v16 + 19;
    if ( v31 && *v31 && (v24 = strlen(v31) >= 5, v33 = &v11[v32], v24) )
    {
      v34 = &dword_650048;
    }
    else
    {
      v33 = &v11[v32];
      v34 = &dword_65005C;
    }
    *(_DWORD *)v33 = 1769546284;
    v35 = v34[1];
    *(_DWORD *)v33 = 1769546284;
    *((_DWORD *)v33 + 1) = v35;
    v36 = v34[2];
    *((_DWORD *)v33 + 1) = v35;
    *((_DWORD *)v33 + 2) = v36;
    v37 = v34[3];
    *((_DWORD *)v33 + 2) = v36;
    *((_DWORD *)v33 + 3) = v37;
    LOBYTE(v36) = *((_BYTE *)v34 + 16);
    v38 = *((_BYTE *)v34 + 17);
    v33[16] = v36;
    v33[17] = v38;
    v39 = (const char *)nvram_get("mrcl_jiaoyu");
    v40 = v16 + 36;
    if ( v39 && *v39 && (v24 = strlen(v39) >= 5, v41 = &v11[v40], v24) )
    {
      v42 = &dword_65007C;
    }
    else
    {
      v41 = &v11[v40];
      v42 = &dword_650090;
    }
    *(_DWORD *)v41 = 1768563244;
    v43 = v42[1];
    *(_DWORD *)v41 = 1768563244;
    *((_DWORD *)v41 + 1) = v43;
    v44 = v42[2];
    *((_DWORD *)v41 + 1) = v43;
    *((_DWORD *)v41 + 2) = v44;
    v45 = v42[3];
    *((_DWORD *)v41 + 2) = v44;
    *((_DWORD *)v41 + 3) = v45;
    LOBYTE(v44) = *((_BYTE *)v42 + 16);
    v46 = *((_BYTE *)v42 + 17);
    v41[16] = v44;
    v41[17] = v46;
    v47 = (const char *)nvram_get("mrcl_changcheng");
    v48 = v16 + 53;
    if ( v47 && *v47 && (v24 = strlen(v47) >= 5, v49 = &v11[v48], v24) )
    {
      v50 = &dword_6500B4;
    }
    else
    {
      v49 = &v11[v48];
      v50 = &dword_6500CC;
    }
    *(_DWORD *)v49 = 1751327276;
    v51 = v50[1];
    *(_DWORD *)v49 = 1751327276;
    *((_DWORD *)v49 + 1) = v51;
    v52 = v50[2];
    *((_DWORD *)v49 + 1) = v51;
    *((_DWORD *)v49 + 2) = v52;
    v53 = v50[3];
    *((_DWORD *)v49 + 2) = v52;
    *((_DWORD *)v49 + 3) = v53;
    v54 = v50[4];
    *((_DWORD *)v49 + 3) = v53;
    *((_DWORD *)v49 + 4) = v54;
    LOBYTE(v53) = *((_BYTE *)v50 + 20);
    v55 = *((_BYTE *)v50 + 21);
    v49[20] = v53;
    v49[21] = v55;
    v56 = (const char *)nvram_get("mrcl_china");
    v57 = v16 + 74;
    if ( v56 && *v56 && (v24 = strlen(v56) >= 5, v58 = &v11[v57], v24) )
    {
      v59 = &dword_6500F0;
    }
    else
    {
      v58 = &v11[v57];
      v59 = &dword_650104;
    }
    *(_DWORD *)v58 = 1751327276;
    v60 = v59[1];
    *(_DWORD *)v58 = 1751327276;
    *((_DWORD *)v58 + 1) = v60;
    v61 = v59[2];
    *((_DWORD *)v58 + 1) = v60;
    *((_DWORD *)v58 + 2) = v61;
    v62 = v59[3];
    *((_DWORD *)v58 + 2) = v61;
    v63 = *((_BYTE *)v59 + 16);
    v64 = v16 + 90;
    *((_DWORD *)v58 + 3) = v62;
    *((_DWORD *)v58 + 3) = v62;
    v58[16] = v63;
    v65 = snprintf(&v11[v64], 5000 - v64, "}}");
    if ( v65 >= 5000 - (v16 + 90) )
      v65 = 4999 - v64;
    result = httpd_cgi_ret(a1, v11, v64 + v65, 8);
  }
  else
  {
    v67 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 5000);
    v68 = snprintf(v69, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v67);
    if ( v68 >= 0x100 )
      v68 = 255;
    result = httpd_cgi_ret(a1, v69, v68, 4);
  }
  return result;
}
// 4C03B8: variable 'v10' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 64FFDC: using guessed type int dword_64FFDC;
// 64FFF0: using guessed type int dword_64FFF0;
// 650014: using guessed type int dword_650014;
// 650028: using guessed type int dword_650028;
// 650048: using guessed type int dword_650048;
// 65005C: using guessed type int dword_65005C;
// 65007C: using guessed type int dword_65007C;
// 650090: using guessed type int dword_650090;
// 6500B4: using guessed type int dword_6500B4;
// 6500CC: using guessed type int dword_6500CC;
// 6500F0: using guessed type int dword_6500F0;
// 650104: using guessed type int dword_650104;
// 678AF0: using guessed type char *off_678AF0[8];
// 678B10: using guessed type void *off_678B10;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

