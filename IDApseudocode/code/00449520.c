int __fastcall sub_449520(int a1)
{
  const char *v1; // $v0
  const char *v2; // $s2
  const char *v3; // $v1
  char *v4; // $v0
  int v5; // $t0
  int v6; // $a3
  int v7; // $a2
  int v8; // $a1
  int v9; // $a1
  int v10; // $a0
  __int16 v11; // $v1
  const char *v12; // $v0
  char *v13; // $s0
  int v14; // $a3
  int v15; // $a2
  int v16; // $a1
  int v17; // $a0
  const char *v18; // $v0
  char *v19; // $s0
  int v20; // $a3
  int v21; // $a2
  int v22; // $a1
  int v23; // $a0
  int v24; // $a3
  __int16 v25; // $a2
  int v26; // $s0
  const char **v27; // $s2
  void *v28; // $v0
  _DWORD *v29; // $s7
  int v30; // $s4
  int v31; // $a1
  void *v32; // $s0
  int v33; // $s5
  _DWORD *v34; // $fp
  int v35; // $s0
  int i; // $s6
  int v37; // $v0
  int v38; // $v0
  int v39; // $v0
  int v40; // $s0
  unsigned int v41; // $v0
  unsigned int v42; // $s0
  unsigned int v43; // $v0
  const char *v45; // $v0
  char *v46; // $s0
  int v47; // $a3
  int v48; // $a2
  int v49; // $a1
  int v50; // $a0
  int v51; // $a0
  int v52; // $a1
  const char *v53; // $v1
  char *v54; // $v0
  int v55; // $t0
  int v56; // $a3
  int v57; // $a2
  int v58; // $a1
  int v59; // $a0
  int v60; // $v1
  const char *v61; // $v1
  char *v62; // $v0
  int v63; // $t0
  int v64; // $a3
  int v65; // $a2
  int v66; // $a1
  const char *v67; // $v1
  char *v68; // $v0
  int v69; // $t0
  int v70; // $a3
  int v71; // $a2
  int v72; // $a1
  const char *v73; // $v0
  char *v74; // $s0
  int v75; // $a3
  int v76; // $a2
  int v77; // $a1
  int v78; // $a0
  __int16 v79; // $t3
  const char *v80; // $v1
  char *v81; // $v0
  int v82; // $t0
  int v83; // $a3
  int v84; // $a2
  int v85; // $a1
  int v86; // $a1
  const char *v87; // $v1
  char *v88; // $v0
  int v89; // $t0
  int v90; // $a3
  int v91; // $a2
  int v92; // $a1
  int v93; // $a1
  int v94; // $a0
  int v95; // $v1
  const char *v96; // $v1
  char *v97; // $v0
  int v98; // $t0
  int v99; // $a3
  int v100; // $a2
  int v101; // $a1
  int v102; // $a0
  __int16 v103; // $v1
  const char *v104; // $v1
  char *v105; // $v0
  int v106; // $t0
  int v107; // $a3
  int v108; // $a2
  int v109; // $a1
  char v110[102400]; // [sp+20h] [-1E008h] BYREF
  char v111[10240]; // [sp+19020h] [-5008h] BYREF
  char v112[10240]; // [sp+1B820h] [-2808h] BYREF
  void *v113; // [sp+1E020h] [-8h]

  memset(v110, 0, sizeof(v110));
  memset(v112, 0, sizeof(v112));
  memset(v111, 0, sizeof(v111));
  v1 = (const char *)nvram_get("vlan_name");
  if ( v1 )
  {
    v2 = v1;
    if ( !strcmp(v1, "L123456789") )
    {
      v18 = "eth3.4081 eth3.4082 eth3.4083 eth3.4084 eth3.4085 eth2.4081 eth2.4082 eth2.4083 eth2.4084";
      v19 = v112;
      do
      {
        v20 = *(_DWORD *)v18;
        v21 = *((_DWORD *)v18 + 1);
        v22 = *((_DWORD *)v18 + 2);
        v23 = *((_DWORD *)v18 + 3);
        v18 += 16;
        *(_DWORD *)v19 = v20;
        *((_DWORD *)v19 + 1) = v21;
        *((_DWORD *)v19 + 2) = v22;
        *((_DWORD *)v19 + 3) = v23;
        v19 += 16;
      }
      while ( v18 != "eth2.4084" );
      v24 = *((_DWORD *)v18 + 1);
      v25 = *((_WORD *)v18 + 4);
      *(_DWORD *)v19 = *(_DWORD *)v18;
      *((_DWORD *)v19 + 1) = v24;
      *((_WORD *)v19 + 4) = v25;
      strcpy(v111, "eth2.4085");
      goto LABEL_20;
    }
    if ( !strcmp(v2, "L12345678") )
    {
      v12 = "eth3.4081 eth3.4082 eth3.4083 eth3.4084 eth3.4085 eth2.4081 eth2.4082 eth2.4083";
      v13 = v112;
      do
      {
        v14 = *(_DWORD *)v12;
        v15 = *((_DWORD *)v12 + 1);
        v16 = *((_DWORD *)v12 + 2);
        v17 = *((_DWORD *)v12 + 3);
        v12 += 16;
        *(_DWORD *)v13 = v14;
        *((_DWORD *)v13 + 1) = v15;
        *((_DWORD *)v13 + 2) = v16;
        *((_DWORD *)v13 + 3) = v17;
        v13 += 16;
      }
      while ( v12 != "eth2.4085 eth2.4084" );
      strcpy(v111, "eth2.4085 eth2.4084");
      goto LABEL_20;
    }
    if ( !strcmp(v2, "L1234567") )
    {
      v73 = "eth3.4081 eth3.4082 eth3.4083 eth3.4084 eth3.4085 eth2.4081 eth2.4082";
      v74 = v112;
      do
      {
        v75 = *(_DWORD *)v73;
        v76 = *((_DWORD *)v73 + 1);
        v77 = *((_DWORD *)v73 + 2);
        v78 = *((_DWORD *)v73 + 3);
        v73 += 16;
        *(_DWORD *)v74 = v75;
        *((_DWORD *)v74 + 1) = v76;
        *((_DWORD *)v74 + 2) = v77;
        *((_DWORD *)v74 + 3) = v78;
        v74 += 16;
      }
      while ( v73 != ".4082" );
      v79 = *((_WORD *)v73 + 2);
      *(_DWORD *)v74 = *(_DWORD *)v73;
      *((_WORD *)v74 + 2) = v79;
      strcpy(v111, "eth2.4085 eth2.4084 eth2.4083");
      goto LABEL_20;
    }
    if ( !strcmp(v2, "L123456") )
    {
      v45 = "eth3.4081 eth3.4082 eth3.4083 eth3.4084 eth3.4085 eth2.4081";
      v46 = v112;
      do
      {
        v47 = *(_DWORD *)v45;
        v48 = *((_DWORD *)v45 + 1);
        v49 = *((_DWORD *)v45 + 2);
        v50 = *((_DWORD *)v45 + 3);
        v45 += 16;
        *(_DWORD *)v46 = v47;
        *((_DWORD *)v46 + 1) = v48;
        *((_DWORD *)v46 + 2) = v49;
        *((_DWORD *)v46 + 3) = v50;
        v46 += 16;
      }
      while ( v45 != "5 eth2.4081" );
      v51 = *((_DWORD *)v45 + 1);
      v52 = *(_DWORD *)v45;
      *((_DWORD *)v46 + 2) = *((_DWORD *)v45 + 2);
      v53 = "eth2.4085 eth2.4084 eth2.4083 eth2.4082";
      *((_DWORD *)v46 + 1) = v51;
      *(_DWORD *)v46 = v52;
      v54 = v111;
      do
      {
        v55 = *(_DWORD *)v53;
        v56 = *((_DWORD *)v53 + 1);
        v57 = *((_DWORD *)v53 + 2);
        v58 = *((_DWORD *)v53 + 3);
        v53 += 16;
        *(_DWORD *)v54 = v55;
        *((_DWORD *)v54 + 1) = v56;
        *((_DWORD *)v54 + 2) = v57;
        *((_DWORD *)v54 + 3) = v58;
        v54 += 16;
      }
      while ( v53 != "h2.4082" );
      v59 = *(_DWORD *)v53;
      v60 = *((_DWORD *)v53 + 1);
      *(_DWORD *)v54 = v59;
      *((_DWORD *)v54 + 1) = v60;
      goto LABEL_20;
    }
  }
  else
  {
    v2 = "";
  }
  if ( !strcmp(v2, "L12345") )
  {
    v61 = "eth3.4081 eth3.4082 eth3.4083 eth3.4084 eth3.4085";
    v62 = v112;
    do
    {
      v63 = *(_DWORD *)v61;
      v64 = *((_DWORD *)v61 + 1);
      v65 = *((_DWORD *)v61 + 2);
      v66 = *((_DWORD *)v61 + 3);
      v61 += 16;
      *(_DWORD *)v62 = v63;
      *((_DWORD *)v62 + 1) = v64;
      *((_DWORD *)v62 + 2) = v65;
      *((_DWORD *)v62 + 3) = v66;
      v62 += 16;
    }
    while ( v61 != "5" );
    *(_WORD *)v62 = *(_WORD *)v61;
    v67 = "eth2.4085 eth2.4084 eth2.4083 eth2.4082 eth2.4081";
    v68 = v111;
    do
    {
      v69 = *(_DWORD *)v67;
      v70 = *((_DWORD *)v67 + 1);
      v71 = *((_DWORD *)v67 + 2);
      v72 = *((_DWORD *)v67 + 3);
      v67 += 16;
      *(_DWORD *)v68 = v69;
      *((_DWORD *)v68 + 1) = v70;
      *((_DWORD *)v68 + 2) = v71;
      *((_DWORD *)v68 + 3) = v72;
      v68 += 16;
    }
    while ( v67 != "1" );
    *(_WORD *)v68 = *(_WORD *)v67;
  }
  else if ( !strcmp(v2, "L1234") )
  {
    v80 = "eth3.4081 eth3.4082 eth3.4083 eth3.4084";
    v81 = v112;
    do
    {
      v82 = *(_DWORD *)v80;
      v83 = *((_DWORD *)v80 + 1);
      v84 = *((_DWORD *)v80 + 2);
      v85 = *((_DWORD *)v80 + 3);
      v80 += 16;
      *(_DWORD *)v81 = v82;
      *((_DWORD *)v81 + 1) = v83;
      *((_DWORD *)v81 + 2) = v84;
      *((_DWORD *)v81 + 3) = v85;
      v81 += 16;
    }
    while ( v80 != "h3.4084" );
    v86 = *(_DWORD *)v80;
    *((_DWORD *)v81 + 1) = *((_DWORD *)v80 + 1);
    *(_DWORD *)v81 = v86;
    v87 = "eth2.4085 eth2.4084 eth2.4083 eth2.4082 eth2.4081 eth3.4085";
    v88 = v111;
    do
    {
      v89 = *(_DWORD *)v87;
      v90 = *((_DWORD *)v87 + 1);
      v91 = *((_DWORD *)v87 + 2);
      v92 = *((_DWORD *)v87 + 3);
      v87 += 16;
      *(_DWORD *)v88 = v89;
      *((_DWORD *)v88 + 1) = v90;
      *((_DWORD *)v88 + 2) = v91;
      *((_DWORD *)v88 + 3) = v92;
      v88 += 16;
    }
    while ( v87 != "1 eth3.4085" );
    v93 = *(_DWORD *)v87;
    v94 = *((_DWORD *)v87 + 1);
    v95 = *((_DWORD *)v87 + 2);
    *(_DWORD *)v88 = v93;
    *((_DWORD *)v88 + 1) = v94;
    *((_DWORD *)v88 + 2) = v95;
  }
  else if ( !strcmp(v2, "L123") )
  {
    v96 = "eth2.4085 eth2.4084 eth2.4083 eth2.4082 eth2.4081 eth3.4085 eth3.4084";
    strcpy(v112, "eth3.4081 eth3.4082 eth3.4083");
    v97 = v111;
    do
    {
      v98 = *(_DWORD *)v96;
      v99 = *((_DWORD *)v96 + 1);
      v100 = *((_DWORD *)v96 + 2);
      v101 = *((_DWORD *)v96 + 3);
      v96 += 16;
      *(_DWORD *)v97 = v98;
      *((_DWORD *)v97 + 1) = v99;
      *((_DWORD *)v97 + 2) = v100;
      *((_DWORD *)v97 + 3) = v101;
      v97 += 16;
    }
    while ( v96 != ".4084" );
    v102 = *(_DWORD *)v96;
    v103 = *((_WORD *)v96 + 2);
    *(_DWORD *)v97 = v102;
    *((_WORD *)v97 + 2) = v103;
  }
  else if ( !strcmp(v2, "L12") )
  {
    v104 = "eth2.4085 eth2.4084 eth2.4083 eth2.4082 eth2.4081 eth3.4085 eth3.4084 eth3.4083";
    strcpy(v112, "eth3.4081 eth3.4082");
    v105 = v111;
    do
    {
      v106 = *(_DWORD *)v104;
      v107 = *((_DWORD *)v104 + 1);
      v108 = *((_DWORD *)v104 + 2);
      v109 = *((_DWORD *)v104 + 3);
      v104 += 16;
      *(_DWORD *)v105 = v106;
      *((_DWORD *)v105 + 1) = v107;
      *((_DWORD *)v105 + 2) = v108;
      *((_DWORD *)v105 + 3) = v109;
      v105 += 16;
    }
    while ( v104 != "eth3.4081" );
  }
  else if ( !strcmp(v2, "L1") )
  {
    v3 = "eth2.4085 eth2.4084 eth2.4083 eth2.4082 eth2.4081 eth3.4085 eth3.4084 eth3.4083 eth3.4082";
    strcpy(v112, "eth3.4081");
    v4 = v111;
    do
    {
      v5 = *(_DWORD *)v3;
      v6 = *((_DWORD *)v3 + 1);
      v7 = *((_DWORD *)v3 + 2);
      v8 = *((_DWORD *)v3 + 3);
      v3 += 16;
      *(_DWORD *)v4 = v5;
      *((_DWORD *)v4 + 1) = v6;
      *((_DWORD *)v4 + 2) = v7;
      *((_DWORD *)v4 + 3) = v8;
      v4 += 16;
    }
    while ( v3 != "eth3.4082" );
    v9 = *(_DWORD *)v3;
    v10 = *((_DWORD *)v3 + 1);
    v11 = *((_WORD *)v3 + 4);
    *(_DWORD *)v4 = v9;
    *((_DWORD *)v4 + 1) = v10;
    *((_WORD *)v4 + 4) = v11;
  }
LABEL_20:
  strcpy(v110, "{\"code\":0,\"error\":\"\",\"data\":{\"bondlist\":");
  v26 = nvram_get("bond_list");
  strcpy(&v110[40], "[");
  if ( !v26 )
  {
    v30 = 1;
    v35 = 1;
    if ( v110[40] != 44 )
      goto LABEL_35;
    goto LABEL_53;
  }
  v27 = (const char **)malloc(0x20u);
  v29 = malloc(0x4008u);
  v28 = malloc(0x200000u);
  v113 = v28;
  if ( v28 )
  {
    v30 = 1;
    if ( v27 )
    {
      v31 = v26;
      if ( v29 )
      {
        v32 = v28;
        strlcpy(v28, v31, 0x200000);
        v33 = split_string(v32, 60, v29, 4096);
        if ( v33 > 0 )
        {
          v34 = v29;
          v35 = 1;
          for ( i = 0; i != v33; ++i )
          {
            v37 = split_string(*v34, 124, v27, 6);
            format_wys_bonding_data(v27, v37, &v110[v35 + 40], 102360 - v35);
            v35 += v38;
            ++v34;
          }
          v30 = v35;
          goto LABEL_28;
        }
        v30 = 1;
      }
    }
    v35 = 1;
LABEL_28:
    free(v113);
    goto LABEL_29;
  }
  v30 = 1;
  v35 = 1;
LABEL_29:
  if ( v27 )
    free(v27);
  if ( v29 )
    free(v29);
  if ( v35 > 0 && v110[v30 + 39] == 44 )
LABEL_53:
    v30 = --v35;
LABEL_35:
  v110[v30 + 40] = 0;
  v39 = snprintf(&v110[v30 + 40], 102360 - v35, &byte_6445A0);
  if ( v39 >= 102360 - v35 )
    v39 = 102359 - v35;
  v40 = v35 + v39 + 40;
  v41 = snprintf(&v110[v40], 102400 - v40, ",\"wan\":\"%s\",\"lan\":\"%s\",\"x86\":\"%d\"", v111, v112, 0);
  if ( v41 >= 102400 - v40 )
    v41 = 102399 - v40;
  v42 = v41 + v40;
  v43 = snprintf(&v110[v42], 102400 - v42, "}}");
  if ( v43 >= 102400 - v42 )
    v43 = 102399 - v42;
  return httpd_cgi_ret(a1, v110, v43 + v42, 4);
}
// 449A40: variable 'v38' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

